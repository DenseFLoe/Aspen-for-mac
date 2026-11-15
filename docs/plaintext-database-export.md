# Aspen V15 �������ݵ���

**���ñ��������ε�������ѹ���鵵�Ƕ�����Ŀ�ʲ����������������ؽ�������ɾ���򸲸ǡ�** �����Խ����ر��棻���뱣������Ŀ¼��Ԫ���ݡ��ָ��ű���У���ļ������ [���ݿ����ñ���ԭ��](database-preservation.md)��

�������ﱣ���ڱ��� `.local/property-database/plaintext-export/`������Դ�����ϴ���������ԴΪ���� Aspen V15 ��װ���������߲����� Aspen DLL�����ݿ�����ơ����롢��Կ������֤���ݡ���ǰ�������� UI ��ǣ���δ����������档

## ���η�Χ����

2026 �� 11 �� 14 �գ������ĸ����� APED ���ݿ⡢�ĸ� TDE/TIIS �ļ����Լ���װĿ¼�з��ֵĸ������ݿ�����������ļ���

| APED ���ݿ� | �ӿ� | ԭʼ��ֵ��Ԫ | API ������¼ | ���ӿ����õ��д�ֵ�Ĳ����� |
| --- | ---: | ---: | ---: | ---: |
| APV150 | 42 | 2,548,216 | 634,304 | 6,719 |
| NISTV150 | 4 | 3,718,633 | 790,083 | 190,707 |
| APESV150 | 6 | 57,243 | 19,239 | 2,284 |
| FACTV150 | 1 | 20,979 | 20,979 | 0 |
| �ϼ� | 53 | 6,345,071 | 1,464,605 | 199,710 |

112 �� active ��ȫ��������ÿ����ֵ��Ԫ�� `(���ݿ�, cp_id, element_index)` ������ SQL ������������˶ԣ���ȫ���������ظ���ȫ������Ϊ�������֡�NIST �� 42 �� API �շ��ؾ���ԭ������ֵ����û�д�ֵ����ϵ��¼�Ա�����δα��Ϊ�㡣

| �������ݿ� | ���� | ���� |
| --- | ---: | ---: |
| TDE9i | 2 | 42,606 |
| TIIS | 28 | 960,121 |
| TDE9m | 43 | 337,302 |
| TDE9r | 16 | 970,771 |

���⵼�� 7 �� SQLite �ļ��� 1 �� Access �ļ���������װĿ¼�� ProgramData ��ͬԴ������**��Ӧ���ظ���������������ѧ����**�����Լ� 189 ���ı������ļ���`support/inventory.json` Ϊ 220 �����ֵ��ļ������¼��Դ��У�顢���λ�ú�״̬������������ TDE �� 8 ��Դ�ļ�ָ������ר�õ�����

16 �ݽṹ�����ݿ⵼������ʹ�ö��� SQLite �ļ����µ��룬��������һ���� `PRAGMA integrity_check` ȫ��Ϊ `ok`����鱣��ԭ�� SQLite �������������У���ԭװ Aspen ����ָ����������ݿ�����ݰ����������棬GitHub ֻ������д���ߡ����Ժ�˵����

**���ܰѱ��ν������Ϊ���а�װ�ļ�����������롣** ���� 15 �ݾɶ������ļ������˿����ʮ�����Ʊ��棻���� 5 ������ Aspen Plus / AprSystem��`bps.dat`��`dmo.dat`��`flowtran.dat`��`aspcost.dat`��`sdffil.sdf`������ 10 ���� HYSYS / Energy Analyzer �� `.mdf` ģ���ļ��������ѵ����� SQL Server MDF������δ��þ�����֤�Ľṹ����ֵ���ͣ�����ֱ����Ϊ���������ȡ��`opaque_binary_preserved_as_hex` �Ǵ�����״̬��������ͬ�������������ݡ���װ�����ݡ�������Ƕ��������δ��װ��Զ�����ݿ�Ҳ����ȫ����֤��Χ�ڡ�

## ��ֵ��ʾ����

ʹ�� API �� `LabelIJArray`��`LabelJIArray` �ؽ�����չ����1,411,994 �� API ������ 14 λ��Ч��������λ��һ�£�52,611 ���Բ�ͬ�����������嵥�����ڸ��� `api-layout-differences.jsonl`�����ð���Щ�������Ϊ����ʧ�ܻ��Զ����ǣ���ȷ�� API �ĶԳ�չ������ȱʧֵ��Ϊ��ı�������̬�����в���Ĳ�����Ҫ���������������͡��ײ�����������ʮ����ֵ���������������ؼ��Ƚϱ����ǳ�ɸ��˳��Ƚϱ����Ǻ������ϸ�ļ�飻���߶��������Թ�ʽ��ȷ�Ե�֤����

92 ��ʮ����ֵ�� .NET Framework �� Python �Ķ����Ƹ�������г���ĩλ���죬���ں����ݲ��ڣ����� `value_text` ԭ�������������������߶�ȡ����ϵ���� API ���ǿ���̵�ͬһʱ��������գ����μ�¼�˼�������Ԫ���ݺ��ļ���ϣ��δ�޸�Դ�⡣

## ���� APED ���ݱ�ʾ

- `aped/<���ݿ�>/values/constant-values.jsonl`��ÿ��ԭʼ��ֵ��Ԫһ�У����� `cp_id`��`element_index`��**ԭʼ����ʮ�����ַ��� `value_text`** ����ֵԤ�� `value`���������ӿ����ü�û���ӿ����õļ�¼��������ѧ���ƺϲ������ݿ��������ݵ�һ���֡�
- `aped/<���ݿ�>/api/parameters.jsonl`��ԭ��װ API �Ĳ�����ͼ��ÿ������ `cp_id` ѡ��һ��ʵ�������ӿ��ȡ��ȫ���ӿ��������� `active_DatabankCompounds` ��������Դ�����ס�ע�Ϳɾ�ԭʼ ID ������`properties.jsonl` ������ǩ������͵�λԪ���ݡ�
- `aped/<���ݿ�>/storage/`������ active ��ϵ�����ж��塢����嵥�������� SHA-256����ʼ�����е� `active_PropValueConst` �Ǳ���洢�������ں���������� `value_text` �滻����Ҫ�ѳ�ʼ�������Ϊ��������ʹ�á�

��ֵ��Ԫʹ�����������ݿ��ϵ�ԭװ `AspenTech.APED.Database.DecryptVal(data, propName, Version)`������ **V15 �ǹ�������**���������򼯰汾Ϊ `41.0.0.1`�����߽������Ѱ�װ������������ʵ�ֻ��ȡ��Կ������ Aspen ��������º˶Խӿ������ݡ��������ȡʹ�� `GetUnaryPropertyValue`�������� CompoundIndex ��ʶ�Ķ�Ԫʵ�塣

`cp_id` ���� `active_CompoundProperty.cpId`���پ� `cpCompoundId`��`cpPropertyId` ������ֺ����ԡ���Ԫ����Ԫ�͵����˳��ֱ����� `active_Duos`��`active_Trios`��`active_ElectrolytePairs`��`element_index` ��ԭʼ `pvcIndex`�����ܵ��� `active_PropElements.peId` �������±ꡣ�������ȼ���ģ�͹�ʽ�ͷ���չ�������ں����������֤��

`value_text` �������ʮ���Ʊ�ʾ��.NET Framework �� Python ��ʮ����ת��Ϊ�����Ƹ���ʱ�������һ�� ULP����˲�Ҫ�� JSON ��ֵԤ����������ԭ API ��ʱ������ `1e35` ȱʧֵ��ʡ�Դ洢ϵ����Ҳ����ֱ���� API ��������ײ�������ֵ��Ԫ��

## TDE �� SQLite

`TDE9i.sqlite`��`TIIS.sqlite` �� SQLite ֻ�����񵼳�Ϊ JSONL���ֶ����͡�NULL��Unicode��BLOB ��������BLOB ʹ����ȷ��ǵ� Base64��Դ TEXT �зǷ� UTF-8 �ֽ�ʹ�� `$text_hex`������Ĭ�滻�ַ���

`TDE9m.sqlite`��`TDE9r.sqlite` �ڱ���������ͨ��ԭװ `TDE.dll` �����ݿ��ȡ�ӿڵ�����׼ SQL��`schema.sql`������ SQL �� `post-schema.sql` ������ͨ SQLite �ָ���BLOB �ͺ� NUL ���ַ���ʹ�� SQL ʮ�������������������ı������ɶ���ʽ��������������� Windows x64 / V15 ABI�����˶�ʵ�ʴ򿪵��ļ�·���������������Ժ�Դ������ϣ��

## ����

�������·����ӦΪ�µı���Ŀ¼��Python SQL ������Ҫ `pyodbc` �� ODBC Driver 17��API ������Ҫ Windows PowerShell 5.1��Դ���ݿ�ֻ��ѯ�����޸ķ������û�ҵ���¼��

```powershell
$root='.local/property-database/new-export'
foreach($db in 'APV150','NISTV150','APESV150','FACTV150') {
    powershell.exe -NoProfile -NonInteractive -ExecutionPolicy Bypass -File tools/Export-AspenDatabase.ps1 `
        -Database $db -Mode storage -OutputDirectory "$root/aped/$db/values"
    powershell.exe -NoProfile -NonInteractive -ExecutionPolicy Bypass -File tools/Export-AspenDatabase.ps1 `
        -Database $db -Mode parameters -OutputDirectory "$root/aped/$db/api"
    & .local-tools/research/venv/Scripts/python.exe tools/export_aspen_catalogs.py `
        --database $db --output "$root/aped/$db/storage"
}
```

������ӿڷ��ؿ�ֵ���¼�� `failures.jsonl` �����ط����˳��룻����������ʵ��ֵ���˶ԣ������ֱ�������ֵ�Ĺ�ϵ��¼���ȡʧ�ܣ����ܽ�ɾ��ʧ���

����Ŀ⵼�������һ���Ժ��飺

```powershell
& .local-tools/research/venv/Scripts/python.exe tools/verify_aspen_plaintext.py `
    --root $root --evidence .local/property-database/new-encoded-evidence --live-sql
& .local-tools/research/venv/Scripts/python.exe tools/audit_aspen_vectors.py --root $root
```

���鹤�߽�������ֵ���������� evidence Ŀ¼������������ֵ�滻����Ŀ¼�е�ͬ������������У���嵥����Ҫ���Ѻ���Ŀ¼�ظ����иò��衣`--live-sql` ������Ԫ�˶�ԭ�����ݡ�

��ͨ SQLite �븽�����ݵĵ�����

```powershell
foreach($name in 'TDE9i.sqlite','TIIS.sqlite') {
    & .local-tools/research/venv/Scripts/python.exe tools/export_aspen_catalogs.py `
        --sqlite "C:/Program Files/AspenTech/AprSystem V15.0/GUI/Xeq/$name" --output "$root/auxiliary/$name"
}
& .local-tools/research/venv/Scripts/python.exe tools/export_aspen_support.py --output "$root/support"
```

���������ж�ʱ�ɼ� `--resume` У��͸�������ɵ��ļ�������δ��ɵĵ���Ŀ¼ʱӦ�������ֳ���ѡ�������λ�á�

����װĿ¼�� `TDE9m.sqlite`��`TDE9r.sqlite`��`TIIS.sqlite` ���Ƶ� `.local/` �¶�������ʱĿ¼�����У�

```powershell
& .local-tools/research/venv/Scripts/python.exe tools/export_aspen_tde.py `
    --source-directory .local/property-database/tde-read-source `
    --output "$root/tde"
```

## �� Mac �ϻָ���ʹ��

�ָ�����ֻ��Ҫ Python 3.11+ ��׼�⣬������ Aspen �� SQL Server��Ŀ���ļ����벻���ڡ���������Ĺ�ϵ�����飬�ٻָ� APED��

```sh
python3 tools/import_aspen_plaintext.py /data/aped/APV150/storage /data/APV150.sqlite
python3 tools/import_aspen_plaintext.py /data/tde/TDE9r.sqlite /data/TDE9r.sqlite
```

API ������ԭʼ��ϵ���ֱ𱣴棬��������Ӧ����ȷ�����/�ӿ�/����/Ԫ�� ID �������ʲ㡣�������ݱ�����ʵ������ѧģ�͡�����������������ҵ��������ȨǨ�ơ�

���߼�飺

```sh
python3 -m unittest discover -s tests -p test_plaintext_export.py -v
```

��鸲�����ġ����С����š�NUL��NULL���������ֶΡ��Ƿ� UTF-8 TEXT ������ָ����Լ��ܾ����������ļ���������ƥ��ʱ�����������ļ���
