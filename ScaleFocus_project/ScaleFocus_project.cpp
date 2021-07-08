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

int main()
{
	try
	{
		nanodbc::string connstr = NANODBC_TEXT("DRIVER={ODBC Driver 17 for SQL Server};Server=UNIVERSE\\SQLEXPRESS;DATABASE=ScaleFocus_Project;Trusted_Connection=yes;"); // an ODBC connection string to your database

		nanodbc::connection conn(connstr);

		//getAllUsers(conn);
		//getAllTeams(conn);
		//getAllProjects(conn);
		//getAllTasks(conn);
		//getAllWorkLogs(conn);

		return EXIT_SUCCESS;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
}
