#ifndef DATABASE
#define DATABASE
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
class database_manager {
public:
	database_manager(SQLCHAR* dsname, SQLCHAR* userID, SQLCHAR* password);
	void getdata(SQLCHAR* stmt);
	void manual_input();
	void finish();
private:
	SQLHSTMT hstmt;
	SQLHANDLE hdlConn;
	double ID[2];
	vector <string> name;
	void show_error(unsigned int handletype, const SQLHANDLE& handle);
	void catch_error(int retcode, string command);
};
#endif