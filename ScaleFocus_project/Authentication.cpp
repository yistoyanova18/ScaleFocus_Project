#include <iostream>
#include <string>
#include <nanodbc.h>
#include <exception>
#include <vector>
#include "Structures.h"

using namespace std;

void isAdmin(nanodbc::connection conn, string username, const int& pass)
{
    nanodbc::statement statement(conn);
    nanodbc::prepare(statement, NANODBC_TEXT(R"(
        SELECT *
            FROM ScaleFocus_Project.dbo.[User]
        WHERE Userneame = admin AND Password = adminpass
    )"));
}

void login(nanodbc::connection conn, string username, const int& pass)
{
    nanodbc::statement statement(conn);
    nanodbc::prepare(statement, NANODBC_TEXT(R"(
        SELECT *
            FROM ScaleFocus_Project.dbo.[User]
        WHERE Userneame = ? AND Password = ?
    )"));

    nanodbc::result result = nanodbc::execute(statement);

    if (result.next()) 
    { 
        // THe user was found    
    }
    else 
    {
        cout << "Incorrect username or password! Try again!" << endl;
    }
}