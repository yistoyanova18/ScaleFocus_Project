#include <iostream>
#include <string>
#include <nanodbc.h>
#include <exception>
#include <vector>
#include "Structures.h"

using namespace std;

string enterText();
int enterInt();

void insertUser(nanodbc::connection conn)
{
	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"(
        INSERT INTO
            ScaleFocus_Project.dbo.[User]
            (Username, Password, FirstName, LastName, DateOfCreation, IdOfCreator, DateLastChange, IdLastChange, isAdmin)
            VALUES
            (?, ?, ?, ?, GETDATE(), ?, GETDATE(), ?, 0)
    )"));

	cout << "Enter the user's username: ";
	const string Username = enterText();
	statement.bind(0, Username.c_str());

	cout << "Enter the user's password: ";
	const string Password = enterText();
	statement.bind(1, Password.c_str());

	cout << "Enter the user's first name: ";
	const string firstName = enterText();
	statement.bind(2, firstName.c_str());

	cout << "Enter the user's last name: ";
	const string lastName = enterText();
	statement.bind(3, lastName.c_str());

	cout << "Enter the id of the creator: ";
	const int idOfCreator = enterInt();
	statement.bind(4, &idOfCreator);

	cout << "Enter the id of the user that did the last change: ";
	const int idLastChange = enterInt();
	statement.bind(5, &idLastChange);

	execute(statement);
}