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
}