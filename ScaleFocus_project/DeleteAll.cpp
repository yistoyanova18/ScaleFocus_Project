#include <iostream>
#include <string>
#include <nanodbc.h>
#include <exception>
#include <vector>
#include "Structures.h"
#include "Functions.h"

using namespace std;

void USER::deleteUserById(nanodbc::connection& conn, const int& id)
{
	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"(
        UPDATE ScaleFocus_Project.dbo.[User]
			SET IsDeleted = 1
            WHERE Id = ?
    )"));

	statement.bind(0, &id);
	auto result = execute(statement);

	cout << "Deleted successfully!" << endl;
	cout << endl;

	getBackToMenu(conn);
}

void TEAM::deleteTeamById(nanodbc::connection& conn, const int& id)
{
	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"(
        UPDATE ScaleFocus_Project.dbo.[Team]
			SET IsDeleted = 1
            WHERE Id = ?
    )"));

	statement.bind(0, &id);
	auto result = execute(statement);

	cout << "Deleted successfully!" << endl;
	cout << endl;

	getBackToMenu(conn);
}

void PROJECT::deleteProjectById(nanodbc::connection& conn, const int& id)
{
	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"(
        UPDATE ScaleFocus_Project.dbo.[Project]
			SET IsDeleted = 1
            WHERE Id = ?
    )"));

	statement.bind(0, &id);
	auto result = execute(statement);

	cout << "Deleted successfully!" << endl;
	cout << endl;

	getBackToMenu(conn);
}

void TASK::deleteTaskById(nanodbc::connection& conn, const int& id)
{
	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"(
        UPDATE ScaleFocus_Project.dbo.[Task]
			SET IsDeleted = 1
            WHERE Id = ?
    )"));

	statement.bind(0, &id);
	auto result = execute(statement);

	cout << "Deleted successfully!" << endl;
	cout << endl;

	getBackToMenu(conn);
}

void WORKLOG::deleteWorkLogById(nanodbc::connection& conn, const int& id)
{
	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"(
        UPDATE ScaleFocus_Project.dbo.[WorkLog]
			SET IsDeleted = 1
            WHERE Id = ?
    )"));

	statement.bind(0, &id);
	auto result = execute(statement);

	cout << "Deleted successfully!" << endl;
	cout << endl;

	getBackToMenu(conn);
}