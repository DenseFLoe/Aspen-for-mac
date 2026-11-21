using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.IO;
using System.IO.Compression;
using System.Linq;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Versioning;
using System.Text;
using System.Xml.Linq;
using AspenTech.Adb.Interfaces;

[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyCompany("AspenTech Corporation")]
[assembly: AssemblyProduct("Aspen Data Share")]
[assembly: AssemblyCopyright("Copyright © AspenTech Corporation 2025")]
[assembly: AssemblyFileVersion("41.0.0.2")]
[assembly: AssemblyTitle("AdsDataMap")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: AssemblyTrademark("")]
[assembly: ComVisible(false)]
[assembly: Guid("ca70018d-9e04-4176-b169-6162622c1577")]
[assembly: TargetFramework(".NETFramework,Version=v4.8", FrameworkDisplayName = ".NET Framework 4.8")]
[assembly: AssemblyVersion("41.0.0.0")]
namespace AdsDataMap;

public class AdmException : Exception
{
	public AdmException(string message)
		: base(message)
	{
	}
}
public abstract class ArgumentScalarData<T> : IArgumentData
{
	public T Value { get; protected set; }

	public abstract string sVal { get; }

	public abstract int? iVal { get; }

	public abstract double? rVal { get; }

	public abstract bool? bVal { get; }

	public abstract string orginalDatatype { get; }

	public virtual IArgumentData reference => null;

	public int Length => 0;

	public bool IsScalar => true;

	public object ScalarValue => Value;

	public IEnumerable<IArgumentData> Values => Enumerable.Empty<IArgumentData>();

	public IEnumerable<string> Ids => Enumerable.Empty<string>();

	public IEnumerable<KeyValuePair<string, IArgumentData>> IdValues => Enumerable.Empty<KeyValuePair<string, IArgumentData>>();

	public ArgumentScalarData(T value)
	{
		Value = value;
	}

	public IArgumentData ValueAt(int index)
	{
		return null;
	}

	public string IdAt(int index)
	{
		return null;
	}

	public KeyValuePair<string, IArgumentData>? IdValueAt(int index)
	{
		return null;
	}
}
public class ArgumentStringData : ArgumentScalarData<string>
{
	public override string sVal => base.Value;

	public override int? iVal
	{
		get
		{
			int? result = null;
			if (int.TryParse(base.Value, out var result2))
			{
				result = result2;
			}
			return result;
		}
	}

	public override double? rVal
	{
		get
		{
			double? result = null;
			if (double.TryParse(base.Value, out var result2))
			{
				result = result2;
			}
			return result;
		}
	}

	public override bool? bVal
	{
		get
		{
			bool? result = null;
			if (bool.TryParse(base.Value, out var result2))
			{
				result = result2;
			}
			return result;
		}
	}

	public override string orginalDatatype => "string";

	public ArgumentStringData(string value)
		: base(value)
	{
	}
}
public class ArgumentIntData : ArgumentScalarData<int?>
{
	public override string sVal
	{
		get
		{
			string result = null;
			if (base.Value.HasValue)
			{
				result = base.Value.Value.ToString();
			}
			return result;
		}
	}

	public override int? iVal => base.Value;

	public override double? rVal
	{
		get
		{
			double? result = null;
			if (base.Value.HasValue)
			{
				result = base.Value.Value;
			}
			return result;
		}
	}

	public override bool? bVal
	{
		get
		{
			bool? result = null;
			if (base.Value.HasValue)
			{
				result = ((base.Value.Value != 0) ? true : false);
			}
			return result;
		}
	}

	public override string orginalDatatype => "int";

	public ArgumentIntData(int? value)
		: base(value)
	{
	}
}
public class ArgumentRealData : ArgumentScalarData<double?>
{
	public override string sVal
	{
		get
		{
			string result = null;
			if (base.Value.HasValue)
			{
				result = base.Value.Value.ToString();
			}
			return result;
		}
	}

	public override int? iVal
	{
		get
		{
			int? result = null;
			if (base.Value.HasValue)
			{
				result = (int)base.Value.Value;
			}
			return result;
		}
	}

	public override double? rVal => base.Value;

	public override bool? bVal
	{
		get
		{
			bool? result = null;
			if (base.Value.HasValue)
			{
				result = (((int)base.Value.Value != 0) ? true : false);
			}
			return result;
		}
	}

	public override string orginalDatatype => "real";

	public ArgumentRealData(double? value)
		: base(value)
	{
	}
}
public class ArgumentBoolData : ArgumentScalarData<bool?>
{
	public override string sVal
	{
		get
		{
			string result = null;
			if (base.Value.HasValue)
			{
				result = base.Value.Value.ToString();
			}
			return result;
		}
	}

	public override int? iVal
	{
		get
		{
			int? result = null;
			if (base.Value.HasValue)
			{
				result = (base.Value.Value ? 1 : 0);
			}
			return result;
		}
	}

	public override double? rVal
	{
		get
		{
			double? result = null;
			if (base.Value.HasValue)
			{
				result = (base.Value.Value ? 1.0 : 0.0);
			}
			return result;
		}
	}

	public override bool? bVal => base.Value;

	public override string orginalDatatype => "bool";

	public ArgumentBoolData(bool? value)
		: base(value)
	{
	}
}
public class ArgumentRefData : ArgumentScalarData<IArgumentData>
{
	public override string sVal => null;

	public override int? iVal => null;

	public override double? rVal => null;

	public override bool? bVal => null;

	public override string orginalDatatype => null;

	public override IArgumentData reference => base.Value;

	public ArgumentRefData(IArgumentData value)
		: base(value)
	{
	}
}
public class ArgumentObjectData : ArgumentScalarData<object>
{
	public override string sVal => null;

	public override int? iVal => null;

	public override double? rVal => null;

	public override bool? bVal => null;

	public override string orginalDatatype => "Object";

	public ArgumentObjectData(object value)
		: base(value)
	{
	}
}
public abstract class ArgumentNonScalarData : IArgumentData
{
	public string sVal => null;

	public int? iVal => null;

	public double? rVal => null;

	public bool? bVal => null;

	public string orginalDatatype => null;

	public IArgumentData reference => null;

	public bool IsScalar => false;

	public object ScalarValue => null;

	public abstract int Length { get; }

	public abstract IEnumerable<IArgumentData> Values { get; }

	public abstract IEnumerable<string> Ids { get; }

	public abstract IEnumerable<KeyValuePair<string, IArgumentData>> IdValues { get; }

	public ArgumentNonScalarData()
	{
	}

	public abstract IArgumentData ValueAt(int index);

	public abstract string IdAt(int index);

	public abstract KeyValuePair<string, IArgumentData>? IdValueAt(int index);
}
public class ArgumentArrayData : ArgumentNonScalarData
{
	private class StringVals : IEnumerable<string>, IEnumerable
	{
		private IArgumentData _stringArray;

		public StringVals(IArgumentData stringArray)
		{
			_stringArray = stringArray;
		}

		public IEnumerator<string> GetEnumerator()
		{
			foreach (IArgumentData value in _stringArray.Values)
			{
				yield return value.sVal;
			}
		}

		IEnumerator IEnumerable.GetEnumerator()
		{
			return GetEnumerator();
		}
	}

	protected string[] _ids;

	protected IArgumentData[] _values;

	protected IArgumentData _idSupplier;

	public override int Length => _values.Length;

	public override IEnumerable<IArgumentData> Values => _values;

	public override IEnumerable<string> Ids
	{
		get
		{
			_ = _ids;
			if (_idSupplier != null)
			{
				new StringVals(_idSupplier);
			}
			return _ids;
		}
	}

	public override IEnumerable<KeyValuePair<string, IArgumentData>> IdValues
	{
		get
		{
			for (int i = 0; i < _values.Length; i++)
			{
				if (_idSupplier != null)
				{
					yield return new KeyValuePair<string, IArgumentData>(_idSupplier.ValueAt(i).sVal, _values[i]);
				}
				else
				{
					yield return new KeyValuePair<string, IArgumentData>(_ids[i], _values[i]);
				}
			}
		}
	}

	public ArgumentArrayData(int length)
	{
		_ids = new string[length];
		_values = new IArgumentData[length];
	}

	public void SetIdSupplier(IArgumentData idSupplier)
	{
		_idSupplier = idSupplier;
	}

	public void SetValue(int index, IArgumentData value)
	{
		_values[index] = value;
	}

	public void SetId(int index, string id)
	{
		_ids[index] = id;
	}

	public void SetIdAndValue(int index, string id, IArgumentData value)
	{
		_values[index] = value;
		_ids[index] = id;
	}

	public override IArgumentData ValueAt(int index)
	{
		return _values[index];
	}

	public override string IdAt(int index)
	{
		return _ids[index];
	}

	public override KeyValuePair<string, IArgumentData>? IdValueAt(int index)
	{
		return (_idSupplier == null) ? new KeyValuePair<string, IArgumentData>(_ids[index], _values[index]) : new KeyValuePair<string, IArgumentData>(_idSupplier.ValueAt(index).sVal, _values[index]);
	}
}
public class ArgumentReducedMatrixData : ArgumentNonScalarData
{
	private ArgumentMatrixData _baseMatrix;

	private List<int> _reducedIndicies;

	private int[] _lengths;

	private int _start;

	private int _increment;

	private int _dimno;

	private int _ndim;

	public override int Length => _lengths[_dimno];

	public override IEnumerable<IArgumentData> Values
	{
		get
		{
			for (int i = _start; i < _lengths[_dimno]; i += _increment)
			{
				if (_dimno == _ndim - 1)
				{
					yield return _baseMatrix.ValueAtRawLocation(i);
					continue;
				}
				List<int> list = new List<int>(_reducedIndicies);
				list.Add(i);
				yield return new ArgumentReducedMatrixData(_baseMatrix, list, i, _increment * _lengths[_dimno]);
			}
		}
	}

	public override IEnumerable<string> Ids => _baseMatrix.BaseIds[_dimno];

	public override IEnumerable<KeyValuePair<string, IArgumentData>> IdValues
	{
		get
		{
			int i = _start;
			int idcnt = 0;
			while (i < _lengths[_dimno])
			{
				if (_dimno == _ndim - 1)
				{
					yield return new KeyValuePair<string, IArgumentData>(_baseMatrix.BaseIds[_dimno][idcnt], _baseMatrix.ValueAtRawLocation(i));
				}
				else
				{
					List<int> list = new List<int>(_reducedIndicies);
					list.Add(i);
					yield return new KeyValuePair<string, IArgumentData>(_baseMatrix.BaseIds[_dimno][idcnt], new ArgumentReducedMatrixData(_baseMatrix, list, i, _increment * _lengths[_dimno]));
				}
				i += _increment;
				idcnt++;
			}
		}
	}

	public ArgumentReducedMatrixData(ArgumentMatrixData baseMatrix, List<int> reducedIndicies, int start, int increment)
	{
		_baseMatrix = baseMatrix;
		_reducedIndicies = reducedIndicies;
		_lengths = _baseMatrix.Lengths;
		_dimno = reducedIndicies.Count;
		_ndim = _lengths.Length;
		_start = start;
		_increment = increment;
	}

	public override IArgumentData ValueAt(int index)
	{
		int num = _start + index * _increment;
		if (_dimno == _ndim - 1)
		{
			return _baseMatrix.ValueAtRawLocation(num);
		}
		List<int> list = new List<int>(_reducedIndicies);
		list.Add(index);
		return new ArgumentReducedMatrixData(_baseMatrix, list, num, _increment * _lengths[_dimno]);
	}

	public override string IdAt(int index)
	{
		return _baseMatrix.BaseIds[_dimno][index];
	}

	public override KeyValuePair<string, IArgumentData>? IdValueAt(int index)
	{
		int num = _start + index * _increment;
		KeyValuePair<string, IArgumentData> value;
		if (_dimno == _ndim - 1)
		{
			value = new KeyValuePair<string, IArgumentData>(_baseMatrix.BaseIds[_dimno][index], _baseMatrix.ValueAtRawLocation(num));
		}
		else
		{
			List<int> list = new List<int>(_reducedIndicies);
			list.Add(index);
			value = new KeyValuePair<string, IArgumentData>(_baseMatrix.BaseIds[_dimno][index], new ArgumentReducedMatrixData(_baseMatrix, list, num, _increment * _lengths[_dimno]));
		}
		return value;
	}
}
public class ArgumentMatrixData : ArgumentNonScalarData
{
	protected string[][] _ids;

	protected IArgumentData[] _values;

	protected int[] _lengths;

	protected int _ndim;

	public int[] Lengths => _lengths;

	public override int Length => _lengths[0];

	public override IEnumerable<IArgumentData> Values
	{
		get
		{
			for (int i = 0; i < _lengths[0]; i++)
			{
				if (_ndim == 1)
				{
					yield return _values[i];
					continue;
				}
				yield return new ArgumentReducedMatrixData(this, new List<int> { i }, i, _lengths[0]);
			}
		}
	}

	public override IEnumerable<string> Ids => _ids[0];

	public override IEnumerable<KeyValuePair<string, IArgumentData>> IdValues
	{
		get
		{
			for (int i = 0; i < _lengths[0]; i++)
			{
				if (_ndim == 1)
				{
					yield return new KeyValuePair<string, IArgumentData>(_ids[0][i], _values[i]);
					continue;
				}
				yield return new KeyValuePair<string, IArgumentData>(_ids[0][i], new ArgumentReducedMatrixData(this, new List<int> { i }, i, _lengths[0]));
			}
		}
	}

	public string[][] BaseIds => _ids;

	public ArgumentMatrixData(int[] rowThenColumnLengths)
	{
		_ndim = rowThenColumnLengths.Length;
		int num = 1;
		_lengths = new int[_ndim];
		_ids = new string[_ndim][];
		for (int i = 0; i < _ndim; i++)
		{
			_lengths[i] = rowThenColumnLengths[i];
			num *= rowThenColumnLengths[i];
			_ids[i] = new string[_lengths[i]];
		}
		_values = new IArgumentData[num];
	}

	protected int Location(int[] rowThenColumnIndex)
	{
		int num = -1;
		if (rowThenColumnIndex.Length == _ndim)
		{
			num = rowThenColumnIndex[_ndim - 1];
			for (int num2 = _ndim - 2; num2 >= 0; num2--)
			{
				num = _lengths[num2] * num + rowThenColumnIndex[num2];
			}
		}
		return num;
	}

	public void SetValue(int[] rowThenColumnIndex, IArgumentData value)
	{
		int num = Location(rowThenColumnIndex);
		if (num != -1)
		{
			_values[num] = value;
		}
	}

	public void SetId(int dimension, int indexAlongDimension, string id)
	{
		_ids[dimension][indexAlongDimension] = id;
	}

	public override IArgumentData ValueAt(int index)
	{
		if (_ndim == 1)
		{
			return _values[index];
		}
		return new ArgumentReducedMatrixData(this, new List<int> { index }, index, _lengths[0]);
	}

	public override string IdAt(int index)
	{
		return _ids[0][index];
	}

	public override KeyValuePair<string, IArgumentData>? IdValueAt(int index)
	{
		KeyValuePair<string, IArgumentData> value = ((_ndim != 1) ? new KeyValuePair<string, IArgumentData>(_ids[0][index], new ArgumentReducedMatrixData(this, new List<int> { index }, index, _lengths[0])) : new KeyValuePair<string, IArgumentData>(_ids[0][index], _values[index]));
		return value;
	}

	public IArgumentData ValueAtRawLocation(int location)
	{
		return _values[location];
	}
}
public class ArgumentResolvedPathData : IArgumentData
{
	private int[] _indexes;

	private int _fix;

	private int _fixLength;

	private int _numUnfixed;

	private IArgumentData _baseArg;

	private IArgumentData _resolvedTo;

	private int _numResolved;

	public int TopElementNumber => _indexes[0];

	public int Length => _fixLength;

	public IEnumerable<IArgumentData> Values
	{
		get
		{
			for (int i = 0; i < _fixLength; i++)
			{
				yield return ValueAt(i);
			}
		}
	}

	public IEnumerable<string> Ids
	{
		get
		{
			for (int i = 0; i < _fixLength; i++)
			{
				yield return IdAt(i);
			}
		}
	}

	public IEnumerable<KeyValuePair<string, IArgumentData>> IdValues
	{
		get
		{
			int loc = 0;
			foreach (IArgumentData value in Values)
			{
				string key = _resolvedTo.IdAt(loc);
				KeyValuePair<string, IArgumentData> keyValuePair = new KeyValuePair<string, IArgumentData>(key, value);
				loc++;
				yield return keyValuePair;
			}
		}
	}

	public string sVal => _resolvedTo.sVal;

	public int? iVal => _resolvedTo.iVal;

	public double? rVal => _resolvedTo.rVal;

	public bool? bVal => _resolvedTo.bVal;

	public string orginalDatatype => _resolvedTo.orginalDatatype;

	public IArgumentData reference => _resolvedTo.reference;

	public bool IsScalar => _resolvedTo.IsScalar;

	public object ScalarValue => _resolvedTo.ScalarValue;

	public ArgumentResolvedPathData(IArgumentData baseArg, int[] indexes, int newFixedIndexVal, IArgumentData resolvedTo, int numResolved)
	{
		_baseArg = baseArg;
		_resolvedTo = resolvedTo;
		_numResolved = numResolved;
		int num = indexes.Length;
		_indexes = new int[num];
		int num2 = 0;
		int num3 = -1;
		for (int i = 0; i < num; i++)
		{
			_indexes[i] = indexes[i];
			if (_indexes[i] < num2)
			{
				num2 = _indexes[i];
				num3 = i;
			}
		}
		_indexes[num3] = newFixedIndexVal;
		num2 = 0;
		num3 = -1;
		for (int j = 0; j < num; j++)
		{
			if (_indexes[j] < num2)
			{
				num2 = _indexes[j];
				num3 = j;
			}
		}
		_fix = num3;
		_numUnfixed = 0;
		for (int k = 0; k < num; k++)
		{
			if (resolvedTo == null)
			{
				break;
			}
			if (_indexes[k] < 0)
			{
				_numUnfixed++;
			}
			if (k == _numResolved && _indexes[k] >= 0)
			{
				_resolvedTo = _resolvedTo.ValueAt(_indexes[k]);
				_numResolved++;
			}
		}
		SetFixLength();
	}

	private void SetFixLength()
	{
		IArgumentData argumentData = _resolvedTo;
		for (int i = _numResolved; i < _fix; i++)
		{
			if (argumentData == null)
			{
				break;
			}
			argumentData = argumentData.ValueAt((_indexes[i] >= 0) ? _indexes[i] : 0);
		}
		if (argumentData != null)
		{
			_fixLength = argumentData.Length;
		}
		else
		{
			_fixLength = 0;
		}
	}

	public ArgumentResolvedPathData(IArgumentData baseArg, ArgumentResolvedPathData parent, int newIndex)
	{
		_baseArg = baseArg;
		if (parent != null)
		{
			_indexes = new int[parent._indexes.Length + 1];
			for (int i = 0; i < parent._indexes.Length; i++)
			{
				_indexes[i] = parent._indexes[i];
			}
			_indexes[_indexes.Length - 1] = newIndex;
			_numUnfixed = parent._numUnfixed;
			_resolvedTo = parent._resolvedTo;
			_numResolved = parent._numResolved;
		}
		else
		{
			_indexes = new int[1];
			_indexes[0] = newIndex;
			_numUnfixed = 0;
			_resolvedTo = _baseArg;
			_numResolved = 0;
		}
		if (newIndex < 0)
		{
			_numUnfixed++;
		}
		else if (_numResolved == _indexes.Length - 1)
		{
			IArgumentData argumentData = _resolvedTo.ValueAt(newIndex);
			if (argumentData != null)
			{
				_resolvedTo = argumentData;
				_numResolved++;
			}
		}
	}

	public ArgumentResolvedPathData(ArgumentResolvedPathData other)
	{
		_indexes = new int[other._indexes.Length];
		Array.Copy(other._indexes, _indexes, _indexes.Length);
		_fix = other._fix;
		_fixLength = other._fixLength;
		_numUnfixed = other._numUnfixed;
		_baseArg = other._baseArg;
		_resolvedTo = other._resolvedTo;
		_numResolved = other._numResolved;
	}

	public void SetIndexes(ObservableCollection<IdResolution> idRes)
	{
		if (idRes == null || !idRes.Any())
		{
			return;
		}
		int[] array = new int[idRes.Count];
		int num = 0;
		for (int i = 0; i < _indexes.Length; i++)
		{
			if (_indexes[i] < 0)
			{
				array[num++] = i;
			}
		}
		int num2 = -idRes.Count;
		for (int j = 0; j < idRes.Count; j++)
		{
			_indexes[array[j]] = num2 + idRes[j].PresentedSequence;
			if (idRes[j].PresentedSequence == 0)
			{
				_fix = array[j];
			}
		}
		SetFixLength();
	}

	public IArgumentData ValueAt(int index)
	{
		if (_numUnfixed == 1)
		{
			IArgumentData argumentData = _resolvedTo;
			for (int i = _numResolved; i < _indexes.Length; i++)
			{
				if (argumentData == null)
				{
					break;
				}
				argumentData = ((i != _fix) ? argumentData.ValueAt(_indexes[i]) : argumentData.ValueAt(index));
			}
			return argumentData;
		}
		return new ArgumentResolvedPathData(_baseArg, _indexes, index, _resolvedTo, _numResolved);
	}

	public string IdAt(int index)
	{
		return _resolvedTo.IdAt(index);
	}

	public KeyValuePair<string, IArgumentData>? IdValueAt(int index)
	{
		return new KeyValuePair<string, IArgumentData>(IdAt(index), ValueAt(index));
	}
}
public class ArgumentStringDataOrDefault : ArgumentStringData
{
	private readonly object _defvalue;

	public override string sVal
	{
		get
		{
			if (base.Value != null || _defvalue == null)
			{
				return base.sVal;
			}
			return _defvalue.ToString();
		}
	}

	public ArgumentStringDataOrDefault(string value, object defvalue = null)
		: base(value)
	{
		_defvalue = defvalue;
	}
}
public class ArgumentIntDataOrDefault : ArgumentIntData
{
	private readonly object _defvalue;

	public override string sVal
	{
		get
		{
			if (base.Value.HasValue || _defvalue == null)
			{
				return base.sVal;
			}
			return _defvalue.ToString();
		}
	}

	public ArgumentIntDataOrDefault(int? value, object defvalue = null)
		: base(value)
	{
		_defvalue = defvalue;
	}
}
public class ArgumentRealDataOrDefault : ArgumentRealData
{
	private readonly object _defvalue;

	public override string sVal
	{
		get
		{
			if (base.Value.HasValue || _defvalue == null)
			{
				return base.sVal;
			}
			return _defvalue.ToString();
		}
	}

	public ArgumentRealDataOrDefault(double? value, object defvalue = null)
		: base(value)
	{
		_defvalue = defvalue;
	}
}
public class ArgumentBoolDataOrDefault : ArgumentBoolData
{
	private readonly object _defvalue;

	public override string sVal
	{
		get
		{
			if (base.Value.HasValue || _defvalue == null)
			{
				return base.sVal;
			}
			return _defvalue.ToString();
		}
	}

	public ArgumentBoolDataOrDefault(bool? value, object defvalue = null)
		: base(value)
	{
		_defvalue = defvalue;
	}
}
public class ConnectedConverterArgs : BaseTable
{
	private DataView _sortedByConverter;

	public DataColumn guidCol { get; set; }

	public DataColumn connectedConverterCol { get; set; }

	public DataColumn isLeftArgCol { get; set; }

	public DataColumn converterArg { get; set; }

	public DataColumn pathElementNumberCol { get; set; }

	public DataColumn variableCol { get; set; }

	public DataColumn objectCol { get; set; }

	public DataColumn literalCol { get; set; }

	private DataView SortedByConverter
	{
		get
		{
			if (_sortedByConverter == null)
			{
				_sortedByConverter = new DataView(base.Table);
				_sortedByConverter.Sort = connectedConverterCol.ColumnName;
			}
			return _sortedByConverter;
		}
	}

	public ConnectedConverterArgs(MapDataSet ds)
		: base(ds, "Cvt")
	{
		base.Table = new DataTable(base.DsTableName = TableName());
		guidCol = new DataColumn("Guid", typeof(Guid));
		base.Table.Columns.Add(guidCol);
		connectedConverterCol = new DataColumn("ConnectedConverter", typeof(Guid));
		base.Table.Columns.Add(connectedConverterCol);
		isLeftArgCol = new DataColumn("IsLeftArg", typeof(bool));
		base.Table.Columns.Add(isLeftArgCol);
		converterArg = new DataColumn("Argument", typeof(Guid));
		base.Table.Columns.Add(converterArg);
		pathElementNumberCol = new DataColumn("PathElementNumber", typeof(int));
		base.Table.Columns.Add(pathElementNumberCol);
		variableCol = new DataColumn("Variable", typeof(Guid));
		base.Table.Columns.Add(variableCol);
		objectCol = new DataColumn("Object", typeof(Guid));
		base.Table.Columns.Add(objectCol);
		literalCol = new DataColumn("Literal", typeof(string));
		base.Table.Columns.Add(literalCol);
		base.Table.PrimaryKey = new DataColumn[1] { guidCol };
		ds.Set.Tables.Add(base.Table);
		ds.CreateRelation(ConnectedConverters.TableName(), TableName(), "ConnectedConverter");
	}

	public override void Remove()
	{
		base.DS.RemoveRelation(ConnectedConverters.TableName(), TableName(), "ConnectedConverter");
		base.Remove();
	}

	public static string TableName()
	{
		return "ConnectedConverterArgs";
	}

	public DataRowView[] ArgsForConnectedConverter(Guid connectedConverter)
	{
		DataRowView[] array = null;
		if (IsCaching)
		{
			return SortedByConverter.FindRows(connectedConverter);
		}
		IEnumerable<DataRowView> source = from DataRowView rv in new DataView(base.Table)
			where rv.Row.Field<Guid>(connectedConverterCol).Equals(connectedConverter)
			select rv;
		if (source.Any())
		{
			return source.ToArray();
		}
		return new DataRowView[0];
	}

	public override void ClearSortCache()
	{
		_sortedByConverter = null;
		base.ClearSortCache();
	}

	internal void CopyConArgsToChild(Guid guid, string leftPrefix, Guid leftObject, string RightPrefix, Guid rightObject)
	{
		DataRowView[] array = ArgsForConnectedConverter(guid);
		for (int i = 0; i < array.Length; i++)
		{
			DataRow row = array[i].Row;
			bool flag = row.Field<bool>(isLeftArgCol);
			Variables variables = base.DS.VariableTable(flag ? leftPrefix : RightPrefix);
			if (!row.IsNull(variableCol) && !row.Field<Guid>(variableCol).Equals(Guid.Empty))
			{
				variables.CopyVariableToChild(row.Field<Guid>(variableCol), flag ? leftObject : rightObject);
			}
			CopyRowToChild(row);
		}
	}
}
public class ConnectedConverterIdResolution : BaseTable
{
	private DataView _sortedByConverter;

	public DataColumn guidCol { get; set; }

	public DataColumn connectedConverterCol { get; set; }

	public DataColumn leftCol { get; set; }

	public DataColumn argGuidCol { get; set; }

	public DataColumn idDimensionNumberCol { get; set; }

	public DataColumn sequenceNumberCol { get; set; }

	public DataColumn variableCol { get; set; }

	private DataView SortedByConverter
	{
		get
		{
			if (_sortedByConverter == null)
			{
				_sortedByConverter = new DataView(base.Table);
				_sortedByConverter.Sort = connectedConverterCol.ColumnName;
			}
			return _sortedByConverter;
		}
	}

	public ConnectedConverterIdResolution(MapDataSet ds)
		: base(ds, "Cvt")
	{
		base.Table = new DataTable(base.DsTableName = TableName());
		guidCol = new DataColumn("Guid", typeof(Guid));
		base.Table.Columns.Add(guidCol);
		connectedConverterCol = new DataColumn("ConnectedConverter", typeof(Guid));
		base.Table.Columns.Add(connectedConverterCol);
		leftCol = new DataColumn("IsLeftArg", typeof(bool));
		base.Table.Columns.Add(leftCol);
		argGuidCol = new DataColumn("ArgGuid", typeof(Guid));
		base.Table.Columns.Add(argGuidCol);
		idDimensionNumberCol = new DataColumn("IdDimensionNumber", typeof(int));
		base.Table.Columns.Add(idDimensionNumberCol);
		sequenceNumberCol = new DataColumn("SequenceNumber", typeof(int));
		base.Table.Columns.Add(sequenceNumberCol);
		base.Table.PrimaryKey = new DataColumn[1] { guidCol };
		ds.Set.Tables.Add(base.Table);
		ds.CreateRelation(ConnectedConverters.TableName(), TableName(), "ConnectedConverter");
	}

	public override void Remove()
	{
		base.DS.RemoveRelation(ConnectedConverters.TableName(), TableName(), "ConnectedConverter");
		base.Remove();
	}

	public static string TableName()
	{
		return "ConnectedConverterIdResolution";
	}

	public DataRowView[] ResolutionForConnectedConverter(Guid connectedConverter)
	{
		DataRowView[] array = null;
		if (IsCaching)
		{
			return SortedByConverter.FindRows(connectedConverter);
		}
		new DataView(base.Table);
		EnumerableRowCollection<DataRowView> source = from DataRowView rv in base.Table.AsEnumerable()
			where rv.Row.Field<Guid>(connectedConverterCol).Equals(connectedConverter)
			select rv;
		if (source.Any())
		{
			return source.ToArray();
		}
		return new DataRowView[0];
	}

	public override void ClearSortCache()
	{
		_sortedByConverter = null;
		base.ClearSortCache();
	}

	internal void CopyResToChild(Guid connectedConverterGuid)
	{
		DataRowView[] array = ResolutionForConnectedConverter(connectedConverterGuid);
		foreach (DataRowView dataRowView in array)
		{
			CopyRowToChild(dataRowView.Row);
		}
	}
}
public class ConnectedConverters : BaseTable
{
	private class MyArg
	{
		public int argno;

		public int elemno;

		public string name;
	}

	public class DataRowComparer : IComparer<DataRow>
	{
		public int Compare(DataRow x, DataRow y)
		{
			Guid guid = x.Field<Guid>(0);
			Guid value = y.Field<Guid>(0);
			return guid.CompareTo(value);
		}
	}

	protected DataRelation _converterRelation;

	private DataView _sortedConverters;

	private static DataRowComparer drCompare = new DataRowComparer();

	public DataColumn guidCol { get; set; }

	public DataColumn converterCol { get; set; }

	public DataColumn leftPrefixCol { get; set; }

	public DataColumn leftObjectCol { get; set; }

	public DataColumn rightPrefixCol { get; set; }

	public DataColumn rightObjectCol { get; set; }

	public DataView SortedConverters
	{
		get
		{
			if (_sortedConverters == null)
			{
				_sortedConverters = new DataView(base.Table);
				_sortedConverters.Sort = "LeftPrefix,RightPrefix,LeftObject,RightObject";
			}
			return _sortedConverters;
		}
	}

	public ConnectedConverters(MapDataSet ds)
		: base(ds, "Cvt")
	{
		base.Table = new DataTable(base.DsTableName = TableName());
		guidCol = new DataColumn("Guid", typeof(Guid));
		base.Table.Columns.Add(guidCol);
		converterCol = new DataColumn("Converter", typeof(Guid));
		base.Table.Columns.Add(converterCol);
		leftPrefixCol = new DataColumn("LeftPrefix", typeof(string));
		base.Table.Columns.Add(leftPrefixCol);
		leftObjectCol = new DataColumn("LeftObject", typeof(Guid));
		base.Table.Columns.Add(leftObjectCol);
		rightPrefixCol = new DataColumn("RightPrefix", typeof(string));
		base.Table.Columns.Add(rightPrefixCol);
		rightObjectCol = new DataColumn("RightObject", typeof(Guid));
		base.Table.Columns.Add(rightObjectCol);
		base.Table.PrimaryKey = new DataColumn[1] { guidCol };
		ds.Set.Tables.Add(base.Table);
		_converterRelation = ds.CreateRelation(Converters.TableName(), TableName(), "Converter");
	}

	public override void Remove()
	{
		base.DS.RemoveRelation(Converters.TableName(), TableName(), "Converter");
		base.Remove();
	}

	public static string TableName()
	{
		return "ConnectedConverters";
	}

	public override void ClearSortCache()
	{
		_sortedConverters = null;
		base.ClearSortCache();
	}

	public void CopyConverterToChild(DataRow row)
	{
		Converters convertersTable = base.DS.ConvertersTable;
		DataRow row2 = convertersTable.Table.Rows.Find(row.Field<Guid>(converterCol));
		convertersTable.CopyRowToChild(row2);
	}

	public void CopyObject(string prefix, Guid obj)
	{
		base.DS.ObjectTable(prefix).CopyObjectToChild(obj);
	}

	public void CopyConnectedConvertersToChild()
	{
		foreach (DataRow row in base.Table.Rows)
		{
			CopyConnectedConverterToChild(row);
		}
	}

	public void CopyConnectedConverterToChild(DataRow row)
	{
		CopyConverterToChild(row);
		CopyRowToChild(row);
		Guid guid = row.Field<Guid>(guidCol);
		Guid guid2 = row.Field<Guid>(leftObjectCol);
		string text = row.Field<string>(leftPrefixCol);
		CopyObject(text, guid2);
		Guid guid3 = row.Field<Guid>(rightObjectCol);
		string text2 = row.Field<string>(rightPrefixCol);
		CopyObject(text2, guid3);
		base.DS.ConnectedConverterArgsTable.CopyConArgsToChild(guid, text, guid2, text2, guid3);
		base.DS.ConnectedConverterIdResolutionTable.CopyResToChild(guid);
	}

	private void AppendVariableName(string argname, ref string outstring)
	{
		if (!outstring.EndsWith("("))
		{
			outstring += ", ";
		}
		outstring += argname;
	}

	private void MessageForDeletedConnectedConverter(DataRow connectedConverterRow, DataRowView[] args, MapDataSet oldDs, MapDataSet newDs, string missingObject, string missingVariable)
	{
		string text = connectedConverterRow.Field<string>(leftPrefixCol);
		string text2 = connectedConverterRow.Field<string>(rightPrefixCol);
		string text3 = oldDs.ObjectTable(text).Table.Rows.Find(connectedConverterRow.Field<Guid>(leftObjectCol)).Field<string>("Name");
		string text4 = oldDs.ObjectTable(text2).Table.Rows.Find(connectedConverterRow.Field<Guid>(rightObjectCol)).Field<string>("Name");
		string outstring = text + ":" + text3 + "(";
		string outstring2 = text2 + ":" + text4 + "(";
		ConverterArgs converterArgsTable = oldDs.ConverterArgsTable;
		Guid converter = connectedConverterRow.Field<Guid>("Converter");
		converterArgsTable.ArgsForConverter(converter);
		List<MyArg> list = new List<MyArg>();
		List<MyArg> list2 = new List<MyArg>();
		foreach (DataRowView dataRowView in args)
		{
			DataRow row = converterArgsTable.Table.Rows.Find(dataRowView.Row.Field<Guid>("Argument"));
			string text5 = null;
			List<MyArg> list3;
			if (dataRowView.Row.Field<bool>("IsLeftArg"))
			{
				text5 = text;
				list3 = list;
			}
			else
			{
				text5 = text2;
				list3 = list2;
			}
			string text6 = null;
			text6 = (dataRowView.Row.IsNull("Literal") ? oldDs.VariableTable(text5).Table.Rows.Find(dataRowView.Row.Field<Guid>("Variable")).Field<string>("Name") : dataRowView.Row.Field<string>("Literal"));
			if (text6 != null)
			{
				int elemno = dataRowView.Row.Field<int>("PathElementNumber");
				list3.Add(new MyArg
				{
					argno = row.Field<int>("ArgNumber"),
					elemno = elemno,
					name = text6
				});
			}
		}
		foreach (MyArg item in list.OrderBy((MyArg x) => x.argno * 10 + x.elemno))
		{
			AppendVariableName(item.name, ref outstring);
		}
		foreach (MyArg item2 in list2.OrderBy((MyArg x) => x.argno * 10 + x.elemno))
		{
			AppendVariableName(item2.name, ref outstring2);
		}
		outstring += ")";
		outstring2 += ")";
		string text7 = "  Connection between\n        " + outstring + "\n    and " + outstring2 + "\n    deleted because ";
		text7 = ((missingVariable != null) ? (text7 + "variable " + missingVariable + " no longer exists in object: " + missingObject + "\n") : (text7 + "object: " + missingObject + " no longer exists\n"));
		newDs.Undos.Log.LogMessage(text7);
	}

	private void AddToDoomedConverters(List<DataRow> doomedConverters, List<Guid> doomedArgGuids, DataRow connectedConverter, DataRowView[] ccvArgs)
	{
		int num = doomedConverters.BinarySearch(connectedConverter, drCompare);
		if (num >= 0)
		{
			return;
		}
		doomedConverters.Insert(~num, connectedConverter);
		for (int i = 0; i < ccvArgs.Length; i++)
		{
			Guid item = ccvArgs[i].Row.Field<Guid>("Guid");
			int num2 = doomedArgGuids.BinarySearch(item);
			if (num2 < 0)
			{
				doomedArgGuids.Insert(~num2, item);
			}
		}
	}

	private void CheckObject(string modifiedPrefix, DataRow row, MapDataSet oldDs, string side, List<DataRow> doomedConnectedConverters, List<Guid> doomedArgGuids)
	{
		string text = side + "Object";
		string text2 = row.Field<string>(side + "Prefix");
		if (text2.Equals(modifiedPrefix))
		{
			Guid guid = row.Field<Guid>(text);
			Guid? guid2 = base.Dm.Ds.ObjectTable(text2).FindObjectWithGuid(oldDs.ObjectTable(text2), guid);
			DataRowView[] array = base.Dm.Ds.ConnectedConverterArgsTable.ArgsForConnectedConverter(row.Field<Guid>("Guid"));
			if (!guid2.HasValue)
			{
				string text3 = oldDs.ObjectTable(text2).Table.Rows.Find(row.Field<Guid>(text)).Field<string>("Name");
				MessageForDeletedConnectedConverter(row, array, oldDs, base.Dm.Ds, text2 + ":" + text3, null);
				AddToDoomedConverters(doomedConnectedConverters, doomedArgGuids, row, array);
			}
			else if (!guid2.Value.Equals(guid))
			{
				DMSetValue(row, text, guid2.Value);
			}
		}
	}

	private void CheckLeftOrRightArg(string modifiedPrefix, DataRow argRow, DataRow ccnvRow, string side, MapDataSet oldDs, List<DataRow> doomedConnectedConverters, List<Guid> doomedArgGuids)
	{
		string text = ccnvRow.Field<string>(side + "Prefix");
		if (!text.Equals(modifiedPrefix))
		{
			return;
		}
		Variables variables = base.Dm.Ds.VariableTable(text);
		Guid guid = ccnvRow.Field<Guid>(side + "Object");
		if (argRow.IsNull("Variable"))
		{
			return;
		}
		Guid guid2 = argRow.Field<Guid>("Variable");
		if (!guid2.Equals(Guid.Empty))
		{
			if (!variables.FindVariableWithGuid(oldDs.VariableTable(text), guid2, oldDs.ObjectTable(text), guid, out var newGuid, out var _))
			{
				string missingVariable = oldDs.VariableTable(text).Table.Rows.Find(guid2).Field<string>("Name");
				string text2 = base.Dm.Ds.ObjectTable(text).Table.Rows.Find(guid).Field<string>("Name");
				DataRowView[] array = base.Dm.Ds.ConnectedConverterArgsTable.ArgsForConnectedConverter(ccnvRow.Field<Guid>(guidCol));
				MessageForDeletedConnectedConverter(ccnvRow, array, oldDs, base.Dm.Ds, text + ":" + text2, missingVariable);
				AddToDoomedConverters(doomedConnectedConverters, doomedArgGuids, ccnvRow, array);
			}
			else if (!newGuid.Value.Equals(guid2))
			{
				base.Dm.Ds.ConnectedConverterArgsTable.DMSetValue(argRow, "Variable", newGuid.Value);
			}
		}
	}

	private void CheckArgument(string modifiedPrefix, DataRow argRow, MapDataSet oldDs, List<DataRow> doomedConnectedConverters, List<Guid> doomedArgGuids)
	{
		Guid item = argRow.Field<Guid>("Guid");
		if (doomedArgGuids.BinarySearch(item) < 0)
		{
			DataRow ccnvRow = base.Table.Rows.Find(argRow.Field<Guid>("ConnectedConverter"));
			if (argRow.Field<bool>("IsLeftArg"))
			{
				CheckLeftOrRightArg(modifiedPrefix, argRow, ccnvRow, "Left", oldDs, doomedConnectedConverters, doomedArgGuids);
			}
			else
			{
				CheckLeftOrRightArg(modifiedPrefix, argRow, ccnvRow, "Right", oldDs, doomedConnectedConverters, doomedArgGuids);
			}
		}
	}

	public void CheckConnectedConvertersAfterUpdate(MapDataSet oldDs, string modifiedPrefix)
	{
		List<DataRow> list = new List<DataRow>();
		List<Guid> list2 = new List<Guid>();
		List<DataRow> list3 = new List<DataRow>();
		ConnectedConverterArgs connectedConverterArgsTable = base.Dm.Ds.ConnectedConverterArgsTable;
		ConnectedConverterIdResolution connectedConverterIdResolutionTable = base.Dm.Ds.ConnectedConverterIdResolutionTable;
		foreach (DataRow row in base.Table.Rows)
		{
			CheckObject(modifiedPrefix, row, oldDs, "Left", list, list2);
			CheckObject(modifiedPrefix, row, oldDs, "Right", list, list2);
		}
		foreach (DataRow row2 in connectedConverterArgsTable.Table.Rows)
		{
			CheckArgument(modifiedPrefix, row2, oldDs, list, list2);
		}
		foreach (DataRow row3 in connectedConverterIdResolutionTable.Table.Rows)
		{
			DataRow item = base.Table.Rows.Find(row3.Field<Guid>("ConnectedConverter"));
			if (list.BinarySearch(item, drCompare) >= 0)
			{
				list3.Add(row3);
			}
		}
		foreach (DataRow item2 in list3)
		{
			connectedConverterIdResolutionTable.DMRemoveRow(item2);
		}
		foreach (Guid item3 in list2)
		{
			connectedConverterArgsTable.DMRemoveRow(connectedConverterArgsTable.Table.Rows.Find(item3));
		}
		foreach (DataRow item4 in list)
		{
			DMRemoveRow(item4);
		}
	}
}
public class ArgumentPathElement
{
	public Guid DataBaseGuid { get; set; }

	public Guid PathGuid { get; set; }

	public Guid PathObjGuid { get; set; }

	public int PathElementNumber { get; set; }
}
public class ConnectedArgument
{
	protected Variables _varTab;

	protected Objects _objTab;

	protected Guid _topObj;

	protected MapDataSet _ds;

	protected int _dimension;

	protected bool _isLiteral;

	protected string _literal;

	public static char PathDelimeter = '\u0005';

	public static char[] PathSplit = new char[1] { PathDelimeter };

	public ObservableCollection<IdResolution> IdRes { get; set; }

	public ObservableCollection<ArgumentPathElement> Path { get; set; }

	public Guid ConverterArgGuid { get; set; }

	public int Dimension => _dimension;

	public string Literal
	{
		get
		{
			return _literal;
		}
		set
		{
			_literal = value;
		}
	}

	public bool IsLiteral
	{
		get
		{
			return _isLiteral;
		}
		set
		{
			_isLiteral = value;
		}
	}

	public string ArgumentName
	{
		get
		{
			string result = null;
			ConverterArgs converterArgsTable = _ds.ConverterArgsTable;
			DataRow dataRow = converterArgsTable.Table.Rows.Find(ConverterArgGuid);
			if (dataRow != null && !dataRow.IsNull(converterArgsTable.nameCol))
			{
				result = dataRow.Field<string>(converterArgsTable.nameCol);
			}
			return result;
		}
	}

	public string PathString
	{
		get
		{
			string text = "";
			foreach (ArgumentPathElement item in Path)
			{
				if (item == null || item.PathGuid.Equals(Guid.Empty))
				{
					break;
				}
				if (!text.Equals(""))
				{
					text += ".";
				}
				DataRow row = _varTab.Table.Rows.Find(item.PathGuid);
				text += row.Field<string>(_varTab.nameCol);
				int num = row.Field<int>(_varTab.numIdsCol);
				for (int i = 0; i < num; i++)
				{
					text += "[";
					text += "]";
				}
			}
			return text;
		}
	}

	public ConnectedArgument(MapDataSet ds, Variables varTab, int dimension, Objects objTab, Guid topObj, Guid converterArgGuid, bool isLiteral)
	{
		_ds = ds;
		_dimension = dimension;
		IdRes = new ObservableCollection<IdResolution>();
		for (int i = 0; i < _dimension; i++)
		{
			IdRes.Add(new IdResolution(varTab.Dm.Ds, this, i, null));
			IdRes[i].Reset();
		}
		Path = new ObservableCollection<ArgumentPathElement>();
		_varTab = varTab;
		_objTab = objTab;
		_topObj = topObj;
		ConverterArgGuid = converterArgGuid;
		_literal = null;
		_isLiteral = isLiteral;
	}

	private string[] SplitCarefully(string prefix, string path)
	{
		string text;
		if (prefix.Equals("ApCxs"))
		{
			text = path.Replace("OUTPUT.", "OUTPUT~");
			text = text.Replace("INPUT.", "INPUT~");
		}
		else
		{
			text = path;
		}
		string[] array = text.Split(PathSplit, StringSplitOptions.RemoveEmptyEntries);
		if (prefix.Equals("ApCxs"))
		{
			for (int i = 0; i < array.Length; i++)
			{
				array[i] = array[i].Replace("OUTPUT~", "OUTPUT.");
				array[i] = array[i].Replace("INPUT~", "INPUT.");
			}
		}
		for (int j = 0; j < array.Length; j++)
		{
			int num = array[j].IndexOf("[]");
			if (num >= 0)
			{
				array[j] = array[j].Substring(0, num);
			}
		}
		return array;
	}

	public string CanAttach(VariableToLink variable)
	{
		string result = null;
		Variables variables = _ds.VariableTable(variable.Prefix);
		_ds.ObjectTable(variable.Prefix);
		Guid objGuid = variable.ObjGuid;
		if (_dimension == -1)
		{
			result = "Cannot attach to literal";
		}
		else
		{
			string[] array = SplitCarefully(variable.Prefix, variable.NamePath);
			Guid? guid = objGuid;
			int num = 0;
			string[] array2 = array;
			foreach (string variableName in array2)
			{
				if (!guid.HasValue)
				{
					result = "Bad Path";
					break;
				}
				Guid actualGuid;
				DataRow dataRow = variables.FindVariableInherited(guid.Value, variableName, out actualGuid);
				dataRow.Field<Guid>("Guid");
				int num2 = dataRow.Field<int>(variables.numIdsCol);
				if (num + num2 > _dimension)
				{
					result = "Wrong number of dimensions";
					break;
				}
				Guid? guid2 = null;
				if (!dataRow.IsNull(variables.refCol))
				{
					guid2 = dataRow.Field<Guid>(variables.refCol);
				}
				num += num2;
				guid = guid2;
			}
			if (num != _dimension)
			{
				result = "Wrong number of dimensions (Variable has " + num + ", converter requires " + _dimension;
			}
		}
		return result;
	}

	public string Attach(VariableToLink variable)
	{
		string result = null;
		_varTab = _ds.VariableTable(variable.Prefix);
		_objTab = _ds.ObjectTable(variable.Prefix);
		_topObj = variable.ObjGuid;
		string[] array = SplitCarefully(variable.Prefix, variable.NamePath);
		Guid? guid = _topObj;
		int num = 0;
		string[] array2 = array;
		foreach (string variableName in array2)
		{
			if (!guid.HasValue)
			{
				result = "Bad Path";
				break;
			}
			Guid actualGuid;
			DataRow dataRow = _varTab.FindVariableInherited(guid.Value, variableName, out actualGuid);
			Guid pathGuid = dataRow.Field<Guid>("Guid");
			int num2 = dataRow.Field<int>(_varTab.numIdsCol);
			if (num + num2 > _dimension)
			{
				result = "Wrong number of dimensions";
				break;
			}
			Guid? guid2 = null;
			if (!dataRow.IsNull(_varTab.refCol))
			{
				guid2 = dataRow.Field<Guid>(_varTab.refCol);
			}
			for (int j = 0; j < num2; j++)
			{
				IdRes[num].PresentedSequence = num;
				num++;
			}
			Path.Add(new ArgumentPathElement
			{
				PathGuid = pathGuid,
				PathObjGuid = actualGuid,
				PathElementNumber = Path.Count,
				DataBaseGuid = Guid.NewGuid()
			});
			guid = guid2;
		}
		if (num != _dimension)
		{
			result = "Wrong number of dimensions (Variable has " + num + ", converter requires " + _dimension;
		}
		return result;
	}

	private string CreateNamePath()
	{
		string text = "";
		foreach (ArgumentPathElement item in Path)
		{
			if (!text.Equals(""))
			{
				text += PathDelimeter;
			}
			DataRow dataRow = _varTab.Table.Rows.Find(item.PathGuid);
			if (dataRow == null)
			{
				text = "";
				break;
			}
			text += dataRow.Field<string>(_varTab.nameCol);
			int num = dataRow.Field<int>(_varTab.numIdsCol);
			for (int i = 0; i < num; i++)
			{
				text += "[]";
			}
		}
		return text;
	}

	public VariableToLink LinkedVariable()
	{
		return new VariableToLink
		{
			Prefix = _varTab.Prefix,
			ObjGuid = _topObj,
			NamePath = CreateNamePath()
		};
	}

	public void Clear()
	{
		for (int i = 0; i < IdRes.Count; i++)
		{
			IdRes[i].Reset();
		}
		Path.Clear();
	}

	public void AddPathElement(Guid argPathElementGuid, Guid pathGuid, Guid pathObjectGuid, int elementNumber)
	{
		int num = 0;
		_ = Path.Count;
		foreach (ArgumentPathElement item2 in Path)
		{
			if (elementNumber < item2.PathElementNumber)
			{
				break;
			}
			num++;
		}
		ArgumentPathElement item = new ArgumentPathElement
		{
			DataBaseGuid = argPathElementGuid,
			PathElementNumber = elementNumber,
			PathGuid = pathGuid,
			PathObjGuid = pathObjectGuid
		};
		Path.Insert(num, item);
	}

	public Guid? FindPathElementContainer(int sequence)
	{
		return null;
	}

	public void MoveIdrItem(int fromVal, int toVal)
	{
		int num = -1;
		int num2 = -1;
		for (int i = 0; i < IdRes.Count; i++)
		{
			if (IdRes[i].PresentedSequence == fromVal)
			{
				num = i;
			}
			if (IdRes[i].PresentedSequence == toVal)
			{
				num2 = i;
			}
		}
		IdResolution[] array = new IdResolution[IdRes.Count];
		int num3 = Math.Min(num, num2);
		int num4 = Math.Max(num, num2);
		for (int j = 0; j < IdRes.Count; j++)
		{
			if (j < num3 || j > num4)
			{
				array[j] = IdRes[j];
			}
			else if (num2 > num)
			{
				if (j == num2)
				{
					array[j] = IdRes[num];
				}
				else
				{
					array[j] = IdRes[j + 1];
				}
			}
			else if (j == num2)
			{
				array[j] = IdRes[num];
			}
			else
			{
				array[j] = IdRes[j - 1];
			}
		}
		IdRes.Clear();
		IdResolution[] array2 = array;
		foreach (IdResolution item in array2)
		{
			IdRes.Add(item);
		}
	}

	public string ValidateErrors()
	{
		string text = null;
		if (_isLiteral)
		{
			if (string.IsNullOrWhiteSpace(Literal))
			{
				text = "Literal value not filled in";
			}
		}
		else
		{
			if (!Path.Any())
			{
				text = "Not all arguments are filled in";
			}
			if (text == null)
			{
				foreach (IdResolution idRe in IdRes)
				{
					text = idRe.ValidateErrors();
					if (text != null)
					{
						break;
					}
				}
			}
		}
		return text;
	}

	public void Save(ConnectedConverterArgs carg, ConnectedConverterIdResolution cidr, Guid converterGuid, int argno, bool isLeft, List<Guid> originalArgs, List<Guid> originalRes)
	{
		if (IsLiteral && Path.Count == 0)
		{
			Guid guid = Guid.NewGuid();
			carg.DMAddRow(new object[12]
			{
				"Guid",
				guid,
				carg.connectedConverterCol.ColumnName,
				converterGuid,
				carg.isLeftArgCol.ColumnName,
				isLeft,
				carg.converterArg.ColumnName,
				ConverterArgGuid,
				carg.pathElementNumberCol.ColumnName,
				0,
				carg.literalCol.ColumnName,
				Literal
			});
			AddPathElement(guid, Guid.Empty, Guid.Empty, 0);
			return;
		}
		foreach (ArgumentPathElement item in Path)
		{
			DataRow dataRow = null;
			if (!item.DataBaseGuid.Equals(Guid.Empty))
			{
				dataRow = carg.Table.Rows.Find(item.DataBaseGuid);
			}
			else
			{
				item.DataBaseGuid = Guid.NewGuid();
			}
			if (dataRow == null)
			{
				dataRow = carg.DMAddRow(new object[2] { "Guid", item.DataBaseGuid });
			}
			else if (originalArgs.Contains(item.DataBaseGuid))
			{
				originalArgs.Remove(item.DataBaseGuid);
			}
			carg.DMSetValues(dataRow, new object[14]
			{
				carg.connectedConverterCol.ColumnName,
				converterGuid,
				carg.isLeftArgCol.ColumnName,
				isLeft,
				carg.converterArg.ColumnName,
				ConverterArgGuid,
				carg.pathElementNumberCol.ColumnName,
				item.PathElementNumber,
				carg.variableCol.ColumnName,
				item.PathGuid,
				carg.objectCol.ColumnName,
				item.PathObjGuid,
				carg.literalCol.ColumnName,
				Literal
			});
		}
		for (int i = 0; i < IdRes.Count; i++)
		{
			IdRes[i].Save(cidr, converterGuid, ConverterArgGuid, i, isLeft, originalRes);
		}
	}
}
public class IdResolution
{
	protected MapDataSet _ds;

	protected Guid _guid;

	protected ConnectedArgument _parent;

	private int _dataSequence;

	public int PresentedSequence { get; set; }

	public IdResolution(MapDataSet ds, ConnectedArgument parent, int dataSequence, Guid? guid)
	{
		_ds = ds;
		_parent = parent;
		_dataSequence = dataSequence;
		PresentedSequence = _dataSequence;
		if (guid.HasValue)
		{
			_guid = guid.Value;
		}
		else
		{
			_guid = Guid.NewGuid();
		}
	}

	public void Reset()
	{
		_guid = Guid.NewGuid();
		PresentedSequence = _dataSequence;
	}

	public string ValidateErrors()
	{
		return null;
	}

	public void Save(ConnectedConverterIdResolution cidr, Guid converterGuid, Guid converterArgGuid, int idno, bool isLeft, List<Guid> originialRes)
	{
		DataRow dataRow = cidr.Table.Rows.Find(_guid);
		if (dataRow == null)
		{
			dataRow = cidr.DMAddRow(new object[2] { "Guid", _guid });
		}
		else if (originialRes.Contains(_guid))
		{
			originialRes.Remove(_guid);
		}
		cidr.DMSetValues(dataRow, new object[10]
		{
			cidr.connectedConverterCol.ColumnName,
			converterGuid,
			cidr.leftCol.ColumnName,
			isLeft,
			cidr.argGuidCol.ColumnName,
			converterArgGuid,
			cidr.idDimensionNumberCol.ColumnName,
			idno,
			cidr.sequenceNumberCol.ColumnName,
			PresentedSequence
		});
	}
}
public class ConnectedConverterVM : INotifyPropertyChanged
{
	public Guid LeftObject;

	public Guid RightObject;

	protected List<Guid> _originalArgGuids = new List<Guid>();

	protected List<Guid> _originalResolutionGuids = new List<Guid>();

	public Guid Guid { get; set; }

	public ConverterVM Converter { get; set; }

	public Guid ConverterGuid { get; set; }

	public string LeftPrefix { get; set; }

	public string RightPrefix { get; set; }

	public ConverterListVM ConverterList { get; set; }

	public ImplementedConverterWrapper ImpConverter { get; set; }

	public string LeftObjectName
	{
		get
		{
			string result = null;
			if (LeftPrefix != null && !LeftObject.Equals(Guid.Empty))
			{
				Objects objects = DS.ObjectTable(LeftPrefix);
				result = objects.Table.Rows.Find(LeftObject).Field<string>(objects.nameCol);
			}
			return result;
		}
	}

	public string RightObjectName
	{
		get
		{
			string result = null;
			if (RightPrefix != null && !RightObject.Equals(Guid.Empty))
			{
				Objects objects = DS.ObjectTable(RightPrefix);
				result = objects.Table.Rows.Find(RightObject).Field<string>(objects.nameCol);
			}
			return result;
		}
	}

	public ObservableCollection<ConnectedArgument> LeftArgs { get; set; }

	public ObservableCollection<ConnectedArgument> RightArgs { get; set; }

	public MapDataSet DS { get; set; }

	public event PropertyChangedEventHandler PropertyChanged;

	public string Initialize(MapDataSet ds, Guid converterGuid, VariableToLink leftVariable, VariableToLink rightVariable)
	{
		string text = null;
		DS = ds;
		_ = DS.ConvertersTable;
		ConverterGuid = converterGuid;
		Converter = new ConverterVM(DS, ConverterGuid);
		LeftPrefix = leftVariable.Prefix;
		LeftObject = leftVariable.ObjGuid;
		RightPrefix = rightVariable.Prefix;
		RightObject = rightVariable.ObjGuid;
		CreateConnectedArguments();
		text = AttachVariable(isLeft: true, leftVariable, 0);
		if (text == null)
		{
			text = AttachVariable(isLeft: false, rightVariable, 0);
		}
		ConverterList = new ConverterListVM(DS, LeftArgs.Any() ? new int?(LeftArgs[0].Dimension) : ((int?)null), RightArgs.Any() ? new int?(RightArgs[0].Dimension) : ((int?)null));
		return text;
	}

	public void RefreshArgs()
	{
		ObservableCollection<ConnectedArgument> observableCollection = new ObservableCollection<ConnectedArgument>(LeftArgs);
		ObservableCollection<ConnectedArgument> observableCollection2 = new ObservableCollection<ConnectedArgument>(RightArgs);
		LeftArgs.Clear();
		RightArgs.Clear();
		foreach (ConnectedArgument item in observableCollection)
		{
			LeftArgs.Add(item);
		}
		foreach (ConnectedArgument item2 in observableCollection2)
		{
			RightArgs.Add(item2);
		}
	}

	protected string MatchArgs(ObservableCollection<ConnectedArgument> conArgs, DataTable args, Variables vars, Objects objs)
	{
		string text = null;
		List<ConnectedArgument> list = new List<ConnectedArgument>();
		for (int i = 0; i < conArgs.Count; i++)
		{
			if (i < args.Rows.Count)
			{
				if (conArgs[i].Dimension != args.Rows[i].Field<int>("Dimensions"))
				{
					text = "Dimensions do not match for Left Arg #" + i;
					break;
				}
				conArgs[i].ConverterArgGuid = args.Rows[i].Field<Guid>("Guid");
			}
			else
			{
				list.Add(conArgs[i]);
			}
		}
		if (text == null)
		{
			foreach (ConnectedArgument item in list)
			{
				conArgs.Remove(item);
			}
			for (int j = conArgs.Count; j < args.Rows.Count; j++)
			{
				conArgs.Add(new ConnectedArgument(DS, vars, args.Rows[j].Field<int>("Dimensions"), objs, LeftObject, args.Rows[j].Field<Guid>("Guid"), args.Rows[j].Field<bool>("IsLiteral")));
			}
		}
		return text;
	}

	public string ChangeConverterGuid(Guid newConverter)
	{
		string text = null;
		ObservableCollection<ConnectedArgument> leftArgs = LeftArgs;
		ObservableCollection<ConnectedArgument> rightArgs = RightArgs;
		ConverterVM converterVM = new ConverterVM(DS, newConverter);
		Variables vars = DS.VariableTable(LeftPrefix);
		Variables vars2 = DS.VariableTable(RightPrefix);
		Objects objs = DS.ObjectTable(LeftPrefix);
		Objects objs2 = DS.ObjectTable(RightPrefix);
		text = MatchArgs(LeftArgs, converterVM.LeftArgs, vars, objs);
		if (text == null)
		{
			text = MatchArgs(RightArgs, converterVM.RightArgs, vars2, objs2);
		}
		if (text != null)
		{
			LeftArgs = leftArgs;
			RightArgs = rightArgs;
		}
		else
		{
			ConverterGuid = newConverter;
			Converter = new ConverterVM(DS, ConverterGuid);
		}
		RefreshArgs();
		return text;
	}

	public void MoveIdrItem(bool isLeft, int argIndex, int fromVal, int toVal)
	{
		(isLeft ? LeftArgs[argIndex] : RightArgs[argIndex]).MoveIdrItem(fromVal, toVal);
	}

	public string AttachVariable(bool isLeft, VariableToLink variable, int argNumber)
	{
		string text = null;
		string text2;
		Guid guid;
		ObservableCollection<ConnectedArgument> observableCollection;
		ConnectedArgument connectedArgument;
		if (isLeft)
		{
			text2 = LeftPrefix;
			guid = LeftObject;
			observableCollection = LeftArgs;
			connectedArgument = LeftArgs[argNumber];
		}
		else
		{
			text2 = RightPrefix;
			guid = RightObject;
			observableCollection = RightArgs;
			connectedArgument = RightArgs[argNumber];
		}
		if (text2 != null && text2 != variable.Prefix)
		{
			text = "All arguments must come from same data model";
		}
		else if (!guid.Equals(Guid.Empty) && !guid.Equals(variable.ObjGuid))
		{
			text = "All arguments must come from same object";
		}
		if (text == null)
		{
			text = connectedArgument.CanAttach(variable);
		}
		if (text == null)
		{
			if (isLeft)
			{
				LeftPrefix = variable.Prefix;
				LeftObject = variable.ObjGuid;
			}
			else
			{
				RightPrefix = variable.Prefix;
				RightObject = variable.ObjGuid;
			}
			connectedArgument.Clear();
			observableCollection.Remove(connectedArgument);
			observableCollection.Insert(argNumber, connectedArgument);
			connectedArgument.Attach(variable);
		}
		return text;
	}

	public ConnectedConverterVM(MapDataSet ds, Guid? guid)
	{
		DS = ds;
		if (guid.HasValue)
		{
			Guid = guid.Value;
			_ = DS.ConvertersTable;
			ConnectedConverters connectedConvertersTable = DS.ConnectedConvertersTable;
			ConnectedConverterArgs connectedConverterArgsTable = ds.ConnectedConverterArgsTable;
			ConnectedConverterIdResolution connectedConverterIdResolutionTable = ds.ConnectedConverterIdResolutionTable;
			DataRow dataRow = connectedConvertersTable.Table.Rows.Find(guid.Value);
			if (dataRow != null)
			{
				if (!dataRow.IsNull(connectedConvertersTable.converterCol))
				{
					ConverterGuid = dataRow.Field<Guid>(connectedConvertersTable.converterCol);
					Converter = new ConverterVM(DS, ConverterGuid);
				}
				if (!dataRow.IsNull(connectedConvertersTable.leftPrefixCol))
				{
					LeftPrefix = dataRow.Field<string>(connectedConvertersTable.leftPrefixCol);
				}
				if (!dataRow.IsNull(connectedConvertersTable.rightPrefixCol))
				{
					RightPrefix = dataRow.Field<string>(connectedConvertersTable.rightPrefixCol);
				}
				if (!dataRow.IsNull(connectedConvertersTable.leftObjectCol))
				{
					LeftObject = dataRow.Field<Guid>(connectedConvertersTable.leftObjectCol);
				}
				if (!dataRow.IsNull(connectedConvertersTable.rightObjectCol))
				{
					RightObject = dataRow.Field<Guid>(connectedConvertersTable.rightObjectCol);
				}
				CreateConnectedArguments();
				DataRowView[] array = connectedConverterArgsTable.ArgsForConnectedConverter(Guid);
				DataRowView[] array2 = connectedConverterIdResolutionTable.ResolutionForConnectedConverter(Guid);
				DataRowView[] array3 = array;
				foreach (DataRowView dataRowView in array3)
				{
					bool num = dataRowView.Row.Field<bool>(connectedConverterArgsTable.isLeftArgCol);
					Guid guid2 = dataRowView.Row.Field<Guid>("Guid");
					Guid apeArgumentGuid = dataRowView.Row.Field<Guid>(connectedConverterArgsTable.converterArg);
					ObservableCollection<ConnectedArgument> source = RightArgs;
					if (num)
					{
						source = LeftArgs;
					}
					ConnectedArgument connectedArgument = (from ConnectedArgument t in source
						where t.ConverterArgGuid.Equals(apeArgumentGuid)
						select t).Single();
					if (connectedArgument.IsLiteral)
					{
						if (!dataRowView.Row.IsNull("Literal"))
						{
							connectedArgument.Literal = dataRowView.Row.Field<string>("Literal");
						}
						else
						{
							connectedArgument.Literal = null;
						}
						connectedArgument.AddPathElement(guid2, Guid.Empty, Guid.Empty, 0);
					}
					else
					{
						Guid pathGuid = dataRowView.Row.Field<Guid>(connectedConverterArgsTable.variableCol);
						Guid pathObjectGuid = Guid.Empty;
						if (!dataRowView.Row.IsNull(connectedConverterArgsTable.objectCol))
						{
							pathObjectGuid = dataRowView.Row.Field<Guid>(connectedConverterArgsTable.objectCol);
						}
						int elementNumber = dataRowView.Row.Field<int>(connectedConverterArgsTable.pathElementNumberCol);
						connectedArgument.AddPathElement(guid2, pathGuid, pathObjectGuid, elementNumber);
					}
					_originalArgGuids.Add(guid2);
				}
				array3 = array2;
				foreach (DataRowView dataRowView2 in array3)
				{
					Guid guid3 = dataRowView2.Row.Field<Guid>("Guid");
					Guid resArgGuid = dataRowView2.Row.Field<Guid>(connectedConverterIdResolutionTable.argGuidCol);
					int num2 = dataRowView2.Row.Field<int>(connectedConverterIdResolutionTable.idDimensionNumberCol);
					ObservableCollection<ConnectedArgument> source2 = RightArgs;
					_ = RightPrefix;
					_ = Converter.NumRight;
					if (dataRowView2.Row.Field<bool>(connectedConverterIdResolutionTable.leftCol))
					{
						source2 = LeftArgs;
						_ = LeftPrefix;
						_ = Converter.NumLeft;
					}
					ConnectedArgument connectedArgument2 = (from ConnectedArgument t in source2
						where t.ConverterArgGuid.Equals(resArgGuid)
						select t).Single();
					IdResolution idResolution = new IdResolution(DS, connectedArgument2, num2, guid3);
					connectedArgument2.IdRes[num2] = idResolution;
					idResolution.PresentedSequence = dataRowView2.Row.Field<int>(connectedConverterIdResolutionTable.sequenceNumberCol);
					_originalResolutionGuids.Add(guid3);
				}
				ConverterList = new ConverterListVM(DS, LeftArgs.Any() ? new int?(LeftArgs[0].Dimension) : ((int?)null), RightArgs.Any() ? new int?(RightArgs[0].Dimension) : ((int?)null));
			}
		}
		else
		{
			Guid = Guid.NewGuid();
		}
		if (ConverterList == null)
		{
			ConverterList = new ConverterListVM(DS);
		}
	}

	private void CreateConnectedArguments()
	{
		Variables varTab = DS.VariableTable(LeftPrefix);
		Variables varTab2 = DS.VariableTable(RightPrefix);
		Objects objTab = DS.ObjectTable(LeftPrefix);
		Objects objTab2 = DS.ObjectTable(RightPrefix);
		LeftArgs = new ObservableCollection<ConnectedArgument>();
		RightArgs = new ObservableCollection<ConnectedArgument>();
		for (int i = 0; i < Converter.NumLeft; i++)
		{
			LeftArgs.Add(new ConnectedArgument(DS, varTab, Converter.LeftArgs.Rows[i].Field<int>("Dimensions"), objTab, LeftObject, Converter.LeftArgs.Rows[i].Field<Guid>("Guid"), Converter.LeftArgs.Rows[i].Field<bool>("IsLiteral")));
		}
		for (int j = 0; j < Converter.NumRight; j++)
		{
			RightArgs.Add(new ConnectedArgument(DS, varTab2, Converter.RightArgs.Rows[j].Field<int>("Dimensions"), objTab2, RightObject, Converter.RightArgs.Rows[j].Field<Guid>("Guid"), Converter.RightArgs.Rows[j].Field<bool>("IsLiteral")));
		}
	}

	public string ValidateErrors()
	{
		string text = null;
		foreach (ConnectedArgument leftArg in LeftArgs)
		{
			text = leftArg.ValidateErrors();
			if (text != null)
			{
				break;
			}
		}
		if (text == null)
		{
			foreach (ConnectedArgument rightArg in RightArgs)
			{
				text = rightArg.ValidateErrors();
				if (text != null)
				{
					break;
				}
			}
		}
		return text;
	}

	public void Delete()
	{
		DS.Undos.StartUndoable("Removing connection");
		DataRow dataRow = DS.ConnectedConvertersTable.Table.Rows.Find(Guid);
		if (dataRow != null)
		{
			RemoveDatabaseRows();
		}
		DS.ConnectedConvertersTable.DMRemoveRow(dataRow);
		DS.Undos.FinishUndoable();
	}

	public void Save()
	{
		DS.Undos.StartUndoable("Saving Connected Converter");
		ConnectedConverters connectedConvertersTable = DS.ConnectedConvertersTable;
		DataRow dataRow = connectedConvertersTable.Table.Rows.Find(Guid);
		if (dataRow == null)
		{
			dataRow = connectedConvertersTable.DMAddRow(new object[2] { "Guid", Guid });
		}
		connectedConvertersTable.DMSetValues(dataRow, new object[10]
		{
			connectedConvertersTable.converterCol.ColumnName,
			ConverterGuid,
			connectedConvertersTable.leftPrefixCol.ColumnName,
			LeftPrefix,
			connectedConvertersTable.rightPrefixCol.ColumnName,
			RightPrefix,
			connectedConvertersTable.leftObjectCol.ColumnName,
			LeftObject,
			connectedConvertersTable.rightObjectCol.ColumnName,
			RightObject
		});
		ConnectedConverterArgs connectedConverterArgsTable = DS.ConnectedConverterArgsTable;
		ConnectedConverterIdResolution connectedConverterIdResolutionTable = DS.ConnectedConverterIdResolutionTable;
		int num = 0;
		foreach (ConnectedArgument leftArg in LeftArgs)
		{
			leftArg.Save(connectedConverterArgsTable, connectedConverterIdResolutionTable, Guid, num++, isLeft: true, _originalArgGuids, _originalResolutionGuids);
		}
		num = 0;
		foreach (ConnectedArgument rightArg in RightArgs)
		{
			rightArg.Save(connectedConverterArgsTable, connectedConverterIdResolutionTable, Guid, num++, isLeft: false, _originalArgGuids, _originalResolutionGuids);
		}
		RemoveDatabaseRows();
		DS.Undos.FinishUndoable();
	}

	private void RemoveDatabaseRows()
	{
		ConnectedConverterArgs connectedConverterArgsTable = DS.ConnectedConverterArgsTable;
		ConnectedConverterIdResolution connectedConverterIdResolutionTable = DS.ConnectedConverterIdResolutionTable;
		foreach (Guid originalArgGuid in _originalArgGuids)
		{
			DataRow dataRow = connectedConverterArgsTable.Table.Rows.Find(originalArgGuid);
			if (dataRow != null)
			{
				connectedConverterArgsTable.DMRemoveRow(dataRow);
			}
		}
		foreach (Guid originalResolutionGuid in _originalResolutionGuids)
		{
			DataRow dataRow2 = connectedConverterIdResolutionTable.Table.Rows.Find(originalResolutionGuid);
			if (dataRow2 != null)
			{
				connectedConverterIdResolutionTable.DMRemoveRow(dataRow2);
			}
		}
	}

	public void NotifyPropertyChanged(string propertyName)
	{
		if (this.PropertyChanged != null)
		{
			this.PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
		}
	}
}
public class ConverterArgs : BaseTable
{
	private DataView _sortedByConverter;

	public DataColumn guidCol { get; set; }

	public DataColumn nameCol { get; set; }

	public DataColumn converterCol { get; set; }

	public DataColumn leftCol { get; set; }

	public DataColumn argNumber { get; set; }

	public DataColumn argDimensions { get; set; }

	private DataView SortedByConverter
	{
		get
		{
			if (_sortedByConverter == null)
			{
				_sortedByConverter = new DataView(base.Table);
				_sortedByConverter.Sort = "Converter";
			}
			return _sortedByConverter;
		}
	}

	public ConverterArgs(MapDataSet ds)
		: base(ds, "Cvt")
	{
		base.Table = new DataTable(base.DsTableName = TableName());
		guidCol = new DataColumn("Guid", typeof(Guid));
		base.Table.Columns.Add(guidCol);
		nameCol = new DataColumn("Name", typeof(string));
		base.Table.Columns.Add(nameCol);
		converterCol = new DataColumn("Converter", typeof(Guid));
		base.Table.Columns.Add(converterCol);
		leftCol = new DataColumn("IsLeftArg", typeof(bool));
		base.Table.Columns.Add(leftCol);
		argNumber = new DataColumn("ArgNumber", typeof(int));
		base.Table.Columns.Add(argNumber);
		argDimensions = new DataColumn("ArgDimensions", typeof(int));
		base.Table.Columns.Add(argDimensions);
		base.Table.PrimaryKey = new DataColumn[1] { guidCol };
		ds.Set.Tables.Add(base.Table);
		ds.CreateRelation(Converters.TableName(), TableName(), "Converter");
	}

	public override void Remove()
	{
		base.DS.RemoveRelation(Converters.TableName(), TableName(), "Converter");
		base.Remove();
	}

	public static string TableName()
	{
		return "ConverterArgs";
	}

	public DataRowView[] ArgsForConverter(Guid converter)
	{
		DataRowView[] array = null;
		if (IsCaching)
		{
			return SortedByConverter.FindRows(converter);
		}
		new DataView(base.Table);
		EnumerableRowCollection<DataRowView> source = from DataRowView rv in base.Table.AsEnumerable()
			where rv.Row.Field<Guid>(converterCol).Equals(converter)
			select rv;
		if (source.Any())
		{
			return source.ToArray();
		}
		return new DataRowView[0];
	}

	public override void ClearSortCache()
	{
		_sortedByConverter = null;
		base.ClearSortCache();
	}

	internal void CopyArgsToChild(Guid guid)
	{
		DataRowView[] array = ArgsForConverter(guid);
		foreach (DataRowView dataRowView in array)
		{
			CopyRowToChild(dataRowView.Row);
		}
	}
}
public class ConverterImplementation
{
	public virtual IArgumentData[] Convert(IArgumentData[] leftArgs)
	{
		return leftArgs;
	}

	public virtual IArgumentData[] ConvertBack(IArgumentData[] rightArgs)
	{
		return rightArgs;
	}
}
public class ConvertGuid
{
	public Guid CGuid { get; set; }

	public string CName { get; set; }
}
public class ConverterListVM
{
	public List<Guid> GuidList = new List<Guid>();

	public ObservableCollection<ConvertGuid> ConvertList { get; set; }

	public MapDataSet DS { get; set; }

	public ConverterListVM(MapDataSet ds, int? firstLeftDim = null, int? firstRightDim = null)
	{
		DS = ds;
		ConvertList = new ObservableCollection<ConvertGuid>();
		Refresh(firstLeftDim, firstRightDim);
	}

	public void Refresh(int? firstLeftDim = null, int? firstRightDim = null)
	{
		Converters convertersTable = DS.ConvertersTable;
		ConverterArgs converterArgsTable = DS.ConverterArgsTable;
		ConvertList.Clear();
		if (!firstLeftDim.HasValue && !firstRightDim.HasValue)
		{
			ConvertList.Add(new ConvertGuid
			{
				CGuid = Guid.Empty,
				CName = "<new>"
			});
		}
		foreach (DataRow row in convertersTable.Table.Rows)
		{
			Guid guid = row.Field<Guid>(convertersTable.guidCol);
			bool flag = true;
			if (firstLeftDim.HasValue || firstRightDim.HasValue)
			{
				DataRowView[] array = converterArgsTable.ArgsForConverter(guid);
				foreach (DataRowView obj in array)
				{
					bool flag2 = obj.Row.Field<bool>(converterArgsTable.leftCol);
					int num = obj.Row.Field<int>(converterArgsTable.argNumber);
					int num2 = obj.Row.Field<int>(converterArgsTable.argDimensions);
					if (num != 0)
					{
						continue;
					}
					if (flag2)
					{
						if (firstLeftDim.HasValue && firstLeftDim.Value != num2)
						{
							flag = false;
						}
					}
					else if (firstRightDim.HasValue && firstRightDim.Value != num2)
					{
						flag = false;
					}
				}
			}
			if (flag)
			{
				ConvertList.Add(new ConvertGuid
				{
					CGuid = guid,
					CName = row.Field<string>(convertersTable.nameCol)
				});
			}
		}
	}
}
public class Converters : BaseTable
{
	public DataColumn guidCol { get; set; }

	public DataColumn nameCol { get; set; }

	public DataColumn descCol { get; set; }

	public DataColumn twoWayCol { get; set; }

	public DataColumn leftArgs { get; set; }

	public DataColumn rightArgs { get; set; }

	public DataColumn implementedCol { get; set; }

	public Converters(MapDataSet ds)
		: base(ds, "Cvt")
	{
		base.Table = new DataTable(base.DsTableName = TableName());
		guidCol = new DataColumn("Guid", typeof(Guid));
		base.Table.Columns.Add(guidCol);
		nameCol = new DataColumn("Name", typeof(string));
		base.Table.Columns.Add(nameCol);
		descCol = new DataColumn("Description", typeof(string));
		base.Table.Columns.Add(descCol);
		twoWayCol = new DataColumn("TwoWay", typeof(bool));
		base.Table.Columns.Add(twoWayCol);
		leftArgs = new DataColumn("LeftArgsCount", typeof(int));
		base.Table.Columns.Add(leftArgs);
		rightArgs = new DataColumn("RightArgsCount", typeof(int));
		base.Table.Columns.Add(rightArgs);
		base.Table.PrimaryKey = new DataColumn[1] { guidCol };
		implementedCol = new DataColumn("Implemented", typeof(bool));
		base.Table.Columns.Add(implementedCol);
		ds.Set.Tables.Add(base.Table);
	}

	public override void Remove()
	{
		base.Remove();
	}

	public static string TableName()
	{
		return "Converters";
	}

	public override void ClearSortCache()
	{
		base.ClearSortCache();
	}

	public override void CopyRowToChild(DataRow row)
	{
		base.CopyRowToChild(row);
		base.DS.ConverterArgsTable.CopyArgsToChild(row.Field<Guid>(guidCol));
	}
}
public class ConnectedArg
{
	public ConverterWithArgs Converter { get; set; }

	public bool IsLeft { get; set; }

	public int ArgNumber { get; set; }

	public ArgTreeNode Parent { get; set; }

	public string Literal { get; set; }

	public StorePathNode GetStorePath()
	{
		return Parent.GetStorePath();
	}
}
public class ArgTreeChildren : List<KeyValuePair<Guid, ArgTreeNode>>
{
	public bool TryGetValue(Guid key, out ArgTreeNode child)
	{
		child = null;
		bool result = false;
		using (Enumerator enumerator = GetEnumerator())
		{
			while (enumerator.MoveNext())
			{
				KeyValuePair<Guid, ArgTreeNode> current = enumerator.Current;
				if (key.Equals(current.Key))
				{
					result = true;
					child = current.Value;
					break;
				}
			}
		}
		return result;
	}
}
public class ArgTreeNode
{
	private ArgTreeChildren _children = new ArgTreeChildren();

	private List<ConnectedArg> _conveterArgs = new List<ConnectedArg>();

	public Guid MyGuid { get; set; }

	public ArgTreeChildren Children => _children;

	public string NodeName { get; set; }

	public string DataType { get; set; }

	public string ArrayDataType { get; set; }

	public ArgTreeNode[] IdNodes { get; protected set; }

	public int Ndim { get; protected set; }

	public ArgTreeNode Parent { get; protected set; }

	public bool HasChildren => Children.Any();

	public List<ConnectedArg> ConnectedArgs => _conveterArgs;

	public ArgTreeNode AddChild(ObservableCollection<ArgumentPathElement> path, int depth, ConverterWithArgs converter, bool isLeft, int argNumber, Variables vtable, PathToVariableIds ptable, string literal)
	{
		ArgTreeNode result = this;
		if (depth < path.Count && (depth < path.Count - 1 || !path[depth].PathGuid.Equals(Guid.Empty)))
		{
			Guid pathGuid = path[depth].PathGuid;
			_ = path[depth].PathObjGuid;
			VariableRow variableRow = vtable.Find(pathGuid);
			if (!Children.TryGetValue(pathGuid, out var child))
			{
				child = new ArgTreeNode();
				child.MyGuid = pathGuid;
				child.NodeName = ((variableRow.vAlias != null) ? variableRow.vAlias : variableRow.vName);
				int vNumids = variableRow.vNumids;
				child.Ndim = vNumids;
				child.Parent = this;
				child.DataType = "Array";
				child.ArrayDataType = variableRow.vDataType;
				if (variableRow.vNumids > 0)
				{
					child.DataType = "Array";
					child.ArrayDataType = variableRow.vDataType;
				}
				else
				{
					child.DataType = variableRow.vDataType;
				}
				Children.Add(new KeyValuePair<Guid, ArgTreeNode>(pathGuid, child));
			}
			result = child.AddChild(path, depth + 1, converter, isLeft, argNumber, vtable, ptable, null);
			IdNodes = new ArgTreeNode[variableRow.vNumids];
		}
		else
		{
			ConnectedArg connectedArg = new ConnectedArg
			{
				Converter = converter,
				IsLeft = isLeft,
				ArgNumber = argNumber,
				Parent = this,
				Literal = literal
			};
			_conveterArgs.Add(connectedArg);
			if (isLeft)
			{
				converter.LeftArgSources[argNumber] = connectedArg;
			}
			else
			{
				converter.RightArgSources[argNumber] = connectedArg;
			}
		}
		return result;
	}

	public StorePathNode GetStorePath()
	{
		StorePathNode storePathNode = new StorePathNode();
		for (int num = Ndim - 1; num >= 0; num--)
		{
			storePathNode.IsEnumerator = true;
			storePathNode = new StorePathNode
			{
				Next = storePathNode
			};
		}
		storePathNode.ConstantValue = MyGuid;
		storePathNode.NodeName = NodeName;
		storePathNode.IsEnumerator = false;
		if (Parent != null)
		{
			StorePathNode storePath = Parent.GetStorePath();
			StorePathNode storePathNode2 = storePath;
			while (storePathNode2.Next != null)
			{
				storePathNode2 = storePathNode2.Next;
			}
			storePathNode2.Next = storePathNode;
			storePathNode = storePath;
		}
		return storePathNode;
	}

	public ArgTreeNode FindPath(List<Guid> path, int depth)
	{
		ArgTreeNode result = null;
		ArgTreeNode child;
		if (depth >= path.Count)
		{
			result = this;
		}
		else if (Children != null && Children.TryGetValue(path[depth], out child))
		{
			result = child.FindPath(path, depth + 1);
		}
		return result;
	}

	internal void GetVariableDescription(XElement parent)
	{
		if (Children == null)
		{
			return;
		}
		foreach (KeyValuePair<Guid, ArgTreeNode> child in Children)
		{
			XElement xElement = new XElement("Arg");
			ArgTreeNode value = child.Value;
			XAttribute content = new XAttribute("path", value.NodeName);
			xElement.Add(content);
			if (value.DataType != null)
			{
				XAttribute content2 = new XAttribute("datatype", value.DataType);
				xElement.Add(content2);
			}
			if (value.ArrayDataType != null)
			{
				XAttribute content3 = new XAttribute("arraydatatype", value.ArrayDataType);
				xElement.Add(content3);
			}
			parent.Add(xElement);
			value.GetVariableDescription(xElement);
		}
	}

	internal void AssignArgsToConverters(IArgumentData baseData, ArgumentResolvedPathData current)
	{
		for (int i = 0; i < Ndim; i++)
		{
			current = new ArgumentResolvedPathData(baseData, current, -1);
		}
		for (int j = 0; j < Children.Count; j++)
		{
			ArgumentResolvedPathData current2 = new ArgumentResolvedPathData(baseData, current, j);
			Children[j].Value.AssignArgsToConverters(baseData, current2);
		}
		foreach (ConnectedArg conveterArg in _conveterArgs)
		{
			IArgumentData argumentData;
			if (conveterArg.Literal != null)
			{
				argumentData = new ArgumentStringData(conveterArg.Literal);
			}
			else
			{
				ArgumentResolvedPathData argumentResolvedPathData = new ArgumentResolvedPathData(current);
				ObservableCollection<IdResolution> idRes = (conveterArg.IsLeft ? conveterArg.Converter.ConnectedConverter.LeftArgs : conveterArg.Converter.ConnectedConverter.RightArgs)[conveterArg.ArgNumber].IdRes;
				argumentResolvedPathData.SetIndexes(idRes);
				argumentData = argumentResolvedPathData;
			}
			if (conveterArg.IsLeft)
			{
				conveterArg.Converter.LeftArgs[conveterArg.ArgNumber] = argumentData;
				conveterArg.Converter.LeftArgSources[conveterArg.ArgNumber] = conveterArg;
			}
			else
			{
				conveterArg.Converter.RightArgs[conveterArg.ArgNumber] = argumentData;
				conveterArg.Converter.RightArgSources[conveterArg.ArgNumber] = conveterArg;
			}
		}
	}
}
public class StorePathNode
{
	public StorePathNode Next { get; set; }

	public Guid ConstantValue { get; set; }

	public bool IsEnumerator { get; set; }

	public string NodeName { get; set; }

	public StorePathNode[] IdNodes { get; set; }
}
public class ConverterWithArgs
{
	private bool _reverse;

	public ConnectedConverterVM ConnectedConverter { get; set; }

	public IArgumentData[] LeftArgs { get; set; }

	public ConnectedArg[] LeftArgSources { get; set; }

	public IArgumentData[] RightArgs { get; set; }

	public ConnectedArg[] RightArgSources { get; set; }

	public ImplementedConverterWrapper ImpConverter { get; set; }

	public ConverterWithArgs(ConnectedConverterVM cvt, bool reverse)
	{
		ConnectedConverter = cvt;
		LeftArgs = new IArgumentData[cvt.LeftArgs.Count];
		LeftArgSources = new ConnectedArg[cvt.LeftArgs.Count];
		RightArgs = new IArgumentData[cvt.RightArgs.Count];
		RightArgSources = new ConnectedArg[cvt.RightArgs.Count];
		_reverse = reverse;
	}

	public bool Convert(IAdsDataStorer target)
	{
		if (_reverse)
		{
			return doConvertBack(target);
		}
		return doConvert(target);
	}

	public bool ConvertBack(IAdsDataStorer target)
	{
		if (_reverse)
		{
			return doConvert(target);
		}
		return doConvertBack(target);
	}

	protected static void DumpArgLevel(int depth, IArgumentData data, StringBuilder sb)
	{
		if (data.IsScalar)
		{
			for (int i = 0; i < depth; i++)
			{
				sb.Append(" ");
			}
			sb.AppendFormat("Type {0} Value {1}\r\n", data.ScalarValue.GetType(), data.ScalarValue.ToString());
			return;
		}
		for (int j = 0; j < depth; j++)
		{
			sb.Append(" ");
		}
		sb.AppendLine("Array:");
		int num = 0;
		foreach (KeyValuePair<string, IArgumentData> idValue in data.IdValues)
		{
			if (idValue.Key != null)
			{
				for (int k = 0; k < depth + 1; k++)
				{
					sb.Append(" ");
				}
				sb.AppendLine("ID: " + idValue.Key);
				if (idValue.Value != null)
				{
					DumpArgLevel(depth + 2, idValue.Value, sb);
				}
				else
				{
					for (int l = 0; l < depth + 1; l++)
					{
						sb.Append(" ");
					}
				}
				sb.AppendLine("null");
			}
			else
			{
				for (int m = 0; m < depth + 1; m++)
				{
					sb.Append(" ");
				}
				sb.AppendLine("Index: " + num);
				if (idValue.Value != null)
				{
					DumpArgLevel(depth + 2, idValue.Value, sb);
				}
				else
				{
					for (int n = 0; n < depth + 1; n++)
					{
						sb.Append(" ");
					}
				}
				sb.AppendLine("null");
			}
			num++;
		}
	}

	public static string DumpArg(IArgumentData data)
	{
		StringBuilder stringBuilder = new StringBuilder();
		DumpArgLevel(0, data, stringBuilder);
		return stringBuilder.ToString();
	}

	private bool doConvert(IAdsDataStorer target)
	{
		bool result = false;
		if (ImpConverter != null)
		{
			int i;
			for (i = 0; i < LeftArgs.Length; i++)
			{
				if (false)
				{
					DumpArg(LeftArgs[i]);
				}
				if (LeftArgs[i] == null)
				{
					break;
				}
			}
			if (i == LeftArgs.Length)
			{
				RightArgs = ImpConverter.Converter.Convert(LeftArgs);
				if (RightArgs != null)
				{
					result = true;
					for (int j = 0; j < RightArgSources.Length && j < RightArgs.Length; j++)
					{
						if (false)
						{
							DumpArg(RightArgs[j]);
						}
						StorePathNode storePath = RightArgSources[j].GetStorePath();
						if (RightArgs[j] != null)
						{
							try
							{
								target.StoreData(storePath, RightArgs[j], null);
							}
							catch (Exception ex)
							{
								_ = ex.Message;
							}
						}
					}
				}
			}
		}
		return result;
	}

	private bool doConvertBack(IAdsDataStorer target)
	{
		bool result = false;
		if (ImpConverter != null)
		{
			int i;
			for (i = 0; i < RightArgs.Length; i++)
			{
				if (false)
				{
					DumpArg(RightArgs[i]);
				}
				if (RightArgs[i] == null)
				{
					break;
				}
			}
			if (i == RightArgs.Length)
			{
				LeftArgs = ImpConverter.Converter.ConvertBack(RightArgs);
				result = true;
				for (int j = 0; j < LeftArgSources.Length && j < LeftArgs.Length; j++)
				{
					if (false)
					{
						DumpArg(LeftArgs[j]);
					}
					StorePathNode storePath = LeftArgSources[j].GetStorePath();
					if (LeftArgs[j] != null)
					{
						try
						{
							target.StoreData(storePath, LeftArgs[j], null);
						}
						catch (Exception ex)
						{
							_ = ex.Message;
						}
					}
				}
			}
		}
		return result;
	}
}
public interface IAdsDataStorer
{
	bool StoreData(StorePathNode path, IArgumentData pathData, StringBuilder formattedData);
}
public class ConvertersBetweenObjects
{
	private struct NeededIds
	{
		public ArgumentArrayData NeedsIds;

		public ArgTreeNode IdSupplier;
	}

	private class XmlStorer : IAdsDataStorer
	{
		public XDocument Document { get; protected set; }

		public XmlStorer()
		{
			Document = new XDocument();
			XElement content = new XElement("Top");
			Document.Add(content);
		}

		public bool StoreData(StorePathNode path, IArgumentData argData, StringBuilder formattedData)
		{
			XElement current = Document.Element("Top");
			StoreDataRecurse(current, path, argData);
			return true;
		}

		protected bool StoreDataRecurse(XElement current, StorePathNode path, IArgumentData argData)
		{
			bool flag = false;
			if (argData != null)
			{
				if (path == null)
				{
					if (argData.IsScalar && argData.sVal != null)
					{
						string orginalDatatype = argData.orginalDatatype;
						if (!string.IsNullOrWhiteSpace(orginalDatatype))
						{
							XAttribute xAttribute = current.Attribute("datatype");
							if (xAttribute == null)
							{
								current.Add(new XAttribute("datatype", orginalDatatype));
							}
							else
							{
								xAttribute.Value = orginalDatatype;
							}
						}
						current.Value = argData.sVal;
						flag = true;
					}
				}
				else if (path.IsEnumerator)
				{
					XElement xElement = current.Element("Array");
					XElement xElement2 = null;
					if (xElement == null)
					{
						xElement2 = new XElement("Array");
						xElement = xElement2;
					}
					int num = -1;
					foreach (KeyValuePair<string, IArgumentData> idValue in argData.IdValues)
					{
						num++;
						bool flag2 = false;
						XElement xElement3 = null;
						XElement xElement4 = null;
						string id = idValue.Key;
						if (id == null)
						{
							id = "#" + num;
						}
						IEnumerable<XElement> source = from el in xElement.Elements("ArrayElement")
							where (string)el.Attribute("id") == id
							select el;
						if (source.Any())
						{
							xElement3 = source.First();
						}
						if (xElement3 == null)
						{
							xElement4 = new XElement("ArrayElement");
							xElement4.Add(new XAttribute("id", id));
							xElement3 = xElement4;
						}
						flag2 = StoreDataRecurse(xElement3, path.Next, idValue.Value);
						if (flag2 && xElement4 != null)
						{
							xElement.Add(xElement4);
						}
						flag = flag || flag2;
					}
					if (flag && xElement2 != null)
					{
						current.Add(xElement2);
					}
				}
				else if (path.ConstantValue.Equals(Guid.Empty))
				{
					flag = StoreDataRecurse(current, path.Next, argData);
				}
				else
				{
					XElement xElement5 = current.Element(path.NodeName);
					XElement xElement6 = null;
					if (xElement5 == null)
					{
						xElement6 = new XElement(path.NodeName);
						xElement6.Add(new XAttribute("guid", path.ConstantValue.ToString()));
						xElement5 = xElement6;
					}
					flag = StoreDataRecurse(xElement5, path.Next, argData);
					if (flag && xElement6 != null)
					{
						current.Add(xElement6);
					}
				}
			}
			return flag;
		}
	}

	private MapDataSet _ds;

	private string _prefix1;

	private string _prefix2;

	private Guid _obj1;

	private Guid _obj2;

	public ArgTreeNode _tree1;

	private ArgTreeNode _tree2;

	private List<ConverterWithArgs> _converters = new List<ConverterWithArgs>();

	public ConvertersBetweenObjects(MapDataSet ds, string prefix1, Guid object1, string prefix2, Guid object2)
	{
		_ds = ds;
		_prefix1 = prefix1;
		_prefix2 = prefix2;
		_obj1 = object1;
		_obj2 = object2;
		_tree1 = new ArgTreeNode();
		_tree2 = new ArgTreeNode();
		Variables vtable = ds.VariableTable(prefix1);
		Variables vtable2 = ds.VariableTable(prefix2);
		Objects objects = ds.ObjectTable(prefix1);
		Objects objects2 = ds.ObjectTable(prefix2);
		PathToVariableIds ptable = ds.PathToVarIDTable(prefix1);
		PathToVariableIds ptable2 = ds.PathToVarIDTable(prefix2);
		DataView sortedConverters = ds.ConnectedConvertersTable.SortedConverters;
		List<Guid> list = new List<Guid>();
		List<Guid> list2 = new List<Guid>();
		Guid? guid = _obj1;
		while (guid.HasValue)
		{
			Guid? guid2 = _obj2;
			while (guid2.HasValue)
			{
				DataRowView[] array = sortedConverters.FindRows(new object[4] { _prefix1, _prefix2, guid.Value, guid2.Value });
				DataRowView[] array2 = sortedConverters.FindRows(new object[4] { _prefix2, _prefix1, guid2.Value, guid.Value });
				DataRowView[] array3 = array;
				foreach (DataRowView dataRowView in array3)
				{
					list.Add(dataRowView.Row.Field<Guid>("Guid"));
				}
				array3 = array2;
				foreach (DataRowView dataRowView2 in array3)
				{
					list2.Add(dataRowView2.Row.Field<Guid>("Guid"));
				}
				guid2 = objects2.Find(guid2.Value).vParent;
			}
			guid = objects.Find(guid.Value).vParent;
		}
		foreach (Guid item in list)
		{
			ConnectedConverterVM connectedConverterVM = new ConnectedConverterVM(_ds, item);
			ConverterWithArgs converterWithArgs = new ConverterWithArgs(connectedConverterVM, reverse: false);
			_converters.Add(converterWithArgs);
			for (int j = 0; j < connectedConverterVM.LeftArgs.Count; j++)
			{
				_tree1.AddChild(connectedConverterVM.LeftArgs[j].Path, 0, converterWithArgs, isLeft: true, j, vtable, ptable, connectedConverterVM.LeftArgs[j].Literal);
			}
			for (int k = 0; k < connectedConverterVM.RightArgs.Count; k++)
			{
				_tree2.AddChild(connectedConverterVM.RightArgs[k].Path, 0, converterWithArgs, isLeft: false, k, vtable2, ptable2, connectedConverterVM.RightArgs[k].Literal);
			}
		}
		foreach (Guid item2 in list2)
		{
			ConnectedConverterVM connectedConverterVM2 = new ConnectedConverterVM(_ds, item2);
			ConverterWithArgs converterWithArgs2 = new ConverterWithArgs(connectedConverterVM2, reverse: true);
			_converters.Add(converterWithArgs2);
			for (int l = 0; l < connectedConverterVM2.LeftArgs.Count; l++)
			{
				_tree2.AddChild(connectedConverterVM2.LeftArgs[l].Path, 0, converterWithArgs2, isLeft: true, l, vtable2, ptable2, connectedConverterVM2.LeftArgs[l].Literal);
			}
			for (int m = 0; m < connectedConverterVM2.RightArgs.Count; m++)
			{
				_tree1.AddChild(connectedConverterVM2.RightArgs[m].Path, 0, converterWithArgs2, isLeft: false, m, vtable, ptable, connectedConverterVM2.RightArgs[m].Literal);
			}
		}
	}

	public ArgTreeNode FindForPath(List<Guid> path, bool isLeft)
	{
		return (isLeft ? _tree1 : _tree2).FindPath(path, 0);
	}

	public void ConnectToConverters(ImplementedConverterList implementedConverters)
	{
		foreach (ConverterWithArgs converter in _converters)
		{
			implementedConverters.TryGetValue(converter.ConnectedConverter.ConverterGuid, out var value);
			converter.ImpConverter = value;
		}
	}

	public XDocument GetAdsXmlVariableDesc()
	{
		XDocument xDocument = new XDocument();
		XElement xElement = new XElement("Args");
		xDocument.Add(xElement);
		_tree2.GetVariableDescription(xElement);
		return xDocument;
	}

	public string GetVariableDescriptionNonAds()
	{
		XDocument xDocument = new XDocument();
		XElement xElement = new XElement("Args");
		xDocument.Add(xElement);
		_tree1.GetVariableDescription(xElement);
		return xDocument.ToString();
	}

	private IArgumentData ObjectToArgumentData(object rawdata, ArgTreeNode argStructure, int idNumber, List<NeededIds> neededIds)
	{
		IArgumentData result = null;
		Type type = rawdata.GetType();
		if (type.Equals(typeof(string)))
		{
			result = new ArgumentStringData((string)rawdata);
		}
		else if (type.Equals(typeof(int)))
		{
			result = new ArgumentIntData((int)rawdata);
		}
		else if (type.Equals(typeof(double)))
		{
			result = new ArgumentRealData((double)rawdata);
		}
		else if (type.Equals(typeof(bool)))
		{
			result = new ArgumentBoolData((bool)rawdata);
		}
		else if (type.Equals(typeof(object)))
		{
			result = new ArgumentRefData(ObjectToArgumentData(rawdata, argStructure.Children.First().Value, 0, neededIds));
		}
		else if (type.Equals(typeof(object[])))
		{
			object[] array = (object[])rawdata;
			ArgumentArrayData argumentArrayData = new ArgumentArrayData(array.Length);
			if (idNumber < argStructure.Ndim && argStructure.IdNodes != null && argStructure.IdNodes.Length > idNumber && argStructure.IdNodes[idNumber] != null)
			{
				neededIds.Add(new NeededIds
				{
					NeedsIds = argumentArrayData,
					IdSupplier = argStructure.IdNodes[idNumber]
				});
			}
			for (int i = 0; i < array.Length; i++)
			{
				if (array[i] != null)
				{
					if (idNumber < argStructure.Ndim)
					{
						argumentArrayData.SetValue(i, ObjectToArgumentData(array[i], argStructure, idNumber + 1, neededIds));
					}
					else
					{
						argumentArrayData.SetValue(i, ObjectToArgumentData(array[i], argStructure.Children[i].Value, 0, neededIds));
					}
				}
			}
			result = argumentArrayData;
			foreach (NeededIds neededId in neededIds)
			{
				if (neededId.IdSupplier == argStructure)
				{
					neededId.NeedsIds.SetIdSupplier(argumentArrayData);
				}
			}
		}
		return result;
	}

	public void ConvertToAdsRaw(object rawData, IAdsDataStorer target)
	{
		IArgumentData formattedDataAsObject = ObjectToArgumentData(rawData, _tree1, 0, new List<NeededIds>());
		ConvertToAds(formattedDataAsObject, target);
	}

	public void ConvertToAds(object formattedDataAsObject, IAdsDataStorer target)
	{
		if (!(formattedDataAsObject is IArgumentData baseData))
		{
			return;
		}
		ArgumentResolvedPathData current = null;
		_tree1.AssignArgsToConverters(baseData, current);
		foreach (ConverterWithArgs converter in _converters)
		{
			converter.Convert(target);
		}
	}

	public XDocument ConvertFromAds(IArgumentData adsData)
	{
		XmlStorer xmlStorer = new XmlStorer();
		if (adsData != null)
		{
			ArgumentResolvedPathData current = null;
			_tree2.AssignArgsToConverters(adsData, current);
			foreach (ConverterWithArgs converter in _converters)
			{
				try
				{
					converter.ConvertBack(xmlStorer);
				}
				catch (Exception)
				{
				}
			}
		}
		return xmlStorer.Document;
	}
}
public class ConverterVM
{
	public class Directions
	{
		public string Display { get; set; }

		public direction Value { get; set; }
	}

	public enum direction
	{
		TwoWay,
		LeftToRight
	}

	protected Directions[] _directionOptions = new Directions[2]
	{
		new Directions
		{
			Display = "Two Way",
			Value = direction.TwoWay
		},
		new Directions
		{
			Display = "Left to Right",
			Value = direction.LeftToRight
		}
	};

	protected List<Guid> _originalArgGuids = new List<Guid>();

	public Directions[] DirectionOptions => _directionOptions;

	public Guid ConverterGuid { get; set; }

	public string Name { get; set; }

	public string Description { get; set; }

	public int Direction { get; set; }

	public DataTable LeftArgs { get; set; }

	public DataTable RightArgs { get; set; }

	public MapDataSet DS { get; set; }

	public int NumLeft
	{
		get
		{
			int result = 0;
			if (LeftArgs != null && LeftArgs.Rows != null)
			{
				result = LeftArgs.Rows.Count;
			}
			return result;
		}
	}

	public int NumRight
	{
		get
		{
			int result = 0;
			if (RightArgs != null && RightArgs.Rows != null)
			{
				result = RightArgs.Rows.Count;
			}
			return result;
		}
	}

	public string ValidateErrors
	{
		get
		{
			string text = null;
			if (string.IsNullOrWhiteSpace(Name))
			{
				text = "Converter name must be specified";
			}
			foreach (DataRow row in LeftArgs.Rows)
			{
				if (row.IsNull("Guid"))
				{
					row.SetField("Guid", Guid.NewGuid());
				}
				if (isPartial(row))
				{
					text = "All arguments must have name and Dimensionality";
					break;
				}
			}
			if (text == null)
			{
				foreach (DataRow row2 in RightArgs.Rows)
				{
					if (row2.IsNull("Guid"))
					{
						row2.SetField("Guid", Guid.NewGuid());
					}
					if (isPartial(row2))
					{
						text = "All arguments must have name and Dimensionality";
						break;
					}
				}
			}
			return text;
		}
	}

	public ConverterVM(MapDataSet ds, Guid? guid)
	{
		DS = ds;
		LeftArgs = new DataTable();
		LeftArgs.Columns.Add(new DataColumn("Guid", typeof(Guid)));
		LeftArgs.Columns.Add(new DataColumn("Name", typeof(string)));
		LeftArgs.Columns.Add(new DataColumn("Dimensions", typeof(int)));
		LeftArgs.Columns.Add(new DataColumn("IsLiteral", typeof(bool)));
		RightArgs = new DataTable();
		RightArgs.Columns.Add(new DataColumn("Guid", typeof(Guid)));
		RightArgs.Columns.Add(new DataColumn("Name", typeof(string)));
		RightArgs.Columns.Add(new DataColumn("Dimensions", typeof(int)));
		RightArgs.Columns.Add(new DataColumn("IsLiteral", typeof(bool)));
		if (guid.HasValue)
		{
			ConverterGuid = guid.Value;
			Converters convertersTable = DS.ConvertersTable;
			DataRow dataRow = convertersTable.Table.Rows.Find(guid.Value);
			if (dataRow == null)
			{
				return;
			}
			Name = dataRow.Field<string>(convertersTable.nameCol);
			if (!dataRow.IsNull(convertersTable.descCol))
			{
				Description = dataRow.Field<string>(convertersTable.descCol);
			}
			else
			{
				Description = "";
			}
			if (dataRow.Field<bool>(convertersTable.twoWayCol))
			{
				Direction = 0;
			}
			else
			{
				Direction = 1;
			}
			ConverterArgs converterArgsTable = DS.ConverterArgsTable;
			DataRowView[] array = converterArgsTable.ArgsForConverter(ConverterGuid);
			foreach (DataRowView dataRowView in array)
			{
				DataTable dataTable = RightArgs;
				if (dataRowView.Row.Field<bool>(converterArgsTable.leftCol))
				{
					dataTable = LeftArgs;
				}
				DataRow row = dataTable.NewRow();
				Guid guid2 = dataRowView.Row.Field<Guid>(converterArgsTable.guidCol);
				row.SetField("Guid", guid2);
				row.SetField("Name", dataRowView.Row.Field<string>(converterArgsTable.nameCol));
				row.SetField("Dimensions", dataRowView.Row.Field<int>(converterArgsTable.argDimensions));
				row.SetField("IsLiteral", dataRowView.Row.Field<int>(converterArgsTable.argDimensions) == -1);
				dataTable.Rows.Add(row);
				_originalArgGuids.Add(guid2);
			}
		}
		else
		{
			ConverterGuid = Guid.NewGuid();
		}
	}

	private int BlankCols(DataRow row)
	{
		int num = 0;
		if (row.IsNull("Guid"))
		{
			num++;
		}
		if (row.IsNull("Name"))
		{
			num++;
		}
		if (row.IsNull("Dimensions"))
		{
			num++;
		}
		return num;
	}

	private bool isFull(DataRow row)
	{
		return BlankCols(row) == 3;
	}

	private bool isEmpty(DataRow row)
	{
		return BlankCols(row) == 0;
	}

	private bool isPartial(DataRow row)
	{
		int num = BlankCols(row);
		if (num != 1)
		{
			return num == 2;
		}
		return true;
	}

	private void SaveArg(DataRow arg, ConverterArgs cargs, Guid converterGuid, bool isLeft, int argNumber)
	{
		Guid guid = arg.Field<Guid>("Guid");
		DataRow dataRow = cargs.Table.Rows.Find(guid);
		if (dataRow == null)
		{
			dataRow = cargs.DMAddRow(new object[2] { "Guid", guid });
		}
		cargs.DMSetValues(dataRow, new object[10]
		{
			cargs.nameCol.ColumnName,
			arg.Field<string>("Name"),
			cargs.converterCol.ColumnName,
			ConverterGuid,
			cargs.leftCol.ColumnName,
			isLeft,
			cargs.argNumber.ColumnName,
			argNumber,
			cargs.argDimensions.ColumnName,
			arg.Field<int>("Dimensions")
		});
		if (_originalArgGuids.Contains(guid))
		{
			_originalArgGuids.Remove(guid);
		}
	}

	public void Save()
	{
		DS.Undos.StartUndoable("Saving Converter " + Name);
		Converters convertersTable = DS.ConvertersTable;
		DataRow dataRow = convertersTable.Table.Rows.Find(ConverterGuid);
		if (dataRow == null)
		{
			dataRow = convertersTable.DMAddRow(new object[4]
			{
				"Guid",
				ConverterGuid,
				convertersTable.implementedCol.ColumnName,
				false
			});
		}
		convertersTable.DMSetValues(dataRow, new object[10]
		{
			convertersTable.nameCol.ColumnName,
			Name,
			convertersTable.descCol.ColumnName,
			Description,
			convertersTable.twoWayCol.ColumnName,
			Direction == 0,
			convertersTable.leftArgs.ColumnName,
			LeftArgs.Rows.Count,
			convertersTable.rightArgs.ColumnName,
			RightArgs.Rows.Count
		});
		ConverterArgs converterArgsTable = DS.ConverterArgsTable;
		int num = 0;
		foreach (DataRow row in LeftArgs.Rows)
		{
			SaveArg(row, converterArgsTable, ConverterGuid, isLeft: true, num++);
		}
		num = 0;
		foreach (DataRow row2 in RightArgs.Rows)
		{
			SaveArg(row2, converterArgsTable, ConverterGuid, isLeft: false, num++);
		}
		DeleteUnusedArgs();
		DS.Undos.FinishUndoable();
	}

	private void DeleteUnusedArgs()
	{
		ConverterArgs converterArgsTable = DS.ConverterArgsTable;
		foreach (Guid originalArgGuid in _originalArgGuids)
		{
			DataRow dataRow = converterArgsTable.Table.Rows.Find(originalArgGuid);
			if (dataRow != null)
			{
				converterArgsTable.DMRemoveRow(dataRow);
			}
		}
	}

	public void Delete()
	{
		Converters convertersTable = DS.ConvertersTable;
		DataRow dataRow = convertersTable.Table.Rows.Find(ConverterGuid);
		if (dataRow != null)
		{
			DS.Undos.StartUndoable("Deleting Converter");
			DeleteUnusedArgs();
			convertersTable.DMRemoveRow(dataRow);
			DS.Undos.FinishUndoable();
		}
	}
}
public class Ids : BaseTable
{
	public Ids(MapDataSet ds, string tableNamePrefix)
		: base(ds, tableNamePrefix)
	{
		base.Table = new DataTable(base.DsTableName = TableName(tableNamePrefix));
		DataColumn dataColumn = new DataColumn("Guid", typeof(Guid));
		base.Table.Columns.Add(dataColumn);
		DataColumn column = new DataColumn("Name", typeof(string));
		base.Table.Columns.Add(column);
		DataColumn column2 = new DataColumn("IdType", typeof(string));
		base.Table.Columns.Add(column2);
		DataColumn column3 = new DataColumn("VariableId", typeof(Guid));
		base.Table.Columns.Add(column3);
		DataColumn column4 = new DataColumn("ObjectId", typeof(Guid));
		base.Table.Columns.Add(column4);
		DataColumn column5 = new DataColumn("Description", typeof(string));
		base.Table.Columns.Add(column5);
		DataColumn column6 = new DataColumn("RefCount", typeof(int));
		base.Table.Columns.Add(column6);
		base.Table.PrimaryKey = new DataColumn[1] { dataColumn };
		ds.Set.Tables.Add(base.Table);
	}

	public static string TableName(string prefix)
	{
		return prefix + "Ids";
	}

	public void CheckVariableAfterRead(MapDataSet oldDs)
	{
		Ids ids = oldDs.IdTable(base.Prefix);
		Variables oldVars = oldDs.VariableTable(base.Prefix);
		Variables variableTable = base.Dm.VariableTable;
		Objects oldObjs = oldDs.ObjectTable(base.Prefix);
		_ = base.Dm.ObjectTable;
		VariableObjectMap variableObjectMap = oldDs.VariableObjectMapTable(base.Prefix);
		VariableIdMap variableIdMap = oldDs.VariableIdMapTable(base.Prefix);
		foreach (DataRow row4 in ids.Table.Rows)
		{
			if (row4.IsNull("VariableId"))
			{
				continue;
			}
			Guid guid = row4.Field<Guid>("VariableId");
			Guid? guid2 = null;
			Guid? newObjGuid = null;
			Guid? newGuid = null;
			Guid id = row4.Field<Guid>("Guid");
			if (!row4.IsNull("ObjectId"))
			{
				guid2 = row4.Field<Guid>("ObjectId");
			}
			if (!guid2.HasValue)
			{
				DataRowView[] array = variableObjectMap.FindForVariable(guid);
				guid2 = array[0].Row.Field<Guid>("Object");
			}
			if (!variableTable.FindVariableWithGuid(oldVars, guid, oldObjs, guid2.Value, out newGuid, out newObjGuid))
			{
				continue;
			}
			DataRow[] array2 = variableIdMap.ConnectionsToId(id);
			foreach (DataRow row in array2)
			{
				Guid oldGuid = row.Field<Guid>("VariableGuid");
				Guid oldObjGuid = row.Field<Guid>("ObjectGuid");
				int num = row.Field<int>("IdIndex");
				if (!variableTable.FindVariableWithGuid(oldVars, oldGuid, oldObjs, oldObjGuid, out var newGuid2, out var newObjGuid2))
				{
					continue;
				}
				DataRow[] array3 = base.Dm.VariableIdMapTable.VarIdConnections(newGuid2.Value, newObjGuid2.Value);
				foreach (DataRow row2 in array3)
				{
					if (row2.Field<int>("IdIndex") == num)
					{
						Guid guid3 = row2.Field<Guid>("IdGuid");
						DataRow row3 = base.Table.Rows.Find(guid3);
						DMSetValues(row3, new object[4] { "VariableId", newGuid.Value, "ObjectId", newObjGuid.Value });
					}
				}
			}
		}
	}
}
public class ImplementedConverterWrapper
{
	private ConverterImplementation _converter;

	private bool triedToInstance;

	public Type ConverterType { get; set; }

	public ConverterImplementation Converter
	{
		get
		{
			if (!triedToInstance)
			{
				_converter = (ConverterImplementation)Activator.CreateInstance(ConverterType);
				triedToInstance = true;
			}
			return _converter;
		}
	}
}
public class ImplementedConverterList : Dictionary<Guid, ImplementedConverterWrapper>
{
}
public delegate void MapChangedEventHandler(object sender, EventArgs e);
public class MapDataSet
{
	private class DMTableCreator : IAction
	{
		private MapDataSet Ds;

		private string Prefix;

		private string Name;

		public DMTableCreator(MapDataSet ds, string prefix, string name, out TableDescriptor tableDesc, out bool needToUndo)
		{
			needToUndo = false;
			tableDesc = ds.TableDesc(prefix);
			if (tableDesc == null)
			{
				Ds = ds;
				Name = name;
				Prefix = prefix;
				ReDo();
				tableDesc = ds.TableDesc(prefix);
				needToUndo = true;
			}
		}

		public void UnDo()
		{
			TableDescriptor tableDescriptor = Ds.TableDesc(Prefix);
			tableDescriptor.UnCreate();
			Ds.Tables.Remove(tableDescriptor);
		}

		public void ReDo()
		{
			TableDescriptor tableDescriptor = new TableDescriptor
			{
				Prefix = Prefix,
				Name = Name
			};
			Ds.Tables.Add(tableDescriptor);
			tableDescriptor.Create(Ds);
		}
	}

	private LocalClipboard _clipboard = new LocalClipboard();

	public static string ConverterFileName = "Ads.Converters";

	public string FileName;

	protected bool _isCaching = true;

	public DataSet Set { get; set; }

	public List<TableDescriptor> Tables { get; set; }

	public Dictionary<string, BaseTable> TablesByName { get; set; }

	public Converters ConvertersTable { get; set; }

	public ConverterArgs ConverterArgsTable { get; set; }

	public ConnectedConverters ConnectedConvertersTable { get; set; }

	public ConnectedConverterIdResolution ConnectedConverterIdResolutionTable { get; set; }

	public ConnectedConverterArgs ConnectedConverterArgsTable { get; set; }

	public LocalClipboard Clipboard => _clipboard;

	public bool Dirty => FileStartIndex != Undos.CurrentIndex;

	public UndoStack Undos { get; set; }

	public long FileStartIndex { get; set; }

	public bool IsCaching
	{
		get
		{
			return _isCaching;
		}
		set
		{
			_isCaching = value;
			foreach (TableDescriptor table in Tables)
			{
				table.IsCaching = value;
			}
			ConvertersTable.IsCaching = value;
			ConverterArgsTable.IsCaching = value;
			ConnectedConvertersTable.IsCaching = value;
			ConnectedConverterIdResolutionTable.IsCaching = value;
			ConnectedConverterArgsTable.IsCaching = value;
		}
	}

	public event MapChangedEventHandler MapChanged;

	public MapDataSet(ILogger log)
	{
		Undos = new UndoStack();
		Undos.MapChanged += Undos_MapChanged;
		Undos.Log = log;
		FileStartIndex = 0L;
		TablesByName = new Dictionary<string, BaseTable>();
		Tables = new List<TableDescriptor>();
		Set = new DataSet();
		ConvertersTable = new Converters(this);
		TablesByName.Add(Converters.TableName(), ConvertersTable);
		ConverterArgsTable = new ConverterArgs(this);
		TablesByName.Add(ConverterArgs.TableName(), ConverterArgsTable);
		ConnectedConvertersTable = new ConnectedConverters(this);
		TablesByName.Add(ConnectedConverters.TableName(), ConnectedConvertersTable);
		ConnectedConverterIdResolutionTable = new ConnectedConverterIdResolution(this);
		TablesByName.Add(ConnectedConverterIdResolution.TableName(), ConnectedConverterIdResolutionTable);
		ConnectedConverterArgsTable = new ConnectedConverterArgs(this);
		TablesByName.Add(ConnectedConverterArgs.TableName(), ConnectedConverterArgsTable);
	}

	public MapDataSet Clone()
	{
		MapDataSet mapDataSet = new MapDataSet(Undos.Log);
		foreach (TableDescriptor table in Tables)
		{
			mapDataSet.Tables.Add(new TableDescriptor(table, mapDataSet));
		}
		mapDataSet.ConvertersTable.FillFromOther(ConvertersTable);
		mapDataSet.ConverterArgsTable.FillFromOther(ConverterArgsTable);
		mapDataSet.ConnectedConvertersTable.FillFromOther(ConnectedConvertersTable);
		mapDataSet.ConnectedConverterIdResolutionTable.FillFromOther(ConnectedConverterIdResolutionTable);
		mapDataSet.ConnectedConverterArgsTable.FillFromOther(ConnectedConverterArgsTable);
		mapDataSet.IsCaching = true;
		return mapDataSet;
	}

	public void ClearTableDesc(string prefix)
	{
		TableDesc(prefix).ClearRows();
	}

	public void FixConnections(MapDataSet oldDs, string prefix)
	{
		ConnectedConvertersTable.CheckConnectedConvertersAfterUpdate(oldDs, prefix);
		TableDesc(prefix).IdTable.CheckVariableAfterRead(oldDs);
		PathToVarIDTable(prefix).FixPaths(oldDs);
	}

	public VariableObjectMap VariableObjectMapTable(string prefix)
	{
		VariableObjectMap result = null;
		TableDescriptor tableDescriptor = TableDesc(prefix);
		if (tableDescriptor != null)
		{
			result = tableDescriptor.VarObjTable;
		}
		return result;
	}

	public VariableIdMap VariableIdMapTable(string prefix)
	{
		VariableIdMap result = null;
		TableDescriptor tableDescriptor = TableDesc(prefix);
		if (tableDescriptor != null)
		{
			result = tableDescriptor.VarIdTable;
		}
		return result;
	}

	public Ids IdTable(string prefix)
	{
		Ids result = null;
		TableDescriptor tableDescriptor = TableDesc(prefix);
		if (tableDescriptor != null)
		{
			result = tableDescriptor.IdTable;
		}
		return result;
	}

	public PathToVariableIds PathToVarIDTable(string prefix)
	{
		PathToVariableIds result = null;
		TableDescriptor tableDescriptor = TableDesc(prefix);
		if (tableDescriptor != null)
		{
			result = tableDescriptor.PathToVarIdTable;
		}
		return result;
	}

	public Variables VariableTable(string prefix)
	{
		Variables result = null;
		TableDescriptor tableDescriptor = TableDesc(prefix);
		if (tableDescriptor != null)
		{
			result = tableDescriptor.VariableTable;
		}
		return result;
	}

	public Objects ObjectTable(string prefix)
	{
		Objects result = null;
		TableDescriptor tableDescriptor = TableDesc(prefix);
		if (tableDescriptor != null)
		{
			result = tableDescriptor.ObjectTable;
		}
		return result;
	}

	public static bool SetCanonicalMapTable(ref string left, ref string right)
	{
		bool result = false;
		if (string.Compare(left, right, ignoreCase: true) > 0)
		{
			result = true;
			string text = left;
			left = right;
			right = text;
		}
		return result;
	}

	public TableDescriptor TableDesc(string prefix)
	{
		TableDescriptor result = null;
		foreach (TableDescriptor table in Tables)
		{
			if (string.Compare(prefix, table.Prefix, ignoreCase: true) == 0)
			{
				result = table;
				break;
			}
		}
		return result;
	}

	private void Undos_MapChanged(object sender, EventArgs e)
	{
		RaiseMapChanged();
	}

	public void RaiseMapChanged()
	{
		if (this.MapChanged != null)
		{
			this.MapChanged(this, new EventArgs());
		}
	}

	public string CreateClassView(string prefix, string classViewName)
	{
		XDocument xDocument = new XDocument();
		XElement xElement = new XElement("AZClassLibrary");
		xElement.Add(new XAttribute("Name", classViewName));
		xElement.Add(new XAttribute("Format", "1"));
		xDocument.Add(xElement);
		XElement xElement2 = new XElement("Header");
		xElement.Add(xElement2);
		XElement xElement3 = new XElement("Version");
		xElement.Add(xElement3);
		xElement3.Add(new XAttribute("Major", "1"));
		xElement3.Add(new XAttribute("Minor", "0"));
		xElement2.Add(xElement3);
		XElement content = new XElement("Author", "Aspen Data Share");
		xElement2.Add(content);
		XElement content2 = new XElement("Comments", "AutoGenerated by Aspen Data Share Mapping Utility " + DateTime.Now.ToString());
		xElement2.Add(content2);
		Variables variables = VariableTable(prefix);
		Objects objects = ObjectTable(prefix);
		VariableObjectMap variableObjectMap = VariableObjectMapTable(prefix);
		foreach (DataRow row in objects.Table.Rows)
		{
			XElement xElement4 = new XElement("ClassView");
			xElement.Add(xElement4);
			xElement4.Add(new XAttribute("Name", row.Field<string>("Name")));
			Guid objGuid = row.Field<Guid>("Guid");
			xElement4.Add(new XAttribute("PrimaryGUID", objGuid.ToString("B").ToUpper()));
			xElement4.Add(new XAttribute("Visible", "1"));
			DataRowView[] array = variableObjectMap.FindForObject(objGuid);
			foreach (DataRowView dataRowView in array)
			{
				VariableRow variableRow = variables.Find(dataRowView.Row.Field<Guid>(variableObjectMap.variableCol));
				XElement xElement5 = new XElement("ClassViewAttribute");
				xElement4.Add(xElement5);
				xElement5.Add(new XAttribute("Name", variableRow.vName));
				xElement5.Add(new XAttribute("PrimaryGUID", variableRow.vGuid.ToString("B").ToUpper()));
				xElement5.Add(new XAttribute("Multiplicity", (variableRow.vNumids == 0) ? "1" : "n"));
				if (!variableRow.vReference.HasValue)
				{
					xElement5.Add(new XAttribute("Type", variableRow.vDataType));
					continue;
				}
				xElement5.Add(new XAttribute("Type", "Object"));
				string content3 = objects.Table.Rows.Find(variableRow.vReference).Field<string>("Name");
				xElement5.Add(new XElement("ClassViewName", content3));
			}
		}
		return xDocument.ToString();
	}

	public virtual TableDescriptor DMCreateTable(string prefix, string name)
	{
		TableDescriptor tableDesc = null;
		bool needToUndo;
		IAction action = new DMTableCreator(this, prefix, name, out tableDesc, out needToUndo);
		if (needToUndo)
		{
			Undos.Act(action);
		}
		return tableDesc;
	}

	protected bool CheckLink(VariableToLink left, VariableToLink right)
	{
		return true;
	}

	protected Guid VtoLVariable(VariableToLink vtol)
	{
		return vtol.Variable.Guid;
	}

	public string SaveDataSet(string directory, string outFileName = "AdsMap.apMap")
	{
		string result = null;
		string path = Path.Combine(directory, outFileName);
		try
		{
			using FileStream fileStream = new FileStream(path, FileMode.Create, FileAccess.ReadWrite);
			fileStream.WriteByte(167);
			using DeflateStream deflateStream = new DeflateStream(fileStream, CompressionMode.Compress, leaveOpen: false);
			XDocument xDocument = new XDocument();
			XElement xElement = new XElement("Tables");
			xDocument.Add(xElement);
			foreach (TableDescriptor table in Tables)
			{
				XElement xElement2 = new XElement("Table");
				xElement2.Add(new XAttribute("Prefix", table.Prefix));
				if (table.Name != null)
				{
					xElement2.Add(new XAttribute("Name", table.Name));
				}
				xElement.Add(xElement2);
			}
			string s = xDocument.ToString();
			byte[] bytes = Encoding.ASCII.GetBytes(s);
			int num = bytes.Length;
			byte[] bytes2 = BitConverter.GetBytes(num);
			deflateStream.Write(bytes2, 0, 4);
			deflateStream.Write(bytes, 0, num);
			Set.WriteXml((Stream)deflateStream);
			deflateStream.Flush();
			deflateStream.Close();
		}
		catch (Exception ex)
		{
			result = ex.Message;
		}
		return result;
	}

	public string SaveToXml(string directory)
	{
		string text = SaveDataSet(directory);
		if (text == null)
		{
			XDocument xDocument = new XDocument();
			XElement xElement = new XElement("AdsDataMap");
			xDocument.Add(xElement);
			XElement xElement2 = new XElement("LastSaved");
			xElement2.Value = DateTime.Now.ToString();
			xElement.Add(xElement2);
			XElement xElement3 = new XElement("TableDescriptors");
			xElement.Add(xElement3);
			foreach (TableDescriptor table in Tables)
			{
				xElement3.Add(table.Serialize());
			}
			try
			{
				xDocument.Save(Path.Combine(directory, "AdsDataMap.adsmap"));
				foreach (TableDescriptor table2 in Tables)
				{
					table2.Save(directory);
				}
				FileStartIndex = Undos.CurrentIndex;
				ConvertersTable.WriteToXml(directory);
				ConverterArgsTable.WriteToXml(directory);
				ConnectedConvertersTable.WriteToXml(directory);
				ConnectedConverterIdResolutionTable.WriteToXml(directory);
				ConnectedConverterArgsTable.WriteToXml(directory);
			}
			catch (Exception ex)
			{
				text = ex.Message;
			}
		}
		return text;
	}

	public bool ReadFromXml(string fullFileName, out string errMsg)
	{
		bool result = true;
		errMsg = null;
		string text = Path.GetExtension(fullFileName).ToUpper();
		string value = Path.GetExtension(ConverterFileName).ToUpper();
		if (text.Equals(".APMAP") || text.Equals(value))
		{
			try
			{
				using FileStream fileStream = new FileStream(fullFileName, FileMode.Open, FileAccess.Read);
				fileStream.ReadByte();
				using DeflateStream deflateStream = new DeflateStream(fileStream, CompressionMode.Decompress, leaveOpen: false);
				byte[] array = new byte[4];
				deflateStream.Read(array, 0, 4);
				int num = BitConverter.ToInt32(array, 0);
				byte[] array2 = new byte[num];
				deflateStream.Read(array2, 0, num);
				foreach (XElement item in XDocument.Parse(Encoding.ASCII.GetString(array2)).Element("Tables").Elements("Table"))
				{
					TableDescriptor tableDescriptor = new TableDescriptor(item);
					Tables.Add(tableDescriptor);
					tableDescriptor.Create(this);
				}
				Set.ReadXml((Stream)deflateStream);
				deflateStream.Close();
			}
			catch (Exception ex)
			{
				result = false;
				errMsg = ex.Message;
			}
		}
		else
		{
			string directoryName = Path.GetDirectoryName(fullFileName);
			string text2 = Path.Combine(directoryName, "AdsDataMap.adsmap");
			try
			{
				XElement xElement = XDocument.Load(text2).Element("AdsDataMap").Element("TableDescriptors");
				if (xElement != null)
				{
					foreach (XElement item2 in xElement.Elements("TableDescriptor"))
					{
						Tables.Add(new TableDescriptor(item2));
					}
				}
				foreach (TableDescriptor table in Tables)
				{
					table.Create(this);
					table.Restore(directoryName);
				}
				ConnectedConverterArgsTable.ClearSortCache();
				ConnectedConverterArgsTable.Table.Rows.Clear();
				ConnectedConverterIdResolutionTable.ClearSortCache();
				ConnectedConverterIdResolutionTable.Table.Rows.Clear();
				ConnectedConvertersTable.ClearSortCache();
				ConnectedConvertersTable.Table.Rows.Clear();
				ConverterArgsTable.ClearSortCache();
				ConverterArgsTable.Table.Rows.Clear();
				ConvertersTable.ClearSortCache();
				ConvertersTable.Table.Rows.Clear();
				ConvertersTable.ReadFromXml(directoryName);
				ConverterArgsTable.ReadFromXml(directoryName);
				ConnectedConvertersTable.ReadFromXml(directoryName);
				ConnectedConverterIdResolutionTable.ReadFromXml(directoryName);
				ConnectedConverterArgsTable.ReadFromXml(directoryName);
			}
			catch
			{
				result = false;
				errMsg = text2 + " is not a valid Ads Map save file";
			}
		}
		return result;
	}

	public DataRelation CreateRelation(string parentTableName, string childTableName, string childColumnName)
	{
		ForeignKeyConstraint foreignKeyConstraint = new ForeignKeyConstraint(childColumnName + "FKC", Set.Tables[parentTableName].Columns["Guid"], Set.Tables[childTableName].Columns[childColumnName]);
		foreignKeyConstraint.UpdateRule = Rule.Cascade;
		Set.Tables[childTableName].Constraints.Add(foreignKeyConstraint);
		DataRelation dataRelation = new DataRelation(parentTableName + childTableName + childColumnName + "Rel", Set.Tables[parentTableName].Columns["Guid"], Set.Tables[childTableName].Columns[childColumnName]);
		Set.Relations.Add(dataRelation);
		return dataRelation;
	}

	public void RemoveRelation(string parentTableName, string childTableName, string childColumnName)
	{
		Set.Relations.Remove(parentTableName + childTableName + childColumnName + "Rel");
		Set.Tables[childTableName].Constraints.Remove(childColumnName + "FKC");
	}

	public string SaveConnectorsDataSet(string path)
	{
		string text = null;
		MapDataSet mapDataSet = new MapDataSet(null);
		foreach (TableDescriptor table in Tables)
		{
			TableDescriptor tableDescriptor = new TableDescriptor
			{
				Name = table.Name,
				Prefix = table.Prefix
			};
			mapDataSet.Tables.Add(tableDescriptor);
			tableDescriptor.Create(mapDataSet);
		}
		foreach (KeyValuePair<string, BaseTable> item in TablesByName)
		{
			item.Value.AssignChild(mapDataSet.TablesByName[item.Key]);
		}
		mapDataSet.IsCaching = false;
		ConnectedConvertersTable.CopyConnectedConvertersToChild();
		text = mapDataSet.SaveDataSet(path, ConverterFileName);
		foreach (BaseTable value in TablesByName.Values)
		{
			value.ReleaseChild();
		}
		return text;
	}
}
public class VariableToLink
{
	public VariableDescriptor Variable { get; set; }

	public string Prefix { get; set; }

	public Guid ObjGuid { get; set; }

	public string NamePath { get; set; }

	public IdDescriptor[] Ids { get; set; }

	public int OneBasedLinkIDNumber { get; set; }

	public List<Guid> VariableGuidPath { get; set; }
}
public class LocalClipboard
{
	private Dictionary<string, object> _clipboard = new Dictionary<string, object>();

	public bool ContainsData(string key)
	{
		return _clipboard.Keys.Contains(key);
	}

	public object GetData(string key)
	{
		object result = null;
		if (_clipboard.TryGetValue(key, out var value))
		{
			result = value;
		}
		return result;
	}

	public void SetData(string key, object value)
	{
		_clipboard[key] = value;
	}

	public void Clear()
	{
		_clipboard.Clear();
	}
}
public class BaseTable
{
	private class DMValueSetter : IAction
	{
		private MapDataSet DS;

		private string TableName;

		private object[] RowPrimaryKey;

		private object[] ColumnNaneValPairs;

		public DMValueSetter(BaseTable btable, DataRow row, object[] columnNaneValPairs, out bool changed)
		{
			TableName = btable.DsTableName;
			DS = btable.DS;
			ColumnNaneValPairs = (object[])columnNaneValPairs.Clone();
			RowPrimaryKey = btable.GetPrimaryKey(row);
			changed = false;
			btable.ClearSortCache();
			for (int i = 0; i < ColumnNaneValPairs.Length; i += 2)
			{
				changed |= SetValueIfChanged(row, (string)ColumnNaneValPairs[i], ref ColumnNaneValPairs[i + 1]);
			}
		}

		public void UnDo()
		{
			BaseTable baseTable = DS.TablesByName[TableName];
			DataRow row = baseTable.Table.Rows.Find(RowPrimaryKey);
			baseTable.ClearSortCache();
			for (int i = 0; i < ColumnNaneValPairs.Length; i += 2)
			{
				SetValueIfChanged(row, (string)ColumnNaneValPairs[i], ref ColumnNaneValPairs[i + 1]);
			}
		}

		public void ReDo()
		{
			UnDo();
		}
	}

	private class DMRowRemover : IAction
	{
		private MapDataSet DS;

		private string TableName;

		private object[] RowPrimaryKey;

		private object[] _items;

		public DMRowRemover(BaseTable btable, DataRow row)
		{
			TableName = btable.DsTableName;
			DS = btable.DS;
			RowPrimaryKey = btable.GetPrimaryKey(row);
			_items = row.ItemArray;
			btable.Table.Rows.Remove(row);
		}

		public void UnDo()
		{
			DataTable table = DS.TablesByName[TableName].Table;
			DataRow dataRow = table.NewRow();
			dataRow.ItemArray = _items;
			table.Rows.Add(dataRow);
		}

		public void ReDo()
		{
			DataTable table = DS.TablesByName[TableName].Table;
			DataRow row = table.Rows.Find(RowPrimaryKey);
			table.Rows.Remove(row);
		}
	}

	private class DMRowAdder : IAction
	{
		private MapDataSet DS;

		private string TableName;

		private object[] RowPrimaryKey;

		private object[] ColumnNaneValPairs;

		public DMRowAdder(BaseTable btable, object[] columnNaneValPairs, out DataRow newRow)
		{
			TableName = btable.DsTableName;
			DS = btable.DS;
			ColumnNaneValPairs = (object[])columnNaneValPairs.Clone();
			btable.ClearSortCache();
			newRow = btable.Table.NewRow();
			for (int i = 0; i < columnNaneValPairs.Length; i += 2)
			{
				SetValue(newRow, (string)columnNaneValPairs[i], columnNaneValPairs[i + 1]);
			}
			btable.Table.Rows.Add(newRow);
			RowPrimaryKey = btable.GetPrimaryKey(newRow);
		}

		public void UnDo()
		{
			BaseTable baseTable = DS.TablesByName[TableName];
			DataTable table = baseTable.Table;
			DataRow dataRow = table.Rows.Find(RowPrimaryKey);
			baseTable.ClearSortCache();
			if (dataRow != null)
			{
				table.Rows.Remove(dataRow);
				return;
			}
			throw new Exception("Undo error.  Row does not exist");
		}

		public void ReDo()
		{
			BaseTable baseTable = DS.TablesByName[TableName];
			DataTable table = baseTable.Table;
			baseTable.ClearSortCache();
			DataRow row = table.NewRow();
			for (int i = 0; i < ColumnNaneValPairs.Length; i += 2)
			{
				SetValue(row, (string)ColumnNaneValPairs[i], ColumnNaneValPairs[i + 1]);
			}
			table.Rows.Add(row);
		}
	}

	public bool IsCaching = true;

	protected BaseTable _childForConverterTransfer;

	public DataTable Table { get; set; }

	public MapDataSet DS { get; set; }

	public string Prefix { get; set; }

	public string DsTableName { get; set; }

	public DM Dm { get; set; }

	public BaseTable(MapDataSet ds, string prefix)
	{
		Prefix = prefix;
		DS = ds;
		Dm = new DM(Prefix, DS);
	}

	public void FillFromOther(BaseTable other)
	{
		foreach (DataRow row in other.Table.Rows)
		{
			Table.ImportRow(row);
		}
	}

	public void Clear()
	{
		DataRow[] array = new DataRow[Table.Rows.Count];
		Table.Rows.CopyTo(array, 0);
		DataRow[] array2 = array;
		foreach (DataRow row in array2)
		{
			DMRemoveRow(row);
		}
	}

	public string FileName(string directory)
	{
		return Path.Combine(directory, Table.TableName) + ".xml";
	}

	public virtual void ClearSortCache()
	{
	}

	public void WriteToXml(string directory)
	{
		using FileStream stream = new FileStream(FileName(directory), FileMode.Create, FileAccess.ReadWrite);
		using StreamWriter streamWriter = new StreamWriter(stream);
		streamWriter.WriteLine("<?xml version=\"1.0\" standalone=\"yes\"?>");
		streamWriter.WriteLine("<NewDataSet>");
		foreach (DataRow row in Table.Rows)
		{
			streamWriter.Write("<" + Table.TableName + ">");
			foreach (DataColumn column in Table.Columns)
			{
				if (!row.IsNull(column))
				{
					string text = ((!(column.DataType == typeof(bool))) ? row[column].ToString() : (row.Field<bool>(column) ? "true" : "false"));
					text = text.Replace("&", "&amp;");
					text = text.Replace("<", "&lt;");
					streamWriter.Write("<" + column.ColumnName + ">" + text + "</" + column.ColumnName + ">");
				}
			}
			streamWriter.WriteLine("</" + Table.TableName + ">");
		}
		streamWriter.WriteLine("</NewDataSet>");
		streamWriter.Flush();
	}

	public void ReadFromXml(string directory)
	{
		string text = FileName(directory);
		if (File.Exists(text))
		{
			Table.ReadXml(text);
		}
	}

	public virtual void Remove()
	{
		DS.Set.Tables.Remove(Table);
	}

	protected virtual object[] GetPrimaryKey(DataRow row)
	{
		object[] array = null;
		DataColumn[] primaryKey = Table.PrimaryKey;
		if (primaryKey != null)
		{
			array = new object[primaryKey.Length];
			int num = 0;
			DataColumn[] array2 = primaryKey;
			foreach (DataColumn column in array2)
			{
				array[num++] = row[column];
			}
			return array;
		}
		throw new Exception("All DM tables must have primary key");
	}

	public static void SetValue(DataRow row, string name, object value)
	{
		if (value == null)
		{
			row[name] = DBNull.Value;
		}
		else
		{
			row[name] = value;
		}
	}

	public static bool SetValueIfChanged(DataRow row, string name, ref object value)
	{
		bool flag = false;
		object obj = value;
		if (row.IsNull(name))
		{
			if (value != null)
			{
				obj = null;
				row[name] = value;
				flag = true;
			}
		}
		else if (value != null)
		{
			if (!value.Equals(row[name]))
			{
				flag = true;
				obj = row[name];
				row[name] = value;
			}
		}
		else
		{
			flag = true;
			obj = row[name];
			row[name] = DBNull.Value;
		}
		if (flag)
		{
			value = obj;
		}
		return flag;
	}

	public virtual void CopyRowToChild(DataRow row)
	{
		if (_childForConverterTransfer != null)
		{
			object[] primaryKey = GetPrimaryKey(row);
			if (_childForConverterTransfer.Table.Rows.Find(primaryKey) == null)
			{
				object[] itemArray = row.ItemArray;
				DataRow dataRow = _childForConverterTransfer.Table.NewRow();
				dataRow.ItemArray = itemArray;
				_childForConverterTransfer.Table.Rows.Add(dataRow);
			}
		}
	}

	public void AssignChild(BaseTable childTable)
	{
		_childForConverterTransfer = childTable;
	}

	public void ReleaseChild()
	{
		_childForConverterTransfer = null;
	}

	public virtual bool DMSetIFNotNull(DataRow row, object[] columnNameValSetIfNullTriples)
	{
		bool result = false;
		object[] array = new object[columnNameValSetIfNullTriples.Length / 3 * 2];
		int num = 0;
		for (int i = 0; i < columnNameValSetIfNullTriples.Length; i += 3)
		{
			if ((bool)columnNameValSetIfNullTriples[i + 2] || columnNameValSetIfNullTriples[i + 1] != null)
			{
				array[num] = columnNameValSetIfNullTriples[i];
				array[num + 1] = columnNameValSetIfNullTriples[i + 1];
				num += 2;
			}
		}
		if (num > 0)
		{
			if (num < array.Length)
			{
				Array.Resize(ref array, num);
			}
			result = DMSetValues(row, array);
		}
		return result;
	}

	public virtual bool DMSetValue(DataRow row, string name, object value)
	{
		return DMSetValues(row, new object[2] { name, value });
	}

	public virtual bool DMSetValues(DataRow row, object[] columnNaneValPairs)
	{
		bool changed = false;
		IAction action = new DMValueSetter(this, row, columnNaneValPairs, out changed);
		if (changed)
		{
			DS.Undos.Act(action);
		}
		return changed;
	}

	public virtual void DMRemoveRow(DataRow row)
	{
		IAction action = new DMRowRemover(this, row);
		DS.Undos.Act(action);
	}

	public virtual DataRow DMAddRow(object[] columnNaneValPairs)
	{
		DataRow newRow;
		IAction action = new DMRowAdder(this, columnNaneValPairs, out newRow);
		DS.Undos.Act(action);
		return newRow;
	}
}
public class ObjectRow
{
	protected Objects _table { get; set; }

	public DataRow Row { get; set; }

	public Guid vGuid => Row.Field<Guid>(_table.guidCol);

	public string vName
	{
		get
		{
			if (!Row.IsNull(_table.nameCol))
			{
				return Row.Field<string>(_table.nameCol);
			}
			return null;
		}
	}

	public string vDescription
	{
		get
		{
			if (!Row.IsNull(_table.descCol))
			{
				return Row.Field<string>(_table.descCol);
			}
			return null;
		}
	}

	public Guid? vParent
	{
		get
		{
			if (!Row.IsNull(_table.parentCol))
			{
				return Row.Field<Guid>(_table.parentCol);
			}
			return null;
		}
	}

	public ObjectRow(Objects vtable, DataRow row)
	{
		_table = vtable;
		Row = row;
	}
}
public class Objects : BaseTable
{
	private DataView _sortedByParent;

	private DataView _sortedByName;

	public ForeignKeyConstraint ObjectToParentFK { get; set; }

	public DataColumn guidCol { get; set; }

	public DataColumn nameCol { get; set; }

	public DataColumn descCol { get; set; }

	public DataColumn parentCol { get; set; }

	private DataView SortedByParent
	{
		get
		{
			if (_sortedByParent == null)
			{
				_sortedByParent = new DataView(base.Table);
				_sortedByParent.Sort = parentCol.ColumnName;
			}
			return _sortedByParent;
		}
	}

	private DataView SortedByName
	{
		get
		{
			if (_sortedByName == null)
			{
				_sortedByName = new DataView(base.Table);
				_sortedByName.Sort = nameCol.ColumnName;
			}
			return _sortedByName;
		}
	}

	public Objects(MapDataSet ds, string tableNamePrefix)
		: base(ds, tableNamePrefix)
	{
		base.Table = new DataTable(base.DsTableName = TableName(tableNamePrefix));
		guidCol = new DataColumn("Guid", typeof(Guid));
		base.Table.Columns.Add(guidCol);
		nameCol = new DataColumn("Name", typeof(string));
		base.Table.Columns.Add(nameCol);
		descCol = new DataColumn("Description", typeof(string));
		base.Table.Columns.Add(descCol);
		parentCol = new DataColumn("Parent", typeof(Guid));
		base.Table.Columns.Add(parentCol);
		base.Table.PrimaryKey = new DataColumn[1] { guidCol };
		ds.Set.Tables.Add(base.Table);
	}

	public override void Remove()
	{
		base.Remove();
	}

	public static string TableName(string prefix)
	{
		return prefix + "Objects";
	}

	public ObjectRow Find(Guid guid)
	{
		ObjectRow result = null;
		DataRow dataRow = base.Table.Rows.Find(guid);
		if (dataRow != null)
		{
			result = new ObjectRow(this, dataRow);
		}
		return result;
	}

	public IEnumerable<DataRow> Children(Guid obj)
	{
		if (IsCaching)
		{
			DataRowView[] array = SortedByParent.FindRows(obj);
			DataRowView[] array2 = array;
			foreach (DataRowView dataRowView in array2)
			{
				yield return dataRowView.Row;
			}
			yield break;
		}
		EnumerableRowCollection<DataRow> enumerableRowCollection = from DataRow rv in base.Table.AsEnumerable()
			where rv.Field<Guid>(parentCol).Equals(obj)
			select rv;
		foreach (DataRow item in enumerableRowCollection)
		{
			yield return item;
		}
	}

	public override void ClearSortCache()
	{
		_sortedByParent = null;
		_sortedByName = null;
		base.ClearSortCache();
	}

	public ObjectRow FindRowByName(string name)
	{
		ObjectRow result = null;
		if (IsCaching)
		{
			int num = SortedByName.Find(name);
			if (num >= 0)
			{
				result = new ObjectRow(this, SortedByName[num].Row);
			}
		}
		else
		{
			foreach (DataRow row in base.Table.Rows)
			{
				if (!row.IsNull("Name") && row.Field<string>("Name").Equals(name, StringComparison.InvariantCultureIgnoreCase))
				{
					result = new ObjectRow(this, row);
					break;
				}
			}
		}
		return result;
	}

	protected Stack<Guid> AncestorsRecurse(Guid objectGuid)
	{
		Stack<Guid> stack = null;
		DataRow dataRow = base.Table.Rows.Find(objectGuid);
		if (dataRow != null)
		{
			stack = ((!dataRow.IsNull("Parent")) ? AncestorsRecurse(dataRow.Field<Guid>("Parent")) : new Stack<Guid>());
			stack.Push(objectGuid);
		}
		return stack;
	}

	public Guid[] Ancestors(Guid objectGuid)
	{
		Guid[] result = null;
		Stack<Guid> stack = AncestorsRecurse(objectGuid);
		if (stack != null)
		{
			result = stack.ToArray();
		}
		return result;
	}

	public bool InheritsFrom(Guid child, Guid ancestor)
	{
		bool flag = false;
		if (child.Equals(ancestor))
		{
			flag = true;
		}
		else
		{
			DataRow dataRow = base.Table.Rows.Find(child);
			while (!flag && dataRow != null && !dataRow.IsNull("Parent"))
			{
				child = dataRow.Field<Guid>("Parent");
				if (child.Equals(ancestor))
				{
					flag = true;
				}
				dataRow = base.Table.Rows.Find(child);
			}
		}
		return flag;
	}

	internal void CopyObjectToChild(Guid obj, bool copyParent = true)
	{
		DataRow dataRow = base.Table.Rows.Find(obj);
		if (copyParent && !dataRow.IsNull(parentCol))
		{
			CopyObjectToChild(dataRow.Field<Guid>(parentCol));
		}
		CopyRowToChild(dataRow);
		foreach (DataRow item in Children(obj))
		{
			CopyObjectToChild(item.Field<Guid>(guidCol), copyParent: false);
		}
	}

	public Guid? FindObjectWithGuid(Objects oldTable, Guid guid)
	{
		Guid? result = null;
		if (base.Table.Rows.Find(guid) != null)
		{
			result = guid;
		}
		else
		{
			DataRow dataRow = oldTable.Table.Rows.Find(guid);
			if (dataRow != null)
			{
				ObjectRow objectRow = FindRowByName(dataRow.Field<string>("Name"));
				if (objectRow != null)
				{
					result = objectRow.vGuid;
				}
			}
		}
		return result;
	}
}
public class PathToVariableIdRow
{
	protected PathToVariableIds _table { get; set; }

	public DataRow Row { get; protected set; }

	public Guid vGuid => Row.Field<Guid>(_table.guidCol);

	public Guid vVariableGuid
	{
		get
		{
			if (!Row.IsNull(_table.variableGuidCol))
			{
				return Row.Field<Guid>(_table.variableGuidCol);
			}
			return Guid.Empty;
		}
	}

	public Guid vObjectGuid
	{
		get
		{
			if (!Row.IsNull(_table.objectGuidCol))
			{
				return Row.Field<Guid>(_table.objectGuidCol);
			}
			return Guid.Empty;
		}
	}

	public int? vVariableIdNumber
	{
		get
		{
			if (!Row.IsNull(_table.variableIdNumberCol))
			{
				return Row.Field<int>(_table.variableIdNumberCol);
			}
			return null;
		}
	}

	public Guid vPathGuid
	{
		get
		{
			if (!Row.IsNull(_table.pathGuidCol))
			{
				return Row.Field<Guid>(_table.pathGuidCol);
			}
			return Guid.Empty;
		}
	}

	public Guid vPathObjGuid
	{
		get
		{
			if (!Row.IsNull(_table.pathObjGuidCol))
			{
				return Row.Field<Guid>(_table.pathObjGuidCol);
			}
			return Guid.Empty;
		}
	}

	public int? vPathElementNumber
	{
		get
		{
			if (!Row.IsNull(_table.elementNumberCol))
			{
				return Row.Field<int>(_table.elementNumberCol);
			}
			return null;
		}
	}

	public PathToVariableIdRow(PathToVariableIds vtable, DataRow row)
	{
		_table = vtable;
		Row = row;
	}
}
public class PathToVariableIds : BaseTable
{
	private class IndexAndOV : IComparable<IndexAndOV>
	{
		public int Index;

		public ObjectVariablePair OV;

		public IndexAndOV(int index, Guid obj, Guid var)
		{
			Index = index;
			OV = new ObjectVariablePair(obj, var);
		}

		public IndexAndOV(int index, ObjectVariablePair ov)
		{
			Index = index;
			OV = ov;
		}

		public int CompareTo(IndexAndOV other)
		{
			int num = Index.CompareTo(other.Index);
			if (num == 0)
			{
				num = OV.CompareTo(other.OV);
			}
			return num;
		}
	}

	private class OVAndPath : IComparable<OVAndPath>
	{
		public IndexAndOV IdIOV;

		public ObjectVariablePair NewOV;

		public List<IndexAndOV> Path = new List<IndexAndOV>();

		public bool AddToNew = true;

		public int CompareTo(OVAndPath other)
		{
			return IdIOV.CompareTo(other.IdIOV);
		}
	}

	private DataView _sortedByObjectVariable;

	private DataView _sortedByVariableAndId;

	public DataColumn guidCol { get; set; }

	public DataColumn variableGuidCol { get; set; }

	public DataColumn objectGuidCol { get; set; }

	public DataColumn variableIdNumberCol { get; set; }

	public DataColumn pathGuidCol { get; set; }

	public DataColumn pathObjGuidCol { get; set; }

	public DataColumn elementNumberCol { get; set; }

	private DataView SortedByObjectVariable
	{
		get
		{
			if (_sortedByObjectVariable == null)
			{
				_sortedByObjectVariable = new DataView(base.Table);
				_sortedByObjectVariable.Sort = "ObjectGuid, VariableGuid";
			}
			return _sortedByObjectVariable;
		}
	}

	private DataView SortedByVariableAndId
	{
		get
		{
			if (_sortedByVariableAndId == null)
			{
				_sortedByVariableAndId = new DataView(base.Table);
				_sortedByVariableAndId.Sort = "ObjectGuid, VariableGuid, VariableIdNumber";
			}
			return _sortedByVariableAndId;
		}
	}

	public PathToVariableIds(MapDataSet ds, string tableNamePrefix)
		: base(ds, tableNamePrefix)
	{
		base.Table = new DataTable(base.DsTableName = TableName(tableNamePrefix));
		guidCol = new DataColumn("Guid", typeof(Guid));
		base.Table.Columns.Add(guidCol);
		variableGuidCol = new DataColumn("VariableGuid", typeof(Guid));
		base.Table.Columns.Add(variableGuidCol);
		objectGuidCol = new DataColumn("ObjectGuid", typeof(Guid));
		base.Table.Columns.Add(objectGuidCol);
		variableIdNumberCol = new DataColumn("VariableIdNumber", typeof(int));
		base.Table.Columns.Add(variableIdNumberCol);
		pathGuidCol = new DataColumn("PathVariableGuid", typeof(Guid));
		base.Table.Columns.Add(pathGuidCol);
		pathObjGuidCol = new DataColumn("PathObjectGuid", typeof(Guid));
		base.Table.Columns.Add(pathObjGuidCol);
		elementNumberCol = new DataColumn("ElementNumber", typeof(int));
		base.Table.Columns.Add(elementNumberCol);
		base.Table.PrimaryKey = new DataColumn[1] { guidCol };
		ds.Set.Tables.Add(base.Table);
	}

	public override void Remove()
	{
		base.Remove();
	}

	public static string TableName(string prefix)
	{
		return prefix + "PathToVariableIds";
	}

	public PathToVariableIdRow Find(Guid guid)
	{
		PathToVariableIdRow result = null;
		DataRow dataRow = base.Table.Rows.Find(guid);
		if (dataRow != null)
		{
			result = new PathToVariableIdRow(this, dataRow);
		}
		return result;
	}

	public override void ClearSortCache()
	{
		_sortedByObjectVariable = null;
		_sortedByVariableAndId = null;
		base.ClearSortCache();
	}

	public IEnumerable<PathToVariableIdRow> ByVariableAndId(Guid oguid, Guid vguid, int idNumber = 0)
	{
		if (IsCaching)
		{
			DataRowView[] array = SortedByVariableAndId.FindRows(new object[3] { oguid, vguid, idNumber });
			DataRowView[] array2 = array;
			foreach (DataRowView dataRowView in array2)
			{
				yield return new PathToVariableIdRow(this, dataRowView.Row);
			}
			yield break;
		}
		EnumerableRowCollection<DataRow> enumerableRowCollection = from DataRow row in base.Table.AsEnumerable()
			where vguid.Equals(row.Field<Guid>("VariableGuid")) && oguid.Equals(row.Field<Guid>("ObjectGuid")) && ((!row.IsNull("VariableIdNumber")) ? (idNumber == row.Field<int>("VariableIdNumber")) : (idNumber == 0))
			select row;
		foreach (DataRow item in enumerableRowCollection)
		{
			yield return new PathToVariableIdRow(this, item);
		}
	}

	public IEnumerable<PathToVariableIdRow> ByVariable(Guid oguid, Guid vguid)
	{
		if (IsCaching)
		{
			DataRowView[] array = SortedByObjectVariable.FindRows(new object[2] { oguid, vguid });
			DataRowView[] array2 = array;
			foreach (DataRowView dataRowView in array2)
			{
				yield return new PathToVariableIdRow(this, dataRowView.Row);
			}
			yield break;
		}
		EnumerableRowCollection<DataRow> enumerableRowCollection = from DataRow row in base.Table.AsEnumerable()
			where vguid.Equals(row.Field<Guid>("VariableGuid")) && oguid.Equals(row.Field<Guid>("ObjectGuid"))
			select row;
		foreach (DataRow item in enumerableRowCollection)
		{
			yield return new PathToVariableIdRow(this, item);
		}
	}

	public ObjectVariablePair[] PathToId(Guid parentObj, Guid parentVar, int idNumber = 0)
	{
		ObjectVariablePair[] array = null;
		IEnumerable<PathToVariableIdRow> enumerable = ByVariableAndId(parentObj, parentVar, idNumber);
		if (enumerable.Any())
		{
			array = new ObjectVariablePair[enumerable.Count()];
			foreach (PathToVariableIdRow item in enumerable)
			{
				array[item.vPathElementNumber.Value] = new ObjectVariablePair(item.vPathObjGuid, item.vPathGuid);
			}
		}
		return array;
	}

	public void RemoveVariable(Guid objGuid, Guid varGuid)
	{
		List<ObjectVariablePair> list = new List<ObjectVariablePair>();
		list.Add(new ObjectVariablePair(objGuid, varGuid));
		foreach (DataRow row in base.Table.Rows)
		{
			if (row.RowVal<Guid>("PathVariableGuid").Equals(varGuid) && row.RowVal<Guid>("PathObjectGuid").Equals(objGuid))
			{
				list.Add(new ObjectVariablePair(row.RowVal<Guid>("VariableGuid"), row.RowVal<Guid>("ObjecteGuid")));
			}
		}
		List<DataRow> list2 = new List<DataRow>();
		foreach (ObjectVariablePair item in list)
		{
			DataRowView[] array = SortedByObjectVariable.FindRows(item.Key);
			foreach (DataRowView dataRowView in array)
			{
				list2.Add(dataRowView.Row);
			}
		}
		if (!list2.Any())
		{
			return;
		}
		base.Dm.Ds.Undos.StartUndoable("Removing Id paths for variable");
		foreach (DataRow item2 in list2)
		{
			DMRemoveRow(item2);
		}
		base.Dm.Ds.Undos.FinishUndoable();
	}

	public void FixPaths(MapDataSet oldDs)
	{
		List<OVAndPath> list = new List<OVAndPath>();
		foreach (DataRow row in oldDs.PathToVarIDTable(base.Prefix).Table.Rows)
		{
			IndexAndOV indexAndOV = new IndexAndOV(row.Field<int>("VariableIdNumber"), row.Field<Guid>("ObjectGuid"), row.Field<Guid>("VariableGuid"));
			OVAndPath oVAndPath = new OVAndPath
			{
				IdIOV = indexAndOV
			};
			int num = list.BinarySearch(oVAndPath);
			if (num < 0)
			{
				list.Insert(~num, oVAndPath);
				ObjectVariablePair objectVariablePair = base.Dm.VariableTable.FindNewOV(oldDs, indexAndOV.OV);
				if (objectVariablePair == null)
				{
					oVAndPath.AddToNew = false;
				}
				else
				{
					oVAndPath.NewOV = objectVariablePair;
				}
			}
			else
			{
				oVAndPath = list[num];
			}
			if (oVAndPath.AddToNew)
			{
				ObjectVariablePair oldOV = new ObjectVariablePair(row.Field<Guid>("PathObjectGuid"), row.Field<Guid>("PathVariableGuid"));
				ObjectVariablePair objectVariablePair2 = base.Dm.VariableTable.FindNewOV(oldDs, oldOV);
				if (objectVariablePair2 == null)
				{
					oVAndPath.AddToNew = false;
				}
				else
				{
					oVAndPath.Path.Add(new IndexAndOV(row.Field<int>("ElementNumber"), objectVariablePair2));
				}
			}
		}
		foreach (OVAndPath item in list)
		{
			if (!item.AddToNew)
			{
				continue;
			}
			foreach (IndexAndOV item2 in item.Path)
			{
				DMAddRow(new object[14]
				{
					"Guid",
					Guid.NewGuid(),
					"VariableGuid",
					item.NewOV.Var,
					"ObjectGuid",
					item.NewOV.Obj,
					"VariableIdNumber",
					item.IdIOV.Index,
					"PathVariableGuid",
					item2.OV.Var,
					"PathObjectGuid",
					item2.OV.Obj,
					"ElementNumber",
					item2.Index
				});
			}
		}
	}
}
public class TableDescriptor
{
	protected bool _isCaching;

	public bool IsCaching
	{
		get
		{
			return _isCaching;
		}
		set
		{
			_isCaching = value;
			ObjectTable.IsCaching = value;
			VariableTable.IsCaching = value;
			IdTable.IsCaching = value;
			VarIdTable.IsCaching = value;
			VarObjTable.IsCaching = value;
			PathToVarIdTable.IsCaching = value;
		}
	}

	protected MapDataSet DS { get; set; }

	public string Prefix { get; set; }

	public string Name { get; set; }

	public Objects ObjectTable { get; set; }

	public Variables VariableTable { get; set; }

	public Ids IdTable { get; set; }

	public VariableIdMap VarIdTable { get; set; }

	public VariableObjectMap VarObjTable { get; set; }

	public PathToVariableIds PathToVarIdTable { get; set; }

	public TableDescriptor()
	{
	}

	public TableDescriptor(XElement elem)
	{
		XAttribute xAttribute = elem.Attribute("Prefix");
		if (xAttribute != null)
		{
			Prefix = xAttribute.Value;
		}
		XAttribute xAttribute2 = elem.Attribute("Name");
		if (xAttribute2 != null)
		{
			Name = xAttribute2.Value;
		}
	}

	public TableDescriptor(TableDescriptor other, MapDataSet ds)
	{
		_isCaching = false;
		Prefix = other.Prefix;
		Name = other.Name;
		Create(ds);
		CatalogTables(DS.TablesByName);
		ObjectTable.FillFromOther(other.ObjectTable);
		VariableTable.FillFromOther(other.VariableTable);
		IdTable.FillFromOther(other.IdTable);
		VarIdTable.FillFromOther(other.VarIdTable);
		VarObjTable.FillFromOther(other.VarObjTable);
		PathToVarIdTable.FillFromOther(other.PathToVarIdTable);
	}

	public void ClearRows()
	{
		PathToVarIdTable.Clear();
		VarObjTable.Clear();
		VarIdTable.Clear();
		IdTable.Clear();
		VariableTable.Clear();
		ObjectTable.Clear();
	}

	public void CatalogTables(Dictionary<string, BaseTable> tableDict)
	{
		tableDict[ObjectTable.DsTableName] = ObjectTable;
		tableDict[VariableTable.DsTableName] = VariableTable;
		tableDict[IdTable.DsTableName] = IdTable;
		tableDict[VarIdTable.DsTableName] = VarIdTable;
		tableDict[VarObjTable.DsTableName] = VarObjTable;
		tableDict[PathToVarIdTable.DsTableName] = PathToVarIdTable;
	}

	public void UnCatalogTables(Dictionary<string, BaseTable> tableDict)
	{
		tableDict.Remove(ObjectTable.DsTableName);
		tableDict.Remove(VariableTable.DsTableName);
		tableDict.Remove(IdTable.DsTableName);
		tableDict.Remove(VarIdTable.DsTableName);
		tableDict.Remove(VarObjTable.DsTableName);
		tableDict.Remove(PathToVarIdTable.DsTableName);
	}

	public void Create(MapDataSet ds)
	{
		DS = ds;
		ObjectTable = new Objects(ds, Prefix);
		VariableTable = new Variables(ds, Prefix);
		IdTable = new Ids(ds, Prefix);
		VarIdTable = new VariableIdMap(ds, Prefix);
		VarObjTable = new VariableObjectMap(ds, Prefix);
		PathToVarIdTable = new PathToVariableIds(ds, Prefix);
		CatalogTables(DS.TablesByName);
	}

	public void UnCreate()
	{
		UnCatalogTables(DS.TablesByName);
		PathToVarIdTable.Remove();
		VarObjTable.Remove();
		VarIdTable.Remove();
		IdTable.Remove();
		VariableTable.Remove();
		ObjectTable.Remove();
	}

	public void Save(string directory)
	{
		PathToVarIdTable.WriteToXml(directory);
		ObjectTable.WriteToXml(directory);
		VariableTable.WriteToXml(directory);
		IdTable.WriteToXml(directory);
		VarIdTable.WriteToXml(directory);
		VarObjTable.WriteToXml(directory);
	}

	public void Restore(string directory)
	{
		PathToVarIdTable.ReadFromXml(directory);
		ObjectTable.ReadFromXml(directory);
		VariableTable.ReadFromXml(directory);
		IdTable.ReadFromXml(directory);
		VarIdTable.ReadFromXml(directory);
		VarObjTable.ReadFromXml(directory);
		VarIdTable.AddObjectGuids();
		CatalogTables(DS.TablesByName);
	}

	public XElement Serialize()
	{
		XElement xElement = new XElement("TableDescriptor");
		xElement.Add(new XAttribute("Prefix", Prefix));
		if (Name != null)
		{
			xElement.Add(new XAttribute("Name", Name));
		}
		return xElement;
	}
}
public interface ILogger
{
	void LogMessageLine(string message);

	void LogMessage(string message);
}
public interface IAction
{
	void UnDo();

	void ReDo();
}
public class Undoable
{
	public enum StatusEnum
	{
		Building,
		Done,
		Undone,
		Undoing,
		Redoing
	}

	public int NestedDepth;

	private Stack<IAction> Actions { get; set; }

	private IAction[] ClosedActions { get; set; }

	public string Description { get; set; }

	public long index { get; set; }

	public StatusEnum Status { get; set; }

	public Undoable(string description, long index)
	{
		Status = StatusEnum.Building;
		Description = description;
		Actions = new Stack<IAction>();
	}

	public void AddAction(IAction action)
	{
		if (Status == StatusEnum.Building)
		{
			Actions.Push(action);
			return;
		}
		throw new Exception("Undo stack error.  Adding Action to closed Undoable");
	}

	public void Finish()
	{
		if (Status == StatusEnum.Building)
		{
			ClosedActions = Actions.ToArray();
			Actions = null;
			Status = StatusEnum.Done;
			return;
		}
		throw new Exception("Undo stack error.  Closing closed Undoable");
	}

	public void Undo()
	{
		if (Status == StatusEnum.Done)
		{
			Status = StatusEnum.Undoing;
			IAction[] closedActions = ClosedActions;
			for (int i = 0; i < closedActions.Length; i++)
			{
				closedActions[i].UnDo();
			}
			Status = StatusEnum.Undone;
			return;
		}
		throw new Exception("Undo stack error.  Undoable in wrong state to undo");
	}

	public void Cancel()
	{
		if (Status == StatusEnum.Building)
		{
			Finish();
			Undo();
			return;
		}
		throw new Exception("Undo stack error.  Undoable in wrong state to cancel");
	}

	public void Redo()
	{
		if (Status == StatusEnum.Undone)
		{
			Status = StatusEnum.Redoing;
			foreach (IAction item in ClosedActions.Reverse())
			{
				item.ReDo();
			}
			Status = StatusEnum.Done;
			return;
		}
		throw new Exception("Undo stack error.  Undoable in wrong state to redo");
	}
}
public class UndoStack
{
	public long CurrentIndex { get; protected set; }

	protected Stack<Undoable> DoneStack { get; set; }

	protected Stack<Undoable> UndoneStack { get; set; }

	public Undoable CurrentOpen { get; set; }

	public ILogger Log { get; set; }

	public bool CanUndo
	{
		get
		{
			bool result = false;
			if (CurrentOpen == null && DoneStack.Any())
			{
				result = true;
			}
			return result;
		}
	}

	public bool CanRedo
	{
		get
		{
			bool result = false;
			if (CurrentOpen == null && UndoneStack.Any())
			{
				result = true;
			}
			return result;
		}
	}

	public IEnumerable<Undoable> Undoables => DoneStack.Reverse();

	public IEnumerable<Undoable> Redoables => UndoneStack.Reverse();

	public event MapChangedEventHandler MapChanged;

	public UndoStack()
	{
		CurrentIndex = 0L;
		DoneStack = new Stack<Undoable>();
		UndoneStack = new Stack<Undoable>();
	}

	public void RaiseMapChanged()
	{
		if (this.MapChanged != null)
		{
			this.MapChanged(this, new EventArgs());
		}
	}

	public void StartUndoable(string description)
	{
		if (CurrentOpen == null)
		{
			CurrentOpen = new Undoable(description, CurrentIndex);
			if (Log != null)
			{
				Log.LogMessageLine(description);
			}
		}
		else
		{
			CurrentOpen.NestedDepth++;
		}
	}

	public void Act(IAction action)
	{
		if (CurrentOpen != null)
		{
			CurrentOpen.AddAction(action);
			return;
		}
		throw new Exception("Undo stack error.  Taking action while undoable is not open");
	}

	public void FinishUndoable()
	{
		if (CurrentOpen != null)
		{
			if (CurrentOpen.NestedDepth == 0)
			{
				CurrentOpen.Finish();
				DoneStack.Push(CurrentOpen);
				CurrentIndex++;
				CurrentOpen = null;
				UndoneStack.Clear();
				RaiseMapChanged();
			}
			else
			{
				CurrentOpen.NestedDepth--;
			}
			return;
		}
		throw new Exception("Undo stack error.  Finishing undoable while undoable is not open");
	}

	public void CancelUndoable()
	{
		if (CurrentOpen != null)
		{
			CurrentOpen.Cancel();
			CurrentOpen = null;
			return;
		}
		throw new Exception("Undo stack error.  Canceling undoable while undoable is not open");
	}

	public void Undo(bool raiseChanged = true)
	{
		if (CurrentOpen == null)
		{
			Undoable undoable = DoneStack.Pop();
			if (undoable != null)
			{
				if (Log != null)
				{
					Log.LogMessageLine("Undoing: " + undoable.Description);
				}
				undoable.Undo();
				UndoneStack.Push(undoable);
				CurrentIndex = undoable.index;
			}
			if (raiseChanged)
			{
				RaiseMapChanged();
			}
			return;
		}
		throw new Exception("Undo stack error.  Undoing while undoable is open");
	}

	public void UndoTo(long index)
	{
		if (index >= 0 && index < CurrentIndex)
		{
			while (index < CurrentIndex)
			{
				Undo(raiseChanged: false);
			}
			RaiseMapChanged();
			return;
		}
		throw new Exception("Undo stack error.  Undoing to nonexisting point");
	}

	public void Redo(bool raiseChanged = true)
	{
		if (CurrentOpen == null)
		{
			Undoable undoable = UndoneStack.Pop();
			if (undoable != null)
			{
				if (Log != null)
				{
					Log.LogMessageLine("Redoing: " + undoable.Description);
				}
				undoable.Redo();
				DoneStack.Push(undoable);
				CurrentIndex = undoable.index + 1;
			}
			if (raiseChanged)
			{
				RaiseMapChanged();
			}
			return;
		}
		throw new Exception("Undo stack error.  Redoing while undoable is open");
	}

	public void RedoTo(long index)
	{
		if (index >= CurrentIndex && UndoneStack.Any() && index <= UndoneStack.First().index)
		{
			while (index >= CurrentIndex)
			{
				Redo(raiseChanged: false);
			}
			RaiseMapChanged();
			return;
		}
		throw new Exception("Undo stack error.  Redoing to nonexisting point");
	}
}
public static class RowExtensions
{
	public static T RowVal<T>(this DataRow row, string name)
	{
		if (row.IsNull(name))
		{
			return default(T);
		}
		return (T)row[name];
	}
}
public class DM
{
	public string Prefix { get; private set; }

	public MapDataSet Ds { get; private set; }

	public Variables VariableTable => Ds.VariableTable(Prefix);

	public Objects ObjectTable => Ds.ObjectTable(Prefix);

	public VariableObjectMap VariableObjectMapTable => Ds.VariableObjectMapTable(Prefix);

	public VariableIdMap VariableIdMapTable => Ds.VariableIdMapTable(Prefix);

	public Ids IdTable => Ds.IdTable(Prefix);

	public PathToVariableIds PathToVarIDTable => Ds.PathToVarIDTable(Prefix);

	public DM(string prefix, MapDataSet ds)
	{
		Prefix = prefix;
		Ds = ds;
	}
}
public class IdDescriptor
{
	public DM Dm { get; set; }

	public Guid Guid { get; set; }

	public string Name { get; set; }

	public string DataType { get; set; }

	public string Description { get; set; }

	public Guid VariableId { get; set; }

	public IdDescriptor(DM dm, DataRow idRow)
	{
		Dm = dm;
		Guid = idRow.RowVal<Guid>("Guid");
		Name = idRow.RowVal<string>("Name");
		DataType = idRow.RowVal<string>("IdType");
		Description = idRow.RowVal<string>("Description");
		VariableId = idRow.RowVal<Guid>("VariableId");
	}
}
public class VariableDescriptor
{
	private bool _implemented;

	public DM Dm { get; set; }

	public Guid Guid { get; set; }

	public string Name { get; set; }

	public string Description { get; set; }

	public string DataType { get; set; }

	public IdDescriptor[] Ids { get; set; }

	public Guid ObjectGuid { get; set; }

	public Guid ReferenceGuid { get; set; }

	public bool Implemented
	{
		get
		{
			return _implemented;
		}
		set
		{
			if (_implemented != value)
			{
				_implemented = value;
				Variables variableTable = Dm.VariableTable;
				DataRow row = variableTable.Table.Rows.Find(Guid);
				Dm.Ds.Undos.StartUndoable("Setting " + row.Field<string>("Name") + " to " + value);
				variableTable.DMSetValue(row, "Implemented", value);
				Dm.Ds.Undos.FinishUndoable();
			}
		}
	}

	public VariableDescriptor(DM dm, DataRow variableRow, Guid objGuid)
	{
		Dm = dm;
		if (variableRow == null)
		{
			return;
		}
		Guid = variableRow.RowVal<Guid>("Guid");
		Name = variableRow.RowVal<string>("Name");
		DataType = variableRow.RowVal<string>("DataType");
		Description = variableRow.RowVal<string>("Description");
		ObjectGuid = objGuid;
		ReferenceGuid = variableRow.RowVal<Guid>(Dm.Prefix + "Reference");
		_implemented = variableRow.RowVal<bool>("Implemented");
		DataRowCollection dataRowCollection = null;
		if (variableRow.RowVal<int>("NumIds") > 0)
		{
			DataRowView[] array = Dm.Ds.VariableIdMapTable(Dm.Prefix).SortedIdMap.FindRows(new object[2] { Guid, objGuid });
			Ids = new IdDescriptor[array.Count()];
			DataRowView[] array2 = array;
			for (int i = 0; i < array2.Length; i++)
			{
				DataRow row = array2[i].Row;
				int num = row.Field<int>("IdIndex");
				if (dataRowCollection == null)
				{
					dataRowCollection = Dm.Ds.IdTable(Dm.Prefix).Table.Rows;
				}
				DataRow idRow = dataRowCollection.Find(row.Field<Guid>("IdGuid"));
				Ids[num] = new IdDescriptor(Dm, idRow);
			}
		}
		else
		{
			Ids = new IdDescriptor[0];
		}
	}
}
public class VariableIdMap : BaseTable
{
	private DataView _sortedIdMap;

	private DataView _sortedByIdMap;

	public DataRelation IdsToMe { get; set; }

	public DataView SortedIdMap
	{
		get
		{
			if (_sortedIdMap == null && IsCaching)
			{
				_sortedIdMap = new DataView(base.Table);
				_sortedIdMap.Sort = "VariableGuid,ObjectGuid";
			}
			return _sortedIdMap;
		}
	}

	public DataView SortedByIdMap
	{
		get
		{
			if (_sortedByIdMap == null && IsCaching)
			{
				_sortedByIdMap = new DataView(base.Table);
				_sortedByIdMap.Sort = "IdGuid";
			}
			return _sortedByIdMap;
		}
	}

	public VariableIdMap(MapDataSet ds, string prefix)
		: base(ds, prefix)
	{
		base.Table = new DataTable(base.DsTableName = TableName(prefix));
		DataColumn dataColumn = new DataColumn("Guid", typeof(Guid));
		base.Table.Columns.Add(dataColumn);
		DataColumn column = new DataColumn("VariableGuid", typeof(Guid));
		base.Table.Columns.Add(column);
		DataColumn column2 = new DataColumn("ObjectGuid", typeof(Guid));
		base.Table.Columns.Add(column2);
		DataColumn column3 = new DataColumn("IdIndex", typeof(int));
		base.Table.Columns.Add(column3);
		DataColumn column4 = new DataColumn("IdGuid", typeof(Guid));
		base.Table.Columns.Add(column4);
		base.Table.PrimaryKey = new DataColumn[1] { dataColumn };
		ds.Set.Tables.Add(base.Table);
		IdsToMe = ds.CreateRelation(Ids.TableName(prefix), base.DsTableName, "IdGuid");
	}

	public override void Remove()
	{
		base.DS.RemoveRelation(Ids.TableName(base.Prefix), TableName(base.Prefix), "IdGuid");
		base.Remove();
	}

	public static string TableName(string preFix)
	{
		return preFix + "VarIdMAP";
	}

	public override void ClearSortCache()
	{
		_sortedIdMap = null;
		_sortedByIdMap = null;
		base.ClearSortCache();
	}

	public DataRow[] VarIdConnections(Guid variableGuid, Guid objectGuid)
	{
		DataRow[] result = new DataRow[0];
		if (SortedIdMap != null)
		{
			DataRowView[] array = _sortedIdMap.FindRows(new object[2] { variableGuid, objectGuid });
			if (array != null && array.Any())
			{
				result = Array.ConvertAll(array, (DataRowView rv) => rv.Row);
			}
		}
		else
		{
			EnumerableRowCollection<DataRow> source = from r in base.Table.AsEnumerable()
				where r.Field<Guid>("VariableGuid") == variableGuid && r.Field<Guid>("ObjectGuid") == objectGuid
				select r;
			if (source.Any())
			{
				result = source.ToArray();
			}
		}
		return result;
	}

	public DataRow[] ConnectionsToId(Guid id)
	{
		DataRow[] result = new DataRow[0];
		if (SortedByIdMap != null)
		{
			DataRowView[] array = SortedByIdMap.FindRows(id);
			if (array != null && array.Any())
			{
				result = Array.ConvertAll(array, (DataRowView rv) => rv.Row);
			}
		}
		else
		{
			EnumerableRowCollection<DataRow> source = from r in base.Table.AsEnumerable()
				where r.Field<Guid>("IdGuid") == id
				select r;
			if (source.Any())
			{
				result = source.ToArray();
			}
		}
		return result;
	}

	public void RemoveVariablesIds(Guid variableGuid, Guid objectGuid)
	{
		DataRow[] array = VarIdConnections(variableGuid, objectGuid);
		if (array != null)
		{
			Ids idTable = base.Dm.IdTable;
			DataRow[] array2 = array;
			foreach (DataRow row in array2)
			{
				Guid guid = row.Field<Guid>("IdGuid");
				DMRemoveRow(row);
				DataRow row2 = idTable.Table.Rows.Find(guid);
				int num = row2.Field<int>("RefCount");
				if (num == 1)
				{
					idTable.DMRemoveRow(idTable.Table.Rows.Find(guid));
				}
				else
				{
					idTable.DMSetValue(row2, "RefCount", num - 1);
				}
			}
		}
		ClearSortCache();
	}

	internal void CopyIdsToChild(Guid variableGuid, Guid objectGuid)
	{
		DataRow[] array = VarIdConnections(variableGuid, objectGuid);
		if (array == null)
		{
			return;
		}
		Ids idTable = base.Dm.IdTable;
		DataRow[] array2 = array;
		for (int i = 0; i < array2.Length; i++)
		{
			Guid guid = array2[i].Field<Guid>("IdGuid");
			DataRow dataRow = idTable.Table.Rows.Find(guid);
			if (dataRow != null)
			{
				idTable.CopyRowToChild(dataRow);
			}
		}
	}

	public void AddObjectGuids()
	{
		foreach (DataRow row in base.Table.Rows)
		{
			if (row.IsNull("ObjectGuid"))
			{
				Guid varGuid = row.Field<Guid>("VariableGuid");
				DataRowView[] array = base.Dm.VariableObjectMapTable.FindForVariable(varGuid);
				array.Count();
				_ = 1;
				row.SetField("ObjectGuid", array[0].Row.Field<Guid>("Object"));
			}
		}
	}
}
public class ObjectVariablePair : IComparable<ObjectVariablePair>
{
	public Guid Obj;

	public Guid Var;

	public object[] Key => new object[2] { Obj, Var };

	public ObjectVariablePair(Guid obj, Guid var)
	{
		Obj = obj;
		Var = var;
	}

	public int CompareTo(ObjectVariablePair other)
	{
		int num = Obj.CompareTo(other.Obj);
		if (num == 0)
		{
			num = Var.CompareTo(other.Var);
		}
		return num;
	}
}
public class VariableObjectMapRow
{
	protected VariableObjectMap _table { get; set; }

	public DataRow Row { get; set; }

	public Guid vGuid => Row.Field<Guid>(_table.guidCol);

	public Guid vObject => Row.Field<Guid>(_table.objectCol);

	public Guid vVariable => Row.Field<Guid>(_table.variableCol);

	public VariableObjectMapRow(VariableObjectMap vtable, DataRow row)
	{
		_table = vtable;
		Row = row;
	}
}
public class VariableObjectMap : BaseTable
{
	private DataView _sortedObjectMap;

	private DataView _sortedVariableMap;

	private DataView _sortedBothMap;

	public ForeignKeyConstraint ObjectToParentFK { get; set; }

	public DataColumn guidCol { get; set; }

	public DataColumn objectCol { get; set; }

	public DataColumn variableCol { get; set; }

	public DataView SortedObjectMap
	{
		get
		{
			if (_sortedObjectMap == null)
			{
				_sortedObjectMap = new DataView(base.Table);
				_sortedObjectMap.Sort = "Object";
			}
			return _sortedObjectMap;
		}
	}

	public DataView SortedVariableMap
	{
		get
		{
			if (_sortedVariableMap == null)
			{
				_sortedVariableMap = new DataView(base.Table);
				_sortedVariableMap.Sort = "Variable";
			}
			return _sortedVariableMap;
		}
	}

	public DataView SortedBothMap
	{
		get
		{
			if (_sortedBothMap == null)
			{
				_sortedBothMap = new DataView(base.Table);
				_sortedBothMap.Sort = "Object,Variable";
			}
			return _sortedBothMap;
		}
	}

	public VariableObjectMap(MapDataSet ds, string tableNamePrefix)
		: base(ds, tableNamePrefix)
	{
		base.Table = new DataTable(base.DsTableName = TableName(tableNamePrefix));
		guidCol = new DataColumn("Guid", typeof(Guid));
		base.Table.Columns.Add(guidCol);
		objectCol = new DataColumn("Object", typeof(Guid));
		base.Table.Columns.Add(objectCol);
		variableCol = new DataColumn("Variable", typeof(Guid));
		base.Table.Columns.Add(variableCol);
		base.Table.PrimaryKey = new DataColumn[1] { guidCol };
		ds.Set.Tables.Add(base.Table);
		ds.CreateRelation(Objects.TableName(tableNamePrefix), TableName(tableNamePrefix), "Object");
		ds.CreateRelation(Variables.TableName(tableNamePrefix), TableName(tableNamePrefix), "Variable");
	}

	public override void Remove()
	{
		base.DS.RemoveRelation(Variables.TableName(base.Prefix), TableName(base.Prefix), "Variable");
		base.DS.RemoveRelation(Objects.TableName(base.Prefix), TableName(base.Prefix), "Object");
		base.Remove();
	}

	public static string TableName(string prefix)
	{
		return prefix + "VariableObjectMap";
	}

	public VariableObjectMapRow Find(Guid guid)
	{
		VariableObjectMapRow result = null;
		DataRow dataRow = base.Table.Rows.Find(guid);
		if (dataRow != null)
		{
			result = new VariableObjectMapRow(this, dataRow);
		}
		return result;
	}

	public DataRowView[] FindForObject(Guid objGuid)
	{
		DataRowView[] array = null;
		if (IsCaching)
		{
			return SortedObjectMap.FindRows(objGuid);
		}
		IEnumerable<DataRowView> source = from DataRowView rv in new DataView(base.Table)
			where rv.Row.Field<Guid>(objectCol).Equals(objGuid)
			select rv;
		if (source.Any())
		{
			return source.ToArray();
		}
		return new DataRowView[0];
	}

	public DataRowView[] FindForBoth(Guid objGuid, Guid varGuid)
	{
		DataRowView[] array = null;
		if (IsCaching)
		{
			return SortedBothMap.FindRows(new object[2] { objGuid, varGuid });
		}
		IEnumerable<DataRowView> source = from DataRowView rv in new DataView(base.Table)
			where rv.Row.Field<Guid>(objectCol).Equals(objGuid) && rv.Row.Field<Guid>(variableCol).Equals(varGuid)
			select rv;
		if (source.Any())
		{
			return source.ToArray();
		}
		return new DataRowView[0];
	}

	public DataRowView[] FindForVariable(Guid varGuid)
	{
		DataRowView[] array = null;
		if (IsCaching)
		{
			return SortedVariableMap.FindRows(varGuid);
		}
		IEnumerable<DataRowView> source = from DataRowView rv in new DataView(base.Table)
			where rv.Row.Field<Guid>(variableCol).Equals(varGuid)
			select rv;
		if (source.Any())
		{
			return source.ToArray();
		}
		return new DataRowView[0];
	}

	public override void ClearSortCache()
	{
		_sortedObjectMap = null;
		_sortedVariableMap = null;
		_sortedBothMap = null;
		base.ClearSortCache();
	}
}
public class VariableRow
{
	protected Variables _table { get; set; }

	public DataRow Row { get; protected set; }

	public Guid vGuid => Row.Field<Guid>(_table.guidCol);

	public string vName
	{
		get
		{
			if (!Row.IsNull(_table.nameCol))
			{
				return Row.Field<string>(_table.nameCol);
			}
			return null;
		}
	}

	public string vDescription
	{
		get
		{
			if (!Row.IsNull(_table.descCol))
			{
				return Row.Field<string>(_table.descCol);
			}
			return null;
		}
	}

	public string vDataType
	{
		get
		{
			if (!Row.IsNull(_table.typeCol))
			{
				return Row.Field<string>(_table.typeCol);
			}
			return null;
		}
	}

	public int vNumids
	{
		get
		{
			if (!Row.IsNull(_table.numIdsCol))
			{
				return Row.Field<int>(_table.numIdsCol);
			}
			return 0;
		}
	}

	public Guid? vReference
	{
		get
		{
			if (!Row.IsNull(_table.refCol))
			{
				return Row.Field<Guid>(_table.refCol);
			}
			return null;
		}
	}

	public bool vImplemented
	{
		get
		{
			if (!Row.IsNull(_table.numIdsCol))
			{
				return Row.Field<bool>(_table.implementedCol);
			}
			return false;
		}
	}

	public string vAlias
	{
		get
		{
			if (!Row.IsNull(_table.aliasCol))
			{
				return Row.Field<string>(_table.aliasCol);
			}
			return null;
		}
	}

	public VariableRow(Variables vtable, DataRow row)
	{
		_table = vtable;
		Row = row;
	}
}
public class Variables : BaseTable
{
	private DataView _sortedByName;

	public DataColumn guidCol { get; set; }

	public DataColumn nameCol { get; set; }

	public DataColumn descCol { get; set; }

	public DataColumn typeCol { get; set; }

	public DataColumn numIdsCol { get; set; }

	public DataColumn refCol { get; set; }

	public DataColumn implementedCol { get; set; }

	public DataColumn aliasCol { get; set; }

	private DataView SortedByName
	{
		get
		{
			if (_sortedByName == null)
			{
				_sortedByName = new DataView(base.Table);
				_sortedByName.Sort = "Name";
			}
			return _sortedByName;
		}
	}

	public Variables(MapDataSet ds, string tableNamePrefix)
		: base(ds, tableNamePrefix)
	{
		base.Table = new DataTable(base.DsTableName = TableName(tableNamePrefix));
		guidCol = new DataColumn("Guid", typeof(Guid));
		base.Table.Columns.Add(guidCol);
		nameCol = new DataColumn("Name", typeof(string));
		base.Table.Columns.Add(nameCol);
		descCol = new DataColumn("Description", typeof(string));
		base.Table.Columns.Add(descCol);
		typeCol = new DataColumn("DataType", typeof(string));
		base.Table.Columns.Add(typeCol);
		numIdsCol = new DataColumn("NumIds", typeof(int));
		base.Table.Columns.Add(numIdsCol);
		refCol = new DataColumn(tableNamePrefix + "Reference", typeof(Guid));
		base.Table.Columns.Add(refCol);
		implementedCol = new DataColumn("Implemented", typeof(bool));
		base.Table.Columns.Add(implementedCol);
		aliasCol = new DataColumn("Alias", typeof(string));
		base.Table.Columns.Add(aliasCol);
		base.Table.PrimaryKey = new DataColumn[1] { guidCol };
		ds.Set.Tables.Add(base.Table);
		ds.CreateRelation(Objects.TableName(tableNamePrefix), TableName(tableNamePrefix), tableNamePrefix + "Reference");
	}

	public override void Remove()
	{
		base.DS.RemoveRelation(Objects.TableName(base.Prefix), TableName(base.Prefix), base.Prefix + "Reference");
		base.Remove();
	}

	public static string TableName(string prefix)
	{
		return prefix + "Variables";
	}

	public VariableRow Find(Guid guid)
	{
		VariableRow result = null;
		DataRow dataRow = base.Table.Rows.Find(guid);
		if (dataRow != null)
		{
			result = new VariableRow(this, dataRow);
		}
		return result;
	}

	public override void ClearSortCache()
	{
		_sortedByName = null;
		base.ClearSortCache();
	}

	private IEnumerable<DataRow> ByName(string name)
	{
		if (IsCaching)
		{
			DataRowView[] array = SortedByName.FindRows(name);
			DataRowView[] array2 = array;
			foreach (DataRowView dataRowView in array2)
			{
				yield return dataRowView.Row;
			}
			yield break;
		}
		EnumerableRowCollection<DataRow> enumerableRowCollection = from DataRow row in base.Table.AsEnumerable()
			where name.Equals(row.Field<string>("Name"), StringComparison.InvariantCultureIgnoreCase)
			select row;
		foreach (DataRow item in enumerableRowCollection)
		{
			yield return item;
		}
	}

	public VariableDescriptor FindVariableDesc(string objName, string variableName)
	{
		VariableDescriptor result = null;
		Guid? objGuid;
		DataRow dataRow = FindVariable(objName, variableName, out objGuid);
		if (dataRow != null)
		{
			result = new VariableDescriptor(base.Dm, dataRow, objGuid.Value);
		}
		return result;
	}

	public DataRow FindVariable(string objName, string variableName, out Guid? objGuid)
	{
		objGuid = null;
		DataRow result = null;
		Objects objects = base.DS.ObjectTable(base.Prefix);
		if (objects != null)
		{
			ObjectRow objectRow = objects.FindRowByName(objName);
			if (objectRow != null)
			{
				objGuid = objectRow.vGuid;
				result = FindVariable(objGuid.Value, variableName);
			}
		}
		return result;
	}

	public DataRow FindVariableInherited(Guid objguid, string variableName, out Guid actualGuid)
	{
		DataRow result = null;
		IEnumerable<DataRow> source = ByName(variableName);
		Objects objects = base.DS.ObjectTable(base.Prefix);
		actualGuid = Guid.Empty;
		if (source.Any())
		{
			VariableObjectMap varMap = base.Dm.VariableObjectMapTable;
			Guid curObject = objguid;
			while (true)
			{
				IEnumerable<DataRow> source2 = from DataRow row in source
					where varMap.FindForBoth(curObject, row.Field<Guid>(guidCol)).Any()
					select row;
				if (source2.Any())
				{
					actualGuid = curObject;
					result = source2.First();
					break;
				}
				DataRow dataRow = objects.Table.Rows.Find(curObject);
				if (dataRow.IsNull(objects.parentCol))
				{
					break;
				}
				curObject = dataRow.Field<Guid>(objects.parentCol);
			}
		}
		return result;
	}

	public DataRow FindVariable(Guid objguid, string variableName)
	{
		DataRow result = null;
		foreach (DataRow item in ByName(variableName))
		{
			if (base.Dm.VariableObjectMapTable.FindForBoth(objguid, item.Field<Guid>(guidCol)).Count() == 1)
			{
				result = item;
				break;
			}
		}
		return result;
	}

	public List<VariableDescriptor> VariableDescForObject(Guid objGuid, bool inherit)
	{
		List<VariableDescriptor> list = new List<VariableDescriptor>();
		VariableObjectMap variableObjectMapTable = base.Dm.VariableObjectMapTable;
		DataRowView[] array = variableObjectMapTable.FindForObject(objGuid);
		foreach (DataRowView dataRowView in array)
		{
			DataRow variableRow = base.Table.Rows.Find(dataRowView.Row.Field<Guid>(variableObjectMapTable.variableCol));
			list.Add(new VariableDescriptor(base.Dm, variableRow, objGuid));
		}
		if (inherit)
		{
			DataRow dataRow = base.DS.ObjectTable(base.Prefix).Table.Rows.Find(objGuid);
			if (!dataRow.IsNull("Parent"))
			{
				List<VariableDescriptor> collection = VariableDescForObject(dataRow.Field<Guid>("Parent"), inherit: true);
				list.AddRange(collection);
			}
		}
		return list;
	}

	public List<VariableDescriptor> VariableDescForObject(string objName, bool inherit)
	{
		List<VariableDescriptor> result = null;
		Objects objects = base.DS.ObjectTable(base.Prefix);
		if (objects != null)
		{
			ObjectRow objectRow = objects.FindRowByName(objName);
			if (objectRow != null)
			{
				Guid vGuid = objectRow.vGuid;
				result = VariableDescForObject(vGuid, inherit);
			}
		}
		return result;
	}

	public void DeleteVariable(VariableDescriptor variable, bool doSubVars = true)
	{
		base.DS.Undos.StartUndoable("Delete Variable " + variable.Name);
		base.Dm.VariableIdMapTable.RemoveVariablesIds(variable.Guid, variable.ObjectGuid);
		base.Dm.PathToVarIDTable.RemoveVariable(variable.ObjectGuid, variable.Guid);
		VariableObjectMap variableObjectMapTable = base.Dm.VariableObjectMapTable;
		DataRowView[] array = variableObjectMapTable.FindForVariable(variable.Guid);
		int num = array.Count();
		DataRowView[] array2 = array;
		foreach (DataRowView dataRowView in array2)
		{
			if (dataRowView.Row.Field<Guid>("Object") == variable.ObjectGuid)
			{
				num--;
				variableObjectMapTable.DMRemoveRow(dataRowView.Row);
			}
		}
		ConnectedConverterArgs connectedConverterArgsTable = base.Dm.Ds.ConnectedConverterArgsTable;
		ConnectedConverters connectedConvertersTable = base.Dm.Ds.ConnectedConvertersTable;
		ConnectedConverterIdResolution connectedConverterIdResolutionTable = base.Dm.Ds.ConnectedConverterIdResolutionTable;
		DataRowView[] array3 = new DataView(connectedConverterArgsTable.Table)
		{
			Sort = "Variable"
		}.FindRows(variable.Guid);
		if (array3.Any())
		{
			List<DataRow> list = new List<DataRow>();
			List<DataRow> list2 = new List<DataRow>();
			array2 = array3;
			foreach (DataRowView dataRowView2 in array2)
			{
				if (!dataRowView2.Row.IsNull("Object") && !(dataRowView2.Row.Field<Guid>("Object") == variable.ObjectGuid))
				{
					continue;
				}
				if (!list2.Contains(dataRowView2.Row))
				{
					list2.Add(dataRowView2.Row);
				}
				Guid guid = dataRowView2.Row.Field<Guid>(connectedConverterArgsTable.connectedConverterCol);
				DataRow item = connectedConvertersTable.Table.Rows.Find(guid);
				if (list.Contains(item))
				{
					continue;
				}
				list.Add(item);
				DataRowView[] array4 = connectedConverterIdResolutionTable.ResolutionForConnectedConverter(guid);
				foreach (DataRowView dataRowView3 in array4)
				{
					connectedConverterIdResolutionTable.DMRemoveRow(dataRowView3.Row);
				}
				array4 = connectedConverterArgsTable.ArgsForConnectedConverter(guid);
				foreach (DataRowView dataRowView4 in array4)
				{
					if (!list2.Contains(dataRowView4.Row))
					{
						list2.Add(dataRowView4.Row);
					}
				}
			}
			foreach (DataRow item2 in list2)
			{
				connectedConverterArgsTable.DMRemoveRow(item2);
			}
			foreach (DataRow item3 in list)
			{
				connectedConvertersTable.DMRemoveRow(item3);
			}
		}
		if (num == 0)
		{
			DataRow row = base.Table.Rows.Find(variable.Guid);
			DMRemoveRow(row);
		}
		base.DS.Undos.FinishUndoable();
	}

	internal void CopyVariableToChild(Guid guid, Guid obj)
	{
		VariableRow variableRow = Find(guid);
		Objects objectTable = base.Dm.ObjectTable;
		VariableIdMap variableIdMapTable = base.Dm.VariableIdMapTable;
		VariableObjectMap variableObjectMapTable = base.Dm.VariableObjectMapTable;
		if (variableRow.vReference.HasValue)
		{
			objectTable.CopyObjectToChild(variableRow.vReference.Value);
		}
		CopyRowToChild(variableRow.Row);
		DataRowView[] array = variableObjectMapTable.FindForVariable(guid);
		foreach (DataRowView dataRowView in array)
		{
			objectTable.CopyObjectToChild(dataRowView.Row.Field<Guid>(variableObjectMapTable.objectCol));
			variableObjectMapTable.CopyRowToChild(dataRowView.Row);
		}
		variableIdMapTable.CopyIdsToChild(guid, obj);
		_ = base.Dm.PathToVarIDTable;
	}

	public bool FindVariableWithGuid(Variables oldVars, Guid oldGuid, Objects oldObjs, Guid oldObjGuid, out Guid? newGuid, out Guid? newObjGuid)
	{
		bool result = false;
		newGuid = null;
		newObjGuid = null;
		newObjGuid = base.Dm.ObjectTable.FindObjectWithGuid(oldObjs, oldObjGuid);
		if (newObjGuid.HasValue)
		{
			DataRow dataRow = base.Table.Rows.Find(oldGuid);
			if (dataRow != null)
			{
				newGuid = oldGuid;
				result = true;
			}
			else
			{
				dataRow = FindVariable(newObjGuid.Value, oldVars.Table.Rows.Find(oldGuid).Field<string>("Name"));
				if (dataRow != null)
				{
					newGuid = dataRow.Field<Guid>("Guid");
					result = true;
				}
			}
		}
		return result;
	}

	public ObjectVariablePair FindNewOV(MapDataSet oldDs, ObjectVariablePair oldOV)
	{
		ObjectVariablePair result = null;
		if (FindVariableWithGuid(oldDs.VariableTable(base.Prefix), oldOV.Var, oldDs.ObjectTable(base.Prefix), oldOV.Obj, out var newGuid, out var newObjGuid))
		{
			result = new ObjectVariablePair(newObjGuid.Value, newGuid.Value);
		}
		return result;
	}
}
