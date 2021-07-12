#include <iostream>
#include <string>
#include <nanodbc.h>
#include <exception>
#include <vector>
#include "Structures.h"
#include "Functions.h"

using namespace std;

int enterInt();

USER login(nanodbc::connection conn, string username, string password)
{
	USER user{};
    nanodbc::statement statement(conn);
    nanodbc::prepare(statement, NANODBC_TEXT(R"(
        SELECT *
            FROM ScaleFocus_Project.dbo.[User]
        WHERE Username = ? AND Password = ?
    )"));

    statement.bind(0, username.c_str());

    statement.bind(1, password.c_str());

    nanodbc::result result = nanodbc::execute(statement);
	if (result.next())
	{
		user.id = result.get<int>("Id");
		user.username = result.get<nanodbc::string>("Username", "");
		user.password = result.get<nanodbc::string>("Password", "");
		user.firstName = result.get<nanodbc::string>("FirstName", "");
		user.lastName = result.get<nanodbc::string>("LastName", "");
		user.dateOfCreation = result.get<nanodbc::string>("DateOfCreation", "");
		user.idOfCreator = result.get<int>("IdOfCreator", 0);
		user.dateOfLastChange = result.get<nanodbc::string>("DateLastChange", "");
		user.idLastChange = result.get<int>("IdLastChange", 0);
		user.isAdmin = result.get<int>("isAdmin");
	}

	return user;
}

void displayMenu()
{
	cout << endl;
	cout << "Welcome to the project management application!" << endl;
	cout << "1) List all" << endl;
	cout << "2) Insert" << endl;
	cout << "3) Update" << endl;
	cout << "4) Delete" << endl;
	cout << "5) Quit" << endl;
	cout << endl;
}

void displayGetAllMenu()
{
	cout << "1) List all users" << endl;
	cout << "2) List all teams" << endl;
	cout << "3) List all projects" << endl;
	cout << "4) List all tasks" << endl;
	cout << "5) List all work logs" << endl;
	cout << endl;
}

void displayInsertAllMenu()
{
	cout << "1) Insert a user" << endl;
	cout << "2) Insert a team" << endl;
	cout << "3) Insert a project" << endl;
	cout << "4) Insert a task" << endl;
	cout << "5) Insert a work log" << endl;
	cout << endl;
}

void displayInsertAllUserMenu()
{
	cout << "1) Insert a project" << endl;
	cout << "2) Insert a task" << endl;
	cout << "3) Insert a work log" << endl;
	cout << endl;
}

void displayUpdateAllMenu()
{
	cout << "1) Update a user" << endl;
	cout << "2) Update a team" << endl;
	cout << "3) Update a project" << endl;
	cout << "4) Update a task" << endl;
	cout << "5) Update a work log" << endl;
	cout << endl;
}

void displayUpdateAllUserMenu()
{
	cout << "1) Update a project" << endl;
	cout << "2) Update a task" << endl;
	cout << "3) Update a work log" << endl;
	cout << endl;
}

bool getAllMenu(nanodbc::connection conn)
{
	int choice;

	displayGetAllMenu();

	cout << "Enter an option from the menu: ";
	cin >> choice;

	switch (choice)
	{
	case 1: {
		system("cls");
		getAllUsers(conn);
		break;
	}

	case 2: {
		system("cls");
		getAllTeams(conn);
		break;
	}

	case 3: {
		system("cls");
		getAllProjects(conn);
		break;
	}

	case 4: {
		system("cls");
		getAllTasks(conn);
		break;
	}

	case 5: {
		system("cls");
		getAllWorkLogs(conn);
		break; 
	}
	default: cout << "Try again! " << endl;
	}

	return true;
}

bool insertAllMenu(nanodbc::connection conn)
{
	int choice;

	displayInsertAllMenu();

	cout << "Enter an option from the menu: ";
	cin >> choice;
	cout << endl;

	switch (choice)
	{
	case 1: {
		system("cls");
		insertUser(conn);
		break;
	}

	case 2: {
		system("cls");
		insertTeam(conn);
		break;
	}

	case 3: {
		system("cls");
		insertProject(conn);
		break;
	}

	case 4: {
		system("cls");
		insertTask(conn);
		break;
	}

	case 5: {
		system("cls");
		insertWorkLog(conn);
		break;
	}
	default: cout << "Try again! " << endl;
	}

	return true;
}

bool insertAllUserMenu(nanodbc::connection conn)
{
	int choice;

	displayInsertAllUserMenu();

	cout << "Enter an option from the menu: ";
	cin >> choice;
	cout << endl;

	switch (choice)
	{
	case 1: {
		system("cls");
		insertProject(conn);
		break;
	}

	case 2: {
		system("cls");
		insertTask(conn);
		break;
	}

	case 3: {
		system("cls");
		insertWorkLog(conn);
		break;
	}
	default: cout << "Try again! " << endl;
	}

	return true;
}

bool updateAllMenu(nanodbc::connection conn)
{
	int choice;
	int id;

	displayUpdateAllMenu();

	cout << "Enter an option from the menu: ";
	cin >> choice;

	switch (choice)
	{
	case 1: {
		system("cls");
		cout << "Enter the user's id that you want to change: ";
		id = enterInt();
		cout << endl;
		updateUser(conn, id);
		break;
	}

	case 2: {
		system("cls");
		cout << "Enter the user's id that you want to change: ";
		id = enterInt();
		cout << endl;
		updateTeam(conn, id);
		break;
	}

	case 3: {
		system("cls");
		cout << "Enter the user's id that you want to change: ";
		id = enterInt();
		cout << endl;
		updateProject(conn, id);
		break;
	}

	case 4: {
		system("cls");
		cout << "Enter the user's id that you want to change: ";
		id = enterInt();
		cout << endl;
		updateTask(conn, id);
		break;
	}

	case 5: {
		system("cls");
		id = enterInt();
		cout << endl;
		updateWorkLog(conn, id);
		break;
	}
	default: cout << "Try again! " << endl;
	}

	return true;
}

bool updateAllUserMenu(nanodbc::connection conn)
{
	int choice;
	int id;

	displayUpdateAllUserMenu();

	cout << "Enter an option from the menu: ";
	cin >> choice;

	switch (choice)
	{
	case 1: {
		system("cls");
		cout << "Enter the user's id that you want to change: ";
		id = enterInt();
		cout << endl;
		updateProject(conn, id);
		break;
	}

	case 2: {
		system("cls");
		cout << "Enter the user's id that you want to change: ";
		id = enterInt();
		cout << endl;
		updateTask(conn, id);
		break;
	}

	case 3: {
		system("cls");
		id = enterInt();
		cout << endl;
		updateWorkLog(conn, id);
		break;
	}
	default: cout << "Try again! " << endl;
	}

	return true;
}

void deleteAllMenu(nanodbc::connection con)
{
	cout << "We are very sorry but this functionality is currently unavailable! :(" << endl;
}

bool adminMenu(nanodbc::connection conn)
{
	int choice;

	displayMenu();

	cout << "Enter an option from the menu: ";
	cin >> choice;

	switch (choice)
	{
	case 1: {
		system("cls");
		getAllMenu(conn);
		break;
	}

	case 2: {
		system("cls");
		insertAllMenu(conn);
		break;
	}

	case 3: {
		system("cls");
		updateAllMenu(conn);
		break;
	}

	case 4: {
		system("cls");
		deleteAllMenu(conn);
		break;
	}

	case 5: return false;
	default: cout << "Try again! " << endl;
	}

	return true;
}

bool userMenu(nanodbc::connection conn)
{
	int choice;

	displayMenu();

	cout << "Enter an option from the menu: ";
	cin >> choice;

	switch (choice)
	{
	case 1: {
		system("cls");
		getAllMenu(conn);
		break;
	}

	case 2: {
		system("cls");
		insertAllUserMenu(conn);
		break;
	}

	case 3: {
		system("cls");
		updateAllUserMenu(conn);
		break;
	}

	case 4: {
		system("cls");
		deleteAllMenu(conn);
		break;
	}

	case 5: return false;
	default: cout << "Try again! " << endl;
	}

	return true;
}