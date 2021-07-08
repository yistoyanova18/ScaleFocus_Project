#include <iostream>
#include <string>
#include <nanodbc.h>
#include <exception>
#include <vector>
#include "Structures.h"

using namespace std;

vector<USER> getUser(nanodbc::connection conn)
{
	vector<USER> users;

	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"( 
        SELECT *
            FROM ScaleFocus_Project.dbo.[User]
    )"));

	auto result = execute(statement);

	while (result.next())
	{
		USER user;
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

		users.push_back(user);
	}

	return users;
}

void getAllUsers(nanodbc::connection conn)
{
	vector<USER> users = getUser(conn);

	for (size_t i = 0; i < users.size(); i++)
	{
		users[i].displayUser();
	}
}

vector<TEAM> getTeam(nanodbc::connection conn)
{
	vector<TEAM> teams;

	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"( 
        SELECT *
            FROM ScaleFocus_Project.dbo.[Team]
    )"));

	auto result = execute(statement);

	while (result.next())
	{
		TEAM team;
		team.id = result.get<int>("Id");
		team.title = result.get<nanodbc::string>("Title", "");
		team.dateOfCreation = result.get<nanodbc::string>("DateOfCreation");
		team.idOfCreator = result.get<int>("IdCreator", 0);
		team.dateOfLastChange = result.get<nanodbc::string>("DateLastChange");
		team.idLastChange = result.get<int>("IdLastChange", 0);

		teams.push_back(team);
	}

	return teams;
}

void getAllTeams(nanodbc::connection conn)
{
	vector<TEAM> teams = getTeam(conn);

	for (size_t i = 0; i < teams.size(); i++)
	{
		teams[i].displayTeam();
		cout << endl;
	}
}

int main()
{
	try
	{
		nanodbc::string connstr = NANODBC_TEXT("DRIVER={ODBC Driver 17 for SQL Server};Server=UNIVERSE\\SQLEXPRESS;DATABASE=ScaleFocus_Project;Trusted_Connection=yes;"); // an ODBC connection string to your database

		nanodbc::connection conn(connstr);

		//getAllUsers(conn);
		getAllTeams(conn);

		return EXIT_SUCCESS;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
}
