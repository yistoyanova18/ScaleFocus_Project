#pragma once
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
void insertTeam(nanodbc::connection conn);
void insertProject(nanodbc::connection conn);
void insertTask(nanodbc::connection conn);
void insertWorkLog(nanodbc::connection conn);
void updateUser(nanodbc::connection conn, const int& id);
void updateTeam(nanodbc::connection conn, const int& id);//ne e testvano
void updateProject(nanodbc::connection conn, const int& id);//ne e testvano
void updateTask(nanodbc::connection conn, const int& id);//ne e testvano
void updateWorkLog(nanodbc::connection conn, const int& id);//ne e testvano
USER login(nanodbc::connection conn, string username, string pass);
void displayMenu();
void displayGetAllMenu();
bool getAllMenu(nanodbc::connection conn);
bool adminMenu(nanodbc::connection conn);
bool userMenu(nanodbc::connection conn);

//void getBackToMenu(nanodbc::connection conn)
//{
//	int choice;
//	cout << "Type '0' to return back to the menu\n";
//enter:
//	cin >> choice;
//
//	if (choice == 0)
//	{
//		system("cls");
//	}
//	else
//	{
//		cout << "Invalid entered value! Plase enter again: ";
//		goto enter;
//	}
//}
