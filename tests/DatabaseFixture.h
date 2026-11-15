#pragma once
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

// Synthetic records only. Each caller owns a fresh temporary directory.
inline QString databaseFixture(const QString &directory) {
        const auto path=directory+"/catalog.sqlite";
        {
            auto db=QSqlDatabase::addDatabase("QSQLITE","fixture-writer");db.setDatabaseName(path);if(!db.open()) return {};
            QSqlQuery q(db);
            const QStringList statements{
                "CREATE TABLE metadata(key TEXT,value TEXT)",
                "INSERT INTO metadata VALUES ('schema_version','1'),('dataset_id','aspen-v15-synthetic-test'),('validation','query-only-unverified-for-calculation')",
                "CREATE TABLE compounds(db TEXT,id TEXT,name TEXT,alias TEXT,cas TEXT)",
                "INSERT INTO compounds VALUES ('TEST','1','TEST-WATER','H2O','7732-18-5')",
                "CREATE TABLE identifiers(db TEXT,compound_id TEXT,kind TEXT,value TEXT)",
                "INSERT INTO identifiers VALUES ('TEST','1','NAME','TEST-WATER'),('TEST','1','ALIAS','H2O'),('TEST','1','CASRN','7732-18-5'),('TEST','1','SYNONYM','A%_literal')",
                "CREATE TABLE parameters(db TEXT,cp_id INTEGER,compound_id TEXT,property_id INTEGER)",
                "INSERT INTO parameters VALUES ('TEST',7,'1',3)",
                "CREATE TABLE properties(db TEXT,id INTEGER,name TEXT,description TEXT,units TEXT,metadata TEXT)",
                "INSERT INTO properties VALUES ('TEST',3,'FAKE','Synthetic parameter','[]','{}')",
                "CREATE TABLE parameter_values(db TEXT,cp_id INTEGER,element_index INTEGER,value_text TEXT)",
                "INSERT INTO parameter_values VALUES ('TEST',7,100,'123.456789012345678901')",
                "CREATE TABLE refs(db TEXT,dbc_id INTEGER,cp_id INTEGER,bank_id INTEGER)",
                "INSERT INTO refs VALUES ('TEST',11,7,9)",
                "CREATE TABLE databanks(db TEXT,id INTEGER,name TEXT)",
                "INSERT INTO databanks VALUES ('TEST',9,'SYNTHETIC')",
                "CREATE TABLE citations(db TEXT,id INTEGER,record TEXT)",
                "CREATE TABLE citation_links(db TEXT,dbc_id INTEGER,citation_id INTEGER)",
                "CREATE TABLE notes(db TEXT,dbc_id INTEGER,note TEXT)",
                "INSERT INTO notes VALUES ('TEST',11,'Synthetic provenance')",
                "CREATE TABLE data_info(db TEXT,dbc_id INTEGER,record TEXT)",
                "CREATE TABLE sources(db TEXT,table_name TEXT,file TEXT,sha256 TEXT,row_count INTEGER)",
                "INSERT INTO sources VALUES ('TEST','active_Compounds','synthetic.jsonl','test-only',1)"
            };
            for(const auto &sql:statements) if(!q.exec(sql)) {qWarning()<<q.lastError();return {};}
        }
        QSqlDatabase::removeDatabase("fixture-writer");return path;
    }
