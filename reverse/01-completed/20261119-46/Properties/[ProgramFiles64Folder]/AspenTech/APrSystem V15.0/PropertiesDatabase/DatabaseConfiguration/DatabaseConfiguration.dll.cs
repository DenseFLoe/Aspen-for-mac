using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.CompilerServices;
using System.Runtime.Serialization;
using System.Runtime.Versioning;
using System.Security.Principal;
using System.Windows.Forms;
using AspenTech.APED.Core;
using Microsoft.Win32;
using Npgsql;

[assembly: CompilationRelaxations(8)]
[assembly: RuntimeCompatibility(WrapNonExceptionThrows = true)]
[assembly: Debuggable(DebuggableAttribute.DebuggingModes.IgnoreSymbolStoreSequencePoints)]
[assembly: TargetFramework(".NETCoreApp,Version=v8.0", FrameworkDisplayName = ".NET 8.0")]
[assembly: AssemblyCompany("DatabaseConfiguration")]
[assembly: AssemblyConfiguration("Release")]
[assembly: AssemblyFileVersion("1.0.0.0")]
[assembly: AssemblyInformationalVersion("1.0.0+7024f19569bdfd8162c7b1a42b39bc5f552cdb3f")]
[assembly: AssemblyProduct("DatabaseConfiguration")]
[assembly: AssemblyTitle("DatabaseConfiguration")]
[assembly: TargetPlatform("Windows8.0")]
[assembly: SupportedOSPlatform("Windows8.0")]
[assembly: AssemblyVersion("1.0.0.0")]
// RefSafetyRules(11) is emitted by the C# compiler.
namespace DatabaseConfiguration;

internal class DatabaseInfor : IDatabaseInfor
{
	public string DatabaseName { get; internal set; }

	public int Components { get; internal set; }

	public int Databanks { get; internal set; }

	public int rxn { get; internal set; }

	public DatabaseInfor()
	{
		DatabaseName = string.Empty;
		Components = 0;
		Databanks = 0;
		rxn = 0;
	}
}
public class FrmDBConfig : Form
{
	private bool isDragging;

	private Point mouseLocation;

	private static string dbProvider = "postgres";

	private static string pgPassword = string.Empty;

	private static string pgOutput = string.Empty;

	private static string pgVersion = string.Empty;

	private static string pgPort = string.Empty;

	private static string pgCommand = string.Empty;

	private static string pgConnString = string.Empty;

	private static string pgDefaultDB = "postgres";

	private static string pgHost = "localhost";

	private static string pgUser = "postgres";

	private static bool pgSuccess;

	private static string pgRunType = string.Empty;

	private static string apedVersion = "41.0";

	private static string apedVersionPath = "C:\\ProgramData\\AspenTech\\APED V15.0";

	private static string pgDatabaseLogPath = apedVersionPath + "\\pgDatabases.log";

	private static string pgDatabasesPath = apedVersionPath + "\\pgDatabases.dat";

	private static string pgBackupFilePath = string.Empty;

	private static bool pgPortLine = false;

	private IDatabaseCollection myDatabases;

	private IDatabaseCollection mySQLDatabases;

	private string myError = string.Empty;

	private string myView = "ATVIEWER";

	private string myDbProvider = "postgres";

	private ArrayList myListOfAvailableSQLDatabases = new ArrayList();

	private ArrayList myListOfAvailablePGDatabases = new ArrayList();

	private ArrayList myListOfDatabases = new ArrayList();

	private ArrayList myListOfDefaults = new ArrayList();

	private string myCurrentDatabase = string.Empty;

	private IDatabase myDatabase;

	private ICompoundManager myCompoundManager;

	private IPropertyManager myPropertyManager;

	private IPropertyValueManager myPropertyValueManager;

	private IReactionManager myReactionManager;

	private ICollection myCompounds;

	private IDatabankCollection myDatabanks;

	private IDatabank myReactionsDB;

	private bool myReactions;

	private Dictionary<string, IDatabaseInfor> myCollectionListOfDatabases = new Dictionary<string, IDatabaseInfor>();

	private Dictionary<string, IDatabaseInfor> myCollectionListOfSQLDatabases = new Dictionary<string, IDatabaseInfor>();

	private string myBackupFile = string.Empty;

	private string myDatabaseName = string.Empty;

	private IContainer components;

	private Button buttonClose;

	private Label labelServer;

	private TextBox textBoxServer;

	private Label labelDBAvailable;

	private ListBox listBoxDBAvaiable;

	private Label labelRestore;

	private Button buttonImport;

	private TextBox textBoxBackup;

	private Button buttonRestore;

	private TextBox textBoxRestoreStatus;

	private Label labelDatabase;

	private Label labelComponents;

	private Label labelDatabanks;

	private Label labelReactions;

	private TextBox textBoxDatabase;

	private TextBox textBoxComponents;

	private TextBox textBoxDatabanks;

	private TextBox textBoxReactions;

	private OpenFileDialog openFileDialog1;

	private Label labelNewDB;

	private TextBox textBoxNewDB;

	private Label lblFrmTitle;

	private Label lblCloseButton;

	private Button buttonViewLogFile;

	private Label labelDBProvider;

	private RadioButton radioButtonPostgres;

	private RadioButton radioButtonSQL;

	private TextBox textBoxpgStartPath;

	public FrmDBConfig()
	{
		InitializeComponent();
		openFileDialog1.Filter = "PostgreSQL backup file|*.tar";
		openFileDialog1.InitialDirectory = apedVersionPath;
		textBoxComponents.Enabled = false;
		textBoxDatabanks.Enabled = false;
		textBoxDatabase.Enabled = false;
		textBoxReactions.Enabled = false;
		textBoxBackup.Enabled = false;
		textBoxNewDB.Enabled = false;
		textBoxRestoreStatus.Enabled = false;
		SetupConfiguration();
	}

	public void SetupConfiguration()
	{
		if (string.IsNullOrEmpty(RegistryUtility.GetPostgresVersion(apedVersion)))
		{
			myDbProvider = "mssql";
			radioButtonPostgres.Enabled = false;
		}
		else
		{
			myDbProvider = RegistryUtility.GetdbProviderForCurrentUser(apedVersion);
			if (string.IsNullOrEmpty(myDbProvider))
			{
				myDbProvider = RegistryUtility.GetdbProvider(apedVersion);
				if (string.IsNullOrEmpty(myDbProvider))
				{
					myDbProvider = "postgres";
				}
			}
		}
		if (myDbProvider == "postgres")
		{
			radioButtonPostgres.Checked = true;
			SetupPostgres();
		}
		else
		{
			radioButtonSQL.Checked = true;
			SetupMssql();
		}
	}

	public void SetupPostgres()
	{
		lblFrmTitle.Text = "Database Configuration for PostgreSQL";
		labelServer.Text = "PostgreSQL Server:";
		textBoxBackup.Text = string.Empty;
		textBoxNewDB.Text = string.Empty;
		textBoxRestoreStatus.Text = string.Empty;
		buttonImport.Enabled = true;
		buttonRestore.Enabled = true;
		SetupPGConfiguration();
	}

	public void SetupMssql()
	{
		lblFrmTitle.Text = "Database Configuration for SQL Server";
		labelServer.Text = "SQL Server:";
		textBoxBackup.Text = string.Empty;
		textBoxNewDB.Text = string.Empty;
		textBoxRestoreStatus.Text = "Using Database Manager or Tester to restore SQL databases.";
		buttonImport.Enabled = false;
		buttonRestore.Enabled = false;
		SetupSQLConfiguration();
	}

	public void SetupPGConfiguration()
	{
		if (IsAdministrator())
		{
			ApedApplication.UpdateErrorReports("Database Configuration for PostgreSQL databases started here...");
		}
		if (!IsAdministrator())
		{
			buttonViewLogFile.Enabled = false;
			buttonViewLogFile.Visible = false;
		}
		else
		{
			buttonViewLogFile.Enabled = true;
			buttonViewLogFile.Visible = true;
		}
		new Stopwatch().Restart();
		SetServerLocation();
		if (CheckpgDatabasesDat(out pgPort).Count == 0)
		{
			textBoxServer.Text += " - the server is not setup correctly. Check installation.";
		}
		else if (myListOfAvailablePGDatabases.Count == 0)
		{
			Cursor = Cursors.WaitCursor;
			myDatabases = new DatabaseCollection();
			if (string.IsNullOrEmpty(pgPort))
			{
				pgPort = RegistryUtility.GetPostgresPort(apedVersion, out pgVersion);
				myError = myDatabases.InitializeFromConfigurationFile(myView, myDbProvider, pgPort);
			}
			else
			{
				myError = myDatabases.InitializeFromConfigurationFile(myView, myDbProvider);
			}
			if (myDatabases.Count > 0)
			{
				foreach (IDatabase myDatabase in myDatabases)
				{
					if (!myListOfAvailablePGDatabases.Contains(myDatabase))
					{
						myListOfAvailablePGDatabases.Add(myDatabase.Alias);
					}
				}
				UpdateListOfDatabases(myListOfAvailablePGDatabases);
				myListOfDefaults = ApedApplication.GetDefaults();
				myListOfDatabases = ApedApplication.GetListOfDatabases();
				if (ApedApplication.pgPortForCurrentUser())
				{
					if (IsAdministrator())
					{
						AddPortLineToDatFile("port:" + pgPort);
						pgPortLine = true;
					}
					else if (!pgPortLine)
					{
						pgPortLine = true;
					}
				}
				textBoxServer.Text += " is running normally.";
			}
			else
			{
				listBoxDBAvaiable.Items.Clear();
				if (IsAdministrator())
				{
					ApedApplication.UpdateErrorReports(myError);
				}
				if (myError.Contains("The port number for PostgreSQL Server is not provided. Check you installation"))
				{
					textBoxServer.Text = "The port number for PostgreSQL is not provided. Check you installation";
				}
				else if (myError.Contains("No connection could be made"))
				{
					textBoxServer.Text += " is not running. Run pgStart.bat from CMD.";
					textBoxpgStartPath.Visible = true;
					textBoxpgStartPath.Text = apedVersionPath + "\\pgStart.dat";
				}
				else
				{
					textBoxServer.Text += " is not setup correctly. Check installation.";
				}
			}
			Cursor = Cursors.Default;
		}
		else
		{
			textBoxServer.Text += " is running normally.";
			UpdateListOfDatabases(myListOfAvailablePGDatabases);
		}
	}

	public void SetupSQLConfiguration()
	{
		new Stopwatch().Restart();
		Cursor = Cursors.WaitCursor;
		buttonViewLogFile.Enabled = false;
		buttonViewLogFile.Visible = false;
		if (myListOfAvailableSQLDatabases.Count == 0)
		{
			mySQLDatabases = new DatabaseCollection();
			myError = mySQLDatabases.InitializeFromConfigurationFile(myView, myDbProvider);
			if (mySQLDatabases.Count > 0)
			{
				foreach (IDatabase mySQLDatabase in mySQLDatabases)
				{
					if (!myListOfAvailableSQLDatabases.Contains(mySQLDatabase))
					{
						myListOfAvailableSQLDatabases.Add(mySQLDatabase.Alias);
					}
				}
				UpdateListOfDatabases(myListOfAvailableSQLDatabases);
				textBoxServer.Text = "The SQL Server is running normally.";
				if (!string.IsNullOrEmpty(GlobalControl.InstanceVersion))
				{
					string instanceVersion = GlobalControl.InstanceVersion;
					if (!(instanceVersion == "15"))
					{
						if (instanceVersion == "16")
						{
							textBoxServer.Text = "SqlLocalDB 2022 is running normally.";
						}
					}
					else
					{
						textBoxServer.Text = "SqlLocalDB 2019 is running normally.";
					}
				}
			}
			else
			{
				textBoxServer.Text = "No SQL Server databases are available.";
				listBoxDBAvaiable.Items.Clear();
			}
		}
		else
		{
			textBoxServer.Text = "The SQL Server is running normally.";
			if (!string.IsNullOrEmpty(GlobalControl.InstanceVersion))
			{
				string instanceVersion = GlobalControl.InstanceVersion;
				if (!(instanceVersion == "15"))
				{
					if (instanceVersion == "16")
					{
						textBoxServer.Text = "SqlLocalDB 2022 is running normally.";
					}
				}
				else
				{
					textBoxServer.Text = "SqlLocalDB 2019 is running normally.";
				}
			}
			UpdateListOfDatabases(myListOfAvailableSQLDatabases);
		}
		Cursor = Cursors.Default;
	}

	public void SetServerLocation()
	{
		string text = "PostgreSQL " + RegistryUtility.GetPostgresVersion(apedVersion);
		textBoxServer.Text = text;
		textBoxServer.Enabled = false;
	}

	public void UpdateListOfDatabases(ArrayList listOfAvailableDatabases)
	{
		listBoxDBAvaiable.Items.Clear();
		if (listOfAvailableDatabases.Count <= 0)
		{
			return;
		}
		foreach (string listOfAvailableDatabase in listOfAvailableDatabases)
		{
			listBoxDBAvaiable.Items.Add(listOfAvailableDatabase);
		}
	}

	public void DisplayDatabase(string database)
	{
		if (myCollectionListOfDatabases.ContainsKey(database))
		{
			DisplayOnly(database);
			return;
		}
		myDatabase = null;
		if (myDatabases != null && myDatabases.Count > 0)
		{
			foreach (IDatabase myDatabase in myDatabases)
			{
				if (myDatabase != null && myDatabase.Alias == database)
				{
					this.myDatabase = myDatabase;
					break;
				}
			}
		}
		if (this.myDatabase != null)
		{
			if (!myCollectionListOfDatabases.ContainsKey(this.myDatabase.Alias))
			{
				GetAndDisplayDatabase(this.myDatabase);
			}
			else
			{
				DisplayOnly(this.myDatabase.Alias);
			}
			return;
		}
		SqlServerDatabase sqlServerDatabase = new SqlServerDatabase();
		sqlServerDatabase.Alias = database;
		sqlServerDatabase.DataSource = "localhost";
		sqlServerDatabase.UserName = pgUser;
		sqlServerDatabase.UserPassword = pgPassword;
		sqlServerDatabase.DBProvider = "postgres";
		sqlServerDatabase.ConnectionString = ApedApplication.BuildConnectionString("postgres", "localhost", pgPort, database, pgUser, pgPassword);
		sqlServerDatabase.IsLegacyDB = false;
		sqlServerDatabase.InitDatabase(out pgOutput);
		if (string.IsNullOrEmpty(pgOutput))
		{
			myDatabases.Add(sqlServerDatabase);
			GetAndDisplayDatabase(sqlServerDatabase);
			return;
		}
		if (pgOutput.Contains("No connection could be made because the target machine actively refused it"))
		{
			pgOutput = "No connection could be made because the target machine actively refused it. The PostgreSQL server is most likely not running and you can try to restart the server  by running pgRestart.bat as Administrator from a command prompt window.";
		}
		if (IsAdministrator())
		{
			pgOutput = ApedApplication.UpdateErrorReports(pgOutput);
		}
	}

	private void DisplayOnly(string database)
	{
		IDatabaseInfor databaseInfor = myCollectionListOfDatabases[database];
		textBoxDatabase.Text = database;
		int num = 0;
		if (databaseInfor.Components > 0)
		{
			num = databaseInfor.Components;
		}
		textBoxComponents.Text = num.ToString();
		int num2 = 0;
		if (databaseInfor.Databanks > 0)
		{
			num2 = databaseInfor.Databanks;
		}
		textBoxDatabanks.Text = num2.ToString();
		int num3 = 0;
		if (databaseInfor.rxn > 0)
		{
			num3 = databaseInfor.rxn;
		}
		textBoxReactions.Text = num3.ToString();
	}

	private void GetAndDisplayDatabase(IDatabase idb)
	{
		Cursor = Cursors.WaitCursor;
		DatabaseInfor databaseInfor = new DatabaseInfor();
		databaseInfor.DatabaseName = idb.Alias;
		textBoxDatabase.Text = idb.Alias;
		SetupMyDatabase(idb);
		if (myCompoundManager != null)
		{
			myCompoundManager.GetAllCompounds(null, out myCompounds);
			if (myCompounds != null && myCompounds.Count > 0)
			{
				databaseInfor.Components = myCompounds.Count;
				textBoxComponents.Text = myCompounds.Count.ToString();
			}
			else
			{
				textBoxComponents.Text = "0";
			}
		}
		idb.EnumerateDatabanks(out myDatabanks);
		if (myDatabanks != null && myDatabanks.Count > 0)
		{
			databaseInfor.Databanks = myDatabanks.Count;
			textBoxDatabanks.Text = myDatabanks.Count.ToString();
			foreach (IDatabank myDatabank in myDatabanks)
			{
				if (myDatabank != null && myDatabank.Name == "REACTIONS")
				{
					myReactionsDB = myDatabank;
					myReactions = true;
					break;
				}
			}
			if (myReactions)
			{
				int rxnCount = 0;
				myReactionManager.GetAllReactionsCount(myReactionsDB, out rxnCount);
				if (rxnCount > 0)
				{
					databaseInfor.rxn = rxnCount;
					textBoxReactions.Text = rxnCount.ToString();
				}
			}
			else
			{
				textBoxReactions.Text = "0";
			}
		}
		else
		{
			textBoxDatabanks.Text = "0";
			textBoxReactions.Text = "0";
		}
		if (!myCollectionListOfDatabases.ContainsKey(idb.Alias))
		{
			myCollectionListOfDatabases.Add(idb.Alias, databaseInfor);
		}
		Cursor = Cursors.Default;
	}

	public void DisplaySQLDatabase(string database)
	{
		if (myCollectionListOfSQLDatabases.ContainsKey(database))
		{
			DisplaySQLOnly(database);
			return;
		}
		myDatabase = null;
		if (mySQLDatabases != null && mySQLDatabases.Count > 0)
		{
			foreach (IDatabase mySQLDatabase in mySQLDatabases)
			{
				if (mySQLDatabase != null && mySQLDatabase.Alias == database)
				{
					myDatabase = mySQLDatabase;
					break;
				}
			}
		}
		if (myDatabase != null)
		{
			if (!myCollectionListOfSQLDatabases.ContainsKey(myDatabase.Alias))
			{
				GetAndDisplaySQLDatabase(myDatabase);
			}
			else
			{
				DisplaySQLOnly(myDatabase.Alias);
			}
		}
	}

	private void DisplaySQLOnly(string database)
	{
		IDatabaseInfor databaseInfor = myCollectionListOfSQLDatabases[database];
		textBoxDatabase.Text = database;
		int num = 0;
		if (databaseInfor.Components > 0)
		{
			num = databaseInfor.Components;
		}
		textBoxComponents.Text = num.ToString();
		int num2 = 0;
		if (databaseInfor.Databanks > 0)
		{
			num2 = databaseInfor.Databanks;
		}
		textBoxDatabanks.Text = num2.ToString();
		int num3 = 0;
		if (databaseInfor.rxn > 0)
		{
			num3 = databaseInfor.rxn;
		}
		textBoxReactions.Text = num3.ToString();
	}

	private void GetAndDisplaySQLDatabase(IDatabase idb)
	{
		Cursor = Cursors.WaitCursor;
		DatabaseInfor databaseInfor = new DatabaseInfor();
		databaseInfor.DatabaseName = idb.Alias;
		textBoxDatabase.Text = idb.Alias;
		SetupMyDatabase(idb);
		if (myCompoundManager != null)
		{
			myCompoundManager.GetAllCompounds(null, out myCompounds);
			if (myCompounds != null && myCompounds.Count > 0)
			{
				databaseInfor.Components = myCompounds.Count;
				textBoxComponents.Text = myCompounds.Count.ToString();
			}
			else
			{
				textBoxComponents.Text = "0";
			}
		}
		idb.EnumerateDatabanks(out myDatabanks);
		if (myDatabanks != null && myDatabanks.Count > 0)
		{
			databaseInfor.Databanks = myDatabanks.Count;
			textBoxDatabanks.Text = myDatabanks.Count.ToString();
			foreach (IDatabank myDatabank in myDatabanks)
			{
				if (myDatabank != null && myDatabank.Name == "REACTIONS")
				{
					myReactionsDB = myDatabank;
					myReactions = true;
					break;
				}
			}
			if (myReactions)
			{
				int rxnCount = 0;
				myReactionManager.GetAllReactionsCount(myReactionsDB, out rxnCount);
				if (rxnCount > 0)
				{
					databaseInfor.rxn = rxnCount;
					textBoxReactions.Text = rxnCount.ToString();
				}
			}
			else
			{
				textBoxReactions.Text = "0";
			}
		}
		else
		{
			textBoxDatabanks.Text = "0";
			textBoxReactions.Text = "0";
		}
		if (!myCollectionListOfSQLDatabases.ContainsKey(idb.Alias))
		{
			myCollectionListOfSQLDatabases.Add(idb.Alias, databaseInfor);
		}
		Cursor = Cursors.Default;
	}

	private void SetupMyDatabase(IDatabase database)
	{
		myCompoundManager = null;
		myPropertyManager = null;
		myPropertyValueManager = null;
		myReactionManager = null;
		myDatabanks = null;
		myCompounds = null;
		myReactionsDB = null;
		myReactions = false;
		if (database is ISupportsCompounds supportsCompounds)
		{
			myCompoundManager = supportsCompounds.CompoundManager;
		}
		if (database is ISupportsProperties supportsProperties)
		{
			myPropertyManager = supportsProperties.PropertyManager;
		}
		if (database is ISupportsPropertyValues supportsPropertyValues)
		{
			myPropertyValueManager = supportsPropertyValues.PropertyValueManager;
		}
		if (database is ISupportsReactions supportsReactions)
		{
			myReactionManager = supportsReactions.ReactionManager;
		}
	}

	public static int RestoreDatabase(string db, string owner, string password, out string output)
	{
		string text = "\"" + db + "\"";
		string text2 = apedVersionPath + "\\" + db + "_backup.tar";
		if (!File.Exists(text2))
		{
			output = "Backup file does not exit for Database " + db + ".";
			return -1;
		}
		text2 = "\"" + text2 + "\"";
		pgCommand = string.Format("--verbose --clean --no-acl --no-owner --username {0} --host localhost -p {1} --dbname {2} {3}", owner, pgPort, text, text2);
		output = RunProcess(pgCommand, password, pgPort, pgRunType, out var exitCode);
		return exitCode;
	}

	public static int RestoreDatabase(string backupFilePath, string db, string owner, string password, out string output)
	{
		string text = "\"" + db + "\"";
		string text2 = backupFilePath + "\\" + db + "_backup.tar";
		if (!File.Exists(text2))
		{
			output = "Backup file does not exit for Database " + db + ".";
			return -1;
		}
		text2 = "\"" + text2 + "\"";
		pgCommand = string.Format("--verbose --clean --no-acl --no-owner --username {0} --host localhost -p {1} --dbname {2} {3}", owner, pgPort, text, text2);
		output = RunProcess(pgCommand, password, pgPort, pgRunType, out var exitCode);
		return exitCode;
	}

	public static List<string> GetAPEDDatabases()
	{
		List<string> list = new List<string>();
		if (!File.Exists(pgDatabasesPath))
		{
			return list;
		}
		StreamReader streamReader = File.OpenText(pgDatabasesPath);
		string text;
		while (!string.IsNullOrEmpty(text = streamReader.ReadLine()))
		{
			if (text.StartsWith("port:"))
			{
				pgPortLine = true;
			}
			else
			{
				list.Add(text);
			}
		}
		if (streamReader != null)
		{
			streamReader.Close();
			streamReader.DiscardBufferedData();
			streamReader.Dispose();
		}
		return list;
	}

	private static string RunProcess(string command, string password, string port)
	{
		Environment.SetEnvironmentVariable("PGPASSWORD", password);
		string arguments = " -h localhost -U postgres -p " + port + " -w " + command;
		ProcessStartInfo startInfo = new ProcessStartInfo
		{
			FileName = RegistryUtility.GetPostgresExecutable(),
			Arguments = arguments,
			CreateNoWindow = true,
			UseShellExecute = false,
			RedirectStandardOutput = true,
			RedirectStandardError = true
		};
		using (Process process = new Process())
		{
			process.StartInfo = startInfo;
			try
			{
				process.Start();
				pgOutput = process.StandardError.ReadToEnd();
				process.WaitForExit();
				if (process.ExitCode != 0 && IsAdministrator())
				{
					ApedApplication.UpdateErrorReports(pgOutput);
				}
			}
			catch (Exception)
			{
			}
		}
		return pgOutput;
	}

	public static bool IsAdministrator()
	{
		return new WindowsPrincipal(WindowsIdentity.GetCurrent()).IsInRole(WindowsBuiltInRole.Administrator);
	}

	private static string RunProcess(string command, string password, string port, string runType)
	{
		Environment.SetEnvironmentVariable("PGPASSWORD", password);
		string arguments = " -h localhost -U postgres -p " + port + " -w " + command;
		ProcessStartInfo startInfo = new ProcessStartInfo
		{
			FileName = RegistryUtility.GetPostgresExecutable(runType),
			Arguments = arguments,
			CreateNoWindow = true,
			UseShellExecute = false,
			RedirectStandardOutput = true,
			RedirectStandardError = true
		};
		using (Process process = new Process())
		{
			process.StartInfo = startInfo;
			try
			{
				process.Start();
				pgOutput = process.StandardError.ReadToEnd();
				process.WaitForExit();
				switch (process.ExitCode)
				{
				case 1:
					if (IsAdministrator())
					{
						ApedApplication.UpdateErrorReports(pgOutput);
					}
					break;
				default:
					if (IsAdministrator())
					{
						ApedApplication.UpdateErrorReports(pgOutput);
					}
					break;
				case 0:
					break;
				}
			}
			catch (Exception)
			{
			}
		}
		return pgOutput;
	}

	private static string RunProcess(string command, string password, string port, string runType, out int exitCode)
	{
		exitCode = 0;
		Environment.SetEnvironmentVariable("PGPASSWORD", password);
		string arguments = " -h localhost -U postgres -p " + port + " -w " + command;
		ProcessStartInfo startInfo = new ProcessStartInfo
		{
			FileName = RegistryUtility.GetPostgresExecutable(runType),
			Arguments = arguments,
			CreateNoWindow = true,
			UseShellExecute = false,
			RedirectStandardOutput = true,
			RedirectStandardError = true
		};
		using (Process process = new Process())
		{
			process.StartInfo = startInfo;
			try
			{
				process.Start();
				pgOutput = process.StandardError.ReadToEnd();
				process.WaitForExit();
				exitCode = process.ExitCode;
			}
			catch (Exception)
			{
			}
		}
		return pgOutput;
	}

	private static string GetConnectionString(string serverorhost, string port, string userID, string password, string db)
	{
		string empty = string.Empty;
		if (string.IsNullOrEmpty(db))
		{
			return string.Format("Server={0};Port={1};User Id={2};Password={3};", serverorhost, port, userID, password);
		}
		if (string.IsNullOrEmpty(port))
		{
			return string.Format("Server={0};Username={2};Password={3};Database={4};", serverorhost, userID, password, db);
		}
		return string.Format("Server={0};Port={1};User Id={2};Password={3};Database={4};", serverorhost, port, userID, password, db);
	}

	public static bool CreateUser(string user, string password)
	{
		bool result = true;
		NpgsqlConnection npgsqlConnection = null;
		try
		{
			pgCommand = string.Format("CREATE USER {0} WITH LOGIN SUPERUSER CREATEDB CREATEROLE INHERIT REPLICATION CONNECTION LIMIT -1 PASSWORD '{1}';", user, password);
			pgConnString = GetConnectionString(pgHost, pgPort, pgUser, pgPassword, pgDefaultDB);
			npgsqlConnection = new NpgsqlConnection(pgConnString);
			npgsqlConnection.Open();
			using NpgsqlCommand npgsqlCommand = new NpgsqlCommand();
			npgsqlCommand.Connection = npgsqlConnection;
			npgsqlCommand.CommandText = pgCommand;
			npgsqlCommand.ExecuteNonQuery();
		}
		catch (NpgsqlException ex)
		{
			pgOutput = ex.Message;
			if (IsAdministrator())
			{
				ApedApplication.UpdateErrorReports(pgOutput);
			}
			result = false;
		}
		finally
		{
			npgsqlConnection?.Close();
		}
		return result;
	}

	public static bool CreateUser(string user, string password, out string output)
	{
		output = string.Empty;
		bool result = true;
		NpgsqlConnection npgsqlConnection = null;
		try
		{
			pgCommand = string.Format("CREATE USER {0} WITH LOGIN CREATEDB CREATEROLE PASSWORD '{1}';", user, password);
			pgConnString = GetConnectionString(pgHost, pgPort, pgUser, pgPassword, pgDefaultDB);
			npgsqlConnection = new NpgsqlConnection(pgConnString);
			npgsqlConnection.Open();
			using NpgsqlCommand npgsqlCommand = new NpgsqlCommand();
			npgsqlCommand.Connection = npgsqlConnection;
			npgsqlCommand.CommandText = pgCommand;
			npgsqlCommand.ExecuteNonQuery();
		}
		catch (NpgsqlException ex)
		{
			pgOutput = ex.Message;
			if (IsAdministrator())
			{
				ApedApplication.UpdateErrorReports(pgOutput);
			}
			result = false;
		}
		finally
		{
			npgsqlConnection?.Close();
		}
		return result;
	}

	public static bool CreateDatabase(string db, string owner)
	{
		bool result = true;
		NpgsqlConnection npgsqlConnection = null;
		try
		{
			pgCommand = "CREATE DATABASE \"" + db + "\" WITH OWNER = " + owner + " ENCODING = 'UTF8' CONNECTION LIMIT = -1";
			pgConnString = GetConnectionString(pgHost, pgPort, pgUser, pgPassword, null);
			npgsqlConnection = new NpgsqlConnection(pgConnString);
			npgsqlConnection.Open();
			using NpgsqlCommand npgsqlCommand = new NpgsqlCommand();
			npgsqlCommand.Connection = npgsqlConnection;
			npgsqlCommand.CommandText = pgCommand;
			npgsqlCommand.ExecuteNonQuery();
		}
		catch (NpgsqlException ex)
		{
			pgOutput = ex.Message;
			if (IsAdministrator())
			{
				ApedApplication.UpdateErrorReports(pgOutput);
			}
			result = false;
		}
		finally
		{
			npgsqlConnection?.Close();
		}
		return result;
	}

	public static bool CreateDatabase(string db, string owner, out string output)
	{
		output = string.Empty;
		bool result = true;
		NpgsqlConnection npgsqlConnection = null;
		try
		{
			pgCommand = "CREATE DATABASE \"" + db + "\" WITH OWNER = " + owner + " ENCODING = 'UTF8' CONNECTION LIMIT = -1";
			pgConnString = GetConnectionString(pgHost, pgPort, pgUser, pgPassword, null);
			npgsqlConnection = new NpgsqlConnection(pgConnString);
			npgsqlConnection.Open();
			using NpgsqlCommand npgsqlCommand = new NpgsqlCommand();
			npgsqlCommand.Connection = npgsqlConnection;
			npgsqlCommand.CommandText = pgCommand;
			npgsqlCommand.ExecuteNonQuery();
		}
		catch (NpgsqlException ex)
		{
			pgOutput = ex.Message;
			if (IsAdministrator())
			{
				ApedApplication.UpdateErrorReports(pgOutput);
			}
			result = false;
		}
		finally
		{
			npgsqlConnection?.Close();
		}
		return result;
	}

	public static List<string> ListOfDatabaseNames(string user, string password)
	{
		List<string> list = new List<string>();
		pgConnString = GetConnectionString(pgHost, pgPort, user, password, pgDefaultDB);
		NpgsqlConnection npgsqlConnection = new NpgsqlConnection(pgConnString);
		npgsqlConnection.Open();
		NpgsqlCommand npgsqlCommand = npgsqlConnection.CreateCommand();
		npgsqlCommand.CommandText = "SELECT datname FROM pg_database";
		NpgsqlDataReader npgsqlDataReader = npgsqlCommand.ExecuteReader();
		while (npgsqlDataReader.Read())
		{
			string text = "";
			for (int i = 0; i < npgsqlDataReader.FieldCount; i++)
			{
				text = text + npgsqlDataReader.GetValue(i).ToString() + ", ";
			}
			list.Add(text);
		}
		npgsqlConnection.Close();
		if (list.Count > 0)
		{
			foreach (string item in list)
			{
				pgConnString = GetConnectionString(pgHost, null, user, password, item);
				NpgsqlDataSource.Create(pgConnString).OpenConnection();
			}
		}
		return list;
	}

	public static bool CheckConnectionToPostgreSQL()
	{
		bool result = true;
		NpgsqlConnection npgsqlConnection = null;
		try
		{
			pgConnString = GetConnectionString(pgHost, pgPort, pgUser, pgPassword, pgDefaultDB);
			npgsqlConnection = new NpgsqlConnection(pgConnString);
			npgsqlConnection.Open();
		}
		catch (NpgsqlException ex)
		{
			pgOutput = ex.Message;
			result = false;
		}
		finally
		{
			npgsqlConnection?.Close();
		}
		return result;
	}

	public static string AddPortLineToDatFile(string portLine)
	{
		string result = string.Empty;
		try
		{
			string[] array = File.ReadAllLines(pgDatabasesPath);
			List<string> list = new List<string>();
			for (int i = 0; i < array.Length; i++)
			{
				if (!string.IsNullOrEmpty(array[i]))
				{
					if (array[i].Contains("port:"))
					{
						break;
					}
					list.Add(array[i]);
				}
			}
			list.Add(portLine);
			File.WriteAllLines(pgDatabasesPath, list);
		}
		catch (Exception ex)
		{
			result = ex.Message;
		}
		return result;
	}

	public static string UpdatepgDatabases(string db)
	{
		string result = string.Empty;
		try
		{
			string[] array = File.ReadAllLines(pgDatabasesPath);
			List<string> list = new List<string>();
			for (int i = 0; i < array.Length; i++)
			{
				string text = array[i].ToString().Trim();
				if (!text.ToUpperInvariant().StartsWith("PORT") && !list.Contains(text))
				{
					list.Add(text);
				}
			}
			if (!list.Contains(db))
			{
				list.Add(db);
				string item = "port:" + pgPort;
				list.Add(item);
				File.WriteAllLines(pgDatabasesPath, list);
			}
		}
		catch (Exception ex)
		{
			result = ex.Message;
		}
		return result;
	}

	public static void RestorepgDatabase(string db)
	{
	}

	private void FrmDBConfig_Load(object sender, EventArgs e)
	{
	}

	private void FrmDBConfig_FormClosed(object sender, FormClosedEventArgs e)
	{
	}

	private void FrmDBConfig_FormClosing(object sender, FormClosingEventArgs e)
	{
	}

	private void buttonClose_Click(object sender, EventArgs e)
	{
		Close();
	}

	private void lblCloseButton_Click(object sender, EventArgs e)
	{
		Close();
	}

	private bool CanDatabaseBeRstored(string db)
	{
		bool result = false;
		pgRunType = "restore";
		if (myListOfDefaults != null && myListOfDefaults.Count > 0)
		{
			for (int i = 0; i < myListOfDefaults.Count; i++)
			{
				switch (i)
				{
				case 0:
					pgPort = myListOfDefaults[0].ToString();
					break;
				case 1:
					pgUser = myListOfDefaults[1].ToString();
					break;
				case 2:
					pgPassword = myListOfDefaults[2].ToString();
					break;
				case 3:
					pgDefaultDB = myListOfDefaults[3].ToString();
					break;
				}
			}
		}
		string owner = pgUser;
		Cursor = Cursors.WaitCursor;
		pgSuccess = CreateDatabase(db, owner, out pgOutput);
		if (!pgSuccess && !pgOutput.Contains("already exists"))
		{
			pgOutput = "Failed to create Database: " + db + ": " + pgOutput;
			if (IsAdministrator())
			{
				ApedApplication.UpdateErrorReports(pgOutput);
			}
			return result;
		}
		int j = 1;
		result = false;
		pgOutput = "Restore Database " + db + " started here...";
		if (IsAdministrator())
		{
			ApedApplication.UpdateErrorReports(pgOutput);
		}
		for (; j < 5; j++)
		{
			int num = (string.IsNullOrEmpty(pgBackupFilePath) ? RestoreDatabase(db, owner, pgPassword, out pgOutput) : RestoreDatabase(pgBackupFilePath, db, owner, pgPassword, out pgOutput));
			if (j == 1 && (pgOutput.Contains("pg_restore: error: input file is too short") || pgOutput.Contains("pg_restore: error: input file does not appear to be a valid archive")))
			{
				pgOutput = "Failed to restore Database " + db + ": " + pgOutput;
				if (IsAdministrator())
				{
					ApedApplication.UpdateErrorReports(pgOutput);
				}
				break;
			}
			switch (num)
			{
			case 0:
				pgOutput = "Database " + db + " restored successfully.";
				if (IsAdministrator())
				{
					ApedApplication.UpdateErrorReports(pgOutput);
				}
				pgOutput = "Process times: " + j + ".";
				if (IsAdministrator())
				{
					ApedApplication.UpdateErrorReports(pgOutput);
				}
				result = true;
				break;
			case -1:
				pgOutput = "Failed to restore Database: " + db + ": " + pgOutput;
				if (IsAdministrator())
				{
					ApedApplication.UpdateErrorReports(pgOutput);
				}
				break;
			default:
				continue;
			}
			break;
		}
		if (j == 5)
		{
			pgOutput = "Failed to restore Database: " + db + ": " + pgOutput;
			if (IsAdministrator())
			{
				ApedApplication.UpdateErrorReports(pgOutput);
			}
		}
		Cursor = Cursors.Default;
		return result;
	}

	private void buttonImport_Click(object sender, EventArgs e)
	{
		if (!IsAdministrator())
		{
			pgOutput = "To import a backup file, you must run this tool as Administrator.";
			base.TopMost = true;
			MessageBox.Show(this, pgOutput, "Database Configuration", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
			base.TopMost = false;
			buttonImport.Focus();
			return;
		}
		myBackupFile = string.Empty;
		pgBackupFilePath = string.Empty;
		if (openFileDialog1.FileName != null && openFileDialog1.FileName != "")
		{
			openFileDialog1.FileName = "";
			textBoxBackup.Text = "";
			textBoxNewDB.Text = "";
			textBoxRestoreStatus.Text = "";
		}
		if (openFileDialog1.ShowDialog() != DialogResult.Cancel && !string.IsNullOrEmpty(openFileDialog1.FileName))
		{
			myBackupFile = openFileDialog1.FileName;
			pgBackupFilePath = Path.GetDirectoryName(myBackupFile);
			string[] array = Path.GetFileNameWithoutExtension(myBackupFile).Split('_');
			myDatabaseName = array[0].ToUpperInvariant();
			if (myListOfAvailablePGDatabases.Contains(myDatabaseName))
			{
				string text = "Database " + myDatabaseName + " is already available. Import a different backup file.";
				MessageBox.Show(this, text);
				myDatabaseName = string.Empty;
				buttonImport.Focus();
			}
			else
			{
				textBoxBackup.Text = myBackupFile;
				textBoxNewDB.Text = myDatabaseName;
				textBoxBackup.Enabled = false;
				textBoxNewDB.Enabled = false;
			}
		}
	}

	private void buttonRestore_Click(object sender, EventArgs e)
	{
		if (!IsAdministrator())
		{
			pgOutput = "To restore a database, you must run this tool as Administrator.";
			base.TopMost = true;
			MessageBox.Show(this, pgOutput, "Database Configuration", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
			base.TopMost = false;
			buttonImport.Focus();
		}
		else if (string.IsNullOrEmpty(myDatabaseName))
		{
			pgOutput = "To restore a database, you must import a backup file first.";
			base.TopMost = true;
			MessageBox.Show(this, pgOutput, "Database Configuration", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
			base.TopMost = false;
			buttonImport.Focus();
		}
		else if (!string.IsNullOrEmpty(myDatabaseName))
		{
			string empty = string.Empty;
			if (CanDatabaseBeRstored(myDatabaseName))
			{
				empty = "Database " + myDatabaseName + " restored successfully.";
				textBoxRestoreStatus.Text = empty;
				myListOfAvailablePGDatabases.Add(myDatabaseName);
				UpdateListOfDatabases(myListOfAvailablePGDatabases);
				UpdatepgDatabases(myDatabaseName);
			}
			else
			{
				empty = "Failed to restore " + myDatabaseName + ". See the log file for details.";
				textBoxRestoreStatus.Text = empty;
			}
		}
	}

	private void listBoxDBAvaiable_SelectedIndexChanged(object sender, EventArgs e)
	{
		if (listBoxDBAvaiable.SelectedItem != null)
		{
			myCurrentDatabase = listBoxDBAvaiable.SelectedItem.ToString().Trim();
			if (myDbProvider.CompareTo("postgres") == 0)
			{
				DisplayDatabase(myCurrentDatabase);
			}
			else
			{
				DisplaySQLDatabase(myCurrentDatabase);
			}
		}
	}

	private void listBoxDBAvaiable_Enter(object sender, EventArgs e)
	{
	}

	private void buttonViewLogFile_Click(object sender, EventArgs e)
	{
		new FrmViewLogFile(pgDatabaseLogPath).ShowDialog();
	}

	private void lblFrmTitle_MouseDown(object sender, MouseEventArgs e)
	{
		if (e.Button == MouseButtons.Left)
		{
			mouseLocation = new Point(-e.X, -e.Y);
			isDragging = true;
		}
	}

	private void lblFrmTitle_MouseUp(object sender, MouseEventArgs e)
	{
		if (isDragging)
		{
			isDragging = false;
		}
	}

	private void lblFrmTitle_MouseMove(object sender, MouseEventArgs e)
	{
		if (isDragging)
		{
			Point mousePosition = Control.MousePosition;
			mousePosition.Offset(mouseLocation.X, mouseLocation.Y);
			base.Location = mousePosition;
		}
	}

	private void radioButtonPostgres_CheckedChanged(object sender, EventArgs e)
	{
	}

	private void radioButtonSQL_CheckedChanged(object sender, EventArgs e)
	{
		textBoxComponents.Text = string.Empty;
		textBoxDatabanks.Text = string.Empty;
		textBoxDatabase.Text = string.Empty;
		textBoxReactions.Text = string.Empty;
		textBoxpgStartPath.Text = string.Empty;
		textBoxpgStartPath.Visible = false;
		textBoxpgStartPath.Enabled = false;
		if (radioButtonSQL.Checked)
		{
			myDbProvider = "mssql";
			RegistryUtility.SetdbProviderForCurrentUser(myDbProvider, apedVersion);
			SetupMssql();
		}
		else if (string.IsNullOrEmpty(RegistryUtility.GetPostgresVersion(apedVersion)))
		{
			myDbProvider = "mssql";
			RegistryUtility.SetdbProviderForCurrentUser(myDbProvider, apedVersion);
			SetupMssql();
			radioButtonSQL.Checked = true;
			radioButtonPostgres.Enabled = false;
		}
		else
		{
			myDbProvider = "postgres";
			RegistryUtility.SetdbProviderForCurrentUser(myDbProvider, apedVersion);
			SetupPostgres();
		}
	}

	public ArrayList CheckpgDatabasesDat(out string port)
	{
		port = string.Empty;
		ArrayList arrayList = new ArrayList();
		if (!File.Exists(pgDatabasesPath))
		{
			return arrayList;
		}
		string[] array = File.ReadAllLines(pgDatabasesPath);
		for (int i = 0; i < array.Length; i++)
		{
			if (array[i].ToLowerInvariant().StartsWith("port"))
			{
				string[] array2 = array[i].Split(':');
				port = array2[1];
			}
			else if (array[i].ToLowerInvariant().Contains("port:"))
			{
				int num = array[i].LastIndexOf(":");
				string text = array[i].Substring(0, num - 4);
				arrayList.Add(text);
				string[] array3 = array[i].Substring(num - 4, array[i].Length - text.Length).Split(':');
				port = array3[1];
			}
			else if (!string.IsNullOrEmpty(array[i]))
			{
				arrayList.Add(array[i]);
			}
		}
		return arrayList;
	}

	protected override void Dispose(bool disposing)
	{
		if (disposing && components != null)
		{
			components.Dispose();
		}
		base.Dispose(disposing);
	}

	private void InitializeComponent()
	{
		System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(DatabaseConfiguration.FrmDBConfig));
		this.buttonClose = new System.Windows.Forms.Button();
		this.labelServer = new System.Windows.Forms.Label();
		this.textBoxServer = new System.Windows.Forms.TextBox();
		this.labelDBAvailable = new System.Windows.Forms.Label();
		this.listBoxDBAvaiable = new System.Windows.Forms.ListBox();
		this.labelRestore = new System.Windows.Forms.Label();
		this.buttonImport = new System.Windows.Forms.Button();
		this.textBoxBackup = new System.Windows.Forms.TextBox();
		this.buttonRestore = new System.Windows.Forms.Button();
		this.textBoxRestoreStatus = new System.Windows.Forms.TextBox();
		this.labelDatabase = new System.Windows.Forms.Label();
		this.labelComponents = new System.Windows.Forms.Label();
		this.labelDatabanks = new System.Windows.Forms.Label();
		this.labelReactions = new System.Windows.Forms.Label();
		this.textBoxDatabase = new System.Windows.Forms.TextBox();
		this.textBoxComponents = new System.Windows.Forms.TextBox();
		this.textBoxDatabanks = new System.Windows.Forms.TextBox();
		this.textBoxReactions = new System.Windows.Forms.TextBox();
		this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
		this.labelNewDB = new System.Windows.Forms.Label();
		this.textBoxNewDB = new System.Windows.Forms.TextBox();
		this.lblFrmTitle = new System.Windows.Forms.Label();
		this.lblCloseButton = new System.Windows.Forms.Label();
		this.buttonViewLogFile = new System.Windows.Forms.Button();
		this.labelDBProvider = new System.Windows.Forms.Label();
		this.radioButtonPostgres = new System.Windows.Forms.RadioButton();
		this.radioButtonSQL = new System.Windows.Forms.RadioButton();
		this.textBoxpgStartPath = new System.Windows.Forms.TextBox();
		base.SuspendLayout();
		this.buttonClose.BackColor = System.Drawing.Color.FromArgb(0, 120, 201);
		this.buttonClose.Font = new System.Drawing.Font("Segoe UI", 11.25f, System.Drawing.FontStyle.Bold);
		this.buttonClose.Location = new System.Drawing.Point(694, 688);
		this.buttonClose.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
		this.buttonClose.Name = "buttonClose";
		this.buttonClose.Size = new System.Drawing.Size(167, 45);
		this.buttonClose.TabIndex = 0;
		this.buttonClose.Text = "Close";
		this.buttonClose.UseVisualStyleBackColor = false;
		this.buttonClose.Click += new System.EventHandler(buttonClose_Click);
		this.labelServer.AutoSize = true;
		this.labelServer.BackColor = System.Drawing.SystemColors.Control;
		this.labelServer.Font = new System.Drawing.Font("Segoe UI", 11.25f, System.Drawing.FontStyle.Bold);
		this.labelServer.Location = new System.Drawing.Point(39, 147);
		this.labelServer.Name = "labelServer";
		this.labelServer.Size = new System.Drawing.Size(184, 25);
		this.labelServer.TabIndex = 1;
		this.labelServer.Text = "PostgreSQL Server:";
		this.labelServer.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
		this.textBoxServer.BackColor = System.Drawing.Color.White;
		this.textBoxServer.Font = new System.Drawing.Font("Segoe UI", 11.25f, System.Drawing.FontStyle.Bold);
		this.textBoxServer.Location = new System.Drawing.Point(294, 144);
		this.textBoxServer.Margin = new System.Windows.Forms.Padding(3, 5, 3, 5);
		this.textBoxServer.Name = "textBoxServer";
		this.textBoxServer.Size = new System.Drawing.Size(636, 32);
		this.textBoxServer.TabIndex = 2;
		this.labelDBAvailable.AutoSize = true;
		this.labelDBAvailable.BackColor = System.Drawing.SystemColors.Control;
		this.labelDBAvailable.Font = new System.Drawing.Font("Segoe UI", 11.25f, System.Drawing.FontStyle.Bold);
		this.labelDBAvailable.Location = new System.Drawing.Point(39, 207);
		this.labelDBAvailable.Name = "labelDBAvailable";
		this.labelDBAvailable.Size = new System.Drawing.Size(191, 25);
		this.labelDBAvailable.TabIndex = 3;
		this.labelDBAvailable.Text = "Available Databases:";
		this.labelDBAvailable.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
		this.listBoxDBAvaiable.Font = new System.Drawing.Font("Segoe UI", 10f, System.Drawing.FontStyle.Bold);
		this.listBoxDBAvaiable.FormattingEnabled = true;
		this.listBoxDBAvaiable.ItemHeight = 23;
		this.listBoxDBAvaiable.Location = new System.Drawing.Point(39, 252);
		this.listBoxDBAvaiable.Margin = new System.Windows.Forms.Padding(3, 5, 3, 5);
		this.listBoxDBAvaiable.Name = "listBoxDBAvaiable";
		this.listBoxDBAvaiable.Size = new System.Drawing.Size(222, 142);
		this.listBoxDBAvaiable.TabIndex = 4;
		this.listBoxDBAvaiable.SelectedIndexChanged += new System.EventHandler(listBoxDBAvaiable_SelectedIndexChanged);
		this.listBoxDBAvaiable.Enter += new System.EventHandler(listBoxDBAvaiable_Enter);
		this.labelRestore.AutoSize = true;
		this.labelRestore.BackColor = System.Drawing.SystemColors.Control;
		this.labelRestore.Font = new System.Drawing.Font("Segoe UI", 11.25f, System.Drawing.FontStyle.Bold);
		this.labelRestore.Location = new System.Drawing.Point(39, 441);
		this.labelRestore.Name = "labelRestore";
		this.labelRestore.Size = new System.Drawing.Size(178, 25);
		this.labelRestore.TabIndex = 5;
		this.labelRestore.Text = "Restore Databases:";
		this.labelRestore.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
		this.buttonImport.BackColor = System.Drawing.Color.FromArgb(0, 120, 201);
		this.buttonImport.Font = new System.Drawing.Font("Segoe UI", 11.25f, System.Drawing.FontStyle.Bold);
		this.buttonImport.Location = new System.Drawing.Point(39, 484);
		this.buttonImport.Margin = new System.Windows.Forms.Padding(3, 5, 3, 5);
		this.buttonImport.Name = "buttonImport";
		this.buttonImport.Size = new System.Drawing.Size(189, 45);
		this.buttonImport.TabIndex = 7;
		this.buttonImport.Text = "Import backup file:";
		this.buttonImport.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
		this.buttonImport.UseVisualStyleBackColor = false;
		this.buttonImport.Click += new System.EventHandler(buttonImport_Click);
		this.textBoxBackup.BackColor = System.Drawing.Color.White;
		this.textBoxBackup.Font = new System.Drawing.Font("Segoe UI", 10f, System.Drawing.FontStyle.Bold);
		this.textBoxBackup.Location = new System.Drawing.Point(294, 488);
		this.textBoxBackup.Margin = new System.Windows.Forms.Padding(3, 5, 3, 5);
		this.textBoxBackup.Name = "textBoxBackup";
		this.textBoxBackup.Size = new System.Drawing.Size(636, 30);
		this.textBoxBackup.TabIndex = 8;
		this.buttonRestore.BackColor = System.Drawing.Color.FromArgb(0, 120, 201);
		this.buttonRestore.Font = new System.Drawing.Font("Segoe UI", 11.25f, System.Drawing.FontStyle.Bold);
		this.buttonRestore.Location = new System.Drawing.Point(39, 621);
		this.buttonRestore.Margin = new System.Windows.Forms.Padding(3, 5, 3, 5);
		this.buttonRestore.Name = "buttonRestore";
		this.buttonRestore.Size = new System.Drawing.Size(98, 45);
		this.buttonRestore.TabIndex = 9;
		this.buttonRestore.Text = "Restore:";
		this.buttonRestore.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
		this.buttonRestore.UseVisualStyleBackColor = false;
		this.buttonRestore.Click += new System.EventHandler(buttonRestore_Click);
		this.textBoxRestoreStatus.BackColor = System.Drawing.Color.White;
		this.textBoxRestoreStatus.Font = new System.Drawing.Font("Segoe UI", 10f, System.Drawing.FontStyle.Bold);
		this.textBoxRestoreStatus.Location = new System.Drawing.Point(294, 621);
		this.textBoxRestoreStatus.Margin = new System.Windows.Forms.Padding(3, 5, 3, 5);
		this.textBoxRestoreStatus.Name = "textBoxRestoreStatus";
		this.textBoxRestoreStatus.Size = new System.Drawing.Size(636, 30);
		this.textBoxRestoreStatus.TabIndex = 10;
		this.labelDatabase.AutoSize = true;
		this.labelDatabase.BackColor = System.Drawing.SystemColors.Control;
		this.labelDatabase.Font = new System.Drawing.Font("Segoe UI", 11.25f, System.Drawing.FontStyle.Bold);
		this.labelDatabase.Location = new System.Drawing.Point(294, 252);
		this.labelDatabase.Name = "labelDatabase";
		this.labelDatabase.Size = new System.Drawing.Size(98, 25);
		this.labelDatabase.TabIndex = 11;
		this.labelDatabase.Text = "Database:";
		this.labelComponents.AutoSize = true;
		this.labelComponents.BackColor = System.Drawing.SystemColors.Control;
		this.labelComponents.Font = new System.Drawing.Font("Segoe UI", 11.25f, System.Drawing.FontStyle.Bold);
		this.labelComponents.Location = new System.Drawing.Point(294, 293);
		this.labelComponents.Name = "labelComponents";
		this.labelComponents.Size = new System.Drawing.Size(131, 25);
		this.labelComponents.TabIndex = 12;
		this.labelComponents.Text = "Components:";
		this.labelDatabanks.AutoSize = true;
		this.labelDatabanks.BackColor = System.Drawing.SystemColors.Control;
		this.labelDatabanks.Font = new System.Drawing.Font("Segoe UI", 11.25f, System.Drawing.FontStyle.Bold);
		this.labelDatabanks.Location = new System.Drawing.Point(294, 339);
		this.labelDatabanks.Name = "labelDatabanks";
		this.labelDatabanks.Size = new System.Drawing.Size(111, 25);
		this.labelDatabanks.TabIndex = 13;
		this.labelDatabanks.Text = "Databanks:";
		this.labelReactions.AutoSize = true;
		this.labelReactions.BackColor = System.Drawing.SystemColors.Control;
		this.labelReactions.Font = new System.Drawing.Font("Segoe UI", 11.25f, System.Drawing.FontStyle.Bold);
		this.labelReactions.Location = new System.Drawing.Point(294, 383);
		this.labelReactions.Name = "labelReactions";
		this.labelReactions.Size = new System.Drawing.Size(102, 25);
		this.labelReactions.TabIndex = 14;
		this.labelReactions.Text = "Reactions:";
		this.textBoxDatabase.BackColor = System.Drawing.Color.White;
		this.textBoxDatabase.Font = new System.Drawing.Font("Segoe UI", 10f, System.Drawing.FontStyle.Bold);
		this.textBoxDatabase.Location = new System.Drawing.Point(493, 252);
		this.textBoxDatabase.Margin = new System.Windows.Forms.Padding(3, 5, 3, 5);
		this.textBoxDatabase.Name = "textBoxDatabase";
		this.textBoxDatabase.Size = new System.Drawing.Size(186, 30);
		this.textBoxDatabase.TabIndex = 15;
		this.textBoxComponents.BackColor = System.Drawing.Color.White;
		this.textBoxComponents.Font = new System.Drawing.Font("Segoe UI", 10f, System.Drawing.FontStyle.Bold);
		this.textBoxComponents.Location = new System.Drawing.Point(493, 293);
		this.textBoxComponents.Margin = new System.Windows.Forms.Padding(3, 5, 3, 5);
		this.textBoxComponents.Name = "textBoxComponents";
		this.textBoxComponents.Size = new System.Drawing.Size(186, 30);
		this.textBoxComponents.TabIndex = 16;
		this.textBoxDatabanks.BackColor = System.Drawing.Color.White;
		this.textBoxDatabanks.Font = new System.Drawing.Font("Segoe UI", 10f, System.Drawing.FontStyle.Bold);
		this.textBoxDatabanks.Location = new System.Drawing.Point(493, 339);
		this.textBoxDatabanks.Margin = new System.Windows.Forms.Padding(3, 5, 3, 5);
		this.textBoxDatabanks.Name = "textBoxDatabanks";
		this.textBoxDatabanks.Size = new System.Drawing.Size(186, 30);
		this.textBoxDatabanks.TabIndex = 17;
		this.textBoxReactions.BackColor = System.Drawing.Color.White;
		this.textBoxReactions.Font = new System.Drawing.Font("Segoe UI", 10f, System.Drawing.FontStyle.Bold);
		this.textBoxReactions.Location = new System.Drawing.Point(493, 383);
		this.textBoxReactions.Margin = new System.Windows.Forms.Padding(3, 5, 3, 5);
		this.textBoxReactions.Name = "textBoxReactions";
		this.textBoxReactions.Size = new System.Drawing.Size(186, 30);
		this.textBoxReactions.TabIndex = 18;
		this.openFileDialog1.FileName = "openFileDialog1";
		this.openFileDialog1.Title = "Import backup file";
		this.labelNewDB.AutoSize = true;
		this.labelNewDB.BackColor = System.Drawing.SystemColors.Control;
		this.labelNewDB.Font = new System.Drawing.Font("Segoe UI", 11.25f, System.Drawing.FontStyle.Bold);
		this.labelNewDB.Location = new System.Drawing.Point(39, 559);
		this.labelNewDB.Name = "labelNewDB";
		this.labelNewDB.Size = new System.Drawing.Size(98, 25);
		this.labelNewDB.TabIndex = 19;
		this.labelNewDB.Text = "Database:";
		this.textBoxNewDB.BackColor = System.Drawing.Color.White;
		this.textBoxNewDB.Font = new System.Drawing.Font("Segoe UI", 10f, System.Drawing.FontStyle.Bold);
		this.textBoxNewDB.Location = new System.Drawing.Point(294, 557);
		this.textBoxNewDB.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
		this.textBoxNewDB.Name = "textBoxNewDB";
		this.textBoxNewDB.Size = new System.Drawing.Size(252, 30);
		this.textBoxNewDB.TabIndex = 20;
		this.lblFrmTitle.BackColor = System.Drawing.Color.FromArgb(0, 120, 201);
		this.lblFrmTitle.Dock = System.Windows.Forms.DockStyle.Top;
		this.lblFrmTitle.Font = new System.Drawing.Font("Segoe UI Semibold", 11.25f, System.Drawing.FontStyle.Bold);
		this.lblFrmTitle.ForeColor = System.Drawing.Color.White;
		this.lblFrmTitle.Location = new System.Drawing.Point(0, 0);
		this.lblFrmTitle.Name = "lblFrmTitle";
		this.lblFrmTitle.Size = new System.Drawing.Size(966, 48);
		this.lblFrmTitle.TabIndex = 0;
		this.lblFrmTitle.Text = "Database Configration for PostgreSQL Databases";
		this.lblFrmTitle.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
		this.lblFrmTitle.MouseDown += new System.Windows.Forms.MouseEventHandler(lblFrmTitle_MouseDown);
		this.lblFrmTitle.MouseMove += new System.Windows.Forms.MouseEventHandler(lblFrmTitle_MouseMove);
		this.lblFrmTitle.MouseUp += new System.Windows.Forms.MouseEventHandler(lblFrmTitle_MouseUp);
		this.lblCloseButton.BackColor = System.Drawing.Color.FromArgb(0, 120, 201);
		this.lblCloseButton.Font = new System.Drawing.Font("Segoe UI", 20.25f, System.Drawing.FontStyle.Bold);
		this.lblCloseButton.ForeColor = System.Drawing.Color.White;
		this.lblCloseButton.Location = new System.Drawing.Point(927, 1);
		this.lblCloseButton.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
		this.lblCloseButton.Name = "lblCloseButton";
		this.lblCloseButton.Size = new System.Drawing.Size(31, 35);
		this.lblCloseButton.TabIndex = 1;
		this.lblCloseButton.Text = "×";
		this.lblCloseButton.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
		this.lblCloseButton.Click += new System.EventHandler(lblCloseButton_Click);
		this.buttonViewLogFile.BackColor = System.Drawing.Color.FromArgb(0, 120, 201);
		this.buttonViewLogFile.Font = new System.Drawing.Font("Segoe UI", 11.25f, System.Drawing.FontStyle.Bold);
		this.buttonViewLogFile.Location = new System.Drawing.Point(327, 688);
		this.buttonViewLogFile.Margin = new System.Windows.Forms.Padding(2, 3, 2, 3);
		this.buttonViewLogFile.Name = "buttonViewLogFile";
		this.buttonViewLogFile.Size = new System.Drawing.Size(147, 45);
		this.buttonViewLogFile.TabIndex = 21;
		this.buttonViewLogFile.Text = "View Log File";
		this.buttonViewLogFile.UseVisualStyleBackColor = false;
		this.buttonViewLogFile.Click += new System.EventHandler(buttonViewLogFile_Click);
		this.labelDBProvider.AutoSize = true;
		this.labelDBProvider.Font = new System.Drawing.Font("Segoe UI", 11.25f, System.Drawing.FontStyle.Bold);
		this.labelDBProvider.Location = new System.Drawing.Point(39, 81);
		this.labelDBProvider.Name = "labelDBProvider";
		this.labelDBProvider.Size = new System.Drawing.Size(181, 25);
		this.labelDBProvider.TabIndex = 22;
		this.labelDBProvider.Text = "Database Provider:";
		this.radioButtonPostgres.AutoSize = true;
		this.radioButtonPostgres.Checked = true;
		this.radioButtonPostgres.Font = new System.Drawing.Font("Segoe UI", 11.25f, System.Drawing.FontStyle.Bold);
		this.radioButtonPostgres.Location = new System.Drawing.Point(294, 84);
		this.radioButtonPostgres.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
		this.radioButtonPostgres.Name = "radioButtonPostgres";
		this.radioButtonPostgres.Size = new System.Drawing.Size(136, 29);
		this.radioButtonPostgres.TabIndex = 23;
		this.radioButtonPostgres.TabStop = true;
		this.radioButtonPostgres.Text = "PostgreSQL";
		this.radioButtonPostgres.UseVisualStyleBackColor = true;
		this.radioButtonPostgres.CheckedChanged += new System.EventHandler(radioButtonPostgres_CheckedChanged);
		this.radioButtonSQL.AutoSize = true;
		this.radioButtonSQL.Font = new System.Drawing.Font("Segoe UI", 11.25f, System.Drawing.FontStyle.Bold);
		this.radioButtonSQL.Location = new System.Drawing.Point(493, 84);
		this.radioButtonSQL.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
		this.radioButtonSQL.Name = "radioButtonSQL";
		this.radioButtonSQL.Size = new System.Drawing.Size(131, 29);
		this.radioButtonSQL.TabIndex = 24;
		this.radioButtonSQL.Text = "SQL Server";
		this.radioButtonSQL.UseVisualStyleBackColor = true;
		this.radioButtonSQL.CheckedChanged += new System.EventHandler(radioButtonSQL_CheckedChanged);
		this.textBoxpgStartPath.Enabled = false;
		this.textBoxpgStartPath.Font = new System.Drawing.Font("Segoe UI", 11.25f, System.Drawing.FontStyle.Bold);
		this.textBoxpgStartPath.Location = new System.Drawing.Point(294, 184);
		this.textBoxpgStartPath.Name = "textBoxpgStartPath";
		this.textBoxpgStartPath.Size = new System.Drawing.Size(636, 32);
		this.textBoxpgStartPath.TabIndex = 25;
		this.textBoxpgStartPath.Visible = false;
		base.AutoScaleDimensions = new System.Drawing.SizeF(8f, 20f);
		base.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
		base.ClientSize = new System.Drawing.Size(966, 775);
		base.ControlBox = false;
		base.Controls.Add(this.textBoxpgStartPath);
		base.Controls.Add(this.radioButtonSQL);
		base.Controls.Add(this.radioButtonPostgres);
		base.Controls.Add(this.labelDBProvider);
		base.Controls.Add(this.buttonViewLogFile);
		base.Controls.Add(this.textBoxNewDB);
		base.Controls.Add(this.labelNewDB);
		base.Controls.Add(this.textBoxReactions);
		base.Controls.Add(this.textBoxDatabanks);
		base.Controls.Add(this.textBoxComponents);
		base.Controls.Add(this.textBoxDatabase);
		base.Controls.Add(this.labelReactions);
		base.Controls.Add(this.labelDatabanks);
		base.Controls.Add(this.labelComponents);
		base.Controls.Add(this.labelDatabase);
		base.Controls.Add(this.textBoxRestoreStatus);
		base.Controls.Add(this.buttonRestore);
		base.Controls.Add(this.textBoxBackup);
		base.Controls.Add(this.buttonImport);
		base.Controls.Add(this.labelRestore);
		base.Controls.Add(this.listBoxDBAvaiable);
		base.Controls.Add(this.labelDBAvailable);
		base.Controls.Add(this.textBoxServer);
		base.Controls.Add(this.labelServer);
		base.Controls.Add(this.buttonClose);
		base.Controls.Add(this.lblCloseButton);
		base.Controls.Add(this.lblFrmTitle);
		base.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
		base.Icon = (System.Drawing.Icon)resources.GetObject("$this.Icon");
		base.Margin = new System.Windows.Forms.Padding(2, 3, 2, 3);
		base.MaximizeBox = false;
		base.Name = "FrmDBConfig";
		base.ShowIcon = false;
		base.FormClosing += new System.Windows.Forms.FormClosingEventHandler(FrmDBConfig_FormClosing);
		base.FormClosed += new System.Windows.Forms.FormClosedEventHandler(FrmDBConfig_FormClosed);
		base.Load += new System.EventHandler(FrmDBConfig_Load);
		base.ResumeLayout(false);
		base.PerformLayout();
	}
}
public class FrmViewLogFile : Form
{
	private string myLogFileName = string.Empty;

	private string err = string.Empty;

	private IContainer components;

	private ListBox listBoxLogFile;

	private Label labelLogFile;

	public FrmViewLogFile()
	{
		InitializeComponent();
	}

	public FrmViewLogFile(string logFileName)
	{
		InitializeComponent();
		myLogFileName = logFileName;
		err = ProcessLogFile();
	}

	private string ProcessLogFile()
	{
		string result = string.Empty;
		try
		{
			string[] array = File.ReadAllLines(myLogFileName);
			new List<string>();
			for (int i = 0; i < array.Length; i++)
			{
				listBoxLogFile.Items.Add(array[i]);
			}
		}
		catch (Exception ex)
		{
			result = ex.Message;
		}
		return result;
	}

	protected override void Dispose(bool disposing)
	{
		if (disposing && components != null)
		{
			components.Dispose();
		}
		base.Dispose(disposing);
	}

	private void InitializeComponent()
	{
		System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(DatabaseConfiguration.FrmViewLogFile));
		this.listBoxLogFile = new System.Windows.Forms.ListBox();
		this.labelLogFile = new System.Windows.Forms.Label();
		base.SuspendLayout();
		this.listBoxLogFile.FormattingEnabled = true;
		this.listBoxLogFile.HorizontalScrollbar = true;
		this.listBoxLogFile.Location = new System.Drawing.Point(64, 80);
		this.listBoxLogFile.Name = "listBoxLogFile";
		this.listBoxLogFile.Size = new System.Drawing.Size(644, 284);
		this.listBoxLogFile.TabIndex = 0;
		this.labelLogFile.AutoSize = true;
		this.labelLogFile.Location = new System.Drawing.Point(64, 44);
		this.labelLogFile.Name = "labelLogFile";
		this.labelLogFile.Size = new System.Drawing.Size(226, 20);
		this.labelLogFile.TabIndex = 1;
		this.labelLogFile.Text = "Database Configuration Log File:";
		base.AutoScaleDimensions = new System.Drawing.SizeF(8f, 20f);
		base.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
		base.ClientSize = new System.Drawing.Size(775, 451);
		base.Controls.Add(this.labelLogFile);
		base.Controls.Add(this.listBoxLogFile);
		this.Font = new System.Drawing.Font("Segoe UI", 9f);
		base.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
		base.Icon = (System.Drawing.Icon)resources.GetObject("$this.Icon");
		base.MaximizeBox = false;
		base.MinimizeBox = false;
		base.Name = "FrmViewLogFile";
		this.Text = "Database Configuration Log File";
		base.ResumeLayout(false);
		base.PerformLayout();
	}
}
internal interface IDatabaseInfor
{
	string DatabaseName { get; }

	int Components { get; }

	int Databanks { get; }

	int rxn { get; }
}
internal static class Program
{
	[STAThread]
	private static void Main()
	{
		ApplicationConfiguration.Initialize();
		Application.Run(new FrmDBConfig());
	}
}
[SupportedOSPlatform("windows")]
public static class RegistryUtility
{
	[SupportedOSPlatform("windows")]
	public static RegistryKey GetRegistryKeyFromLocalMachine(string path)
	{
		return RegistryKey.OpenBaseKey(RegistryHive.LocalMachine, RegistryView.Registry64)?.OpenSubKey(path);
	}

	[SupportedOSPlatform("windows")]
	public static RegistryKey GetRegistryKeyFromCurrentUser(string path)
	{
		return RegistryKey.OpenBaseKey(RegistryHive.CurrentUser, RegistryView.Registry64)?.OpenSubKey(path);
	}

	[SupportedOSPlatform("windows")]
	public static List<string> GetSubKeys(RegistryKey registryKey)
	{
		return registryKey.GetSubKeyNames().ToList();
	}

	[SupportedOSPlatform("windows")]
	public static string GetPostgresExecutable()
	{
		RegistryKey registryKeyFromLocalMachine = GetRegistryKeyFromLocalMachine("SOFTWARE\\PostgreSQL\\Installations");
		if (registryKeyFromLocalMachine == null)
		{
			return string.Empty;
		}
		List<string> subKeys = GetSubKeys(registryKeyFromLocalMachine);
		if (subKeys == null || subKeys.Count == 0)
		{
			return string.Empty;
		}
		string selectedInstallation = subKeys.Last();
		return GetPostgresExecutablePath(registryKeyFromLocalMachine, selectedInstallation);
	}

	[SupportedOSPlatform("windows")]
	public static string GetPostgresExecutablePath(RegistryKey postgresRegKey, string selectedInstallation)
	{
		RegistryKey registryKey = postgresRegKey.OpenSubKey(selectedInstallation);
		if (registryKey == null)
		{
			return string.Empty;
		}
		string text = registryKey.GetValue("Base Directory").ToString();
		if (text == null)
		{
			return string.Empty;
		}
		return Path.Combine(text, "bin\\psql.exe");
	}

	[SupportedOSPlatform("windows")]
	public static string GetPostgresPort()
	{
		RegistryKey registryKeyFromLocalMachine = GetRegistryKeyFromLocalMachine("SOFTWARE\\PostgreSQL\\Services");
		if (registryKeyFromLocalMachine == null)
		{
			return string.Empty;
		}
		List<string> subKeys = GetSubKeys(registryKeyFromLocalMachine);
		if (subKeys == null || subKeys.Count == 0)
		{
			return string.Empty;
		}
		string name = subKeys.Last();
		return registryKeyFromLocalMachine.OpenSubKey(name).GetValue("Port").ToString();
	}

	[SupportedOSPlatform("windows")]
	public static string GetPostgresPort(string apVersion, out string pgVersion)
	{
		pgVersion = string.Empty;
		if (!GetCurrentPGVersion(apVersion, out pgVersion))
		{
			return string.Empty;
		}
		RegistryKey registryKeyFromLocalMachine = GetRegistryKeyFromLocalMachine("SOFTWARE\\PostgreSQL\\Services");
		if (registryKeyFromLocalMachine == null)
		{
			return string.Empty;
		}
		List<string> subKeys = GetSubKeys(registryKeyFromLocalMachine);
		if (subKeys == null || subKeys.Count == 0)
		{
			return string.Empty;
		}
		string name = string.Empty;
		foreach (string item in subKeys)
		{
			string[] array = item.ToString().Split('-');
			if (array.Length > 1 && pgVersion.CompareTo(array[^1]) == 0)
			{
				name = item;
				break;
			}
		}
		return registryKeyFromLocalMachine.OpenSubKey(name).GetValue("Port").ToString();
	}

	[SupportedOSPlatform("windows")]
	public static string GetPostgresVersion(string apVersion)
	{
		string currentPGVersion = string.Empty;
		if (!GetCurrentPGVersion(apVersion, out currentPGVersion))
		{
			return string.Empty;
		}
		RegistryKey registryKeyFromLocalMachine = GetRegistryKeyFromLocalMachine("SOFTWARE\\PostgreSQL\\Installations");
		if (registryKeyFromLocalMachine == null)
		{
			return string.Empty;
		}
		List<string> subKeys = GetSubKeys(registryKeyFromLocalMachine);
		if (subKeys == null || subKeys.Count == 0)
		{
			return string.Empty;
		}
		string name = string.Empty;
		foreach (string item in subKeys)
		{
			string[] array = item.ToString().Split('-');
			if (array.Length > 1 && currentPGVersion.CompareTo(array[^1]) == 0)
			{
				name = item;
				break;
			}
		}
		return registryKeyFromLocalMachine.OpenSubKey(name).GetValue("Version").ToString();
	}

	[SupportedOSPlatform("windows")]
	public static string GetServerName(string apVersion)
	{
		_ = string.Empty;
		string currentPGVersion = string.Empty;
		if (!GetCurrentPGVersion(apVersion, out currentPGVersion))
		{
			return string.Empty;
		}
		RegistryKey registryKeyFromLocalMachine = GetRegistryKeyFromLocalMachine("SOFTWARE\\PostgreSQL\\Services");
		if (registryKeyFromLocalMachine == null)
		{
			return string.Empty;
		}
		List<string> subKeys = GetSubKeys(registryKeyFromLocalMachine);
		if (subKeys == null || subKeys.Count == 0)
		{
			return string.Empty;
		}
		string name = string.Empty;
		foreach (string item in subKeys)
		{
			string[] array = item.ToString().Split('-');
			if (array.Length > 1 && currentPGVersion.CompareTo(array[^1]) == 0)
			{
				name = item;
				break;
			}
		}
		RegistryKey registryKey = registryKeyFromLocalMachine.OpenSubKey(name);
		if (registryKey == null)
		{
			return string.Empty;
		}
		return registryKey.GetValue("Display Name").ToString();
	}

	[SupportedOSPlatform("windows")]
	public static bool GetCurrentPGVersion(string apVersion, out string currentPGVersion, out string currentPort)
	{
		currentPGVersion = string.Empty;
		currentPort = string.Empty;
		string text = string.Empty;
		RegistryKey registryKeyFromLocalMachine = GetRegistryKeyFromLocalMachine("SOFTWARE\\AspenTech\\PGVersion");
		if (registryKeyFromLocalMachine == null)
		{
			return false;
		}
		List<string> subKeys = GetSubKeys(registryKeyFromLocalMachine);
		if (subKeys == null || subKeys.Count == 0)
		{
			return false;
		}
		foreach (string item in subKeys)
		{
			if (item.Equals(apVersion))
			{
				text = item;
				break;
			}
		}
		if (string.IsNullOrEmpty(text))
		{
			return false;
		}
		RegistryKey registryKey = registryKeyFromLocalMachine.OpenSubKey(text);
		if (registryKey == null)
		{
			return false;
		}
		try
		{
			currentPGVersion = registryKey.GetValue("Version").ToString();
			currentPort = registryKey.GetValue("Port").ToString();
		}
		catch (Exception ex)
		{
			_ = ex.Message;
			currentPGVersion = string.Empty;
			currentPort = string.Empty;
			return false;
		}
		return true;
	}

	[SupportedOSPlatform("windows")]
	public static string GetdbProvider(string version)
	{
		string text = string.Empty;
		RegistryKey registryKeyFromLocalMachine = GetRegistryKeyFromLocalMachine("SOFTWARE\\AspenTech\\APED");
		if (registryKeyFromLocalMachine == null)
		{
			return "mssql";
		}
		List<string> subKeys = GetSubKeys(registryKeyFromLocalMachine);
		if (subKeys == null || subKeys.Count == 0)
		{
			return "mssql";
		}
		foreach (string item in subKeys)
		{
			if (item.Equals(version))
			{
				text = item;
				break;
			}
		}
		if (string.IsNullOrEmpty(text))
		{
			return "mssql";
		}
		RegistryKey registryKey = registryKeyFromLocalMachine.OpenSubKey(text);
		if (registryKey == null)
		{
			return "mssql";
		}
		object value = registryKey.GetValue("dbProvider");
		if (value == null)
		{
			return "mssql";
		}
		return value.ToString();
	}

	[SupportedOSPlatform("windows")]
	public static bool SetdbProvider(string dbProvider, string version)
	{
		string text = string.Empty;
		RegistryKey registryKeyFromLocalMachine = GetRegistryKeyFromLocalMachine("SOFTWARE\\AspenTech\\APED");
		if (registryKeyFromLocalMachine == null)
		{
			return false;
		}
		foreach (string subKey in GetSubKeys(registryKeyFromLocalMachine))
		{
			if (subKey.Equals(version))
			{
				text = subKey;
				break;
			}
		}
		if (string.IsNullOrEmpty(text))
		{
			return false;
		}
		registryKeyFromLocalMachine.OpenSubKey(text, writable: true).SetValue("dbProvider", dbProvider);
		return true;
	}

	[SupportedOSPlatform("windows")]
	public static string GetdbProviderForCurrentUser(string version)
	{
		string text = string.Empty;
		RegistryKey registryKeyFromCurrentUser = GetRegistryKeyFromCurrentUser("SOFTWARE\\AspenTech\\APED");
		if (registryKeyFromCurrentUser == null)
		{
			return string.Empty;
		}
		List<string> subKeys = GetSubKeys(registryKeyFromCurrentUser);
		if (subKeys == null || subKeys.Count == 0)
		{
			return string.Empty;
		}
		foreach (string item in subKeys)
		{
			if (item.Equals(version))
			{
				text = item;
				break;
			}
		}
		if (string.IsNullOrEmpty(text))
		{
			return string.Empty;
		}
		object value = registryKeyFromCurrentUser.OpenSubKey(text).GetValue("dbProvider");
		if (value == null)
		{
			return string.Empty;
		}
		return value.ToString();
	}

	[SupportedOSPlatform("windows")]
	public static bool SetdbProviderForCurrentUser(string dbProvider, string version)
	{
		string text = string.Empty;
		RegistryKey registryKeyFromCurrentUser = GetRegistryKeyFromCurrentUser("SOFTWARE\\AspenTech\\APED");
		if (registryKeyFromCurrentUser == null)
		{
			text = "SOFTWARE\\AspenTech\\APED\\" + version;
			registryKeyFromCurrentUser = Registry.CurrentUser.CreateSubKey(text);
			registryKeyFromCurrentUser.SetValue("dbProvider", dbProvider);
		}
		else
		{
			List<string> subKeys = GetSubKeys(registryKeyFromCurrentUser);
			if (subKeys != null && subKeys.Count > 0)
			{
				foreach (string item in subKeys)
				{
					if (item.Equals(version))
					{
						text = item;
						break;
					}
				}
			}
			if (string.IsNullOrEmpty(text))
			{
				text = "SOFTWARE\\AspenTech\\APED\\" + version;
				registryKeyFromCurrentUser = Registry.CurrentUser.CreateSubKey(text);
				registryKeyFromCurrentUser.SetValue("dbProvider", dbProvider);
			}
			else
			{
				registryKeyFromCurrentUser.OpenSubKey(text, writable: true).SetValue("dbProvider", dbProvider);
			}
		}
		return true;
	}

	[SupportedOSPlatform("windows")]
	public static bool GetCurrentPGVersion(string apVersion, out string currentPGVersion)
	{
		currentPGVersion = string.Empty;
		string text = string.Empty;
		RegistryKey registryKeyFromLocalMachine = GetRegistryKeyFromLocalMachine("SOFTWARE\\AspenTech\\PGVersion");
		if (registryKeyFromLocalMachine == null)
		{
			return false;
		}
		List<string> subKeys = GetSubKeys(registryKeyFromLocalMachine);
		if (subKeys == null || subKeys.Count == 0)
		{
			return false;
		}
		foreach (string item in subKeys)
		{
			if (item.Equals(apVersion))
			{
				text = item;
				break;
			}
		}
		if (string.IsNullOrEmpty(text))
		{
			return false;
		}
		RegistryKey registryKey = registryKeyFromLocalMachine.OpenSubKey(text);
		currentPGVersion = registryKey.GetValue("Version").ToString();
		return true;
	}

	[SupportedOSPlatform("windows")]
	public static void SetLocalPort(string apedVersion, string localPort)
	{
		RegistryKey registryKeyFromLocalMachine = GetRegistryKeyFromLocalMachine("SOFTWARE\\AspenTech\\PGVersion");
		if (registryKeyFromLocalMachine != null)
		{
			RegistryKey? registryKey = registryKeyFromLocalMachine.OpenSubKey(apedVersion, writable: true);
			int num = Convert.ToInt32(localPort);
			registryKey.SetValue("Port", num, RegistryValueKind.DWord);
		}
	}

	[SupportedOSPlatform("windows")]
	public static string GetPostgresExecutable(string type)
	{
		RegistryKey registryKeyFromLocalMachine = GetRegistryKeyFromLocalMachine("SOFTWARE\\PostgreSQL\\Installations");
		if (registryKeyFromLocalMachine == null)
		{
			return null;
		}
		List<string> subKeys = GetSubKeys(registryKeyFromLocalMachine);
		if (subKeys == null || subKeys.Count == 0)
		{
			return null;
		}
		string selectedInstallation = subKeys.Last();
		return GetPostgresExecutablePath(registryKeyFromLocalMachine, selectedInstallation, type);
	}

	[SupportedOSPlatform("windows")]
	public static string GetPostgresExecutablePath(RegistryKey postgresRegKey, string selectedInstallation, string type)
	{
		string path = postgresRegKey.OpenSubKey(selectedInstallation).GetValue("Base Directory").ToString();
		if (type == "backup")
		{
			return Path.Combine(path, "bin\\pg_dump.exe");
		}
		if (type == "restore")
		{
			return Path.Combine(path, "bin\\pg_restore.exe");
		}
		return Path.Combine(path, "bin\\psql.exe");
	}
}
[Serializable]
public class SetupException : ApplicationException
{
	public int StatusCode { get; set; }

	public SetupException(string message, int statusCode = 500)
		: base(message)
	{
		StatusCode = statusCode;
	}

	public SetupException(Exception ex, int statusCode = 500)
		: base(ex.Message)
	{
		StatusCode = statusCode;
	}

	protected SetupException(SerializationInfo info, StreamingContext context)
		: base(info, context)
	{
	}
}
[CompilerGenerated]
internal static class ApplicationConfiguration
{
	public static void Initialize()
	{
		Application.EnableVisualStyles();
		Application.SetCompatibleTextRenderingDefault(defaultValue: false);
		Application.SetHighDpiMode(HighDpiMode.SystemAware);
	}
}
