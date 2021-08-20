#include "odbc.h"
SQLHSTMT hstmt;
SQLHANDLE hdlConn;
SQLCHAR* dsnName = (SQLCHAR*)"PostgresVS"; //the database name
SQLCHAR* userID = (SQLCHAR*)"postgres"; //the user ID needed to log in
SQLCHAR* password = (SQLCHAR*)"zhang man"; //the password needed to verify credentials
SQLCHAR* stmt = (SQLCHAR*)"SELECT id, name FROM public.company"; // the SQL command to get all table data

int main(int argc, char* argv[]) {
	odbc_setup(dsnName, userID, password, &hstmt, &hdlConn);
	odbc_data(hstmt, stmt);
	odbc_manual(hstmt);
	odbc_finish(hdlConn, hstmt);
	return 0;
}