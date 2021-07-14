#include <iostream>
#include <string>
#include <nanodbc.h>
#include <exception>
#include <vector>
#include "Structures.h"
#include "Functions.h"

using namespace std;

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

	cout << "Enter the user's new username: ";
	const string username = enterText();
	statement.bind(0, username.c_str());

	cout << "Enter the user's new password: ";
	const string password = enterText();
	statement.bind(1, password.c_str());

	cout << "Enter the user's new first name: ";
	const string firstName = enterText();
	statement.bind(2, firstName.c_str());

	cout << "Enter the user's new last name: ";
	const string lastName = enterText();
	statement.bind(3, lastName.c_str());

	cout << "Enter the id of the user that did the last change: ";
	const int idLastChange = enterInt();
	statement.bind(4, &idLastChange);

	statement.bind(5, &id);

	execute(statement);

	getBackToMenu(conn);
}

void updateTeam(nanodbc::connection conn, const int& id)
{
	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"(
        UPDATE ScaleFocus_Project.dbo.[Team]
		SET
            Title = ?
			,DateLastChange = GETDATE()
			,IdLastChange = ?
		WHERE Id = ?;
    )"));

	cout << "Enter the team's new title: ";
	const string title = enterText();
	statement.bind(0, title.c_str());

	cout << "Enter the id of the user that did the last change: ";
	const int idLastChange = enterInt();
	statement.bind(1, &idLastChange);

	statement.bind(2, &id);

	execute(statement);

	getBackToMenu(conn);
}

void updateProject(nanodbc::connection conn, const int& id)
{
	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"(
        UPDATE ScaleFocus_Project.dbo.[Project]
		SET
            Title = ?
			,Description = ?
			,DateLastChange = GETDATE()
			,IdLastChange = ?
		WHERE Id = ?;
    )"));

	cout << "Enter the project's new title: ";
	const string title = enterText();
	statement.bind(0, title.c_str());

	cout << "Enter the project's new description: ";
	const string description = enterText();
	statement.bind(1, description.c_str());

	cout << "Enter the id of the user that did the last change: ";
	const int idLastChange = enterInt();
	statement.bind(2, &idLastChange);

	statement.bind(3, &id);

	execute(statement);

	getBackToMenu(conn);
}

void updateTask(nanodbc::connection conn, const int& id)
{
	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"(
        UPDATE ScaleFocus_Project.dbo.[Task]
		SET
			IdOfAssignee = ?
            ,Title = ?
			,Description = ?
			,TaskStatus = ?
			,DateLastChange = GETDATE()
			,IdLastChange = ?
		WHERE Id = ?;
    )"));

	cout << "Enter the new id of the user that this task has been assigned to: ";
	const int idOfAssignee = enterInt();
	statement.bind(0, &idOfAssignee);

	cout << "Enter the task's new title: ";
	const string title = enterText();
	statement.bind(1, title.c_str());

	cout << "Enter the task's new description: ";
	const string description = enterText();
	statement.bind(2, description.c_str());

	cout << "Enter the task's new status(Pending/ InProgress/ Completed): ";
	const string taskStatus = enterText();
	statement.bind(3, taskStatus.c_str());

	cout << "Enter the id of the user that did the last change: ";
	const int idLastChange = enterInt();
	statement.bind(4, &idLastChange);

	statement.bind(5, &id);

	execute(statement);

	getBackToMenu(conn);
}

void updateWorkLog(nanodbc::connection conn, const int& id)
{
	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"(
        UPDATE ScaleFocus_Project.dbo.[WorkLog]
		SET
			IdTask = ?
            ,IdUser = ?
			,Time = ?
			,Date = ?
		WHERE Id = ?;
    )"));

	cout << "Enter the new id of the task that you are logging work for: ";
	const int idTask = enterInt();
	statement.bind(0, &idTask);

	cout << "Enter the new id of the user that is logging work: ";
	const int idUser = enterInt();
	statement.bind(1, &idUser);

	cout << "Enter the number of hours spent working on the task for that day: ";
	const int time = enterInt();
	statement.bind(2, &time);

	cout << "Enter the date when the time was spent on the task (year-month-day): ";
	const string date = enterText();
	statement.bind(3, date.c_str());

	statement.bind(4, &id);

	execute(statement);

	getBackToMenu(conn);
}