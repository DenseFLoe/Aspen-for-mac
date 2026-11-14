// Read-only APED export. Vendor assemblies are resolved from the local install.
using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Diagnostics;
using System.IO;
using System.Globalization;
using System.Reflection;
using System.Text;
using System.Web.Script.Serialization;
using AspenTech.APED;

public static class AspenDatabaseExporter
{
    public static void RunStorage(string database, string output, int limit)
    {
        if (Array.IndexOf(new[] { "APV150", "NISTV150", "APESV150", "FACTV150" }, database) < 0)
            throw new ArgumentException("Unsupported database");
        if (Directory.Exists(output)) throw new IOException("Output exists");
        Directory.CreateDirectory(output);
        var json = new JavaScriptSerializer();
        var db = new SqlServerDatabase();
        long count = 0, invalid = 0, plainChecks = 0;
        var watch = Stopwatch.StartNew();
        try
        {
            if (!db.Connect(database, ".", "", "", database)) throw new Exception("APED connection failed");
            // Invoke the installed V15 value decoder on its connected database.
            // No key/token is read, no decoder implementation is copied, and no
            // database or access setting is changed. This NON-PUBLIC method is
            // version-specific and its result must be checked against the API.
            var method = typeof(Database).GetMethod("DecryptVal", BindingFlags.Instance | BindingFlags.NonPublic);
            if (method == null || method.ReturnType != typeof(string))
                throw new NotSupportedException("Installed value decoder is incompatible");
            var decode = (Func<string, string, int, string>)Delegate.CreateDelegate(
                typeof(Func<string, string, int, string>), db, method);
            using (var sql = new SqlConnection("Server=.;Database=" + database + ";Integrated Security=true"))
            using (var writer = Writer(output, "constant-values.jsonl.partial"))
            {
                sql.Open();
                var command = sql.CreateCommand(); command.CommandTimeout = 300;
                command.CommandText = @"SELECT v.pvcCompoundPropId,v.pvcIndex,p.propName,v.pvcValue
                    FROM active_PropValueConst v
                    JOIN active_CompoundProperty cp ON cp.cpId=v.pvcCompoundPropId
                    JOIN active_Properties p ON p.propId=cp.cpPropertyId
                    ORDER BY v.pvcCompoundPropId,v.pvcIndex";
                using (var reader = command.ExecuteReader()) while (reader.Read())
                {
                    if (limit > 0 && count >= limit) break;
                    string property = reader.GetString(2), source = reader.GetString(3);
                    string decoded = decode(source, property, db.Version);
                    double number, original;
                    bool numeric = Double.TryParse(decoded, NumberStyles.Float, CultureInfo.InvariantCulture, out number)
                        && !Double.IsNaN(number) && !Double.IsInfinity(number);
                    if (!numeric) invalid++;
                    if (Double.TryParse(source, NumberStyles.Float, CultureInfo.InvariantCulture, out original))
                    {
                        if (!numeric || original != number) throw new InvalidDataException("Plain numeric source mismatch");
                        plainChecks++;
                    }
                    writer.WriteLine(json.Serialize(Row("cp_id", reader.GetInt32(0), "element_index", reader.GetInt32(1),
                        "property", property, "value_text", decoded, "value", numeric ? (object)number : null,
                        "status", numeric ? "decoded_numeric" : "non_numeric_review_required")));
                    count++;
                    if (count % 100000 == 0)
                    {
                        writer.Flush();
                        Console.WriteLine("{0}: decoded_cells={1} invalid={2} seconds={3:F1}",
                            database, count, invalid, watch.Elapsed.TotalSeconds);
                    }
                }
            }
            File.Move(Path.Combine(output, "constant-values.jsonl.partial"), Path.Combine(output, "constant-values.jsonl"));
            using (var summary = Writer(output, "summary.json"))
                summary.WriteLine(json.Serialize(Row("database", database, "format_version", 1,
                    "decoder", "installed AspenTech.APED.Database.DecryptVal (non-public)",
                    "api_version", typeof(SqlServerDatabase).Assembly.GetName().Version.ToString(),
                    "data_version", db.Version, "rows", count, "non_numeric", invalid,
                    "plain_numeric_checks", plainChecks, "limited_run", limit > 0,
                    "elapsed_seconds", watch.Elapsed.TotalSeconds)));
            Console.WriteLine("{0}: STORAGE COMPLETE rows={1} invalid={2}", database, count, invalid);
            if (invalid != 0) throw new InvalidDataException("Some decoded values require review");
        }
        finally { db.CloseConnection(); db.Dispose(); }
    }

    static Dictionary<string, object> Row(params object[] pairs)
    {
        var row = new Dictionary<string, object>();
        for (int i = 0; i < pairs.Length; i += 2) row.Add((string)pairs[i], pairs[i + 1]);
        return row;
    }

    static StreamWriter Writer(string directory, string name)
    {
        return new StreamWriter(new FileStream(Path.Combine(directory, name),
            FileMode.CreateNew, FileAccess.Write), new UTF8Encoding(false), 65536);
    }

    static Dictionary<string, object> Metadata(IProperty p)
    {
        var units = new List<object>();
        if (p.UnitsTypeList != null) foreach (var u in p.UnitsTypeList)
            units.Add(Row("row_id", u.RowId, "type", u.UnitRowName, "default_unit", u.DefaultUOM));
        return Row("property_id", p.Id, "name", p.Name, "description", p.Description,
            "data_type", p.DataType.ToString(), "interaction_type", p.InteractionType.ToString(),
            "compound_type", p.CompoundType.ToString(), "is_global", p.IsGlobal,
            "element_count", p.ElementCount, "labels", p.LabelList,
            "label_ij", p.LabelIJArray, "label_ji", p.LabelJIArray,
            "symmetry", p.SymmetryList, "units", units);
    }

    public static void Run(string database, string output, int limit)
    {
        if (Array.IndexOf(new[] { "APV150", "NISTV150", "APESV150", "FACTV150" }, database) < 0)
            throw new ArgumentException("Unsupported database");
        if (Directory.Exists(output)) throw new IOException("Output exists");
        Directory.CreateDirectory(output);
        var json = new JavaScriptSerializer { MaxJsonLength = Int32.MaxValue };
        var db = new SqlServerDatabase();
        var watch = Stopwatch.StartNew();
        int requested = 0, exported = 0, failed = 0;
        try
        {
            if (!db.Connect(database, ".", "", "", database)) throw new Exception("APED connection failed");
            IDatabankCollection banks = null;
            db.EnumerateDatabanks(out banks);
            var bankMap = new Dictionary<int, IDatabank>();
            foreach (IDatabank bank in banks) bankMap.Add(bank.Id, bank);
            var properties = new HashSet<int>();
            using (var sql = new SqlConnection("Server=.;Database=" + database + ";Integrated Security=true"))
            using (var values = Writer(output, "parameters.jsonl.partial"))
            using (var metadata = Writer(output, "properties.jsonl.partial"))
            using (var errors = Writer(output, "failures.jsonl.partial"))
            {
                sql.Open();
                var command = sql.CreateCommand();
                command.CommandTimeout = 300;
                // Export each physical parameter set once, retaining ALL bank links in
                // the separately exported active_DatabankCompounds table. No merging
                // by chemical name, no guessed units, no flattened directional arrays.
                command.CommandText = @"
                    SELECT cp.cpId,cp.cpCompoundId,cp.cpPropertyId,p.propName,
                           x.bankId,idx.ciValue
                    FROM active_CompoundProperty cp
                    JOIN (SELECT dbcCompoundPropId,MIN(dbcDatabankId) bankId
                          FROM active_DatabankCompounds GROUP BY dbcCompoundPropId) x
                      ON x.dbcCompoundPropId=cp.cpId
                    JOIN active_Properties p ON p.propId=cp.cpPropertyId
                    LEFT JOIN active_CompoundIdentifiers idx
                      ON idx.ciCompoundId=cp.cpCompoundId AND idx.ciIdentifierId=
                         (SELECT identId FROM active_Identifiers WHERE identName='CompoundIndex')
                    ORDER BY x.bankId,cp.cpCompoundId,cp.cpId";
                using (var reader = command.ExecuteReader())
                while (reader.Read())
                {
                    if (limit > 0 && requested >= limit) break;
                    requested++;
                    int cp = reader.GetInt32(0), entity = reader.GetInt32(1), propId = reader.GetInt32(2);
                    string property = reader.GetString(3);
                    int bankId = reader.GetInt32(4);
                    string index = reader.IsDBNull(5) ? null : reader.GetString(5);
                    var record = Row("cp_id", cp, "entity_id", entity, "property_id", propId,
                        "property", property, "read_bank_id", bankId, "compound_index", index);
                    try
                    {
                        if (index == null) throw new InvalidOperationException("Missing CompoundIndex");
                        IPropertyValue value = null;
                        db.PropertyValueManager.GetUnaryPropertyValue(bankMap[bankId], index,
                            "CompoundIndex", property, out value);
                        if (value == null || value.Value == null) throw new InvalidOperationException("No value");
                        if (value.Property.Name != property || value.Databank.Id != bankId ||
                            (string)value.GetType().GetProperty("Identity").GetValue(value, null) !=
                                cp.ToString(System.Globalization.CultureInfo.InvariantCulture))
                            throw new InvalidOperationException("Provenance mismatch");
                        record.Add("value", value.Value);
                        record.Add("value_type", value.Value.GetType().FullName);
                        record.Add("data_source_type", value.DataSourceType);
                        record.Add("uncertainty", value.Uncertainty);
                        record.Add("uncertainty_source", value.UncertaintySource);
                        record.Add("notes", value.Notes);
                        // Serialize immediately: API-owned arrays must not outlive the call.
                        string line = json.Serialize(record);
                        if (!properties.Contains(propId))
                        {
                            metadata.WriteLine(json.Serialize(Metadata(value.Property)));
                            properties.Add(propId);
                        }
                        values.WriteLine(line);
                        exported++;
                    }
                    catch (Exception error)
                    {
                        // Never serialize an exception message or connection object.
                        record.Remove("value");
                        record.Add("error_type", error.GetType().FullName);
                        errors.WriteLine(json.Serialize(record));
                        failed++;
                    }
                    if (requested % 10000 == 0)
                    {
                        values.Flush(); metadata.Flush(); errors.Flush();
                        Console.WriteLine("{0}: requested={1} exported={2} failed={3} seconds={4:F1}",
                            database, requested, exported, failed, watch.Elapsed.TotalSeconds);
                    }
                }
            }
            foreach (var name in new[] { "parameters.jsonl", "properties.jsonl", "failures.jsonl" })
                File.Move(Path.Combine(output, name + ".partial"), Path.Combine(output, name));
            using (var summary = Writer(output, "summary.json"))
                summary.WriteLine(json.Serialize(Row("format_version", 1, "database", database,
                    "api_version", typeof(SqlServerDatabase).Assembly.GetName().Version.ToString(),
                    "requested", requested, "exported", exported, "failed", failed,
                    "limited_run", limit > 0, "elapsed_seconds", watch.Elapsed.TotalSeconds,
                    "created_utc", DateTime.UtcNow.ToString("o"))));
            Console.WriteLine("{0}: COMPLETE requested={1} exported={2} failed={3}",
                database, requested, exported, failed);
            if (failed > 0) throw new Exception("Some parameter reads failed; inspect failures.jsonl");
        }
        finally { db.CloseConnection(); db.Dispose(); }
    }
}
