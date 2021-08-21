#include "database_manager.h"
const char* dsnName = "PostgresVS"; //the database name
const char* userID = "postgres"; //the user ID needed to log in
const char* password = "zhang man"; //the password needed to verify credentials
const char* stmt = "SELECT id, name FROM public.company"; // the SQL command to get all table data

int main(int argc, char* argv[]) {
	database_manager database_session1(dsnName, userID, password);
	database_session1.getdata(stmt);
	database_session1.manual_input();
	database_session1.finish();
	return 0;
}