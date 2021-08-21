#include "database_manager.h"

/*odbc constructor function: It sets up odbc statement handle and connection based on server name, user ID, and password
Inputs: SQLCHAR* dsname, SQLCHAR* userID, SQLCHAR* password
*/
database_manager::database_manager(const char* dsname, const char* userID, const char* password) {
	SQLRETURN retcode; //the return code to check the success of each operation
	SQLHANDLE hdlEnv; //the handle environment
	retcode = SQLAllocHandle(SQL_HANDLE_ENV, NULL, &hdlEnv); //allocates environment handle  
	catch_error(retcode, "Environment handle allocation"); //catches any errors for environment handle allocation 
	retcode = SQLSetEnvAttr(hdlEnv, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0); //sets the ODBC version environment
	catch_error(retcode, "ODBC version environment setup"); //catches any errors for ODBC version environment setup
	retcode = SQLAllocHandle(SQL_HANDLE_DBC, hdlEnv, &hdlConn); //allocates connection handle  
	catch_error(retcode, "Connection handle allocation"); //catches any errors for connection handle allocation
	SQLFreeHandle(SQL_HANDLE_ENV, hdlEnv);
	retcode = SQLConnect(hdlConn, (SQLCHAR*) dsname, SQL_NTS, (SQLCHAR*)userID, SQL_NTS, (SQLCHAR*)password, SQL_NTS); //connects to data server
	catch_error(retcode, "Server connection"); //catches any errors for server connection
	retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdlConn, &hstmt); //allocates statement handle  
	catch_error(retcode, "Statement handle allocation"); //catches any errors for statement handle allocation
}

/*odbc_data function: It exectues command and obtains SQL table data
Input: SQLCHAR* stmt
*/
void database_manager::getdata(const char* stmt) {
	SQLINTEGER cbData, cbName, retcode, sCustID; //defines four SQL integers
	SQLCHAR* szName[50]; //defines a SQL character pointer with 50 characters capacity
	retcode = SQLExecDirect(hstmt, (SQLCHAR*) stmt, SQL_NTS); //executes the stmt statement in the statement handle
	int i = 0; //defines iteration integer
	while (SQLFetch(hstmt) == SQL_SUCCESS) {
		SQLGetData(hstmt, 1, SQL_C_SLONG, &sCustID, 256, &cbData); //gets SQL data of first column
		SQLGetData(hstmt, 2, SQL_C_CHAR, &szName, 50, &cbName); //gets SQL data of second column
		ID[i] = sCustID;
		string s((char*)szName); //converts character pointer to string
		name.push_back(s); //pushes string into string vector
		i++; //increments iteration integer
	}
	for (int i = 0; i < 2; i++) cout << ID[i] << "  "; //prints contents of double array
	cout << endl;
	for (int i = 0; i < 2; i++) cout << name[i] << "  "; //prints contents of string vector
	cout << endl;
	retcode = SQLCloseCursor(hstmt); //closes cursor to prevent 'invalid cursor state' error
	catch_error(retcode, "Cursor close"); //catches any errors for cursor closure
}

/*odbc_manual function: It allows user to manually enter ODBC input
Inputs: None
*/
void database_manager::manual_input() {
	SQLINTEGER retcode;
	while (1) {
		char* input = new char[100]; //defines character input for input
		cout << "Enter input or exit to quit: "; //input prompt message
		fgets(input, 100, stdin); //gets the user input
		if (strcmp(input, "exit\n") == 0) break; //if user typed 'exit' then break the program
		retcode = SQLExecDirect(hstmt, (SQLCHAR*)input, SQL_NTS); //otherwise execute the user input in SQL statement handle
		if (retcode != SQL_SUCCESS) show_error(SQL_HANDLE_STMT, hstmt); //if input failed to execute, show error
		SQLCloseCursor(hstmt); //closes cursor to prevent 'invalid cursor state' error
	}
}

/*odbc_finish function: It finishes ODBC connection
Inputs: None
*/
void database_manager::finish() {
	SQLRETURN retcode = SQLDisconnect(hdlConn); //terminate ODBC connection
	catch_error(retcode, "Connection termination"); //catches any errors for ODBC connection termination
	SQLFreeHandle(SQL_HANDLE_STMT, hstmt); //frees the statement handle
}

/*show_error function: It shows errors for SQL commands
Inputs: unsigned int handletype and const SQLHANDLE& handle
*/
void database_manager::show_error(unsigned int handletype, const SQLHANDLE& handle) {
	SQLCHAR sqlstate[1024];
	SQLCHAR message[1024];
	if (SQL_SUCCESS == SQLGetDiagRec(handletype, handle, 1, sqlstate, NULL, message, 1024, NULL))
		cout << "Message: " << message << "\nSQLSTATE: " << sqlstate << endl;
}

/*catch_error function: It catches errors for SQL functions
Inputs: int retcode and string command
*/
void database_manager::catch_error(int retcode, string command) {
	if (retcode == SQL_SUCCESS) cout << command << " successful." << endl;
	else {
		cout << command << " failed. Error return code: " << retcode << endl;
		exit(1);
	}
}