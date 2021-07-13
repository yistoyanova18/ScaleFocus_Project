#pragma once
#include <iostream>
#include <string>
#include <nanodbc.h>
#include <exception>
#include <vector>
#include "Structures.h"

using namespace std;

//list all
void getAllUsers(nanodbc::connection conn);
void getAllTeams(nanodbc::connection conn);
void getAllProjects(nanodbc::connection conn);
void getAllTasks(nanodbc::connection conn);
void getAllWorkLogs(nanodbc::connection conn);

//insert all
void insertUser(nanodbc::connection conn);
void insertTeam(nanodbc::connection conn);
void insertProject(nanodbc::connection conn);
void insertTask(nanodbc::connection conn);
void insertWorkLog(nanodbc::connection conn);

//update all
void updateUser(nanodbc::connection conn, const int& id);
void updateTeam(nanodbc::connection conn, const int& id);
void updateProject(nanodbc::connection conn, const int& id);
void updateTask(nanodbc::connection conn, const int& id);
void updateWorkLog(nanodbc::connection conn, const int& id);

USER login(nanodbc::connection conn, string username, string pass);
//display
void displayMenu();
void displayGetAllMenu();
void displayInsertAllMenu();
void displayInsertAllUserMenu();
void displayUpdateAllMenu();
void displayUpdateAllUserMenu();
//function menus
bool getAllMenu(nanodbc::connection conn);
bool insertAllMenu(nanodbc::connection conn);
bool insertAllUserMenu(nanodbc::connection conn);
bool updateAllMenu(nanodbc::connection conn);
bool updateAllUserMenu(nanodbc::connection conn);
void deleteAllMenu(nanodbc::connection con);
//main menus
bool adminMenu(nanodbc::connection conn);
bool userMenu(nanodbc::connection conn);

void getBackToMenu(nanodbc::connection conn);

