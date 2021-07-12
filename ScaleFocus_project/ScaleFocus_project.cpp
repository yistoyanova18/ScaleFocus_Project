#include <iostream>
#include <string>
#include <nanodbc.h>
#include <exception>
#include <vector>
#include "Structures.h"
#include "Functions.h"

using namespace std;

//bool deleteUserById(nanodbc::connection conn, const int& id)
//{
//	nanodbc::statement statement(conn);
//	nanodbc::prepare(statement, NANODBC_TEXT(R"(
//        DELETE 
//            FROM ScaleFocus_Project.dbo.[User]
//            WHERE Id = ?
//    )"));
//
//	statement.bind(0, &id);
//
//	auto result = execute(statement);
//
//	return result.affected_rows() != 0;
//
//}

string enterText()
{
	string text;
	//getline(cin, text);
	cin >> text;
	return text;
}

int enterInt()
{
	string num;
	//getline(cin, num);
	cin >> num;
	return stoi(num);
}

void loginMenu(nanodbc::connection conn, USER& user)
{
	string username, pass;

	cout << "Enter your username and password please" << endl;
	cout << "Username: ";
	getline(cin, username);
	cout << "Password: ";
	getline(cin, pass);

	user = login(conn, username, pass);

	if (user.id > 0)
	{

		if (username == "admin" and pass == "adminpass")
		{
			cout << adminMenu(conn);
		}
		else
		{
			cout << "enter user menu";
		}
	}
	else
	{
		cout << endl;
		cout << "Incorrect username or password! Try again!" << endl;
	}
}

int main()
{
	try
	{
		nanodbc::string connstr = NANODBC_TEXT("DRIVER={ODBC Driver 17 for SQL Server};Server=UNIVERSE\\SQLEXPRESS;DATABASE=ScaleFocus_Project;Trusted_Connection=yes;"); // an ODBC connection string to your database

		nanodbc::connection conn(connstr);

		bool queryResult = false;
		int id;
		USER currentUser{};

		loginMenu(conn, currentUser);

		/*cout << "Enter the id of the user you want to delete: ";
		id = enterInt();
		queryResult = deleteUserById(conn, id);

		if (queryResult)
		{
			cout << endl << "The lake with id " << id << " was deleted successfully!" << endl;
		}
		else {
			cout << endl << "The lake with id " << id << " was not found!" << endl;
		}*/

		//getAllUsers(conn);
		//getAllTeams(conn);
		//getAllProjects(conn);
		//getAllTasks(conn);
		//getAllWorkLogs(conn);
		//insertUser(conn);
		//insertTeam(conn);
		//insertProject(conn);
		//insertTask(conn);
		//insertWorkLog(conn);

		/*cout << "Enter the user's id that you want to change: ";
		id = enterInt();
		updateUser(conn, id);*/

		return EXIT_SUCCESS;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
}
