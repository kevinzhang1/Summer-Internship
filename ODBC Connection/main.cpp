#include "odbc.h"
SQLCHAR* dsnName = (SQLCHAR*)"PostgresVS"; //the database name
SQLCHAR* userID = (SQLCHAR*)"postgres"; //the user ID needed to log in
SQLCHAR* password = (SQLCHAR*)"zhang man"; //the password needed to verify credentials
SQLCHAR* stmt = (SQLCHAR*)"SELECT id, name FROM public.company"; // the SQL command to get all table data

int main(int argc, char* argv[]) {
	odbc o(dsnName, userID, password);
	o.odbc_data(stmt);
	o.odbc_manual();
	o.odbc_finish();
	return 0;
}