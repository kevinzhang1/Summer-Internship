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

void show_error(unsigned int handletype, const SQLHANDLE& handle);
void catch_error(int retcode, string command);
void odbc_setup(SQLCHAR* dsname, SQLCHAR* userID, SQLCHAR* password, SQLHSTMT* hstmt, SQLHANDLE* hdlConn);
void odbc_finish(SQLHANDLE hdlConn, SQLHSTMT hstmt);
void odbc_data(SQLHSTMT hstmt, SQLCHAR* stmt);
void odbc_manual(SQLHSTMT hstmt);
#endif