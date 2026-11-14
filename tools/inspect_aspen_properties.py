"""Inventory a local APED SQL Server and create a small API export plan.

Requires pyodbc and the Microsoft ODBC Driver 17 for SQL Server. Uses Windows
integrated authentication and SELECT statements only. Database contents belong
in a machine-local output directory, never in the source repository.
"""
import argparse
import json
import sqlite3
from pathlib import Path

import pyodbc

DATABASES = ("APV150", "NISTV150", "APESV150", "FACTV150")
CATALOG_TABLES = (
    "active_Identifiers", "active_CompoundIdentifiers", "active_Databanks",
    "active_Properties", "active_PropElements", "active_PropertyUnitrow",
    "active_UOM", "active_LabeledValue", "active_Duos", "active_ElectrolytePairs",
)


def records(connection, sql):
    cursor = connection.execute(sql)
    names = [column[0] for column in cursor.description]
    return [dict(zip(names, row)) for row in cursor]


def connect(database):
    return pyodbc.connect(
        "DRIVER={ODBC Driver 17 for SQL Server};SERVER=.;DATABASE=" + database
        + ";Trusted_Connection=yes;Encrypt=no;",
        autocommit=True, readonly=True, timeout=10,
    )


def inspect_database(database, output):
    connection = connect(database)
    try:
        schema = records(connection, """
            SELECT TABLE_NAME,COLUMN_NAME,DATA_TYPE,ORDINAL_POSITION
            FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME LIKE 'active[_]%'
            ORDER BY TABLE_NAME,ORDINAL_POSITION
        """)
        tables = [row[0] for row in connection.execute(
            "SELECT name FROM sys.tables WHERE name LIKE 'active[_]%' ORDER BY name"
        )]
        counts = {name: connection.execute(
            "SELECT COUNT_BIG(*) FROM [" + name.replace("]", "]]") + "]"
        ).fetchone()[0] for name in tables}
        banks = records(connection, "SELECT * FROM active_Databanks ORDER BY dbId")
        named = connection.execute("""
            SELECT COUNT(DISTINCT ciCompoundId) FROM active_CompoundIdentifiers
            JOIN active_Identifiers ON identId=ciIdentifierId WHERE identName='NAME'
        """).fetchone()[0]
        encoding = {"numeric_text": 0, "non_numeric_text": 0}
        for (value,) in connection.execute("SELECT pvcValue FROM active_PropValueConst"):
            try:
                float(value)
                encoding["numeric_text"] += 1
            except (ValueError, TypeError):
                encoding["non_numeric_text"] += 1
        catalog_path = output / (database + "-catalog.sqlite")
        if catalog_path.exists():
            raise FileExistsError(catalog_path)
        catalog = sqlite3.connect(catalog_path)
        try:
            for table in CATALOG_TABLES:
                columns = [c for c in schema if c["TABLE_NAME"] == table]
                types = {"int": "INTEGER", "bit": "INTEGER"}
                definitions = ",".join('"' + c["COLUMN_NAME"] + '" '
                    + types.get(c["DATA_TYPE"], "TEXT") for c in columns)
                catalog.execute('CREATE TABLE "' + table + '" (' + definitions + ')')
                cursor = connection.execute("SELECT * FROM [" + table + "]")
                insert = 'INSERT INTO "' + table + '" VALUES (' + ','.join('?' for _ in columns) + ')'
                while batch := cursor.fetchmany(4096):
                    catalog.executemany(insert, [tuple(row) for row in batch])
                actual = catalog.execute('SELECT COUNT(*) FROM "' + table + '"').fetchone()[0]
                if actual != counts[table]:
                    raise RuntimeError(f"Row count changed for {database}.{table}")
            catalog.commit()
            if catalog.execute("PRAGMA integrity_check").fetchone()[0] != "ok":
                raise RuntimeError("SQLite integrity check failed")
        finally:
            catalog.close()
        result = dict(database=database, entity_rows=counts["active_Compounds"],
                      named_compounds=named, table_counts=counts, schema=schema,
                      databanks=banks, value_encoding=encoding)
        print(json.dumps({k: result[k] for k in ("database", "entity_rows", "named_compounds", "value_encoding")}))
        return result
    finally:
        connection.close()


def sample_plan():
    connection = connect("APV150")
    try:
        # SQL supplies identities and provenance. Values are read by the Aspen
        # API, which handles the installed version's storage representation.
        rows = records(connection, """
            SELECT DISTINCT b.dbName,idx.ciValue AS compoundIndex,p.propName,
              n.ciValue AS compoundName,cp.cpCompoundId
            FROM active_Databanks b
            JOIN active_DatabankCompounds d ON d.dbcDatabankId=b.dbId
            JOIN active_CompoundProperty cp ON cp.cpId=d.dbcCompoundPropId
            JOIN active_Properties p ON p.propId=cp.cpPropertyId
            JOIN active_CompoundIdentifiers idx ON idx.ciCompoundId=cp.cpCompoundId AND idx.ciIdentifierId=1
            JOIN active_CompoundIdentifiers n ON n.ciCompoundId=cp.cpCompoundId AND n.ciIdentifierId=2
            WHERE b.dbName='PURE41' AND n.ciValue IN ('METHANE','WATER','ETHANOL')
            ORDER BY n.ciValue,p.propName
        """)
        plan = [dict(database="APV150", bank=r["dbName"], entity_id=r["cpCompoundId"],
                     compound_index=r["compoundIndex"], compounds=[r["compoundName"]],
                     property=r["propName"], interaction="pure") for r in rows]
        pairs = records(connection, """
            SELECT DISTINCT b.dbName,idx.ciValue AS compoundIndex,p.propName,
              n1.ciValue AS compound1,n2.ciValue AS compound2,du.duoId
            FROM active_Duos du
            JOIN active_CompoundIdentifiers n1 ON n1.ciCompoundId=du.duoCompound1Id AND n1.ciIdentifierId=2
            JOIN active_CompoundIdentifiers n2 ON n2.ciCompoundId=du.duoCompound2Id AND n2.ciIdentifierId=2
            JOIN active_CompoundIdentifiers idx ON idx.ciCompoundId=du.duoId AND idx.ciIdentifierId=1
            JOIN active_CompoundProperty cp ON cp.cpCompoundId=du.duoId
            JOIN active_Properties p ON p.propId=cp.cpPropertyId
            JOIN active_DatabankCompounds d ON d.dbcCompoundPropId=cp.cpId
            JOIN active_Databanks b ON b.dbId=d.dbcDatabankId
            WHERE b.dbName='VLE-IG' AND n1.ciValue='ETHANOL' AND n2.ciValue='WATER'
            ORDER BY p.propName
        """)
        plan += [dict(database="APV150", bank=r["dbName"], entity_id=r["duoId"],
                      compound_index=r["compoundIndex"], compounds=[r["compound1"],r["compound2"]],
                      property=r["propName"], interaction="binary") for r in pairs]
        return plan
    finally:
        connection.close()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--output", type=Path, required=True, help="New machine-local output directory")
    args = parser.parse_args()
    args.output.mkdir(parents=True, exist_ok=False)
    inventory = [inspect_database(db, args.output) for db in DATABASES]
    (args.output / "inventory.json").write_text(json.dumps(inventory, indent=2), encoding="utf-8")
    plan = sample_plan()
    (args.output / "sample-plan.json").write_text(json.dumps(plan, indent=2), encoding="utf-8")
    print(f"Validated four SQLite catalogs; planned {len(plan)} parameter reads.")


if __name__ == "__main__":
    main()
