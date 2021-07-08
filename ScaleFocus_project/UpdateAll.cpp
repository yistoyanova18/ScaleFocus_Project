#include <iostream>
#include <string>
#include <nanodbc.h>
#include <exception>
#include <vector>
#include "Structures.h"

using namespace std;

string enterText();
int enterInt();


void updateUser(nanodbc::connection conn, const int& id)
{
	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"(
        UPDATE ScaleFocus_Project.dbo.[User]
		SET
            Username = ?
			,Password = ?
			,FirstName = ?
			,LastName = ?
			,DateLastChange = GETDATE()
			,IdLastChange = ?
		WHERE Id = ?;
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

	cout << "Enter the id of the user that did the last change: ";
	const int idLastChange = enterInt();
	statement.bind(4, &idLastChange);

	statement.bind(5, &id);

	execute(statement);
}