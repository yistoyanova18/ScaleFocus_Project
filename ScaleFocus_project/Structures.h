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
	string dateOfCreation;
	int idOfCreator = 0;
	string dateOfLastChange;
	int idLastChange = 0;
	bool isAdmin;

	void displayUser()
	{
		cout << "User id: " << this->id << endl;
		cout << "Username: " << this->username << endl;
		cout << "Password: " << this->password << endl;
		cout << "First name: " << this->firstName << endl;
		cout << "Last name: " << this->lastName << endl;
		cout << "Date of creation: " << this->dateOfCreation << endl;
		cout << "Id of creator: " << this->idOfCreator << endl;
		cout << "Date of last change: " << this->dateOfLastChange << endl;
		cout << "Id of last change: " << this->idLastChange << endl;
		cout << "Admin: " << this->isAdmin << endl << endl;
	}
};

struct TEAM
{
	int id = 0;
	string title = "";
	string dateOfCreation;
	int idOfCreator = 0;
	string dateOfLastChange;
	int idLastChange = 0;

	void displayTeam()
	{
		cout << "Team id: " << this->id << endl;
		cout << "Title: " << this->title << endl;
		cout << "Date of creation: " << this->dateOfCreation << endl;
		cout << "Id of creator: " << this->idOfCreator << endl;
		cout << "Date of last change: " << this->dateOfLastChange << endl;
		cout << "Id of last change: " << this->idLastChange << endl;
	}
};

struct PROJECT
{
	int id = 0;
	string title = "";
	string description = "";
	string dateOfCreation;
	int idOfCreator = 0;
	string dateOfLastChange;
	int idLastChange = 0;

	void displayProject()
	{
		cout << "Team id: " << this->id << endl;
		cout << "Title: " << this->title << endl;
		cout << "Description: " << this->description << endl;
		cout << "Date of creation: " << this->dateOfCreation << endl;
		cout << "Id of creator: " << this->idOfCreator << endl;
		cout << "Date of last change: " << this->dateOfLastChange << endl;
		cout << "Id of last change: " << this->idLastChange << endl;
	}
};

struct TASK
{
	int id = 0;
	int idOfProject = 0;
	int idOfAssignee = 0;
	string title = "";
	string description = "";
	string taskStatus;
	string dateOfCreation;
	int idOfCreator = 0;
	string dateOfLastChange;
	int idLastChange = 0;

	void displayTask()
	{
		cout << "Task id: " << this->id << endl;
		cout << "Project id: " << this->idOfProject << endl;
		cout << "Assignee id: " << this->idOfAssignee << endl;
		cout << "Title: " << this->title << endl;
		cout << "Description: " << this->description << endl;
		cout << "Date of creation: " << this->dateOfCreation << endl;
		cout << "Id of creator: " << this->idOfCreator << endl;
		cout << "Date of last change: " << this->dateOfLastChange << endl;
		cout << "Id of last change: " << this->idLastChange << endl;
	}
};

struct WORKLOG
{
	int id = 0;
	int idOfTask = 0;
	int idOfUser = 0;
	string time;
	string date;

	void displayWorkLog()
	{
		cout << "Worklog id: " << this->id << endl;
		cout << "Task id: " << this->idOfTask << endl;
		cout << "User id: " << this->idOfUser << endl;
		cout << "Time: " << this->time << endl;
		cout << "Date: " << this->date << endl;
	}
};
