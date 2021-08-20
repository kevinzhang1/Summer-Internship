#include "database_manager.h"
SQLCHAR* dsnName = (SQLCHAR*)"PostgresVS"; //the database name
SQLCHAR* userID = (SQLCHAR*)"postgres"; //the user ID needed to log in
SQLCHAR* password = (SQLCHAR*)"zhang man"; //the password needed to verify credentials
SQLCHAR* stmt = (SQLCHAR*)"SELECT id, name FROM public.company"; // the SQL command to get all table data

int main(int argc, char* argv[]) {
	database_manager d(dsnName, userID, password);
	d.getdata(stmt);
	d.manual_input();
	d.finish();
	return 0;
}