#include <iostream>
#include <string>
#include <nanodbc.h>
#include <exception>
#include <vector>
#include <windows.h>
#include <conio.h>
#include "Structures.h"
#include "Functions.h"

using namespace std;

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
void displayMessage()
{
	system("cls");
	cout <<"		       "<< u8"𝐖𝐞𝐥𝐜𝐨𝐦𝐞 𝐭𝐨 𝐭𝐡𝐞 𝐩𝐫𝐨𝐣𝐞𝐜𝐭 𝐦𝐚𝐧𝐚𝐠𝐞𝐦𝐞𝐧𝐭 𝐚𝐩𝐩𝐥𝐢𝐜𝐚𝐭𝐢𝐨𝐧!" << endl;
}

void displayMenu()
{
	cout << endl;
	cout << "			+_________________________________________+" << endl;
	cout << endl;
	cout << "					 1) List all" << endl;
	cout << "					 2) Insert" << endl;
	cout << "					 3) Update" << endl;
	cout << "					 4) Delete" << endl;
	cout << "					 5) Quit" << endl;
	cout << "			+________________________________________+" << endl;
	cout << endl;
}

void displayGetAllMenu()
{
	cout << "			 +_________________________________________+" << endl;
	cout << endl;
	cout << "					 1) List all users" << endl;
	cout << "					 2) List all teams" << endl;
	cout << "					 3) List all projects" << endl;
	cout << "					 4) List all tasks" << endl;
	cout << "					 5) List all work logs" << endl;
	cout << "					 6) Return back to main menu" << endl;
	cout << "			 +_________________________________________+" << endl;
	cout << endl;
}

void displayGetAllUserMenu()
{
	cout << "			 +_________________________________________+" << endl;
	cout << endl;
	cout << "					 1) List all users" << endl;
	cout << "					 2) List all teams" << endl;
	cout << "					 3) List all projects" << endl;
	cout << "					 4) List all tasks" << endl;
	cout << "					 5) Return back to main menu" << endl;
	cout << "			 +_________________________________________+" << endl;
	cout << endl;
}

void displayGetAllWorkLogsFormTasksMenu()
{
	cout << "			 +_________________________________________+" << endl;
	cout << endl;
	cout << "					 1) List all tasks" << endl;
	cout << "					 2) List all work logs" << endl;
	cout << "					 3) Return back to main menu" << endl;
	cout << "			 +_________________________________________+" << endl;
	cout << endl;
}

void displayInsertAllMenu()
{
	cout << "			 +_________________________________________+" << endl;
	cout << endl;
	cout << "					 1) Insert a user" << endl;
	cout << "					 2) Insert a team" << endl;
	cout << "					 3) Insert a project" << endl;
	cout << "					 4) Insert a task" << endl;
	cout << "					 5) Insert a work log" << endl;
	cout << "					 6) Return back to main menu" << endl;
	cout << "			 +_________________________________________+" << endl;
	cout << endl;
}

void displayInsertAllUserMenu()
{
	cout << "			 +_________________________________________+" << endl;
	cout << endl;
	cout << "					 1) Insert a project" << endl;
	cout << "					 2) Insert a task" << endl;
	cout << "					 3) Return back to main menu" << endl;
	cout << "			 +_________________________________________+" << endl;
	cout << endl;
}

void displayInsertLogsInTaskMenu()
{
	cout << "			 +_________________________________________+" << endl;
	cout << endl;
	cout << "					 1) Insert a task" << endl;
	cout << "					 2) Insert a work log" << endl;
	cout << "					 3) Return back to main menu" << endl;
	cout << "			 +_________________________________________+" << endl;
	cout << endl;
}

void displayUpdateAllMenu()
{
	cout << "			 +_________________________________________+" << endl;
	cout << endl;
	cout << "					 1) Update a user" << endl;
	cout << "					 2) Update a team" << endl;
	cout << "					 3) Update a project" << endl;
	cout << "					 4) Update a task" << endl;
	cout << "					 5) Update a work log" << endl;
	cout << "					 6) Return back to main menu" << endl;
	cout << "			 +_________________________________________+" << endl;
	cout << endl;
}

void displayUpdateAllUserMenu()
{
	cout << "			 +_________________________________________+" << endl;
	cout << endl;
	cout << "					 1) Update a project" << endl;
	cout << "					 2) Update a task" << endl;
	cout << "					 3) Return back to main menu" << endl;
	cout << "			 +_________________________________________+" << endl;
	cout << endl;
}

void displayUpdateLogsInTaskMenu()
{
	cout << "			 +_________________________________________+" << endl;
	cout << endl;
	cout << "					 1) Update a task" << endl;
	cout << "					 2) Update a work log" << endl;
	cout << "					 3) Return back to main menu" << endl;
	cout << "			 +_________________________________________+" << endl;
	cout << endl;
}

void displayDeleteAllMenu()
{
	cout << "			 +_________________________________________+" << endl;
	cout << endl;
	cout << "					 1) Delete a user" << endl;
	cout << "					 2) Delete a team" << endl;
	cout << "					 3) Delete a project" << endl;
	cout << "					 4) Delete a task" << endl;
	cout << "					 5) Delete a work log" << endl;
	cout << "					 6) Return back to main menu" << endl;
	cout << "			 +_________________________________________+" << endl; 
	cout << endl;
}

void displayDeleteAllUserMenu()
{
	cout << "			 +_________________________________________+" << endl;
	cout << endl;
	cout << "					 1) Delete a project" << endl;
	cout << "					 2) Delete a task" << endl;
	cout << "					 3) Return back to main menu" << endl;
	cout << "			 +_________________________________________+" << endl;
	cout << endl;
}

void displayDeleteLogsInTaskMenu()
{
	cout << "			 +_________________________________________+" << endl;
	cout << endl;
	cout << "					 1) Delete a task" << endl;
	cout << "					 2) Delete a work log" << endl;
	cout << "					 3) Return back to main menu" << endl;
	cout << "			 +_________________________________________+" << endl;
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

	do {
		displayGetAllMenu();

		cout << "Enter an option from the menu: ";
		choice = enterInt();

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

		case 6: {
			return false;
		}
		default: cout << "Try again! " << endl;
		}
	} while (true);

	return true;
}

bool getAllUserMenu(nanodbc::connection conn, USER& user)
{
	int choice;

	do {
		system("cls");

		displayGetAllUserMenu();

		cout << "Enter an option from the menu: ";
		choice = enterInt();

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

			displayGetAllWorkLogsFormTasksMenu();
			cout << "Enter an option from the menu: ";
			choice = enterInt();
			cout << endl;

			switch (choice)
			{
			case 1: {
				system("cls");
				getAllTasks(conn);
				break;
			}

			case 2: {
				system("cls");
				getAllWorkLogs(conn);
				break;
			}

			case 3: {
				system("cls");
				getAllUserMenu(conn, user);
				break;
			}

			default: cout << "Try again! " << endl;
			}

			break;
		}

		case 5: {
			return false;
		}
		default: cout << "Try again! " << endl;
		}
	} while (true);
	return true;
}

bool insertAllMenu(nanodbc::connection conn, USER& user)
{
	int choice;

	do {
		displayInsertAllMenu();

		cout << "Enter an option from the menu: ";
		choice = enterInt();
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

		case 6: {
			return false;
		}
		default: cout << "Try again! " << endl;
		}
	} while (true);

	return true;
}

bool insertAllUserMenu(nanodbc::connection conn, USER& user)
{
	int choice;

	do {
		displayInsertAllUserMenu();

		cout << "Enter an option from the menu: ";
		choice = enterInt();
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

			displayInsertLogsInTaskMenu();
			cout << "Enter an option from the menu: ";
			cin >> choice;
			cout << endl;

			switch (choice)
			{
			case 1: {
				system("cls");
				insertTask(conn);
				break;
			}

			case 2: {
				system("cls");
				insertWorkLog(conn);
				break;
			}

			case 3: {
				system("cls");
				insertAllUserMenu(conn, user);
				break;
			}

			default: cout << "Try again! " << endl;
			}

			break;
		}

		case 3: {
			return false;
		}
		default: cout << "Try again! " << endl;
		}
	} while (true);

	return true;
}

bool updateAllMenu(nanodbc::connection conn, USER& user)
{
	int choice;
	int id;

	do {
		displayUpdateAllMenu();

		cout << "Enter an option from the menu: ";
		choice = enterInt();

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

		case 6: {
			return false;
		}
		default: cout << "Try again! " << endl;
		}
	} while (true);

	return true;
}

bool updateAllUserMenu(nanodbc::connection conn, USER& user)
{
	int choice;
	int id;

	do {
		displayUpdateAllUserMenu();

		cout << "Enter an option from the menu: ";
		choice = enterInt();

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
			do {
				displayUpdateLogsInTaskMenu();
				cout << "Enter an option from the menu: ";
				choice = enterInt();
				cout << endl;

				switch (choice)
				{
				case 1: {
					cout << "Enter the task's id that you want to change: ";
					id = enterInt();
					cout << endl;

					TASK task = getTaskById(conn, id);
					if (user.id == task.idOfCreator)
					{

						updateTask(conn, id);
					}
					else
					{
						cout << "Sorry, you can't change a task that you didn't create :(" << endl;
					}
					break;
				}

				case 2: {
					cout << "Enter the work log's id that you want to change: ";
					id = enterInt();
					cout << endl;

					updateWorkLog(conn, id);
					break;
				}

				case 3: {
					return false;
				}
				default: cout << "Try again! " << endl;
				}
			} while (true);

		}

		case 3: {
			return false;
		}
		default: cout << "Try again! " << endl;
		}
	} while (true);

	return true;
}

bool deleteAllMenu(nanodbc::connection conn, USER& user)
{
	nanodbc::statement statement(conn);
	int choice;
	int id;

	do {
		displayDeleteAllMenu();

		cout << "Enter an option from the menu: ";
		choice = enterInt();

		switch (choice)
		{
		case 1: {
			system("cls");
			cout << "Enter the user's id that you want to delete: ";
			id = enterInt();
			cout << endl;
			USER::deleteUserById(conn, id);
			break;
		}

		case 2: {
			system("cls");
			cout << "Enter the team's id that you want to delete: ";
			id = enterInt();
			cout << endl;
			TEAM::deleteTeamById(conn, id);
			break;
		}

		case 3: {
			system("cls");
			cout << "Enter the project's id that you want to delete: ";
			id = enterInt();
			cout << endl;
			PROJECT::deleteProjectById(conn, id);
			break;
		}

		case 4: {
			system("cls");
			cout << "Enter the task's id that you want to delete: ";
			id = enterInt();
			cout << endl;
			TASK::deleteTaskById(conn, id);
			break;
		}

		case 5: {
			system("cls");
			cout << "Enter the work log's id that you want to delete: ";
			id = enterInt();
			cout << endl;
			WORKLOG::deleteWorkLogById(conn, id);
			break;
		}

		case 6: {
			return false;
		}
		default: cout << "Try again! " << endl;
		}
	} while (true);

	return true;
}

bool deleteAllUserMenu(nanodbc::connection conn, USER& user)
{
	nanodbc::statement statement(conn);
	int choice;
	int id;

	do {
		displayDeleteAllUserMenu();

		cout << "Enter an option from the menu: ";
		choice = enterInt();

		switch (choice)
		{
		case 1: {
			system("cls");
			cout << "Enter the project's id that you want to delete: ";
			id = enterInt();
			cout << endl;
			PROJECT project = getProjectById(conn, id);

			if (user.id == project.idOfCreator)
			{

				PROJECT::deleteProjectById(conn, id);
			}
			else
			{
				cout << "Sorry, you can't delete a project that you didn't create :(" << endl;
			}

			break;
		}

		case 2: {
			system("cls");

			do {
				displayDeleteLogsInTaskMenu();
				cout << "Enter an option from the menu: ";
				cin >> choice;
				cout << endl;

				switch (choice)
				{
				case 1: {
					cout << "Enter the task's id that you want to delete: ";
					id = enterInt();
					cout << endl;

					TASK task = getTaskById(conn, id);
					if (user.id == task.idOfCreator)
					{

						TASK::deleteTaskById(conn, id);
					}
					else
					{
						cout << "Sorry, you can't delete a task that you didn't create :(" << endl;
					}
					break;
				}

				case 2: {
					cout << "Enter the work log's id that you want to delete: ";
					id = enterInt();
					cout << endl;

					WORKLOG::deleteWorkLogById(conn, id);
					break;
				}

				case 3: {
					return false;
				}

				default: cout << "Try again! " << endl;
				}
			} while (true);

			break;
		}

		case 3: {
			return false;
		}

		default: cout << "Try again! " << endl;
		}
	} while (true);

	return true;
}

//main menus
bool adminMenu(nanodbc::connection conn, USER& user)
{
	int choice;

	do {
		system("cls");
		displayMessage();
		displayMenu();

		cout << "Enter an option from the menu: ";
		choice = enterInt();

		switch (choice)
		{
		case 1: {
			system("cls");
			getAllMenu(conn, user);
			//adminMenu(conn, user);
			break;
		}

		case 2: {
			system("cls");
			insertAllMenu(conn, user);
			//adminMenu(conn, user);
			break;
		}

		case 3: {
			system("cls");
			updateAllMenu(conn, user);
			//adminMenu(conn, user);
			break;
		}

		case 4: {
			system("cls");
			deleteAllMenu(conn, user);
			//adminMenu(conn, user);
			break;
		}

		case 5: goodbyemessage();  return false;

		default: cout << "Try again! " << endl;
		}
	} while (true);

	return true;
}

bool userMenu(nanodbc::connection conn, USER& user)
{
	int choice;

	do {
		system("cls");
		displayMenu();

		cout << "Enter an option from the menu: ";
		choice = enterInt();
		system("cls");

		switch (choice)
		{
		case 1: {
			getAllUserMenu(conn, user);
			break;
		}

		case 2: {
			insertAllUserMenu(conn, user);
			break;
		}

		case 3: {
			updateAllUserMenu(conn, user);
			break;
		}

		case 4: {
			deleteAllUserMenu(conn, user);
			break;
		}

		case 5: {
			goodbyemessage();
			return false;
		};

		default: cout << "Try again! " << endl;
		}
	} while (true);

	return true;
}