#ifndef ODBC
#define ODBC
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <sqltypes.h>
#include <sql.h>
#include <sqlext.h>
#include <string.h>
#include <map>
#include <vector>
using namespace std;
class odbc {
public:
	odbc(SQLCHAR* dsname, SQLCHAR* userID, SQLCHAR* password);
	void odbc_data(SQLCHAR* stmt);
	void odbc_manual();
	void odbc_finish();
private:
	SQLHSTMT hstmt;
	SQLHANDLE hdlConn;
	double ID[2];
	vector <string> name;
	void show_error(unsigned int handletype, const SQLHANDLE& handle);
	void catch_error(int retcode, string command);
};
#endif