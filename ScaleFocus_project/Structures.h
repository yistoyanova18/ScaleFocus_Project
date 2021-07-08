#pragma once
#include <iostream>
#include <string>
#include <nanodbc.h>
#include <exception>

using namespace std;

struct USER 
{
	int id = 0;
	string username = "";
	string password = "";
	string firstName = "";
	string lastName = "";
	nanodbc::timestamp dateOfCreation;
	int idOfCreator = 0;
	nanodbc::timestamp dateOfLastChange;
	int idLastChange = 0;
	bool isAdmin;
};

struct TEAM
{
	int id = 0;
	string Title = "";
	nanodbc::timestamp dateOfCreation;
	int idOfCreator = 0;
	nanodbc::timestamp dateOfLastChange;
	int idLastChange = 0;
};

struct PROJECT
{
	int id = 0;
	string Title = "";
	string Description = "";
	nanodbc::timestamp dateOfCreation;
	int idOfCreator = 0;
	nanodbc::timestamp dateOfLastChange;
	int idLastChange = 0;
};

struct TASK
{
	int id = 0;
	int idOfProject = 0;
	int idOfAssignee = 0;
	string Title = "";
	string Description = "";
	int status = 0;
	nanodbc::timestamp dateOfCreation;
	int idOfCreator = 0;
	nanodbc::timestamp dateOfLastChange;
	int idLastChange = 0;
};

struct WorkLog
{
	int id = 0;
	int idOfTask = 0;
	int idOfUser = 0;
	nanodbc::timestamp time;
	nanodbc::timestamp date;
};
