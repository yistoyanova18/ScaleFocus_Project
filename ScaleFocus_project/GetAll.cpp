#include <iostream>
#include <string>
#include <nanodbc.h>
#include <exception>
#include <vector>
#include "Structures.h"
#include "Functions.h"

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

	getBackToMenu(conn);
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

	getBackToMenu(conn);
}

vector<PROJECT> getProject(nanodbc::connection conn)
{
	vector<PROJECT> projects;

	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"( 
        SELECT *
            FROM ScaleFocus_Project.dbo.[Project]
    )"));

	auto result = execute(statement);

	while (result.next())
	{
		PROJECT project;
		project.id = result.get<int>("Id");
		project.title = result.get<nanodbc::string>("Title", "");
		project.description = result.get<nanodbc::string>("Description", "");
		project.dateOfCreation = result.get<nanodbc::string>("DateOfCreation");
		project.idOfCreator = result.get<int>("IdCreator", 0);
		project.dateOfLastChange = result.get<nanodbc::string>("DateLastChange");
		project.idLastChange = result.get<int>("IdLastChange", 0);

		projects.push_back(project);
	}

	return projects;
}

void getAllProjects(nanodbc::connection conn)
{
	vector<PROJECT> projects = getProject(conn);

	for (size_t i = 0; i < projects.size(); i++)
	{
		projects[i].displayProject();
		cout << endl;
	}

	getBackToMenu(conn);
}

vector<TASK> getTask(nanodbc::connection conn)
{
	vector<TASK> tasks;

	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"( 
        SELECT *
            FROM ScaleFocus_Project.dbo.[Task]
    )"));

	auto result = execute(statement);

	while (result.next())
	{
		TASK task;
		task.id = result.get<int>("Id");
		task.idOfProject = result.get<int>("IdOfProject");
		task.idOfAssignee = result.get<int>("IdOfAssignee");
		task.title = result.get<nanodbc::string>("Title", "");
		task.description = result.get<nanodbc::string>("Description", "");
		task.taskStatus = result.get<nanodbc::string>("TaskStatus", "");
		task.dateOfCreation = result.get<nanodbc::string>("DateOfCreation");
		task.idOfCreator = result.get<int>("IdOfCreator", 0);
		task.dateOfLastChange = result.get<nanodbc::string>("DateLastChange");
		task.idLastChange = result.get<int>("IdLastChange", 0);

		tasks.push_back(task);
	}

	return tasks;
}

void getAllTasks(nanodbc::connection conn)
{
	vector<TASK> tasks = getTask(conn);

	for (size_t i = 0; i < tasks.size(); i++)
	{
		tasks[i].displayTask();
		cout << endl;
	}

	getBackToMenu(conn);
}

vector<WORKLOG> getWorkLog(nanodbc::connection conn)
{
	vector<WORKLOG> workLogs;

	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"( 
        SELECT *
            FROM ScaleFocus_Project.dbo.[WorkLog]
    )"));

	auto result = execute(statement);

	while (result.next())
	{
		WORKLOG workLog;
		workLog.id = result.get<int>("Id");
		workLog.idOfTask = result.get<int>("IdTask");
		workLog.idOfUser = result.get<int>("IdUser");
		workLog.date = result.get<nanodbc::string>("Date", "");
		workLog.time = result.get<nanodbc::string>("Time", "");

		workLogs.push_back(workLog);
	}

	return workLogs;
}

void getAllWorkLogs(nanodbc::connection conn)
{
	vector<WORKLOG> workLogs = getWorkLog(conn);

	for (size_t i = 0; i < workLogs.size(); i++)
	{
		workLogs[i].displayWorkLog();
		cout << endl;
	}

	getBackToMenu(conn);
}