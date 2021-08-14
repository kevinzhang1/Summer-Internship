#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <sqltypes.h>
#include <sql.h>
#include <sqlext.h>
#include <string.h>
using namespace std;
SQLHSTMT hstmt;
SQLHANDLE hdlEnv, hdlConn, hdlDbc;
const char* dsnName = "PostgresVS";
const char* userID = "postgres";
const char* passwd = "zhang man";
const char* stmt = "SELECT TABLE_NAME FROM INFORMATION_SCHEMA.TABLES WHERE TABLE_TYPE = 'BASE TABLE' AND TABLE_CATALOG = 'dbName'";
SQLINTEGER cbData;
char* retVal[256];
SQLINTEGER sCustID;
SQLRETURN rc1;

void show_error(unsigned int handletype, const SQLHANDLE& handle)
{
	SQLCHAR sqlstate[1024];
	SQLCHAR message[1024];
	if (SQL_SUCCESS == SQLGetDiagRec(handletype, handle, 1, sqlstate, NULL, message, 1024, NULL))
		cout << "Message: " << message << "\nSQLSTATE: " << sqlstate << endl;
}

int main(int argc, char* argv[])
{
	SWORD sParm1 = 0, sParm2 = 1;
	SQLLEN cbParm1 = SQL_NTS;
	SQLLEN cbParm2 = SQL_NTS;
	SQLRETURN retcode;
	retcode = SQLAllocHandle(SQL_HANDLE_ENV, NULL, &hdlEnv);
	retcode = SQLSetEnvAttr(hdlEnv, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0);
	retcode = SQLAllocHandle(SQL_HANDLE_DBC, hdlEnv, &hdlConn);
	 retcode=SQLConnect(hdlConn, (SQLCHAR*)dsnName, SQL_NTS, (SQLCHAR*)userID, SQL_NTS, (SQLCHAR*)passwd, SQL_NTS);
	 if (retcode == SQL_SUCCESS) {
		 cout << "Connection successful." << endl;
	 }
	 else {
		 cout << "Connection failed. Error return code: " << retcode << endl;
		 return 1;
	 }
	 retcode=SQLAllocHandle(SQL_HANDLE_STMT, hdlConn, &hstmt);
	 if (retcode == SQL_SUCCESS) {
		 cout << "Allocation successful." << endl;
	 }
	 else {
		 cout << "Allocation failed. Error return code: " << (SQLRETURN)retcode << endl;
		 return 1;
	 }
	 // Bind the return code to variable sParm1.  
	 retcode = SQLBindParameter(hstmt, 1, SQL_PARAM_OUTPUT, SQL_C_SSHORT, SQL_INTEGER, 0, 0, &sParm1, 0, &cbParm1);
	 if ((retcode != SQL_SUCCESS) && (retcode != SQL_SUCCESS_WITH_INFO)) {
		 printf("SQLBindParameter(sParm1) Failed\n\n");
		 return(9);
	 }

	 // Bind the output parameter to variable sParm2.  
	 retcode = SQLBindParameter(hstmt, 2, SQL_PARAM_OUTPUT, SQL_C_SSHORT, SQL_INTEGER, 0, 0, &sParm2, 0, &cbParm2);
	 if ((retcode != SQL_SUCCESS) && (retcode != SQL_SUCCESS_WITH_INFO)) {
		 printf("SQLBindParameter(sParm2) Failed\n\n");
		 return(9);
	 }
	 while(1) {
		 char* input = new char[100];
		 cout << "Enter input or exit to quit: ";
		 fgets(input, 100, stdin);
		 if(strcmp(input, "exit\n")==0) break;
		 retcode = SQLExecDirect(hstmt, (SQLCHAR*)input, SQL_NTS);
		 if (retcode == SQL_SUCCESS) {
			 while (SQLFetch(hstmt) == SQL_SUCCESS)
			 {
				 SQLGetData(hdlConn, 0, DT_CHARSTREAM, retVal, 256, &cbData);
				 cout << retVal << endl;
			 }
		 }
		 else {
			 show_error(SQL_HANDLE_STMT, hstmt);
		 }
	 }
	 retcode = SQLDisconnect(hdlConn);
	 if (retcode == SQL_SUCCESS) {
		 cout << "Terminated connection." << endl;
	 }
	 else {
		 cout << "Failed to terminate connection. Error return code: " << (SQLRETURN)retcode << endl;
		 return 1;
	 }
	return 0;
}