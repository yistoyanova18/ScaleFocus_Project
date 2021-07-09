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
void insertUser(nanodbc::connection conn);
void updateUser(nanodbc::connection conn, const int& id);
void insertTeam(nanodbc::connection conn);
void insertProject(nanodbc::connection conn);
void insertTask(nanodbc::connection conn);
void insertWorkLog(nanodbc::connection conn);

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

int main()
{
	try
	{
		nanodbc::string connstr = NANODBC_TEXT("DRIVER={ODBC Driver 17 for SQL Server};Server=UNIVERSE\\SQLEXPRESS;DATABASE=ScaleFocus_Project;Trusted_Connection=yes;"); // an ODBC connection string to your database

		nanodbc::connection conn(connstr);

		bool queryResult = false;
		int id;

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
