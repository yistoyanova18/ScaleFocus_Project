#include <iostream>
#include <string>
#include <nanodbc.h>
#include <exception>
#include <vector>
#include "Structures.h"
#include "Functions.h"

using namespace std;

int enterInt();

PROJECT getProjectById(nanodbc::connection conn, int id)
{
	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"( 
        SELECT *
            FROM ScaleFocus_Project.dbo.[Project]
		WHERE Id = ?
    )"));

	statement.bind(0, &id);

	auto result = execute(statement);

	PROJECT project;

	if (!result.next()); //cout << "There is no such id" << endl;
	else {
		project.id = result.get<int>("Id");
		project.title = result.get<nanodbc::string>("Title", "");
		project.description = result.get<nanodbc::string>("Description", "");
		project.dateOfCreation = result.get<nanodbc::string>("DateOfCreation");
		project.idOfCreator = result.get<int>("IdCreator", 0);
		project.dateOfLastChange = result.get<nanodbc::string>("DateLastChange");
		project.idLastChange = result.get<int>("IdLastChange", 0);
	}

	return project;
}

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

//display menus
void displayMenu()
{
	cout << endl;
	cout << " Welcome to the project management application!" << endl;
	cout << endl;
	cout << "             1) List all" << endl;
	cout << "             2) Insert" << endl;
	cout << "             3) Update" << endl;
	cout << "             4) Delete" << endl;
	cout << "             5) Quit" << endl;
	cout << " +___________________________________________+" << endl;
	cout << endl;
}

void displayGetAllMenu()
{
	cout << " +_________________________________________+" << endl;
	cout << endl;
	cout << "         1) List all users" << endl;
	cout << "         2) List all teams" << endl;
	cout << "         3) List all projects" << endl;
	cout << "         4) List all tasks" << endl;
	cout << "         5) List all work logs" << endl;
	cout << " +_________________________________________+" << endl;
	cout << endl;
}

void displayInsertAllMenu()
{
	cout << " +_________________________________________+" << endl;
	cout << endl;
	cout << "           1) Insert a user" << endl;
	cout << "           2) Insert a team" << endl;
	cout << "           3) Insert a project" << endl;
	cout << "           4) Insert a task" << endl;
	cout << "           5) Insert a work log" << endl;
	cout << " +_________________________________________+" << endl;
	cout << endl;
}

void displayInsertAllUserMenu()
{
	cout << " +_________________________________________+" << endl;
	cout << endl;
	cout << "           1) Insert a project" << endl;
	cout << "           2) Insert a task" << endl;
	cout << "           3) Insert a work log" << endl;
	cout << " +_________________________________________+" << endl;
	cout << endl;
}

void displayUpdateAllMenu()
{
	cout << " +_________________________________________+" << endl;
	cout << endl;
	cout << "           1) Update a user" << endl;
	cout << "           2) Update a team" << endl;
	cout << "           3) Update a project" << endl;
	cout << "           4) Update a task" << endl;
	cout << "           5) Update a work log" << endl;
	cout << " +_________________________________________+" << endl;
	cout << endl;
}

void displayUpdateAllUserMenu()
{
	cout << " +_________________________________________+" << endl;
	cout << endl;
	cout << "           1) Update a project" << endl;
	cout << "           2) Update a task" << endl;
	cout << "           3) Update a work log" << endl;
	cout << " +_________________________________________+" << endl;
	cout << endl;
}

void goodbyemessage()
{
	cout << endl;
	cout << "Goodbye! See you soon!" << endl;
}

//function menus
bool getAllMenu(nanodbc::connection conn, USER& user)
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

bool insertAllMenu(nanodbc::connection conn, USER& user)
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

bool insertAllUserMenu(nanodbc::connection conn, USER& user)
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

bool updateAllMenu(nanodbc::connection conn, USER& user)
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
		cout << "Enter the team's id that you want to change: ";
		id = enterInt();
		cout << endl;
		updateTeam(conn, id);
		break;
	}

	case 3: {
		system("cls");
		cout << "Enter the project's id that you want to change: ";
		id = enterInt();
		cout << endl;
		updateProject(conn, id);
		break;
	}

	case 4: {
		system("cls");
		cout << "Enter the task's id that you want to change: ";
		id = enterInt();
		cout << endl;
		updateTask(conn, id);
		break;
	}

	case 5: {
		system("cls");
		cout << "Enter the work log's id that you want to change: ";
		id = enterInt();
		cout << endl;
		updateWorkLog(conn, id);
		break;
	}
	default: cout << "Try again! " << endl;
	}

	return true;
}

bool updateAllUserMenu(nanodbc::connection conn, USER& user)
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
		cout << "Enter the project's id that you want to change: ";
		id = enterInt();
		cout << endl;

		PROJECT project = getProjectById(conn, id);

		if (user.id == project.idOfCreator)
		{

			updateProject(conn, id);
		}
		else
		{
			cout << "Sorry, you can't change a project that you didn't create :(" << endl;
		}
		
		break;
	}

	case 2: {
		system("cls");
		cout << "Enter the task's id that you want to change: ";
		id = enterInt();
		cout << endl;
		updateTask(conn, id);
		break;
	}

	case 3: {
		system("cls");
		cout << "Enter the work log's id that you want to change: ";
		id = enterInt();
		cout << endl;
		updateWorkLog(conn, id);
		break;
	}
	default: cout << "Try again! " << endl;
	}

	return true;
}

void deleteAllMenu(nanodbc::connection conn)
{
	cout << "We are very sorry but this functionality is currently unavailable! :(" << endl;
}

//main menus
bool adminMenu(nanodbc::connection conn, USER& user)
{
	int choice;

	displayMenu();

	cout << "Enter an option from the menu: ";
	cin >> choice;

	switch (choice)
	{
	case 1: {
		system("cls");
		getAllMenu(conn, user);
		adminMenu(conn, user);
		break;
	}

	case 2: {
		system("cls");
		insertAllMenu(conn, user);
		adminMenu(conn, user);
		break;
	}

	case 3: {
		system("cls");
		updateAllMenu(conn, user);
		adminMenu(conn, user);
		break;
	}

	case 4: {
		system("cls");
		deleteAllMenu(conn);
		adminMenu(conn, user);
		break;
	}

	case 5: goodbyemessage();  return false;
	default: cout << "Try again! " << endl;
	}

	return true;
}

bool userMenu(nanodbc::connection conn, USER& user)
{
	int choice;

	displayMenu();

	cout << "Enter an option from the menu: ";
	cin >> choice;

	switch (choice)
	{
	case 1: {
		system("cls");
		getAllMenu(conn, user);
		userMenu(conn, user);
		break;
	}

	case 2: {
		system("cls");
		insertAllUserMenu(conn, user);
		userMenu(conn, user);
		break;
	}

	case 3: {
		system("cls");
		updateAllUserMenu(conn, user);
		userMenu(conn, user);
		break;
	}

	case 4: {
		system("cls");
		deleteAllMenu(conn);
		userMenu(conn, user);
		break;
	}

	case 5: goodbyemessage();  return false;
	default: cout << "Try again! " << endl;
	}

	return true;
}