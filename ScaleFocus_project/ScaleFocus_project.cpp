#include <iostream>
#include <string>
#include <nanodbc.h>
#include <exception>
#include <vector>
#include "Structures.h"

using namespace std;

void getAllUsers(nanodbc::connection conn);
void getAllTeams(nanodbc::connection conn);
void getAllProjects(nanodbc::connection conn);
void getAllTasks(nanodbc::connection conn);
void getAllWorkLogs(nanodbc::connection conn);

string enterText()
{
	string text;
	getline(cin, text);

	return text;
}

int enterInt()
{
	string num;
	getline(cin, num);

	return stoi(num);
}

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

int main()
{
	try
	{
		nanodbc::string connstr = NANODBC_TEXT("DRIVER={ODBC Driver 17 for SQL Server};Server=UNIVERSE\\SQLEXPRESS;DATABASE=ScaleFocus_Project;Trusted_Connection=yes;"); // an ODBC connection string to your database

		nanodbc::connection conn(connstr);

		int id;
		cout << "Enter the user's id that you want to change: ";
		id = enterInt();

		//getAllUsers(conn);
		//getAllTeams(conn);
		//getAllProjects(conn);
		//getAllTasks(conn);
		//getAllWorkLogs(conn);
		//insertUser(conn);
		updateUser(conn, id);

		return EXIT_SUCCESS;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
}
