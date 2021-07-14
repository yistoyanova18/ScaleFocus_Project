#include <iostream>
#include <string>
#include <nanodbc.h>
#include <exception>
#include <vector>
#include "Structures.h"
#include "Functions.h"

using namespace std;

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

	cout << endl;

	cout << u8"                ҉ Enter the user's username: ";
	const string Username = enterText();
	statement.bind(0, Username.c_str());

	cout << u8"                ҉ Enter the user's password: ";
	const string Password = enterText();
	statement.bind(1, Password.c_str());

	cout << u8"                ҉ Enter the user's first name: ";
	const string firstName = enterText();
	statement.bind(2, firstName.c_str());

	cout << u8"                ҉ Enter the user's last name: ";
	const string lastName = enterText();
	statement.bind(3, lastName.c_str());

	cout << u8"                ҉ Enter the id of the creator: ";
	const int idOfCreator = enterInt();
	statement.bind(4, &idOfCreator);

	cout << u8"                ҉ Enter the id of the user that did the last change: ";
	const int idLastChange = enterInt();
	statement.bind(5, &idLastChange);

	execute(statement);

	getBackToMenu(conn);
}

void insertTeam(nanodbc::connection conn)
{
	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"(
        INSERT INTO
            ScaleFocus_Project.dbo.[Team]
            (Title, DateOfCreation, IdCreator, DateLastChange, IdLastChange)
            VALUES
            (?, GETDATE(), ?, GETDATE(), ?)
    )"));

	cout << endl;

	cout << u8"                ҉ Enter the team's title: ";
	const string title = enterText();
	statement.bind(0, title.c_str());

	cout << u8"                ҉ Enter the id of the creator: ";
	const int idOfCreator = enterInt();
	statement.bind(1, &idOfCreator);

	cout << u8"                ҉ Enter the id of the user that did the last change: ";
	const int idLastChange = enterInt();
	statement.bind(2, &idLastChange);

	execute(statement);

	getBackToMenu(conn);
}

void insertProject(nanodbc::connection conn)
{
	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"(
        INSERT INTO
            ScaleFocus_Project.dbo.[Project]
            (Title, Description, DateOfCreation, IdCreator, DateLastChange, IdLastChange)
            VALUES
            (?, ?, GETDATE(), ?, GETDATE(), ?)
    )"));

	cout << endl;

	cout << u8"                ҉ Enter the project's title: ";
	const string title = enterText();
	statement.bind(0, title.c_str());

	cout << u8"                ҉ Enter the project's description: ";
	const string description = enterText();
	statement.bind(1, description.c_str());

	cout << u8"                ҉ Enter the id of the creator: ";
	const int idOfCreator = enterInt();
	statement.bind(2, &idOfCreator);

	cout << u8"                ҉ Enter the id of the user that did the last change: ";
	const int idLastChange = enterInt();
	statement.bind(3, &idLastChange);

	execute(statement);

	getBackToMenu(conn);
}

void insertTask(nanodbc::connection conn)
{
	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"(
        INSERT INTO
            ScaleFocus_Project.dbo.[Task]
            (IdOfProject, IdOfAssignee, Title, Description, TaskStatus, DateOfCreation, IdOfCreator, DateLastChange, IdLastChange)
            VALUES
            (?, ?, ?, ?, ?, GETDATE(), ?, GETDATE(), ?)
    )"));

	cout << endl;

	cout << u8"                ҉ Enter the id of the project that the task belongs to: ";
	const int idOfProject = enterInt();
	statement.bind(0, &idOfProject);

	cout << u8"                ҉ Enter the id of the user that this task has been assigned to: ";
	const int idOfAssignee = enterInt();
	statement.bind(1, &idOfAssignee);

	cout << u8"                ҉ Enter the task's title: ";
	const string title = enterText();
	statement.bind(2, title.c_str());


	cout << u8"                ҉ Enter the task's description: ";
	const string description = enterText();
	statement.bind(3, description.c_str());

	cout << u8"                ҉ Enter the task's status(Pending/ InProgress/ Completed): ";
	const string taskStatus = enterText();
	statement.bind(4, taskStatus.c_str());

	cout << u8"                ҉ Enter the id of the creator: ";
	const int idOfCreator = enterInt();
	statement.bind(5, &idOfCreator);

	cout << u8"                ҉ Enter the id of the user that did the last change: ";
	const int idLastChange = enterInt();
	statement.bind(6, &idLastChange);

	execute(statement);

	getBackToMenu(conn);
}

void insertWorkLog(nanodbc::connection conn)
{
	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"(
        INSERT INTO
            ScaleFocus_Project.dbo.[WorkLog]
            (IdTask, IdUser, Time, Date)
            VALUES
            (?, ?, ?, ?)
    )"));

	cout << endl;

	cout << u8"                ҉ Enter the id of the task that you are logging work for: ";
	const int idTask = enterInt();
	statement.bind(0, &idTask);

	cout << u8"                ҉ Enter the id of the user that is logging work: ";
	const int idUser = enterInt();
	statement.bind(1, &idUser);

	cout << u8"                ҉ Enter the number of hours spent working on the task for that day: ";
	const int time = enterInt();
	statement.bind(2, &time);

	cout << u8"                ҉ Enter the date when the time was spent on the task (Month Day Year Time(AM/PM)): ";
	const string date = enterText();
	statement.bind(3, date.c_str());

	execute(statement);

	getBackToMenu(conn);
}