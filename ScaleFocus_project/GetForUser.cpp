#include <iostream>
#include <string>
#include <nanodbc.h>
#include <exception>
#include <vector>
#include "Structures.h"
#include "Functions.h"

using namespace std;

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

TASK getTaskById(nanodbc::connection conn, int id)
{
	nanodbc::statement statement(conn);
	nanodbc::prepare(statement, NANODBC_TEXT(R"( 
        SELECT *
            FROM ScaleFocus_Project.dbo.[Task]
		WHERE Id = ?
    )"));

	statement.bind(0, &id);

	auto result = execute(statement);

	TASK task;

	if (!result.next()); //cout << "There is no such id" << endl;
	else {
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
	}

	return task;
}