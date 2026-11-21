// Selected C# from the checked local original. See code-extraction.json for omitted ranges and fingerprints.
using System;
using System.Collections;
using System.ComponentModel;
using System.Diagnostics;
using System.IO;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Soap;
using System.Runtime.Versioning;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading;
using Microsoft.Win32;

[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: AssemblyCompany("AspenTech")]
[assembly: AssemblyProduct("Aspen Properties Enterprise Database V15")]
[assembly: AssemblyCopyright("Copyright © 2025 Aspen Technology, Inc.")]
[assembly: AssemblyTrademark("")]
[assembly: AssemblyFileVersion("41.0.0.11")]
[assembly: AssemblyDelaySign(false)]
[assembly: AssemblyKeyFile("..\\..\\..\\..\\aped.snk")]
[assembly: AssemblyKeyName("")]
[assembly: AssemblyTitle("APED Data Gateway Component")]
[assembly: AssemblyDescription("")]
[assembly: AssemblyConfiguration("")]
[assembly: TargetFramework(".NETFramework,Version=v4.8", FrameworkDisplayName = ".NET Framework 4.8")]
[assembly: AssemblyVersion("41.0.0.1")]
namespace AspenTech.APED;

public interface IDatabaseObjectAssocationManager
{
	IDatabase Database { get; }

	void AssociateObjects(IDatabaseObjectMoniker Object1, IDatabaseObjectMoniker Object2);

	void RemoveAssociation(IDatabaseObjectMoniker Object1, IDatabaseObjectMoniker Object2);

	void RemoveAllAssociations(IDatabaseObjectMoniker Object1);

	void DeleteAssociation(IDatabaseObjectMoniker Object1, IDatabaseObjectMoniker Object2);

	void DeleteAllAssociations(IDatabaseObjectMoniker Object1);

	void FindAssociatedObjects(IDatabaseObjectMoniker Object1, DatabaseObjectType AssociatedObjectsType, out IDatabaseObjectMoniker[] AssociatedObjects);
}
public interface IAuditLog
{
	IDatabase Database { get; }

	IList Entries { get; }

	void WriteEntry(string Category, string Message);
}
public interface IAuditLogEntry
{
	IDatabase Database { get; }

	string Category { get; }

	DateTime UtcTimeGenerated { get; }

	string UserName { get; }

	string Message { get; }
}
[ComVisible(false)]
public delegate void ChangeEventHandlerDelegate(IChange change);
[InterfaceType(ComInterfaceType.InterfaceIsIDispatch)]
public interface IChangeControlManagerEvents
{
	void ChangeSubmitted(IChange change);
}
public interface IChangeControlManager
{
	IDatabase Database { get; }

	bool IsChangeControlEnabled { get; }

	IList PendingChanges { get; }

	IList ApprovedChanges { get; }

	event ChangeEventHandlerDelegate ChangeSubmitted;

	void ApproveAll();

	bool ApproveLast();

	void RejectAll();

	void RejectLast();
}
public enum ChangeState
{
	Unsubmitted,
	Submitted,
	Approved,
	Rejected
}
public interface IChange
{
	ChangeState State { get; }

	bool Result { get; }

	string Category { get; }

	DateTime UtcTimeSubmitted { get; }

	DateTime UtcTimeApproved { get; }

	string SubmitterName { get; }

	string ApproverName { get; }

	string Message { get; }

	void Approve();

	void Reject();
}
public interface ICitationManager
{
	IDatabase Database { get; }

	void AddNote(IDatabank databank, string compoundId, string compoundIdType, string propertyName, NotesObject noteObj);

	void GetNote(IDatabank databank, string compoundId, string compoundIdType, string propertyName, out NotesObject noteObj);

	void RemoveNote(IDatabank databank, string compoundId, string compoundIdType, string propertyName);

	void DeleteNote(IDatabank databank, string compoundId, string compoundIdType, string propertyName);

	void UpdateNote(IDatabank databank, string compoundId, string compoundIdType, string propertyName, NotesObject newNoteObj);

	void AddDataInfo(IDatabank databank, string compoundId, string compoundIdType, string propertyName, PropertyDataInfoObject errObj);

	void GetDataInfo(IDatabank databank, string compoundId, string compoundIdType, string propertyName, out PropertyDataInfoObject errObj);

	void RemoveDataInfo(IDatabank databank, string compoundId, string compoundIdType, string propertyName);

	void DeleteDataInfo(IDatabank databank, string compoundId, string compoundIdType, string propertyName);

	void UpdateDataInfo(IDatabank databank, string compoundId, string compoundIdType, string propertyName, PropertyDataInfoObject newErrObj);

	void AddCitation(string name, string title, string pages, string journal, string date, string book, string volume, string publisher, string notes, string authors, out ICitation citation);

	void AddCitation(IDatabank databank, string compoundId, string compoundIdType, string propertyName, PropertyCitationsObject citObj);

	void GetCitation(string name, out ICitation citation);

	void GetCitation(IDatabank databank, string compoundId, string compoundIdType, string propertyName, out ArrayList citObjLst);

	void RemoveCitation(ICitation citation);

	void DeleteCitationAssociation(IDatabank databank, string compoundId, string compoundIdType, string propertyName);

	void DeleteCitation(string citName);

	void UpdateCitation(ref ICitation citation, string name, string title, string pages, string journal, string date, string book, string volume, string publisher, string notes, string authors);

	void GetAllCitations(out SortedList citationList);
}
public enum InteractionType
{
	Unknown = -1,
	Unary,
	Binary,
	Ternary,
	Pair
}
public enum CompoundType
{
	Unknown = -1,
	Compound,
	UnifacGroup,
	ElectrolytePair
}
public interface IIdentifier
{
	int Id { get; }

	string Name { get; }

	string Description { get; }

	bool AllowMultiples { get; }
}
public interface IIdentifierValue
{
	ICompound Compound { get; }

	IIdentifier Identifier { get; }

	ICollection ValueList { get; }
}
public interface ICompound
{
	int Id { get; }

	string Compound1Name { get; }

	string Compound2Name { get; }

	string Compound3Name { get; }

	string Compound4Name { get; }

	IIdentifier Identifier { get; }

	CompoundType CompoundType { get; }

	InteractionType InteractionType { get; }

	bool IsReverse { get; }
}
public interface ICompoundManager
{
	IDatabase Database { get; }

	void AddIdentifier(string name, string description, bool allowMultiples, out IIdentifier identifier);

	void UpdateIdentifier(ref IIdentifier identifier, string name, string description, bool allowMultiples);

	void RemoveIdentifier(IIdentifier identifier);

	void GetIdentifier(string name, out IIdentifier identifier);

	void GetAllIdentifiers(out ICollection identifiers);

	void AddCompound(string id, IIdentifier identifier, out ICompound compound);

	void RemoveCompound(ICompound compound);

	void GetCompound(string id, IIdentifier identifier, out ICompound compound);

	void AddIdentifierValue(ICompound compound, IIdentifier identifier, string[] identifierList, out IIdentifierValue identifierValue);

	void UpdateIdentifierValue(ref IIdentifierValue identifierValue, string[] identifierList);

	void GetIdentifierValue(ICompound compound, IIdentifier identifier, out IIdentifierValue identifierValue);

	void RemoveIdentifierValue(IIdentifierValue identifierValue);

	void GetAllIdentifierValues(ICompound compound, out ICollection identifierValues);

	void GetCompoundIdentifier(string CompoundId, string CompoundIdType, string OutCompoundIdType, out IIdentifierValue identValue);

	void GetCompoundDuoId(int compound1Id, int compound2Id, bool addIfMissing, out int duoId, out bool isReversed);

	void GetDatabankCompoundPropertyId(IDatabank testDatabank, int compid, out SortedList dbcid);

	void SetWorkingCompounds(ICollection workingCompounds);

	void Find(ICollection searchSource, int identSearchOption, string identSearchString, string compclassToSearch, ICollection propertiesToSearch, string[] outputPropertyNames, out ICollection matches);

	void FindForMM(ICollection searchSource, string identSearchString, string identifierType, string outputProperty, out ICollection matches);

	void FindForMM_Multiple(ICollection searchSource, string identifierType, ref Hashtable identSearchStrings, string outputProperty, out ICollection matches);

	void FindForAPlus(ICollection searchSource, string identSearchString, int dbankContentDataType, out int compId, out string compName, out string compAlias);

	void GetCompoundDatabankList(ICompound compound, out ICollection databankList);

	void GetAllCompounds(IDatabank databank, out ICollection compounds);

	bool DatabankHasCompound(IDatabank databank, ICompound compound);

	void OptimizedFind(Hashtable comp_Table, string databaseName, out Hashtable engineCompTable, out Hashtable gatewayCompTable, int isHYSIDX, int isEDLIDX);

	void NameAliasCasrnAlreadyExists(ArrayList identifierValues);
}
public interface ICompoundObject
{
	string CompoundIndex { get; }

	void GetCompoundIdentifier(string CompoundIdType, out string CompoundId);
}
public class CompoundObject : DatabaseObject, ICompoundObject, IDatabaseObject, IDatabaseObjectIdentity, ICompound
{
	private int myId;

	private string myComp1Name;

	private string myComp2Name;

	private string myComp3Name;

	private string myComp4Name;

	private IIdentifier myIdentifier;

	private bool myIsReverse;

	private CompoundType myCompoundType;

	private InteractionType myInteractionType;

	public int Id
	{
		get
		{
			return myId;
		}
		set
		{
			myId = value;
		}
	}

	public string Compound1Name
	{
		get
		{
			return myComp1Name;
		}
		set
		{
			myComp1Name = value;
		}
	}

	public string Compound2Name
	{
		get
		{
			return myComp2Name;
		}
		set
		{
			myComp2Name = value;
		}
	}

	public string Compound3Name
	{
		get
		{
			return myComp3Name;
		}
		set
		{
			myComp3Name = value;
		}
	}

	public string Compound4Name
	{
		get
		{
			return myComp4Name;
		}
		set
		{
			myComp4Name = value;
		}
	}

	public IIdentifier Identifier
	{
		get
		{
			return myIdentifier;
		}
		set
		{
			myIdentifier = value;
		}
	}

	public bool IsReverse
	{
		get
		{
			return myIsReverse;
		}
		set
		{
			myIsReverse = value;
		}
	}

	public CompoundType CompoundType
	{
		get
		{
			return myCompoundType;
		}
		set
		{
			myCompoundType = value;
		}
	}

	public InteractionType InteractionType
	{
		get
		{
			return myInteractionType;
		}
		set
		{
			myInteractionType = value;
		}
	}

	public override DatabaseObjectType ObjectType => DatabaseObjectType.Compound;

	public string CompoundIndex => base.Identity;

	public CompoundObject(int id, string comp1Name, string comp2Name, string comp3Name, string comp4Name, IIdentifier identifier, CompoundType compoundType, InteractionType interactionType, bool isReverse)
	{
		myId = id;
		myComp1Name = comp1Name;
		myComp2Name = comp2Name;
		myComp3Name = comp3Name;
		myComp4Name = comp4Name;
		myIdentifier = identifier;
		myCompoundType = compoundType;
		myInteractionType = interactionType;
		myIsReverse = isReverse;
	}

	public CompoundObject(string comp1Name, string comp2Name, string comp3Name, string comp4Name, IIdentifier identifier, CompoundType compoundType, InteractionType interactionType, bool isReverse)
	{
		myId = 0;
		myComp1Name = comp1Name;
		myComp2Name = comp2Name;
		myComp3Name = comp3Name;
		myComp4Name = comp4Name;
		myIdentifier = identifier;
		myCompoundType = compoundType;
		myInteractionType = interactionType;
		myIsReverse = isReverse;
	}

	public CompoundObject()
	{
	}

	public CompoundObject(IDatabase Database, int CompoundIndex)
		: base(CompoundIndex.ToString(), Database)
	{
	}

	internal static IDatabaseObject ResolveMoniker(IDatabaseObjectMoniker moniker)
	{
		return new CompoundObject(moniker.Database, Convert.ToInt32(moniker.Identity));
	}

	public void GetCompoundIdentifier(string CompoundIdType, out string CompoundId)
	{
		ICompoundManager compoundManager;
		if (!(base.Database is ISupportsCompounds) || (compoundManager = (base.Database as ISupportsCompounds).CompoundManager) == null)
		{
			throw new GatewayException("The database does not support compounds");
		}
		compoundManager.GetIdentifier("CompoundIndex", out var identifier);
		compoundManager.GetCompound(CompoundIndex, identifier, out var compound);
		compoundManager.GetIdentifier(CompoundIdType, out identifier);
		compoundManager.GetIdentifierValue(compound, identifier, out var identifierValue);
		string[] array = new string[identifierValue.ValueList.Count];
		identifierValue.ValueList.CopyTo(array, 0);
		CompoundId = array[0];
	}

	void IDatabaseObject.GetMoniker(out IDatabaseObjectMoniker Moniker)
	{
		Moniker = new DatabaseObjectMoniker(((IDatabaseObjectIdentity)this).Database, ((IDatabaseObjectIdentity)this).ObjectType, ((IDatabaseObjectIdentity)this).Identity, ResolveMoniker);
	}
}
internal class CompoundPropertyListEvaluator : IGatewayEvaluator
{
	private SortedList myProperties;

	public CompoundPropertyListEvaluator()
	{
		myProperties = new SortedList();
	}

	public bool Evaluate(IDatabank Databank, IDatabase Database)
	{
		if (Database == null)
		{
			throw new ArgumentException("A valid database must be given", "Database");
		}
		if (!(Database is ISupportsPropertyValues))
		{
			return false;
		}
		IPropertyValueManager propertyValueManager = ((ISupportsPropertyValues)Database).PropertyValueManager;
		return false;
	}

	public void Result(out SortedList properties)
	{
		if (myProperties != null)
		{
			properties = myProperties;
		}
		else
		{
			properties = null;
		}
	}
}
internal class CompoundPropertyEvaluator : IGatewayEvaluator
{
	private string myCompoundId;

	private string myCompoundIdType;

	private string myPropertyId;

	private IPropertyValue myValue;

	public CompoundPropertyEvaluator(string CompoundId, string CompoundIdType, string PropertyId)
	{
		myCompoundId = CompoundId;
		myCompoundIdType = CompoundIdType;
		myPropertyId = PropertyId;
	}

	public bool Evaluate(IDatabank Databank, IDatabase Database)
	{
		if (Databank == null)
		{
			throw new ArgumentException("A valid databank must be given", "Databank");
		}
		if (!(Database is ISupportsPropertyValues))
		{
			return false;
		}
		IPropertyValueManager propertyValueManager = ((ISupportsPropertyValues)Database).PropertyValueManager;
		if (propertyValueManager == null)
		{
			return false;
		}
		myValue = null;
		return false;
	}

	public void Result(out IPropertyValue value)
	{
		value = myValue;
	}
}
internal class CompoundAllPropertyEvaluator : IGatewayEvaluator
{
	private string myCompoundId;

	private string myCompoundIdType;

	private ICollection myAllValue;

	public CompoundAllPropertyEvaluator(string CompoundId, string CompoundIdType)
	{
		myCompoundId = CompoundId;
		myCompoundIdType = CompoundIdType;
	}

	public bool Evaluate(IDatabank Databank, IDatabase Database)
	{
		if (Databank == null)
		{
			throw new ArgumentException("A valid databank must be given", "Databank");
		}
		if (!(Database is ISupportsPropertyValues))
		{
			return false;
		}
		IPropertyValueManager propertyValueManager = ((ISupportsPropertyValues)Database).PropertyValueManager;
		if (propertyValueManager == null)
		{
			return false;
		}
		myAllValue = null;
		return false;
	}

	public void Result(out ICollection AllValue)
	{
		AllValue = myAllValue;
	}
}
public interface ICompoundPropertyGateway
{
	IDatabankCollection Databanks { get; set; }

	void GetProperties(out SortedList Properties);

	void GetCompoundProperty(string CompoundId, string CompoundIdType, string PropertyId, out IPropertyValue Value);

	void GetAllCompoundProperties(string CompoundId, string CompoundIdType, out ICollection AllValue);
}
[ClassInterface(ClassInterfaceType.None)]
public class CompoundPropertyGateway : ICompoundPropertyGateway
{
	private IDatabankCollection myDatabankList;

	public IDatabankCollection Databanks
	{
		get
		{
			return myDatabankList;
		}
		set
		{
			myDatabankList = value;
		}
	}

	public void GetProperties(out SortedList Properties)
	{
		try
		{
			EvaluateOnDatabasesAlgorithm evaluateOnDatabasesAlgorithm = new EvaluateOnDatabasesAlgorithm();
			CompoundPropertyListEvaluator compoundPropertyListEvaluator = new CompoundPropertyListEvaluator();
			evaluateOnDatabasesAlgorithm.Execute(myDatabankList, compoundPropertyListEvaluator);
			compoundPropertyListEvaluator.Result(out Properties);
		}
		catch (GatewayException)
		{
			throw;
		}
		catch (Exception inner)
		{
			throw new GatewayException("An error occurred enumerating the available compound properties", inner);
		}
	}

	public void GetCompoundProperty(string CompoundId, string CompoundIdType, string PropertyId, out IPropertyValue Value)
	{
		try
		{
			EvaluateOnDatabanksAlgorithm evaluateOnDatabanksAlgorithm = new EvaluateOnDatabanksAlgorithm();
			CompoundPropertyEvaluator compoundPropertyEvaluator = new CompoundPropertyEvaluator(CompoundId, CompoundIdType, PropertyId);
			evaluateOnDatabanksAlgorithm.Execute(myDatabankList, compoundPropertyEvaluator);
			compoundPropertyEvaluator.Result(out Value);
		}
		catch (GatewayException)
		{
			throw;
		}
		catch (Exception inner)
		{
			throw new GatewayException("An error occurred getting the compound property value", inner);
		}
	}

	public void GetAllCompoundProperties(string CompoundId, string CompoundIdType, out ICollection AllValue)
	{
		try
		{
			EvaluateOnDatabanksAlgorithm evaluateOnDatabanksAlgorithm = new EvaluateOnDatabanksAlgorithm();
			CompoundAllPropertyEvaluator compoundAllPropertyEvaluator = new CompoundAllPropertyEvaluator(CompoundId, CompoundIdType);
			evaluateOnDatabanksAlgorithm.Execute(myDatabankList, compoundAllPropertyEvaluator);
			compoundAllPropertyEvaluator.Result(out AllValue);
		}
		catch (GatewayException)
		{
			throw;
		}
		catch (Exception inner)
		{
			throw new GatewayException("An error occurred getting the compound property values", inner);
		}
	}
}
public enum ContentDataType
{
	Unknown = -1,
	PurePropertyData,
	BinaryPropertyData,
	TernaryPropertyData,
	PairPropertyData,
	ReactionData
}
public interface IDatabank
{
	int Id { get; }

	IDatabase Database { get; }

	string Name { get; }

	string BaseDatabankName { get; }

	string Description { get; }

	bool IsLocked { get; }

	ICollection AllCompounds { get; set; }

	ArrayList CompoundIDs { get; set; }

	string[] AllProperties { get; set; }

	bool PureDatabank { get; set; }

	bool BinaryDatabank { get; set; }

	ArrayList BinaryParameters { get; set; }

	bool bShow { get; set; }

	void GetCompoundsWithData(out ICollection Compounds);

	void GetCompoundIDsWithData(out ArrayList Compounds);

	void GetContentDataTypes(out ICollection dataTypes);

	void UpdateDatabankDescription(string newDescription, out bool retval);
}
public interface IDatabankCollection : ICollection, IEnumerable
{
	IDatabank this[object Index] { get; set; }

	int Add(IDatabank Databank);

	void Clear();

	void Insert(int Index, IDatabank Databank);

	void Remove(IDatabank Databank);

	void RemoveAt(int Index);
}
[ClassInterface(ClassInterfaceType.None)]
public class DatabankCollection : IDatabankCollection, ICollection, IEnumerable
{
	private ArrayList myDatabanks;

	public IDatabank this[object index]
	{
		get
		{
			if (index.GetType() == typeof(int))
			{
				return (IDatabank)myDatabanks[(int)index];
			}
			if (index.GetType() == typeof(string))
			{
				int num = findIndex((string)index);
				if (num < 0)
				{
					return null;
				}
				return (IDatabank)myDatabanks[num];
			}
			throw new ArgumentException("The index must be a nonnegative integer or a text string", "index");
		}
		set
		{
			if (index.GetType() != typeof(int))
			{
				throw new ArgumentException("The index must be a nonnegative integer", "index");
			}
			myDatabanks[(int)index] = value;
		}
	}

	public int Count => myDatabanks.Count;

	public bool IsSynchronized => myDatabanks.IsSynchronized;

	public object SyncRoot => myDatabanks.SyncRoot;

	public DatabankCollection()
	{
		myDatabanks = new ArrayList();
	}

	public DatabankCollection(IDatabase Database)
		: this()
	{
		if (Database == null)
		{
			throw new ArgumentException("A database is required", "database");
		}
		initializeFromDatabase(Database);
	}

	public DatabankCollection(IDatabank[] Databanks)
		: this()
	{
		myDatabanks.AddRange(Databanks);
	}

	public int Add(IDatabank Databank)
	{
		return myDatabanks.Add(Databank);
	}

	public void Clear()
	{
		myDatabanks.Clear();
	}

	public void Insert(int Index, IDatabank Databank)
	{
		myDatabanks.Insert(Index, Databank);
	}

	public void Remove(IDatabank Databank)
	{
		myDatabanks.Remove(Databank);
	}

	public void RemoveAt(int Index)
	{
		myDatabanks.RemoveAt(Index);
	}

	public void CopyTo(Array array, int index)
	{
		myDatabanks.CopyTo(array, index);
	}

	public IEnumerator GetEnumerator()
	{
		return myDatabanks.GetEnumerator();
	}

	private void initializeFromDatabase(IDatabase database)
	{
		database.EnumerateDatabanks(out var Databanks);
		myDatabanks.AddRange(Databanks);
	}

	private int findIndex(string name)
	{
		int result = -1;
		for (int i = 0; i < myDatabanks.Count; i++)
		{
			IDatabank databank = this[i];
			if (databank.Name.ToLowerInvariant().CompareTo(name.ToLowerInvariant()) == 0)
			{
				result = i;
				break;
			}
		}
		return result;
	}
}






















































public interface ISupportsCompounds
{
	ICompoundManager CompoundManager { get; }
}
public interface ISupportsProperties
{
	IPropertyManager PropertyManager { get; }
}
public interface ISupportsPropertyValues
{
	IPropertyValueManager PropertyValueManager { get; }
}
public interface ISupportsUnifacGroups
{
	IUnifacGroups UnifacGroupManager { get; }
}
public interface ISupportsAuditing
{
	IAuditLog AuditLogManager { get; }
}
public interface ISupportsChangeControl
{
	IChangeControlManager ChangeControlManager { get; }
}
public interface ISupportsSundryData
{
	ISundryDataManager SundryDataManager { get; }
}
public interface ISupportsUOMData
{
	IUOMDataManager UOMDataManager { get; }
}
public interface ISupportsMolData
{
	IMolDataManager MolDataManager { get; }
}
public interface ISupportsCitations
{
	ICitationManager CitationManager { get; }
}
public interface ISupportsAssociations
{
	IDatabaseObjectAssocationManager AssociationManager { get; }
}
public interface ISupportsReactions
{
	IReactionManager ReactionManager { get; }
}
public interface IDatabankManager
{
	IDatabank AddDatabank(string Name, IDatabank BaseDatabank, string Description);

	void UpdateDatabank(IDatabank Databank, string Description);

	void RemoveDatabank(IDatabank Databank);

	void DeleteDatabank(IDatabank Databank);
}
public interface IDatabaseSynchronizationSource
{
	IDatabase Database { get; }

	int DatabaseIdentity { get; }

	void GetContents(out string Contents);

	void ApplyChangesTo(IDatabaseSynchronizationTarget Target);
}
public interface IDatabaseSynchronizationTarget
{
	IDatabase Database { get; }

	int DatabaseIdentity { get; }

	DateTime UtcTimeOfLastSyncronization { get; }

	void SynchronizeTo(IDatabaseSynchronizationSource Source, bool ResetTargetDatabaseContents);

	void ApplyChange(IChange Change);
}
[ComVisible(false)]
public delegate void DatabaseCollectionEventHandlerDelegate(IDatabase database);
[InterfaceType(ComInterfaceType.InterfaceIsIDispatch)]
public interface IDatabaseCollectionEvents
{
	void DatabaseAdded(IDatabase database);

	void DatabaseRemoved(IDatabase database);

	void DatabaseChanged(IDatabase database);
}



























































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































public enum DatabaseObjectType
{
	Unknown = -1,
	Equation = 0,
	PropertyValue = 1,
	InteractionParameterValue = 2,
	InteractionParameterDatabankInformation = 3,
	Compound = 4,
	Note = 5,
	Error = 6,
	Reference = 7,
	IpHelpInfo = 8,
	PureDatabankInfo = 9,
	History = 10,
	CompoundIdentifierValue = 11,
	User = 65536
}
public interface IDatabaseObjectIdentity
{
	IDatabase Database { get; set; }

	string Identity { get; set; }

	DatabaseObjectType ObjectType { get; }
}
public interface IDatabaseObject : IDatabaseObjectIdentity
{
	void GetMoniker(out IDatabaseObjectMoniker Moniker);
}
public abstract class DatabaseObject : IDatabaseObjectIdentity, ISerializable
{
	private string myIdentity;

	[NonSerialized]
	private IDatabase myDatabase;

	public IDatabase Database
	{
		get
		{
			return myDatabase;
		}
		set
		{
			myDatabase = value;
		}
	}

	public string Identity
	{
		get
		{
			return myIdentity;
		}
		set
		{
			myIdentity = value;
		}
	}

	public abstract DatabaseObjectType ObjectType { get; }

	protected DatabaseObject()
	{
	}

	protected DatabaseObject(string Identity, IDatabase Database)
	{
		myIdentity = Identity;
		myDatabase = Database;
	}

	protected DatabaseObject(SerializationInfo info, StreamingContext context)
	{
		myDatabase = context.Context as IDatabase;
		myIdentity = info.GetString("identity");
	}

	public override bool Equals(object obj)
	{
		return GetHashCode() == obj.GetHashCode();
	}

	public override int GetHashCode()
	{
		return myIdentity.GetHashCode();
	}

	public virtual void GetObjectData(SerializationInfo info, StreamingContext context)
	{
		info.AddValue("identity", myIdentity);
	}
}
public interface IDatabaseObjectMoniker : IDatabaseObjectIdentity
{
	IDatabaseObject Resolve();
}
[ComVisible(false)]
public delegate IDatabaseObject ResolveDatabaseObjectMonikerDelegate(IDatabaseObjectMoniker Moniker);
[Serializable]
[ComVisible(false)]
public class DatabaseObjectMoniker : IDatabaseObjectMoniker, IDatabaseObjectIdentity, ISerializable
{
	[NonSerialized]
	private IDatabase myDatabase;

	private DatabaseObjectType myObjectType;

	private string myIdentity;

	private ResolveDatabaseObjectMonikerDelegate myResolveMonikerDelegate;

	public IDatabase Database
	{
		get
		{
			return myDatabase;
		}
		set
		{
			if (value == null)
			{
				throw new ArgumentException("A database must be provided");
			}
			myDatabase = value;
		}
	}

	public string Identity
	{
		get
		{
			return myIdentity;
		}
		set
		{
			if (value == "" || value == null)
			{
				throw new ArgumentException("The Identity cannot be empty", "Identity");
			}
			myIdentity = value;
		}
	}

	public DatabaseObjectType ObjectType => myObjectType;

	public DatabaseObjectMoniker(IDatabase Database, DatabaseObjectType ObjectType, string Identity, ResolveDatabaseObjectMonikerDelegate ResolveMonikerDelegate)
	{
		if (Database == null)
		{
			throw new ArgumentException("A database must be given", "Database");
		}
		if (ObjectType == DatabaseObjectType.Unknown)
		{
			throw new ArgumentException("The database object type cannot be Unknown", "ObjectType");
		}
		if (Identity == "" || Identity == null)
		{
			throw new ArgumentException("The object identity be empty", "Identity");
		}
		if (ResolveMonikerDelegate == null)
		{
			throw new ArgumentException("The resolve moniker delegate cannot be empty", "ResolveMonikerDelegate");
		}
		myDatabase = Database;
		myObjectType = ObjectType;
		myIdentity = Identity;
		myResolveMonikerDelegate = ResolveMonikerDelegate;
	}

	public override bool Equals(object obj)
	{
		return GetHashCode() == obj.GetHashCode();
	}

	public override int GetHashCode()
	{
		return Database.GetHashCode() ^ Identity.GetHashCode() ^ ObjectType.GetHashCode();
	}

	public void GetObjectData(SerializationInfo info, StreamingContext context)
	{
		info.SetType(typeof(DatabaseObjectMonikerSerializationProxy));
		DatabaseObjectMonikerSerializationProxy databaseObjectMonikerSerializationProxy = new DatabaseObjectMonikerSerializationProxy(this);
		databaseObjectMonikerSerializationProxy.GetObjectData(info, context);
	}

	public IDatabaseObject Resolve()
	{
		return myResolveMonikerDelegate(this);
	}
}
[Serializable]
internal sealed class DatabaseObjectMonikerSerializationProxy : IObjectReference, ISerializable
{
	private IDatabase myDatabase;

	private DatabaseObjectType myObjectType;

	private string myIdentity;

	public DatabaseObjectMonikerSerializationProxy(IDatabaseObjectMoniker Moniker)
	{
		myDatabase = Moniker.Database;
		myObjectType = Moniker.ObjectType;
		myIdentity = Moniker.Identity;
	}

	private DatabaseObjectMonikerSerializationProxy(SerializationInfo info, StreamingContext context)
	{
		myDatabase = context.Context as IDatabase;
		myObjectType = (DatabaseObjectType)info.GetInt32("objectType");
		myIdentity = info.GetString("identity");
	}

	public void GetObjectData(SerializationInfo info, StreamingContext context)
	{
		info.AddValue("objectType", myObjectType);
		info.AddValue("identity", myIdentity);
	}

	object IObjectReference.GetRealObject(StreamingContext context)
	{
		return DatabaseObjectMonikerFactory.CreateMoniker(myDatabase, myObjectType, myIdentity);
	}
}
[ComVisible(false)]
public class DatabaseObjectMonikerFactory
{
	public static IDatabaseObjectMoniker CreateMoniker(IDatabase Database, DatabaseObjectType ObjectType, string Identity)
	{
		IDatabaseObject databaseObject = ObjectType switch
		{
			DatabaseObjectType.Equation => new EquationObject(), 
			DatabaseObjectType.PropertyValue => new PropertyValueObject(), 
			DatabaseObjectType.Reference => new PropertyCitationsObject(), 
			DatabaseObjectType.History => new PropertyHistoryObject(), 
			_ => throw new ArgumentException("The database object type is unknown", "ObjectType"), 
		};
		databaseObject.Database = Database;
		databaseObject.Identity = Identity;
		databaseObject.GetMoniker(out var Moniker);
		return Moniker;
	}
}
public interface IEngineCompound
{
	string DatabaseName { get; set; }

	int CompoundPosition { get; set; }

	int CompoundIndex { get; set; }

	string CompoundName { get; set; }

	string CompoundAlias { get; set; }

	string CompoundCasNo { get; set; }

	double CompoundClassDblValue { get; set; }

	double HysysIndex { get; set; }

	double EDLIndex { get; set; }
}
public class EngineCompoundObject : IEngineCompound
{
	private int compIndex;

	private int compPosition;

	private string dbName;

	private string compName;

	private string compAlias;

	private string compCasNo;

	private double compClassDblValue;

	private double hysidx;

	private double EDLidx;

	public string DatabaseName
	{
		get
		{
			return dbName;
		}
		set
		{
			dbName = value;
		}
	}

	public int CompoundPosition
	{
		get
		{
			return compPosition;
		}
		set
		{
			compPosition = value;
		}
	}

	public int CompoundIndex
	{
		get
		{
			return compIndex;
		}
		set
		{
			compIndex = value;
		}
	}

	public string CompoundName
	{
		get
		{
			return compName;
		}
		set
		{
			compName = value;
		}
	}

	public string CompoundAlias
	{
		get
		{
			return compAlias;
		}
		set
		{
			compAlias = value;
		}
	}

	public string CompoundCasNo
	{
		get
		{
			return compCasNo;
		}
		set
		{
			compCasNo = value;
		}
	}

	public double CompoundClassDblValue
	{
		get
		{
			return compClassDblValue;
		}
		set
		{
			compClassDblValue = value;
		}
	}

	public double HysysIndex
	{
		get
		{
			return hysidx;
		}
		set
		{
			hysidx = value;
		}
	}

	public double EDLIndex
	{
		get
		{
			return EDLidx;
		}
		set
		{
			EDLidx = value;
		}
	}

	public EngineCompoundObject(string db_name, int comp_pos, int comp_index, string comp_name, string comp_alias, string comp_casno)
	{
		dbName = db_name;
		compPosition = comp_pos;
		compIndex = comp_index;
		compName = comp_name;
		compAlias = comp_alias;
		compCasNo = comp_casno;
	}
}
public interface IEnginePropertyValue
{
	int DatabankPosition { get; }

	object Values { get; }
}
public class EnginePropertyValueObject : IEnginePropertyValue
{
	private int databank_position;

	private SortedList valueList;

	public int DatabankPosition => databank_position;

	public object Values => valueList;

	public EnginePropertyValueObject(int databankPos, SortedList valList)
	{
		databank_position = databankPos;
		valueList = valList;
	}
}
public class EnginePairPropertyValueObject
{
	private int comp1_position;

	private int comp2_position;

	private int comp3_position;

	private int comp4_position;

	private int prop_position;

	private int databank_position;

	private object valueList;

	public int Compound1Position => comp1_position;

	public int Compound2Position => comp2_position;

	public int Compound3Position => comp3_position;

	public int Compound4Position => comp4_position;

	public int PropertyPosition => prop_position;

	public int DatabankPosition => databank_position;

	public object Values => valueList;

	public EnginePairPropertyValueObject(int comp1Pos, int comp2Pos, int comp3Pos, int comp4Pos, int propPos, int databankPos, object valList)
	{
		comp1_position = comp1Pos;
		comp2_position = comp2Pos;
		comp3_position = comp3Pos;
		comp4_position = comp4Pos;
		prop_position = propPos;
		databank_position = databankPos;
		valueList = valList;
	}
}
public interface IEquationObject
{
	string Name { get; set; }

	int NumParameters { get; set; }

	string Description { get; set; }

	byte[] ImageData { get; set; }

	string ImageFormat { get; set; }
}
[Serializable]
[ClassInterface(ClassInterfaceType.None)]
public class EquationObject : DatabaseObject, IEquationObject, IDatabaseObject, IDatabaseObjectIdentity, ISerializable
{
	private int myNumParameters;

	private string myDescription;

	private byte[] myImageData;

	private string myImageFormat;

	public string Name
	{
		get
		{
			return base.Identity;
		}
		set
		{
			base.Identity = value;
		}
	}

	public int NumParameters
	{
		get
		{
			return myNumParameters;
		}
		set
		{
			myNumParameters = value;
		}
	}

	public string Description
	{
		get
		{
			return myDescription;
		}
		set
		{
			myDescription = value;
		}
	}

	public byte[] ImageData
	{
		get
		{
			return myImageData;
		}
		set
		{
			myImageData = value;
		}
	}

	public string ImageFormat
	{
		get
		{
			return myImageFormat;
		}
		set
		{
			myImageFormat = value;
		}
	}

	public override DatabaseObjectType ObjectType => DatabaseObjectType.Equation;

	public EquationObject()
	{
	}

	public EquationObject(string Name, int NumParameters, string Description, byte[] ImageData, string ImageFormat)
		: base(Name, null)
	{
		myDescription = Description;
		myImageData = ImageData;
		myNumParameters = NumParameters;
		myImageFormat = ImageFormat;
	}

	protected EquationObject(SerializationInfo info, StreamingContext context)
		: base(info, context)
	{
		myDescription = info.GetString("description");
		myImageData = (byte[])info.GetValue("imageData", typeof(byte[]));
		myNumParameters = info.GetInt32("numParameters");
		myImageFormat = info.GetString("imageFormat");
	}

	internal static IDatabaseObject ResolveMoniker(IDatabaseObjectMoniker moniker)
	{
		ISundryDataManager sundryDataManager;
		if (!(moniker.Database is ISupportsSundryData) || (sundryDataManager = (moniker.Database as ISupportsSundryData).SundryDataManager) == null)
		{
			throw new GatewayException("The database does not support sundry data or an error occurred referencing the sundry data manager");
		}
		return sundryDataManager.GetItem(moniker.Identity);
	}

	public override void GetObjectData(SerializationInfo info, StreamingContext context)
	{
		base.GetObjectData(info, context);
		info.AddValue("description", myDescription);
		info.AddValue("imageData", myImageData);
		info.AddValue("numParameters", myNumParameters);
		info.AddValue("imageFormat", myImageFormat);
	}

	void IDatabaseObject.GetMoniker(out IDatabaseObjectMoniker Moniker)
	{
		Moniker = new DatabaseObjectMoniker(((IDatabaseObjectIdentity)this).Database, ((IDatabaseObjectIdentity)this).ObjectType, ((IDatabaseObjectIdentity)this).Identity, ResolveMoniker);
	}
}
public interface IFindConstraint
{
	string[] ConstrainedPropertyNames { get; }

	string[] ConstrainedIdentifierNames { get; }

	bool IsMatch(IDictionary propertyValues);
}
internal abstract class BinaryOperators
{
	public static bool LessThan(double arg1, double arg2)
	{
		return arg1 < arg2;
	}

	public static bool LessThanOrEqual(double arg1, double arg2)
	{
		return arg1 <= arg2;
	}

	public static bool GreaterThan(double arg1, double arg2)
	{
		return arg1 > arg2;
	}

	public static bool GreaterThanOrEqual(double arg1, double arg2)
	{
		return arg1 >= arg2;
	}
}
internal delegate bool BinaryInequalityOperator(double arg1, double arg2);
internal class PropertyValueRangeConstraint : IFindConstraint
{
	public enum PropertyValueRangeConstraintOptions
	{
		Inclusive,
		Exclusive
	}

	private string myPropertyName;

	private string myIdentifierName;

	private double myLowValue;

	private double myHighValue;

	private BinaryInequalityOperator myLesserOp;

	private BinaryInequalityOperator myGreaterOp;

	public string[] ConstrainedPropertyNames => new string[1] { myPropertyName };

	public string[] ConstrainedIdentifierNames => null;

	public PropertyValueRangeConstraint(string propertyName, double lowValue, double highValue, PropertyValueRangeConstraintOptions option)
	{
		if (propertyName == null || propertyName == "")
		{
			throw new ArgumentException("A property name must be given", "propertyName");
		}
		myPropertyName = propertyName;
		myIdentifierName = null;
		myLowValue = lowValue;
		myHighValue = highValue;
		if (option == PropertyValueRangeConstraintOptions.Exclusive)
		{
			myLesserOp = BinaryOperators.LessThan;
			myGreaterOp = BinaryOperators.GreaterThan;
		}
		else
		{
			myLesserOp = BinaryOperators.LessThanOrEqual;
			myGreaterOp = BinaryOperators.GreaterThanOrEqual;
		}
	}

	public bool IsMatch(IDictionary propertyValues)
	{
		object obj = propertyValues[myPropertyName];
		if (obj == null)
		{
			return false;
		}
		Array array = (Array)obj;
		if (array.Length > 1)
		{
			return false;
		}
		double arg = Convert.ToDouble(array.GetValue(0));
		if (myGreaterOp(arg, myLowValue))
		{
			return myLesserOp(arg, myHighValue);
		}
		return false;
	}
}
internal class PropertyValueRelationalConstraint
{
	private string myPropertyName;

	private string myIdentifierName;

	private double myValue;

	private BinaryInequalityOperator myOperator;

	public string[] ConstrainedPropertyNames => new string[1] { myPropertyName };

	public string[] ConstrainedIdentifierNames => null;

	public PropertyValueRelationalConstraint(string propertyName, double value, BinaryInequalityOperator oper)
	{
		if (propertyName == null || propertyName == "")
		{
			throw new ArgumentException("A property name must be given", "propertyName");
		}
		myPropertyName = propertyName;
		myIdentifierName = null;
		myValue = value;
		myOperator = oper;
	}

	public bool IsMatch(IDictionary propertyValues)
	{
		object obj = propertyValues[myPropertyName];
		if (obj == null)
		{
			return false;
		}
		Array array = (Array)obj;
		if (array.Length > 1)
		{
			return false;
		}
		double arg = Convert.ToDouble(array.GetValue(0));
		return myOperator(arg, myValue);
	}
}
[ClassInterface(ClassInterfaceType.None)]
public class PropertyValueConstantConstraint : IFindConstraint
{
	private string myPropertyName;

	private string myIdentifierName;

	private object myValue;

	public string[] ConstrainedPropertyNames => new string[1] { myPropertyName };

	public string[] ConstrainedIdentifierNames => null;

	public PropertyValueConstantConstraint(string propertyName, object value)
	{
		if (propertyName == null || propertyName == "")
		{
			throw new ArgumentException("A property name must be given", "propertyName");
		}
		myPropertyName = propertyName;
		myIdentifierName = null;
		myValue = value;
	}

	public bool IsMatch(IDictionary propertyValues)
	{
		if (myValue == null)
		{
			if (propertyValues[myPropertyName] == null)
			{
				return true;
			}
			return false;
		}
		object obj = propertyValues[myPropertyName];
		if (obj == null)
		{
			return false;
		}
		Array array = (Array)obj;
		if (array.Length > 1)
		{
			return false;
		}
		double num = Convert.ToDouble(array.GetValue(0));
		return myValue.Equals(num);
	}
}
[ClassInterface(ClassInterfaceType.None)]
public class PropertyValueInclusiveRangeConstraint : IFindConstraint
{
	private PropertyValueRangeConstraint myConstraint;

	public string[] ConstrainedPropertyNames => myConstraint.ConstrainedPropertyNames;

	public string[] ConstrainedIdentifierNames => myConstraint.ConstrainedIdentifierNames;

	public PropertyValueInclusiveRangeConstraint(string propertyName, double lowValue, double highValue)
	{
		myConstraint = new PropertyValueRangeConstraint(propertyName, lowValue, highValue, PropertyValueRangeConstraint.PropertyValueRangeConstraintOptions.Inclusive);
	}

	public bool IsMatch(IDictionary propertyValues)
	{
		return myConstraint.IsMatch(propertyValues);
	}
}
[ClassInterface(ClassInterfaceType.None)]
public class PropertyValueExclusiveRangeConstraint : IFindConstraint
{
	private PropertyValueRangeConstraint myConstraint;

	public string[] ConstrainedPropertyNames => myConstraint.ConstrainedPropertyNames;

	public string[] ConstrainedIdentifierNames => myConstraint.ConstrainedIdentifierNames;

	public PropertyValueExclusiveRangeConstraint(string propertyName, double lowValue, double highValue)
	{
		myConstraint = new PropertyValueRangeConstraint(propertyName, lowValue, highValue, PropertyValueRangeConstraint.PropertyValueRangeConstraintOptions.Exclusive);
	}

	public bool IsMatch(IDictionary propertyValues)
	{
		return myConstraint.IsMatch(propertyValues);
	}
}
[ClassInterface(ClassInterfaceType.None)]
public class PropertyValueLessThanConstraint : IFindConstraint
{
	private PropertyValueRelationalConstraint myConstraint;

	public string[] ConstrainedPropertyNames => myConstraint.ConstrainedPropertyNames;

	public string[] ConstrainedIdentifierNames => myConstraint.ConstrainedIdentifierNames;

	public PropertyValueLessThanConstraint(string propertyName, double value)
	{
		myConstraint = new PropertyValueRelationalConstraint(propertyName, value, BinaryOperators.LessThan);
	}

	public bool IsMatch(IDictionary propertyValues)
	{
		return myConstraint.IsMatch(propertyValues);
	}
}
[ClassInterface(ClassInterfaceType.None)]
public class PropertyValueLessThanOrEqualConstraint : IFindConstraint
{
	private PropertyValueRelationalConstraint myConstraint;

	public string[] ConstrainedPropertyNames => myConstraint.ConstrainedPropertyNames;

	public string[] ConstrainedIdentifierNames => myConstraint.ConstrainedIdentifierNames;

	public PropertyValueLessThanOrEqualConstraint(string propertyName, double value)
	{
		myConstraint = new PropertyValueRelationalConstraint(propertyName, value, BinaryOperators.LessThanOrEqual);
	}

	public bool IsMatch(IDictionary propertyValues)
	{
		return myConstraint.IsMatch(propertyValues);
	}
}
[ClassInterface(ClassInterfaceType.None)]
public class PropertyValueGreaterThanConstraint : IFindConstraint
{
	private PropertyValueRelationalConstraint myConstraint;

	public string[] ConstrainedPropertyNames => myConstraint.ConstrainedPropertyNames;

	public string[] ConstrainedIdentifierNames => myConstraint.ConstrainedIdentifierNames;

	public PropertyValueGreaterThanConstraint(string propertyName, double value)
	{
		myConstraint = new PropertyValueRelationalConstraint(propertyName, value, BinaryOperators.GreaterThan);
	}

	public bool IsMatch(IDictionary propertyValues)
	{
		return myConstraint.IsMatch(propertyValues);
	}
}
[ClassInterface(ClassInterfaceType.None)]
public class PropertyValueGreaterThanOrEqualConstraint : IFindConstraint
{
	private PropertyValueRelationalConstraint myConstraint;

	public string[] ConstrainedPropertyNames => myConstraint.ConstrainedPropertyNames;

	public string[] ConstrainedIdentifierNames => myConstraint.ConstrainedIdentifierNames;

	public PropertyValueGreaterThanOrEqualConstraint(string propertyName, double value)
	{
		myConstraint = new PropertyValueRelationalConstraint(propertyName, value, BinaryOperators.GreaterThanOrEqual);
	}

	public bool IsMatch(IDictionary propertyValues)
	{
		return myConstraint.IsMatch(propertyValues);
	}
}
[ClassInterface(ClassInterfaceType.None)]
public class PropertyValueRegexConstraint : IFindConstraint
{
	private string myPropertyName;

	private string myIdentifierName;

	private Regex myRegex;

	public string[] ConstrainedPropertyNames => new string[1] { myPropertyName };

	public string[] ConstrainedIdentifierNames => null;

	public PropertyValueRegexConstraint(string propertyName, string regexPattern)
	{
		if (propertyName == null || propertyName == "")
		{
			throw new ArgumentException("A property name must be given", "propertyName");
		}
		myPropertyName = propertyName;
		myIdentifierName = null;
		myRegex = new Regex(regexPattern, RegexOptions.IgnoreCase);
	}

	public bool IsMatch(IDictionary propertyValues)
	{
		object obj = propertyValues[myPropertyName];
		if (obj == null)
		{
			return false;
		}
		if (obj.GetType().IsArray)
		{
			object[] array = (object[])obj;
			object[] array2 = array;
			foreach (object obj2 in array2)
			{
				string input = Convert.ToString(obj2);
				if (myRegex.IsMatch(input))
				{
					return true;
				}
			}
			return false;
		}
		string input2 = Convert.ToString(obj);
		return myRegex.IsMatch(input2);
	}
}
[ClassInterface(ClassInterfaceType.None)]
public class CompoundIdentifierConstraint : IFindConstraint
{
	private string myPropertyName;

	private string myIdentifierName;

	private Regex myRegex;

	public string[] ConstrainedPropertyNames => null;

	public string[] ConstrainedIdentifierNames => new string[1] { myIdentifierName };

	public CompoundIdentifierConstraint(string identifierName, string regexPattern)
	{
		if (identifierName == null || identifierName == "")
		{
			throw new ArgumentException("An identifier name must be given", "identifierName");
		}
		myPropertyName = null;
		myIdentifierName = identifierName;
		myRegex = new Regex(regexPattern, RegexOptions.IgnoreCase);
	}

	public bool IsMatch(IDictionary identifierValues)
	{
		object obj = identifierValues[myIdentifierName];
		if (obj == null)
		{
			return false;
		}
		if (obj.GetType().IsArray)
		{
			object[] array = (object[])obj;
			object[] array2 = array;
			foreach (object obj2 in array2)
			{
				string input = Convert.ToString(obj2);
				if (myRegex.IsMatch(input))
				{
					return true;
				}
			}
			return false;
		}
		string input2 = Convert.ToString(obj);
		return myRegex.IsMatch(input2);
	}
}
[ClassInterface(ClassInterfaceType.None)]
public class LogicalAndConstraint : IFindConstraint
{
	private IFindConstraint[] myConstraints;

	private string[] myPropertyNames;

	private string[] myIdentifierNames;

	public string[] ConstrainedPropertyNames => myPropertyNames;

	public string[] ConstrainedIdentifierNames => myIdentifierNames;

	public LogicalAndConstraint(IFindConstraint[] constraints)
	{
		if (constraints == null || constraints.Length == 0)
		{
			throw new ArgumentException("At least one constraint must be given", "constraints");
		}
		myConstraints = constraints;
		ArrayList arrayList = new ArrayList();
		ArrayList arrayList2 = new ArrayList();
		IFindConstraint[] array = myConstraints;
		foreach (IFindConstraint findConstraint in array)
		{
			if (findConstraint.ConstrainedPropertyNames != null)
			{
				arrayList.AddRange(findConstraint.ConstrainedPropertyNames);
			}
			if (findConstraint.ConstrainedIdentifierNames != null)
			{
				arrayList2.AddRange(findConstraint.ConstrainedIdentifierNames);
			}
		}
		myPropertyNames = (string[])arrayList.ToArray(typeof(string));
		myIdentifierNames = (string[])arrayList2.ToArray(typeof(string));
	}

	public bool IsMatch(IDictionary propertyValues)
	{
		IFindConstraint[] array = myConstraints;
		foreach (IFindConstraint findConstraint in array)
		{
			if (!findConstraint.IsMatch(propertyValues))
			{
				return false;
			}
		}
		return true;
	}
}
[ClassInterface(ClassInterfaceType.None)]
public class LogicalOrConstraint : IFindConstraint
{
	private IFindConstraint[] myConstraints;

	private string[] myPropertyNames;

	private string[] myIdentifierNames;

	public string[] ConstrainedPropertyNames => myPropertyNames;

	public string[] ConstrainedIdentifierNames => myIdentifierNames;

	public LogicalOrConstraint(IFindConstraint[] constraints)
	{
		if (constraints == null || constraints.Length == 0)
		{
			throw new ArgumentException("At least one constraint must be given", "constraints");
		}
		myConstraints = constraints;
		ArrayList arrayList = new ArrayList();
		ArrayList arrayList2 = new ArrayList();
		IFindConstraint[] array = myConstraints;
		foreach (IFindConstraint findConstraint in array)
		{
			if (findConstraint.ConstrainedPropertyNames != null)
			{
				arrayList.AddRange(findConstraint.ConstrainedPropertyNames);
			}
			if (findConstraint.ConstrainedIdentifierNames != null)
			{
				arrayList2.AddRange(findConstraint.ConstrainedIdentifierNames);
			}
		}
		myPropertyNames = (string[])arrayList.ToArray(typeof(string));
		myIdentifierNames = (string[])arrayList2.ToArray(typeof(string));
	}

	public bool IsMatch(IDictionary propertyValues)
	{
		IFindConstraint[] array = myConstraints;
		foreach (IFindConstraint findConstraint in array)
		{
			if (findConstraint.IsMatch(propertyValues))
			{
				return true;
			}
		}
		return false;
	}
}
public interface IFindResult
{
	IDatabank Databank { get; set; }

	ICompoundObject Compound { get; set; }

	IDatabaseObject[] Results { get; set; }
}
[ClassInterface(ClassInterfaceType.None)]
public class FindResult : IFindResult
{
	private IDatabank myDatabank;

	private ICompoundObject myCompound;

	private IDatabaseObject[] myResults;

	public IDatabank Databank
	{
		get
		{
			return myDatabank;
		}
		set
		{
			myDatabank = value;
		}
	}

	public ICompoundObject Compound
	{
		get
		{
			return myCompound;
		}
		set
		{
			myCompound = value;
		}
	}

	public IDatabaseObject[] Results
	{
		get
		{
			return myResults;
		}
		set
		{
			myResults = value;
		}
	}

	public FindResult()
	{
	}

	public FindResult(IDatabank Databank, ICompoundObject Compound, IDatabaseObject[] Results)
	{
		myDatabank = Databank;
		myCompound = Compound;
		myResults = Results;
	}

	public override bool Equals(object target)
	{
		return GetHashCode() == target.GetHashCode();
	}

	public override int GetHashCode()
	{
		return myCompound.GetHashCode();
	}
}
public interface IFoundCompounds
{
	IDatabank Databank { get; }

	ICompound Compound { get; }

	ICollection IdentifierValues { get; }

	ICollection PropertyValues { get; set; }

	int CompoundPosition { get; set; }
}
[ClassInterface(ClassInterfaceType.None)]
public class FoundCompounds : IFoundCompounds
{
	private IDatabank myDatabank;

	private ICompound myCompound;

	private ICollection myIdentifierValues;

	private ICollection myPropertyValues;

	private int myCompoundPosition;

	public IDatabank Databank => myDatabank;

	public ICompound Compound => myCompound;

	public ICollection IdentifierValues => myIdentifierValues;

	public ICollection PropertyValues
	{
		get
		{
			return myPropertyValues;
		}
		set
		{
			myPropertyValues = value;
		}
	}

	public int CompoundPosition
	{
		get
		{
			return myCompoundPosition;
		}
		set
		{
			myCompoundPosition = value;
		}
	}

	public FoundCompounds()
	{
	}

	public FoundCompounds(IDatabank Databank, ICompound Compound, ICollection identifierValues, ICollection propertyValues)
	{
		myDatabank = Databank;
		myCompound = Compound;
		myIdentifierValues = identifierValues;
		myPropertyValues = propertyValues;
	}
}
internal interface IGatewayEvaluator
{
	bool Evaluate(IDatabank Databank, IDatabase Database);
}
internal class EvaluateOnDatabanksAlgorithm
{
	public void Execute(IDatabankCollection Databanks, IGatewayEvaluator Evaluator)
	{
		if (Databanks == null)
		{
			throw new ArgumentException("The list of databanks cannot be null", "Databanks");
		}
		if (Evaluator == null)
		{
			throw new ArgumentException("An evaluator object must be supplied", "Evaluator");
		}
		foreach (IDatabank Databank in Databanks)
		{
			if (Evaluator.Evaluate(Databank, Databank.Database))
			{
				break;
			}
		}
	}
}
internal class EvaluateOnDatabasesAlgorithm
{
	private ArrayList myDatabases;

	public EvaluateOnDatabasesAlgorithm()
	{
		myDatabases = new ArrayList();
	}

	public void Execute(IDatabankCollection Databanks, IGatewayEvaluator Evaluator)
	{
		if (Databanks == null)
		{
			throw new ArgumentException("The list of databanks cannot be null", "Databanks");
		}
		if (Evaluator == null)
		{
			throw new ArgumentException("An evaluator object is required", "Evaluator");
		}
		ExtractDatabases(Databanks);
		foreach (IDatabase myDatabase in myDatabases)
		{
			if (Evaluator.Evaluate(null, myDatabase))
			{
				break;
			}
		}
	}

	private void ExtractDatabases(IDatabankCollection dbs)
	{
		foreach (IDatabank db in dbs)
		{
			IDatabank databank2 = db;
			IDatabase database = databank2.Database;
			if (!myDatabases.Contains(database))
			{
				myDatabases.Add(database);
			}
		}
	}
}
public class IdentifierObject : IIdentifier
{
	private int ident_Id;

	private string ident_Name;

	private string ident_Description;

	private bool ident_AllowMultiples;

	public int Id
	{
		get
		{
			return ident_Id;
		}
		set
		{
			ident_Id = value;
		}
	}

	public string Name
	{
		get
		{
			return ident_Name;
		}
		set
		{
			ident_Name = value;
		}
	}

	public string Description
	{
		get
		{
			return ident_Description;
		}
		set
		{
			ident_Description = value;
		}
	}

	public bool AllowMultiples
	{
		get
		{
			return ident_AllowMultiples;
		}
		set
		{
			ident_AllowMultiples = value;
		}
	}

	public IdentifierObject(int id, string name, string description, bool allowMultiples)
	{
		ident_Id = id;
		ident_Name = name;
		ident_Description = description;
		ident_AllowMultiples = allowMultiples;
	}
}
public class IdentifierValueObject : DatabaseObject, IIdentifierValue, IDatabaseObject, IDatabaseObjectIdentity
{
	private ICompound myCompound;

	private IIdentifier myIdentifier;

	private ICollection myValueList;

	public ICompound Compound
	{
		get
		{
			return myCompound;
		}
		set
		{
			myCompound = value;
		}
	}

	public IIdentifier Identifier
	{
		get
		{
			return myIdentifier;
		}
		set
		{
			myIdentifier = value;
		}
	}

	public ICollection ValueList
	{
		get
		{
			return myValueList;
		}
		set
		{
			myValueList = value;
		}
	}

	public override DatabaseObjectType ObjectType => DatabaseObjectType.CompoundIdentifierValue;

	public IdentifierValueObject(ICompound compound, IIdentifier identifier, string[] valueList)
	{
		myCompound = compound;
		myIdentifier = identifier;
		myValueList = valueList;
	}

	public void GetMoniker(out IDatabaseObjectMoniker Moniker)
	{
		Moniker = null;
	}
}
public interface IMolDataGateway
{
	IDatabankCollection Databanks { get; set; }

	bool GetStructure(int ComponentId, out string MolText, int StructureType);

	bool GetStructureByName(string IdName, string IdType, out string MolText, int StructureType);
}
[ClassInterface(ClassInterfaceType.None)]
public class MolDataGateway : IMolDataGateway
{
	private IDatabankCollection myDatabankList;

	public IDatabankCollection Databanks
	{
		get
		{
			return myDatabankList;
		}
		set
		{
			myDatabankList = value;
		}
	}

	public bool GetStructure(int ComponentId, out string MolText, int StructureType)
	{
		MolText = "";
		try
		{
			EvaluateOnDatabasesAlgorithm evaluateOnDatabasesAlgorithm = new EvaluateOnDatabasesAlgorithm();
			StructureEvaluator structureEvaluator = new StructureEvaluator(ComponentId, StructureType);
			evaluateOnDatabasesAlgorithm.Execute(myDatabankList, structureEvaluator);
			structureEvaluator.Result(out MolText);
			return true;
		}
		catch (GatewayException)
		{
			throw;
		}
		catch (Exception inner)
		{
			throw new GatewayException("An error occurred retrieving the Molecular Structure data by Component Id", inner);
		}
	}

	public bool GetStructureByName(string IdName, string IdType, out string MolText, int StructureType)
	{
		MolText = "";
		try
		{
			EvaluateOnDatabasesAlgorithm evaluateOnDatabasesAlgorithm = new EvaluateOnDatabasesAlgorithm();
			StructureByNameEvaluator structureByNameEvaluator = new StructureByNameEvaluator(IdName, IdType, StructureType);
			evaluateOnDatabasesAlgorithm.Execute(myDatabankList, structureByNameEvaluator);
			structureByNameEvaluator.Result(out MolText);
			return true;
		}
		catch (GatewayException)
		{
			throw;
		}
		catch (Exception inner)
		{
			throw new GatewayException("An error occurred retrieving the Molecular Structure data by named identifier", inner);
		}
	}
}
public interface IMolDataManager
{
	IDatabase Database { get; }

	void AddStructure(int ComponentId, string MolText, int StructureType);

	void AddStructureByName(string IdName, string IdValue, string MolText, int StructureType);

	void RemoveStructure(int ComponentId, int StructureType);

	void RemoveStructureByName(string IdName, string IdType, int StructureType);

	void DeleteStructure(int ComponentId, int StructureType);

	void DeleteStructureByName(string IdName, string IdType, int StructureType);
}
public interface IMolData
{
	IDatabase Database { get; }

	bool GetStructure(int ComponentId, out string MolText, int StructureType);

	bool GetStructureByName(string IdName, string IdType, out string MolText, int StructureType);
}
internal class StructureEvaluator : IGatewayEvaluator
{
	private string myMolText;

	private int myComponentId;

	private int myStructureType;

	public StructureEvaluator(int ComponentId, int StructureType)
	{
		myComponentId = ComponentId;
		myStructureType = StructureType;
	}

	public bool Evaluate(IDatabank Databank, IDatabase Database)
	{
		if (Database == null)
		{
			throw new ArgumentException("A valid database must be given", "Database");
		}
		if (!(Database is ISupportsMolData))
		{
			return false;
		}
		if (!(((ISupportsMolData)Database).MolDataManager is IMolData molData))
		{
			return false;
		}
		molData.GetStructure(myComponentId, out myMolText, myStructureType);
		if (myMolText != null)
		{
			return true;
		}
		return false;
	}

	public void Result(out string mol_text)
	{
		mol_text = myMolText;
	}
}
internal class StructureByNameEvaluator : IGatewayEvaluator
{
	private string myIdName;

	private string myIdType;

	private string myMolText;

	private int myStructureType;

	public StructureByNameEvaluator(string IdName, string IdType, int StructureType)
	{
		myIdName = IdName;
		myIdType = IdType;
		myStructureType = StructureType;
	}

	public bool Evaluate(IDatabank Databank, IDatabase Database)
	{
		if (Database == null)
		{
			throw new ArgumentException("A valid database must be given", "Database");
		}
		if (!(Database is ISupportsMolData))
		{
			return false;
		}
		if (!(((ISupportsMolData)Database).MolDataManager is IMolData molData))
		{
			return false;
		}
		molData.GetStructureByName(myIdName, myIdType, out myMolText, myStructureType);
		if (myMolText != null)
		{
			return true;
		}
		return false;
	}

	public void Result(out string mol_text)
	{
		mol_text = myMolText;
	}
}
public interface INotesObject
{
	string Name { get; set; }

	string Note { get; set; }
}
[Serializable]
[ClassInterface(ClassInterfaceType.None)]
public class NotesObject : DatabaseObject, INotesObject, IDatabaseObject, IDatabaseObjectIdentity, ISerializable
{
	private string myNote;

	public string Name
	{
		get
		{
			return base.Identity;
		}
		set
		{
			base.Identity = value;
		}
	}

	public string Note
	{
		get
		{
			return myNote;
		}
		set
		{
			myNote = value;
		}
	}

	public override DatabaseObjectType ObjectType => DatabaseObjectType.Note;

	public NotesObject()
	{
	}

	public NotesObject(string Name, string Note)
		: base(Name, null)
	{
		myNote = Note;
	}

	protected NotesObject(SerializationInfo info, StreamingContext context)
		: base(info, context)
	{
		myNote = info.GetString("note");
	}

	internal static IDatabaseObject ResolveMoniker(IDatabaseObjectMoniker moniker)
	{
		ISundryDataManager sundryDataManager;
		if (!(moniker.Database is ISupportsSundryData) || (sundryDataManager = (moniker.Database as ISupportsSundryData).SundryDataManager) == null)
		{
			throw new GatewayException("The database does not support sundry data or an error occurred referencing the sundry data manager");
		}
		return sundryDataManager.GetItem(moniker.Identity);
	}

	public override void GetObjectData(SerializationInfo info, StreamingContext context)
	{
		base.GetObjectData(info, context);
		info.AddValue("note", myNote);
	}

	void IDatabaseObject.GetMoniker(out IDatabaseObjectMoniker Moniker)
	{
		Moniker = new DatabaseObjectMoniker(((IDatabaseObjectIdentity)this).Database, ((IDatabaseObjectIdentity)this).ObjectType, ((IDatabaseObjectIdentity)this).Identity, ResolveMoniker);
	}
}
public interface IPropertyDataInfoObject
{
	string Name { get; set; }

	string Uncertainty { get; set; }

	string UncertaintySource { get; set; }

	string DataSourceType { get; set; }
}
[Serializable]
[ClassInterface(ClassInterfaceType.None)]
public class PropertyDataInfoObject : DatabaseObject, IPropertyDataInfoObject, IDatabaseObject, IDatabaseObjectIdentity, ISerializable
{
	private string myUncertainty;

	private string myUncertaintySource;

	private string myDataType;

	public string Name
	{
		get
		{
			return base.Identity;
		}
		set
		{
			base.Identity = value;
		}
	}

	public string Uncertainty
	{
		get
		{
			return myUncertainty;
		}
		set
		{
			myUncertainty = value;
		}
	}

	public string UncertaintySource
	{
		get
		{
			return myUncertaintySource;
		}
		set
		{
			myUncertaintySource = value;
		}
	}

	public string DataSourceType
	{
		get
		{
			return myDataType;
		}
		set
		{
			myDataType = value;
		}
	}

	public override DatabaseObjectType ObjectType => DatabaseObjectType.Error;

	public PropertyDataInfoObject()
	{
	}

	public PropertyDataInfoObject(string Name, string Error, string ErrorSource, string DataType)
		: base(Name, null)
	{
		myUncertainty = Error;
		myUncertaintySource = ErrorSource;
		myDataType = DataType;
	}

	protected PropertyDataInfoObject(SerializationInfo info, StreamingContext context)
		: base(info, context)
	{
		myUncertainty = info.GetString("error");
		myUncertaintySource = info.GetString("errorsource");
		myDataType = info.GetString("datatype");
	}

	internal static IDatabaseObject ResolveMoniker(IDatabaseObjectMoniker moniker)
	{
		ISundryDataManager sundryDataManager;
		if (!(moniker.Database is ISupportsSundryData) || (sundryDataManager = (moniker.Database as ISupportsSundryData).SundryDataManager) == null)
		{
			throw new GatewayException("The database does not support sundry data or an error occurred referencing the sundry data manager");
		}
		return sundryDataManager.GetItem(moniker.Identity);
	}

	public override void GetObjectData(SerializationInfo info, StreamingContext context)
	{
		base.GetObjectData(info, context);
		info.AddValue("error", myUncertainty);
		info.AddValue("errorsource", myUncertaintySource);
		info.AddValue("datatype", myDataType);
	}

	void IDatabaseObject.GetMoniker(out IDatabaseObjectMoniker Moniker)
	{
		Moniker = new DatabaseObjectMoniker(((IDatabaseObjectIdentity)this).Database, ((IDatabaseObjectIdentity)this).ObjectType, ((IDatabaseObjectIdentity)this).Identity, ResolveMoniker);
	}
}
public interface IPropertyHistoryObject
{
	string Name { get; set; }

	string History { get; set; }
}
[Serializable]
[ClassInterface(ClassInterfaceType.None)]
public class PropertyHistoryObject : DatabaseObject, IPropertyHistoryObject, IDatabaseObject, IDatabaseObjectIdentity, ISerializable
{
	private string myHistory;

	public string Name
	{
		get
		{
			return base.Identity;
		}
		set
		{
			base.Identity = value;
		}
	}

	public string History
	{
		get
		{
			return myHistory;
		}
		set
		{
			myHistory = value;
		}
	}

	public override DatabaseObjectType ObjectType => DatabaseObjectType.History;

	public PropertyHistoryObject()
	{
	}

	public PropertyHistoryObject(string Name, string History)
		: base(Name, null)
	{
		myHistory = History;
	}

	protected PropertyHistoryObject(SerializationInfo info, StreamingContext context)
		: base(info, context)
	{
		myHistory = info.GetString("History");
	}

	internal static IDatabaseObject ResolveMoniker(IDatabaseObjectMoniker moniker)
	{
		ISundryDataManager sundryDataManager;
		if (!(moniker.Database is ISupportsSundryData) || (sundryDataManager = (moniker.Database as ISupportsSundryData).SundryDataManager) == null)
		{
			throw new GatewayException("The database does not support sundry data or an error occurred referencing the sundry data manager");
		}
		return sundryDataManager.GetItem(moniker.Identity);
	}

	public override void GetObjectData(SerializationInfo info, StreamingContext context)
	{
		base.GetObjectData(info, context);
		info.AddValue("History", myHistory);
	}

	void IDatabaseObject.GetMoniker(out IDatabaseObjectMoniker Moniker)
	{
		Moniker = new DatabaseObjectMoniker(((IDatabaseObjectIdentity)this).Database, ((IDatabaseObjectIdentity)this).ObjectType, ((IDatabaseObjectIdentity)this).Identity, ResolveMoniker);
	}
}
public enum PropertyDataType
{
	Unknown = -1,
	Enumeration,
	Numeric,
	LongText
}
public interface IProperty
{
	int Id { get; }

	string Name { get; }

	string Description { get; }

	bool IsGlobal { get; }

	PropertyDataType DataType { get; }

	InteractionType InteractionType { get; }

	CompoundType CompoundType { get; }

	int ElementCount { get; }

	int[] SymmetryList { get; }

	string[] LabelList { get; }

	int[] LabelIJArray { get; }

	int[] LabelJIArray { get; }

	IUnitRow[] UnitsTypeList { get; }

	bool Status { get; }
}
public interface IPropertyManager
{
	IDatabase Database { get; }

	void AddProperty(string name, string description, bool isGlobal, PropertyDataType dataType, InteractionType interactionType, CompoundType compoundType, int elementCount, int[] symmetryList, string[] labelList, IUnitRow[] unitsTypeList, bool propStatus, out IProperty property);

	void UpdateProperty(ref IProperty property, string name, string description, bool isGlobal, PropertyDataType dataType, InteractionType interactionType, CompoundType compoundType, int elementCount, int[] symmetryList, string[] labelList, IUnitRow[] unitsTypeList);

	void RemoveProperty(IProperty property);

	void GetProperty(string name, out IProperty property);

	void GetAllProperties(IDatabank databank, bool bOnlyWithValues, out ICollection properties);

	void GetAllUnitRows(out ICollection unitRows);

	void AddPropertyEnumerations(string propertyName, ICollection enumValues);

	void RemovePropertyEnumerations(IProperty property, ICollection enumToRemove);

	void GetPropertyEnumerations(string name, out ICollection enumValues);

	void UpdatePropertyEnumerations(IProperty prop, ICollection newEnumValues);
}
public class PropertyObject : IProperty
{
	private int myId;

	private string myName;

	private string myDescription;

	private bool myIsGlobal;

	private PropertyDataType myDataType;

	private InteractionType myInteractionType;

	private CompoundType myCompoundType;

	private int myElementCount;

	private int[] mySymmetryList;

	private int[] myLabelIJList;

	private int[] myLabelJIList;

	private string[] myLabelList;

	private IUnitRow[] myUnitsTypeList;

	private bool myStatus;

	public bool Status
	{
		get
		{
			return myStatus;
		}
		set
		{
			myStatus = value;
		}
	}

	public int Id
	{
		get
		{
			return myId;
		}
		set
		{
			myId = value;
		}
	}

	public string Name
	{
		get
		{
			return myName;
		}
		set
		{
			myName = value;
		}
	}

	public string Description
	{
		get
		{
			return myDescription;
		}
		set
		{
			myDescription = value;
		}
	}

	public bool IsGlobal
	{
		get
		{
			return myIsGlobal;
		}
		set
		{
			myIsGlobal = value;
		}
	}

	public PropertyDataType DataType
	{
		get
		{
			return myDataType;
		}
		set
		{
			myDataType = value;
		}
	}

	public InteractionType InteractionType
	{
		get
		{
			return myInteractionType;
		}
		set
		{
			myInteractionType = value;
		}
	}

	public CompoundType CompoundType
	{
		get
		{
			return myCompoundType;
		}
		set
		{
			myCompoundType = value;
		}
	}

	public int ElementCount
	{
		get
		{
			return myElementCount;
		}
		set
		{
			myElementCount = value;
		}
	}

	public int[] SymmetryList
	{
		get
		{
			return mySymmetryList;
		}
		set
		{
			mySymmetryList = value;
		}
	}

	public int[] LabelIJArray
	{
		get
		{
			return myLabelIJList;
		}
		set
		{
			myLabelIJList = value;
		}
	}

	public int[] LabelJIArray
	{
		get
		{
			return myLabelJIList;
		}
		set
		{
			myLabelJIList = value;
		}
	}

	public string[] LabelList
	{
		get
		{
			return myLabelList;
		}
		set
		{
			myLabelList = value;
		}
	}

	public IUnitRow[] UnitsTypeList
	{
		get
		{
			return myUnitsTypeList;
		}
		set
		{
			myUnitsTypeList = value;
		}
	}

	public PropertyObject(int id, string name, string description, bool isGlobal, PropertyDataType dataType, InteractionType interactionType, CompoundType compoundType, int elementCount, int[] symmetryList, int[] labelIJList, int[] labelJIList, string[] labelList, IUnitRow[] unitsTypeList, bool propStatus)
	{
		myId = id;
		myName = name;
		myDescription = description;
		myIsGlobal = isGlobal;
		myDataType = dataType;
		myInteractionType = interactionType;
		myCompoundType = compoundType;
		myElementCount = elementCount;
		mySymmetryList = symmetryList;
		myLabelIJList = labelIJList;
		myLabelJIList = labelJIList;
		myLabelList = labelList;
		myUnitsTypeList = unitsTypeList;
		myStatus = propStatus;
	}

	public PropertyObject(int id, string name, string description, bool isGlobal, PropertyDataType dataType, InteractionType interactionType, CompoundType compoundType, int elementCount, int[] symmetryList, int[] labelIJList, int[] labelJIList, string[] labelList, IUnitRow[] unitsTypeList)
	{
		myId = id;
		myName = name;
		myDescription = description;
		myIsGlobal = isGlobal;
		myDataType = dataType;
		myInteractionType = interactionType;
		myCompoundType = compoundType;
		myElementCount = elementCount;
		mySymmetryList = symmetryList;
		myLabelIJList = labelIJList;
		myLabelJIList = labelJIList;
		myLabelList = labelList;
		myUnitsTypeList = unitsTypeList;
	}

	public PropertyObject()
	{
	}
}
public interface ICitation
{
	int CitationId { get; }

	string Name { get; }

	string Title { get; }

	string Pages { get; }

	string Journal { get; }

	string Date { get; }

	string Book { get; }

	string Volume { get; }

	string Publisher { get; }

	string Notes { get; }

	string Authors { get; }
}
[Serializable]
[ClassInterface(ClassInterfaceType.None)]
public class PropertyCitationsObject : DatabaseObject, ICitation, IDatabaseObject, IDatabaseObjectIdentity, ISerializable
{
	private int myCitId;

	private string myName;

	private string myTitle;

	private string myPages;

	private string myJournal;

	private string myDate;

	private string myBook;

	private string myVolume;

	private string myPublisher;

	private string myNotes;

	private string myAuthors;

	public int CitationId => myCitId;

	public string Name => base.Identity;

	public string Title => myTitle;

	public string Pages => myPages;

	public string Journal => myJournal;

	public string Date => myDate;

	public string Book => myBook;

	public string Volume => myVolume;

	public string Publisher => myPublisher;

	public string Notes => myNotes;

	public string Authors => myAuthors;

	public override DatabaseObjectType ObjectType => DatabaseObjectType.Reference;

	public PropertyCitationsObject()
	{
	}

	public PropertyCitationsObject(int id, string name, string title, string pages, string journal, string date, string book, string volume, string publisher, string notes, string authors)
		: base(name, null)
	{
		myCitId = id;
		myName = name;
		myTitle = title;
		myPages = pages;
		myJournal = journal;
		myDate = date;
		myBook = book;
		myVolume = volume;
		myPublisher = publisher;
		myNotes = notes;
		myAuthors = authors;
	}

	public PropertyCitationsObject(string name, string title, string pages, string journal, string date, string book, string volume, string publisher, string notes, string authors)
		: base(name, null)
	{
		myName = name;
		myTitle = title;
		myPages = pages;
		myJournal = journal;
		myDate = date;
		myBook = book;
		myVolume = volume;
		myPublisher = publisher;
		myNotes = notes;
		myAuthors = authors;
	}

	protected PropertyCitationsObject(SerializationInfo info, StreamingContext context)
		: base(info, context)
	{
		myTitle = info.GetString("title");
		myPages = info.GetString("pages");
		myJournal = info.GetString("journal");
		myDate = info.GetString("date");
		myBook = info.GetString("book");
		myVolume = info.GetString("volume");
		myPublisher = info.GetString("publisher");
		myNotes = info.GetString("notes");
		myAuthors = info.GetString("authors");
		myCitId = info.GetInt32("id");
	}

	internal static IDatabaseObject ResolveMoniker(IDatabaseObjectMoniker moniker)
	{
		ISundryDataManager sundryDataManager;
		if (!(moniker.Database is ISupportsSundryData) || (sundryDataManager = (moniker.Database as ISupportsSundryData).SundryDataManager) == null)
		{
			throw new GatewayException("The database does not support sundry data or an error occurred referencing the sundry data manager");
		}
		return sundryDataManager.GetItem(moniker.Identity);
	}

	public override void GetObjectData(SerializationInfo info, StreamingContext context)
	{
		base.GetObjectData(info, context);
		info.AddValue("title", myTitle);
		info.AddValue("pages", myPages);
		info.AddValue("journal", myJournal);
		info.AddValue("date", myDate);
		info.AddValue("book", myBook);
		info.AddValue("volume", myVolume);
		info.AddValue("publisher", myPublisher);
		info.AddValue("notes", myNotes);
		info.AddValue("authors", myAuthors);
	}

	void IDatabaseObject.GetMoniker(out IDatabaseObjectMoniker Moniker)
	{
		Moniker = new DatabaseObjectMoniker(((IDatabaseObjectIdentity)this).Database, ((IDatabaseObjectIdentity)this).ObjectType, ((IDatabaseObjectIdentity)this).Identity, ResolveMoniker);
	}
}
public interface IPropertyValue
{
	IDatabank Databank { get; }

	ICompound Compound { get; }

	IProperty Property { get; }

	object Value { get; }

	string Uncertainty { get; }

	string UncertaintySource { get; }

	string DataSourceType { get; }

	ICitation Citation { get; }

	ArrayList CitationList { get; set; }

	string Notes { get; }

	object History { get; }

	bool HasRegressionInfo { get; set; }
}
public interface IPropertyValueManager
{
	IDatabase Database { get; }

	void GetPropertyValue(IDatabank databank, ICompound compound, IProperty property, bool bCondensedForViewing, out IPropertyValue propertyValue);

	void GetUnaryPropertyValue(IDatabank databank, string compoundId, string compoundIdType, string propertyName, out IPropertyValue propertyValue);

	void GetBinaryPropertyValue(IDatabank databank, string compound1Id, string compound2Id, string compoundIdType, string propertyName, bool bCondensedForViewing, out IPropertyValue propertyValue);

	void GetTernaryPropertyValue(IDatabank databank, string compound1Id, string compound2Id, string compound3Id, string compoundIdType, string propertyName, out IPropertyValue propertyValue);

	void GetPairPropertyValue(IDatabank databank, string compound1Id, string compound2Id, string compound3Id, string compound4Id, string compoundIdType, string propertyName, bool bCondensedForViewing, out IPropertyValue propertyValue);

	void GetPropertyValueByIndex(int propertyValueIndex, bool bCondensedForViewing, out IPropertyValue propertyValue);

	void GetAllUnaryPropertyValues(IDatabank databank, ICompound compound, out ICollection propertyValues);

	void GetAllUnaryPropertyValues(IDatabank databank, string compoundId, string compoundIdType, out ICollection propertyValues);

	void GetAllUnaryPropertyValues(ICollection databankFilter, ICollection compoundFilter, ICollection propertyFilter, out ICollection databankList, out ICollection compoundList, out ICollection propertyList, out ICollection propertyValues);

	void GetAllBinaryPropertyValues(ICollection databankFilter, ICollection compound1Filter, ICollection compound2Filter, ICollection propertyFilter, IIdentifier identifier, out ICollection databankList, out ICollection compound1List, out ICollection compound2List, out ICollection propertyList, bool bCondensedForViewing, out ICollection propertyValues);

	void GetAllTernaryPropertyValues(ICollection databankFilter, ICollection compound1Filter, ICollection compound2Filter, ICollection compound3Filter, IIdentifier compoundIdentifier, ICollection propertyFilter, out ICollection databankList, out ICollection compound1List, out ICollection compound2List, out ICollection compound3List, out ICollection propertyList, out ICollection propertyValues);

	void GetAllPairPropertyValues(ICollection databankFilter, ICollection pair1Filter, ICollection pair2Filter, IIdentifier compoundIdentifier, ICollection propertyFilter, out ICollection databankList, out ICollection pair1List, out ICollection pair2List, out ICollection propertyList, bool bCondensedForViewing, out ICollection propertyValues);

	void AddPropertyValue(IDatabank databank, string CompoundId, string CompoundIdType, string PropertyName, object Value, string uncertainty, string uncertaintySource, string dataSourceType, ICitation citation, string notes, out IPropertyValue propertyValue);

	void AddPropertyValue(IDatabank databank, ICompound compound, IProperty property, object Value, string uncertainty, string uncertaintySource, string dataSourceType, ICitation citation, string notes, out IPropertyValue propertyValue);

	void AddBinaryPropertyValue(IDatabank databank, string Compound1Id, string Compound2Id, string CompoundIdType, string PropertyName, object Value, string uncertainty, string uncertaintySource, string dataSourceType, ICitation citation, string notes, out IPropertyValue propertyValue);

	void AddTernaryPropertyValue(IDatabank databank, string Compound1Id, string Compound2Id, string Compound3Id, string CompoundIdType, string PropertyName, object Value, string uncertainty, string uncertaintySource, string dataSourceType, ICitation citation, string notes, out IPropertyValue propertyValue);

	void AddPairPropertyValue(IDatabank databank, string Compound1Id, string Compound2Id, string Compound3Id, string Compound4Id, string CompoundIdType, string PropertyName, object Value, string uncertainty, string uncertaintySource, string dataSourceType, ICitation citation, string notes, out IPropertyValue propertyValue);

	void RemovePropertyValue(IPropertyValue propertyValue);

	void UpdatePropertyValue(ref IPropertyValue propertyValue, bool bCondensedForViewing, object newValue, string uncertainty, string uncertaintySource, string dataSourceType, ICitation citation, string notes);

	void UpdatePropertyValue(IDatabank databank, ICompound compound, IProperty property, bool bCondensedForViewing, object newValue, string uncertainty, string uncertaintySource, string dataSourceType, ICitation citation, string notes, out IPropertyValue propertyValue);

	void UpdatePropertyValue(IDatabank databank, string compoundId, string compoundIdType, string propertyName, bool bCondensedForViewing, object newValue, string uncertainty, string uncertaintySource, string dataSourceType, ICitation citation, string notes, out IPropertyValue propertyValue);

	void UpdateBinaryPropertyValue(IDatabank databank, string compound1Id, string compound2Id, string compoundIdType, string propertyName, bool bCondensedForViewing, object newValue, string uncertainty, string uncertaintySource, string dataSourceType, ICitation citation, string notes, out IPropertyValue propertyValue);

	void UpdateTernaryPropertyValue(IDatabank databank, string compound1Id, string compound2Id, string compound3Id, string compoundIdType, string propertyName, bool bCondensedForViewing, object newValue, string uncertainty, string uncertaintySource, string dataSourceType, ICitation citation, string notes, out IPropertyValue propertyValue);

	void UpdatePairPropertyValue(IDatabank databank, string compound1Id, string compound2Id, string compound3Id, string compound4Id, string compoundIdType, string propertyName, bool bCondensedForViewing, object newValue, string uncertainty, string uncertaintySource, string dataSourceType, ICitation citation, string notes, out IPropertyValue propertyValue);

	void GetAllGlobalPropertyValues(ICompound compound, int molestructType, out string molestruct, out ICollection identifierValues, out ICollection propertyValues);

	void GetAllBinaryPropertyValuesForModelManager(ICollection compoundPairs, string compoundIdType, ICollection databanks, ICollection properties, bool bCondensedForViewing, out ICollection propertyValueObjects);

	void GetAllBinaryPropertyValuesOnly(ICollection compoundPairs, string compoundIdType, ICollection databanks, ICollection properties, bool bCondensedForViewing, out ICollection propertyValueObjects);

	void GetAllPairPropertyValuesForModelManager(ICollection compoundPairs, string compoundIdType, ICollection databanks, ICollection properties, bool bCondensedForViewing, int numOfCompsIncludingDuplicates, out ICollection propertyValueObjects);

	void GetAllUnaryPropertyValues_APlus(int databankIndex, int compoundIndex, out ICollection propertyValues);

	void OptimizedGetAllScalarPropertyValues(Hashtable compIndexPositionTable, Hashtable duplicateCompTable, Hashtable PropTable, Hashtable DbankTable, Array dbankBlock, ref Hashtable ScalarValueTable);

	void OptimizedGetAllVectorPropertyValues(Hashtable compIndexPositionTable, Hashtable duplicateCompTable, Hashtable PropTable, Hashtable DbankTable, Array dbankBlock, ref Hashtable VectorValueTable);

	void OptimizedGetAllBinaryPropertyValues(int compCount, Hashtable CompTable, Hashtable compIndexPositionTable, Hashtable duplicateCompTable, Hashtable PropTable, Hashtable DbankTable, Array dbankBlock, ref Hashtable BinaryValueTable);

	bool CheckDatabankHasPropertyValues(IProperty property, IDatabank databank);

	bool CheckDatabankHasPurePropertyValues(IDatabank databank);
}
public class PropertyValueObject : DatabaseObject, IPropertyValue, IDatabaseObject, IDatabaseObjectIdentity
{
	private IDatabank myDatabank;

	private ICompound myCompound;

	private IProperty myProperty;

	private object myValue;

	private string myNotes;

	private string myUncertainty;

	private string myUncertaintySource;

	private string myDataSourceType;

	private ICitation myCitation;

	private ArrayList myCitationList;

	private object myHistory;

	private bool myHasRegressionInfo;

	public IDatabank Databank => myDatabank;

	public ICompound Compound => myCompound;

	public IProperty Property => myProperty;

	public object Value => myValue;

	public string Uncertainty => myUncertainty;

	public string UncertaintySource => myUncertaintySource;

	public string DataSourceType => myDataSourceType;

	public ICitation Citation => myCitation;

	public ArrayList CitationList
	{
		get
		{
			return myCitationList;
		}
		set
		{
			value = myCitationList;
		}
	}

	public string Notes => myNotes;

	public object History => myHistory;

	public bool HasRegressionInfo
	{
		get
		{
			return myHasRegressionInfo;
		}
		set
		{
			myHasRegressionInfo = value;
		}
	}

	public override DatabaseObjectType ObjectType => DatabaseObjectType.PropertyValue;

	public PropertyValueObject()
	{
	}

	public PropertyValueObject(IDatabank databank, ICompound compound, IProperty property, object val)
	{
		myDatabank = databank;
		myCompound = compound;
		myProperty = property;
		myValue = val;
	}

	public PropertyValueObject(IDatabank databank, ICompound compound, IProperty property, object val, bool hasRegInfo)
	{
		myDatabank = databank;
		myCompound = compound;
		myProperty = property;
		myValue = val;
		myHasRegressionInfo = hasRegInfo;
	}

	public PropertyValueObject(int PropertyValueIndex, IDatabank databank, ICompound compound, IProperty property, object val, string notes, string uncertainty, string uncertaintySource, string dataSourceType, ICitation citation, ArrayList citationList, bool hasRegInfo)
		: base(PropertyValueIndex.ToString(), databank.Database)
	{
		myDatabank = databank;
		myCompound = compound;
		myProperty = property;
		myValue = val;
		myUncertainty = uncertainty;
		myUncertaintySource = uncertaintySource;
		myDataSourceType = dataSourceType;
		myCitation = citation;
		myCitationList = citationList;
		myNotes = notes;
		myHasRegressionInfo = hasRegInfo;
	}

	internal static IDatabaseObject ResolveMoniker(IDatabaseObjectMoniker moniker)
	{
		IPropertyValueManager propertyValueManager;
		if (!(moniker.Database is ISupportsPropertyValues) || (propertyValueManager = (moniker.Database as ISupportsPropertyValues).PropertyValueManager) == null)
		{
			throw new GatewayException("The database does not support compound property data");
		}
		IPropertyValue propertyValue = null;
		propertyValueManager.GetPropertyValueByIndex(Convert.ToInt32(moniker.Identity), bCondensedForViewing: false, out propertyValue);
		return (IDatabaseObject)propertyValue;
	}

	void IDatabaseObject.GetMoniker(out IDatabaseObjectMoniker Moniker)
	{
		Moniker = new DatabaseObjectMoniker(((IDatabaseObjectIdentity)this).Database, ((IDatabaseObjectIdentity)this).ObjectType, ((IDatabaseObjectIdentity)this).Identity, ResolveMoniker);
	}
}
public interface IReaction
{
	IDatabank Databank { get; set; }

	int Id { get; set; }

	string Name { get; set; }

	string Type { get; set; }

	string Basis { get; set; }

	string Phase { get; set; }

	string EquationType { get; set; }
}
public interface IReactionManager
{
	IDatabase Database { get; }

	void AddReaction(IDatabank databank, string reactnName, string reactnType, ICollection synArrList, ICollection coeffsArrList, ICollection exponentArrList, ICollection eqConstsArrList, string reactnBasis, string reactnPhase, string eqType, ArrayList SymmetricEqConsts, string SymmetricEqConstBasis, out IReaction reaction);

	void GetReactionByName(string Name, out IReaction Reaction);

	void DeleteReaction(string reactnName);

	void GetCompoundsReactions(ICollection compids, string identifier, ICollection databanks, out ICollection reactions);

	void GetAllReactionsCount(IDatabank databank, out int rxnCount);
}
public class ReactionObject : IReaction
{
	private IDatabank myDatabank;

	private int reactn_Id;

	private string reactn_Name;

	private string reactn_Type;

	private string reactn_Basis;

	private ArrayList reactn_Synonyms;

	private ArrayList reactn_Coefficients;

	private ArrayList reactn_Exponents;

	private ArrayList reactn_EqConsts;

	private string reactn_Phase;

	private string reactn_EqType;

	private ArrayList reactn_SymmetricEqConsts;

	private string reactn_SymmetricEqConstBasis;

	public int Id
	{
		get
		{
			return reactn_Id;
		}
		set
		{
			reactn_Id = value;
		}
	}

	public string Name
	{
		get
		{
			return reactn_Name;
		}
		set
		{
			reactn_Name = value;
		}
	}

	public string Type
	{
		get
		{
			return reactn_Type;
		}
		set
		{
			reactn_Type = value;
		}
	}

	public string Basis
	{
		get
		{
			return reactn_Basis;
		}
		set
		{
			reactn_Basis = value;
		}
	}

	public ArrayList Synonyms
	{
		get
		{
			return reactn_Synonyms;
		}
		set
		{
			reactn_Synonyms = value;
		}
	}

	public ArrayList Coefficients
	{
		get
		{
			return reactn_Coefficients;
		}
		set
		{
			reactn_Coefficients = value;
		}
	}

	public ArrayList Exponents
	{
		get
		{
			return reactn_Exponents;
		}
		set
		{
			reactn_Exponents = value;
		}
	}

	public ArrayList EqConsts
	{
		get
		{
			return reactn_EqConsts;
		}
		set
		{
			reactn_EqConsts = value;
		}
	}

	public IDatabank Databank
	{
		get
		{
			return myDatabank;
		}
		set
		{
			myDatabank = value;
		}
	}

	public string Phase
	{
		get
		{
			return reactn_Phase;
		}
		set
		{
			reactn_Phase = value;
		}
	}

	public string EquationType
	{
		get
		{
			return reactn_EqType;
		}
		set
		{
			reactn_EqType = value;
		}
	}

	public ArrayList SymmetricEqConsts
	{
		get
		{
			return reactn_SymmetricEqConsts;
		}
		set
		{
			reactn_SymmetricEqConsts = value;
		}
	}

	public string SymmetricEqConstBasis
	{
		get
		{
			return reactn_SymmetricEqConstBasis;
		}
		set
		{
			reactn_SymmetricEqConstBasis = value;
		}
	}

	public ReactionObject(IDatabank databank, int id, string name, string type, string basis, ArrayList SynList, ArrayList CoeffList, ArrayList ExpoList, ArrayList EqConstList, string phase, string eqType, ArrayList SymmetricEqConsts, string SymmetricEqConstBasis)
	{
		myDatabank = databank;
		reactn_Id = id;
		reactn_Name = name;
		reactn_Type = type;
		reactn_Basis = basis;
		reactn_Synonyms = SynList;
		reactn_Coefficients = CoeffList;
		reactn_Exponents = ExpoList;
		reactn_EqConsts = EqConstList;
		reactn_Phase = phase;
		reactn_EqType = eqType;
		reactn_SymmetricEqConsts = SymmetricEqConsts;
		reactn_SymmetricEqConstBasis = SymmetricEqConstBasis;
	}

	public ReactionObject(IDatabank databank, string name, string type, string basis, ArrayList SynList, ArrayList CoeffList, ArrayList ExpoList, ArrayList EqConstList, string phase, string eqType, ArrayList SymmetricEqConsts, string SymmetricEqConstBasis)
	{
		myDatabank = databank;
		reactn_Name = name;
		reactn_Type = type;
		reactn_Basis = basis;
		reactn_Synonyms = SynList;
		reactn_Coefficients = CoeffList;
		reactn_Exponents = ExpoList;
		reactn_EqConsts = EqConstList;
		reactn_Phase = phase;
		reactn_EqType = eqType;
		reactn_SymmetricEqConsts = SymmetricEqConsts;
		reactn_SymmetricEqConstBasis = SymmetricEqConstBasis;
	}

	public SortedList GetReactionExponents()
	{
		ArrayList synonyms = Synonyms;
		ArrayList exponents = Exponents;
		SortedList sortedList = new SortedList();
		if (exponents != null && exponents.Count > 0)
		{
			for (int i = 0; i < exponents.Count; i++)
			{
				if (exponents[i] != null)
				{
					sortedList.Add(synonyms[i], exponents[i]);
				}
				else
				{
					sortedList.Add(synonyms[i], 1E+35);
				}
			}
		}
		return sortedList;
	}

	public string GetReactionEquation()
	{
		ArrayList synonyms = Synonyms;
		ArrayList coefficients = Coefficients;
		ArrayList eqConsts = EqConsts;
		ArrayList arrayList = new ArrayList();
		ArrayList arrayList2 = new ArrayList();
		ArrayList arrayList3 = new ArrayList();
		ArrayList arrayList4 = new ArrayList();
		for (int i = 0; i < synonyms.Count; i++)
		{
			if ((double)coefficients[i] <= 0.0)
			{
				arrayList.Add(synonyms[i]);
				arrayList2.Add(coefficients[i]);
			}
			else
			{
				arrayList3.Add(synonyms[i]);
				arrayList4.Add(coefficients[i]);
			}
		}
		string text = "";
		double num = (double)arrayList2[arrayList2.Count - 1];
		for (int j = 0; j < arrayList.Count; j++)
		{
			double num2 = -1.0 * (double)arrayList2[j];
			if (j == arrayList.Count - 1)
			{
				if (num2 != 0.0)
				{
					text = ((num2 != 1.0) ? (text + num2 + " " + (string)arrayList[j]) : (text + (string)arrayList[j]));
				}
				if (Type == "SALT")
				{
					text += "(S)";
				}
			}
			else
			{
				if (num2 != 0.0)
				{
					text = ((num2 != 1.0) ? (text + num2 + " " + (string)arrayList[j]) : (text + (string)arrayList[j]));
				}
				if (num2 != 0.0 && (num != 0.0 || j != arrayList.Count - 2))
				{
					text += " + ";
				}
			}
		}
		string text2 = "";
		for (int k = 0; k < arrayList3.Count; k++)
		{
			text2 = ((k != arrayList3.Count - 1) ? (((double)arrayList4[k] != 1.0) ? (text2 + arrayList4[k].ToString() + " " + (string)arrayList3[k] + "  +  ") : (text2 + (string)arrayList3[k] + "  +  ")) : (((double)arrayList4[k] != 1.0) ? (text2 + arrayList4[k].ToString() + " " + (string)arrayList3[k]) : (text2 + (string)arrayList3[k])));
		}
		string text3 = text;
		text3 = ((!(Type == "STOIC") && !(Type == "SALT") && !(Type == "WATER") && !(Type == "ICE")) ? (text3 + "  ---->  ") : (text3 + "  <---->  "));
		return text3 + text2;
	}

	public virtual bool Equals(ReactionObject obj)
	{
		if (Name == obj.Name)
		{
			return true;
		}
		return false;
	}
}
public interface ISundryDataManager
{
	IDatabase Database { get; }

	IList Items { get; }

	IDatabaseObject GetItem(string Identity);

	void UpdateItem(IDatabaseObject Item);

	void RemoveItem(string Identity);

	void DeleteItem(string Identity);
}
internal class UnifacMainGroupListEvaluator : IGatewayEvaluator
{
	private ArrayList myGroups;

	public UnifacMainGroupListEvaluator()
	{
		myGroups = new ArrayList();
	}

	public bool Evaluate(IDatabank Databank, IDatabase Database)
	{
		if (Database == null)
		{
			throw new ArgumentException("A valid database must be given", "Database");
		}
		if (!(Database is ISupportsUnifacGroups))
		{
			return false;
		}
		IUnifacGroups unifacGroupManager = ((ISupportsUnifacGroups)Database).UnifacGroupManager;
		if (unifacGroupManager == null)
		{
			return false;
		}
		unifacGroupManager.GetMainGroups(out var MainGroups);
		myGroups.Add(MainGroups);
		return false;
	}

	public void Result(out string[] groups)
	{
		groups = null;
		myGroups.CopyTo(groups, 0);
	}
}
internal class UnifacSubgroupListEvaluator : IGatewayEvaluator
{
	private ArrayList mySubgroups;

	private ArrayList myMainGroups;

	public UnifacSubgroupListEvaluator()
	{
		mySubgroups = new ArrayList();
		myMainGroups = new ArrayList();
	}

	public bool Evaluate(IDatabank Databank, IDatabase Database)
	{
		if (Database == null)
		{
			throw new ArgumentException("A valid database must be given", "Database");
		}
		if (!(Database is ISupportsUnifacGroups))
		{
			return false;
		}
		IUnifacGroups unifacGroupManager = ((ISupportsUnifacGroups)Database).UnifacGroupManager;
		if (unifacGroupManager == null)
		{
			return false;
		}
		unifacGroupManager.GetSubgroups(out var Subgroups, out var MainGroups);
		for (int i = 0; i < Subgroups.Length; i++)
		{
			string text = Subgroups[i];
			if (!mySubgroups.Contains(text))
			{
				mySubgroups.Add(text);
				myMainGroups.Add(MainGroups[i]);
			}
		}
		return false;
	}

	public void Result(out string[] subgroups, out string[] mainGroups)
	{
		subgroups = (string[])mySubgroups.ToArray(typeof(string));
		mainGroups = (string[])myMainGroups.ToArray(typeof(string));
	}
}
internal class UnifacMainGroupInteractionModelListEvaluator : IGatewayEvaluator
{
	private ArrayList myModels;

	public UnifacMainGroupInteractionModelListEvaluator()
	{
		myModels = new ArrayList();
	}

	public bool Evaluate(IDatabank Databank, IDatabase Database)
	{
		if (Database == null)
		{
			throw new ArgumentException("A valid database must be given", "Database");
		}
		if (!(Database is ISupportsUnifacGroups))
		{
			return false;
		}
		IUnifacGroups unifacGroupManager = ((ISupportsUnifacGroups)Database).UnifacGroupManager;
		if (unifacGroupManager == null)
		{
			return false;
		}
		unifacGroupManager.GetMainGroupInteractionModels(out var Models);
		myModels.Add(Models);
		return false;
	}

	public void Result(out string[] models)
	{
		models = null;
		myModels.CopyTo(models, 0);
	}
}
internal class UnifacMainGroupInteractionsEvaluator : IGatewayEvaluator
{
	private string myModelName;

	private string myGroup1Formula;

	private string myGroup2Formula;

	private double[] myParameters;

	private IDatabank myDatabank;

	private bool mybCondensedForViewing;

	public UnifacMainGroupInteractionsEvaluator(string ModelName, string Group1Formula, string Group2Formula, bool bCondensedForViewing)
	{
		myModelName = ModelName;
		myGroup1Formula = Group1Formula;
		myGroup2Formula = Group2Formula;
		mybCondensedForViewing = bCondensedForViewing;
	}

	public bool Evaluate(IDatabank Databank, IDatabase Database)
	{
		return false;
	}

	public void Result(out IDatabank databank, out double[] parameters)
	{
		databank = myDatabank;
		parameters = myParameters;
	}
}
internal class UnifacSubgroupParametersEvaluator : IGatewayEvaluator
{
	private string mySubgroupFormula;

	private double myR;

	private double myQ;

	private IDatabank myDatabank;

	public UnifacSubgroupParametersEvaluator(string SubgroupFormula)
	{
		mySubgroupFormula = SubgroupFormula;
	}

	public bool Evaluate(IDatabank Databank, IDatabase Database)
	{
		return false;
	}

	public void Result(out IDatabank databank, out double r, out double q)
	{
		databank = myDatabank;
		r = myR;
		q = myQ;
	}
}
public interface IUnifacGateway
{
	IDatabankCollection Databanks { get; set; }

	void GetMainGroups(out string[] MainGroups);

	void GetSubgroups(out string[] Subgroups, out string[] MainGroups);

	void GetMainGroupInteractionModels(out string[] Models);

	void GetMainGroupInteractions(string ModelName, string Group1Formula, string Group2Formula, bool bCondensedForViewing, out double[] Values, out IDatabank Databank);

	void GetSubgroupParameters(string SubgroupFormula, out double R, out double Q, out IDatabank Databank);
}
[ClassInterface(ClassInterfaceType.None)]
public class UnifacGateway : IUnifacGateway
{
	private IDatabankCollection myDatabankList;

	public IDatabankCollection Databanks
	{
		get
		{
			return myDatabankList;
		}
		set
		{
			myDatabankList = value;
		}
	}

	public void GetMainGroups(out string[] MainGroups)
	{
		MainGroups = null;
		try
		{
			EvaluateOnDatabasesAlgorithm evaluateOnDatabasesAlgorithm = new EvaluateOnDatabasesAlgorithm();
			UnifacMainGroupListEvaluator unifacMainGroupListEvaluator = new UnifacMainGroupListEvaluator();
			evaluateOnDatabasesAlgorithm.Execute(myDatabankList, unifacMainGroupListEvaluator);
			unifacMainGroupListEvaluator.Result(out MainGroups);
		}
		catch (GatewayException)
		{
			throw;
		}
		catch (Exception inner)
		{
			throw new GatewayException("An error occurred retrieving the UNIFAC main groups", inner);
		}
	}

	public void GetSubgroups(out string[] Subgroups, out string[] MainGroups)
	{
		Subgroups = null;
		MainGroups = null;
		try
		{
			EvaluateOnDatabasesAlgorithm evaluateOnDatabasesAlgorithm = new EvaluateOnDatabasesAlgorithm();
			UnifacSubgroupListEvaluator unifacSubgroupListEvaluator = new UnifacSubgroupListEvaluator();
			evaluateOnDatabasesAlgorithm.Execute(myDatabankList, unifacSubgroupListEvaluator);
			unifacSubgroupListEvaluator.Result(out Subgroups, out MainGroups);
		}
		catch (GatewayException)
		{
			throw;
		}
		catch (Exception inner)
		{
			throw new GatewayException("An error occurred retrieving the UNIFAC subgroups", inner);
		}
	}

	public void GetMainGroupInteractionModels(out string[] Models)
	{
		Models = null;
		try
		{
			EvaluateOnDatabasesAlgorithm evaluateOnDatabasesAlgorithm = new EvaluateOnDatabasesAlgorithm();
			UnifacMainGroupInteractionModelListEvaluator unifacMainGroupInteractionModelListEvaluator = new UnifacMainGroupInteractionModelListEvaluator();
			evaluateOnDatabasesAlgorithm.Execute(myDatabankList, unifacMainGroupInteractionModelListEvaluator);
			unifacMainGroupInteractionModelListEvaluator.Result(out Models);
		}
		catch (GatewayException)
		{
			throw;
		}
		catch (Exception inner)
		{
			throw new GatewayException("An error occurred retrieving the UNIFAC main group interaction models", inner);
		}
	}

	public void GetMainGroupInteractions(string ModelName, string Group1Formula, string Group2Formula, bool bCondensedForViewing, out double[] Values, out IDatabank Databank)
	{
		Values = null;
		try
		{
			EvaluateOnDatabanksAlgorithm evaluateOnDatabanksAlgorithm = new EvaluateOnDatabanksAlgorithm();
			UnifacMainGroupInteractionsEvaluator unifacMainGroupInteractionsEvaluator = new UnifacMainGroupInteractionsEvaluator(ModelName, Group1Formula, Group2Formula, bCondensedForViewing);
			evaluateOnDatabanksAlgorithm.Execute(myDatabankList, unifacMainGroupInteractionsEvaluator);
			unifacMainGroupInteractionsEvaluator.Result(out Databank, out Values);
		}
		catch (GatewayException)
		{
			throw;
		}
		catch (Exception inner)
		{
			throw new GatewayException("An error occurred retrieving the UNIFAC main group interaction parameters", inner);
		}
	}

	public void GetSubgroupParameters(string SubgroupFormula, out double R, out double Q, out IDatabank Databank)
	{
		R = 0.0;
		Q = 0.0;
		try
		{
			EvaluateOnDatabanksAlgorithm evaluateOnDatabanksAlgorithm = new EvaluateOnDatabanksAlgorithm();
			UnifacSubgroupParametersEvaluator unifacSubgroupParametersEvaluator = new UnifacSubgroupParametersEvaluator(SubgroupFormula);
			evaluateOnDatabanksAlgorithm.Execute(myDatabankList, unifacSubgroupParametersEvaluator);
			unifacSubgroupParametersEvaluator.Result(out Databank, out R, out Q);
		}
		catch (GatewayException)
		{
			throw;
		}
		catch (Exception inner)
		{
			throw new GatewayException("An error occurred retrieving the UNIFAC subgroup parameters", inner);
		}
	}
}
public interface IUnifacGroupManager
{
	IDatabase Database { get; }

	void AddMainGroup(string Formula);

	void RemoveMainGroup(string Formula);

	void DeleteMainGroup(string Formula);

	void AddSubgroup(string Formula, string MainGroupFormula);

	void RemoveSubgroup(string Formula);

	void DeleteSubgroup(string Formula);
}
public interface IUnifacGroups
{
	IDatabase Database { get; }

	void GetMainGroups(out string[] MainGroups);

	void GetSubgroups(out string[] Subgroups, out string[] MainGroups);

	void GetMainGroupInteractionModels(out string[] Models);

	bool GetMainGroupInteractions(IDatabank Databank, string ModelName, string Group1Formula, string Group2Formula, bool bCondensedForViewing, out double[] Values);

	void UpdateMainGroupInteractions(IDatabank Databank, string ModelName, string Group1Formula, string Group2Formula, double[] Values, bool bCondensedForViewing);

	bool GetSubgroupParameters(IDatabank Databank, string SubgroupFormula, out double R, out double Q);

	void UpdateSubgroupParameters(IDatabank Databank, string SubgroupFormula, double R, double Q);
}
public class UnitRowObject : IUnitRow, IComparable
{
	private int myRowId;

	private string myUnitRowName;

	private string myDefaultUOM;

	public int RowId
	{
		get
		{
			return myRowId;
		}
		set
		{
			myRowId = value;
		}
	}

	public string UnitRowName
	{
		get
		{
			return myUnitRowName;
		}
		set
		{
			myUnitRowName = value;
		}
	}

	public string DefaultUOM
	{
		get
		{
			return myDefaultUOM;
		}
		set
		{
			myDefaultUOM = value;
		}
	}

	public UnitRowObject(int row_id, string unit_rowname, string default_uom)
	{
		myRowId = row_id;
		myUnitRowName = unit_rowname;
		myDefaultUOM = default_uom;
	}

	public int CompareTo(object obj)
	{
		return UnitRowName.ToUpperInvariant().CompareTo(((UnitRowObject)obj).UnitRowName.ToUpperInvariant());
	}
}
public interface IUOMDataGateway
{
	IDatabankCollection Databanks { get; set; }

	void GetRowNameAndUOM(int RowId, out string RowName, out string DefaultUOM);

	int GetRowId(string RowName);
}
[ClassInterface(ClassInterfaceType.None)]
public class UOMDataGateway : IUOMDataGateway
{
	private IDatabankCollection myDatabankList;

	public IDatabankCollection Databanks
	{
		get
		{
			return myDatabankList;
		}
		set
		{
			myDatabankList = value;
		}
	}

	public void GetRowNameAndUOM(int RowId, out string RowName, out string DefaultUOM)
	{
		DefaultUOM = "";
		RowName = "";
		try
		{
			EvaluateOnDatabasesAlgorithm evaluateOnDatabasesAlgorithm = new EvaluateOnDatabasesAlgorithm();
			RowNameAndUOMEvaluator rowNameAndUOMEvaluator = new RowNameAndUOMEvaluator(RowId);
			evaluateOnDatabasesAlgorithm.Execute(myDatabankList, rowNameAndUOMEvaluator);
			rowNameAndUOMEvaluator.Result(out RowName, out DefaultUOM);
		}
		catch (GatewayException)
		{
			throw;
		}
		catch (Exception inner)
		{
			throw new GatewayException("An error occurred retrieving the UNIFAC main groups", inner);
		}
	}

	public int GetRowId(string RowName)
	{
		int rowid = -1;
		try
		{
			EvaluateOnDatabasesAlgorithm evaluateOnDatabasesAlgorithm = new EvaluateOnDatabasesAlgorithm();
			RowIdEvaluator rowIdEvaluator = new RowIdEvaluator(RowName);
			evaluateOnDatabasesAlgorithm.Execute(myDatabankList, rowIdEvaluator);
			rowIdEvaluator.Result(out rowid);
			return rowid;
		}
		catch (GatewayException)
		{
			throw;
		}
		catch (Exception inner)
		{
			throw new GatewayException("An error occurred while retrieving the unit of measure RowId", inner);
		}
	}
}
public interface IUnitRow
{
	int RowId { get; }

	string UnitRowName { get; }

	string DefaultUOM { get; }
}
public interface IUOMDataManager
{
	IDatabase Database { get; }

	void AddUOMData(int RowId, string RowName, string DefaultUOM);

	void DeleteUOMData(int RowId);

	bool UpdateUOMData(int RowId, string RowName, string DefaultUOM);

	void RemoveUOMData(int RowId);
}
public interface IUOMData
{
	IDatabase Database { get; }

	void GetRowNameAndUOM(int RowId, out string RowName, out string DefaultUOM);

	int GetRowId(string RowName);

	bool UpdateUOMData(int RowId, string RowName, string DefaultUOM);
}
internal class RowNameAndUOMEvaluator : IGatewayEvaluator
{
	private string myRowName;

	private string myUOM;

	private int myRowId;

	public RowNameAndUOMEvaluator(int RowId)
	{
		myRowId = RowId;
	}

	public bool Evaluate(IDatabank Databank, IDatabase Database)
	{
		if (Database == null)
		{
			throw new ArgumentException("A valid database must be given", "Database");
		}
		if (!(Database is ISupportsUOMData))
		{
			return false;
		}
		IUOMData iUOMData = (IUOMData)((ISupportsUOMData)Database).UOMDataManager;
		if (iUOMData == null)
		{
			return false;
		}
		iUOMData.GetRowNameAndUOM(myRowId, out myRowName, out myUOM);
		if (myRowName != null)
		{
			return true;
		}
		return false;
	}

	public void Result(out string row_name, out string uom_)
	{
		uom_ = myUOM;
		row_name = myRowName;
	}
}
internal class RowIdEvaluator : IGatewayEvaluator
{
	private int myRowId;

	private string myRowName;

	public RowIdEvaluator(string rowname)
	{
		myRowName = rowname;
		myRowId = -1;
	}

	public bool Evaluate(IDatabank Databank, IDatabase Database)
	{
		if (Database == null)
		{
			throw new ArgumentException("A valid database must be given", "Database");
		}
		if (!(Database is ISupportsUOMData))
		{
			return false;
		}
		IUOMData iUOMData = (IUOMData)((ISupportsUOMData)Database).UOMDataManager;
		if (iUOMData == null)
		{
			return false;
		}
		myRowId = iUOMData.GetRowId(myRowName);
		if (myRowId != -1)
		{
			return true;
		}
		return false;
	}

	public void Result(out int rowid)
	{
		rowid = myRowId;
	}
}
