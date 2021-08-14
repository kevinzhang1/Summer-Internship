#include <iostream>
#include "windows.h"
#include <stdio.h>
#include <stdlib.h>
#include <sqltypes.h>
#include <sql.h>
#include <sqlext.h>
#include <string.h>
using namespace std;
#define NAME_LEN 64
#define STMT_LEN 128

void show_error(unsigned int handletype, const SQLHANDLE& handle) {
    SQLCHAR sqlstate[1024];
    SQLCHAR message[1024];
    if (SQL_SUCCESS == SQLGetDiagRec(handletype, handle, 1, sqlstate, NULL, message, 1024, NULL))
        cout << "Message: " << message << "\nSQLSTATE: " << sqlstate << endl;
}

int main() {
    SQLHENV  henv = SQL_NULL_HENV;   	// Environment
    SQLHDBC  hdbc = SQL_NULL_HDBC;   	// Connection handle
    SQLHSTMT hstmt = SQL_NULL_HSTMT;  	// Statement handle
    SQLRETURN retcode;
    char sqlStmtCreate[] = "SELECT * FROM public.company;";
    char table[NAME_LEN];
    char sqlstr[STMT_LEN];
    char confirm = 'Y';
    char reply = ' ';

    // Allocate an environment handle
    retcode = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &henv);
  
    //CHECK_ERROR(retcode, "SQLAllocHandle(SQL_HANDLE_ENV)",henv, SQL_HANDLE_ENV);

    // We want ODBC 3 support
    retcode = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0);
  
    //CHECK_ERROR(retcode, "SQLSetEnvAttr(SQL_ATTR_ODBC_VERSION)", hdbc, SQL_HANDLE_DBC);

    // Allocate a connection handle
    retcode = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);
  //  CHECK_ERROR(retcode, "SQLAllocHandle", hdbc, SQL_HANDLE_DBC);

    // Connect to the DSN
    retcode = SQLDriverConnect(hdbc, NULL, (SQLCHAR* )"DSN=PostgresVS;", SQL_NTS, NULL, 0, NULL, SQL_DRIVER_COMPLETE);
   // CHECK_ERROR(retcode, "SQLDriverConnect(DSN=DATASOURCE;)", hdbc, SQL_HANDLE_DBC);

    // Allocate a statement handle
    retcode = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
   
    //sprintf(sqlstr, sqlStmtCreate, table);
    //printf("Sending : %s\n", sqlstr);
    
    retcode = SQLExecDirect(hstmt, (SQLCHAR*)sqlStmtCreate, SQL_NTS);
    show_error(SQL_HANDLE_STMT, hstmt);
    /*
    // Ask user for table name (TestTBL1)
    reply = getStr("Table Name", table, NAME_LEN, confirm);
    if (reply == 'Y' || reply == 'y') {
        // Substitute table name in statement
        
        // Execute CREATE TABLE
       
        if (retcode == SQL_SUCCESS || retcode == SQL_SUCCESS_WITH_INFO) {
            printf("Table Created\n");
        }
        else {
            printf("Table Create Failed : \n");
            CHECK_ERROR(retcode, "SQLExecDirect(STMT)",
                hstmt, SQL_HANDLE_STMT);
        }
    }

exit:

    printf("\nComplete.\n");

    // Free handles
    // Statement
    if (hstmt != SQL_NULL_HSTMT)
        SQLFreeHandle(SQL_HANDLE_STMT, hstmt);

    // Connection
    if (hdbc != SQL_NULL_HDBC) {
        SQLDisconnect(hdbc);
        SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
    }

    // Environment
    if (henv != SQL_NULL_HENV)
        SQLFreeHandle(SQL_HANDLE_ENV, henv);
        */
    return 0;
}