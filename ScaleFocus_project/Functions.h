#pragma once
#include <iostream>
#include <string>
#include <nanodbc.h>
#include <exception>
#include <vector>
#include "Structures.h"

using namespace std;

//colors
#define RESET   "\033[0m"
#define RED     "\033[1;91m" 
#define GREEN   "\033[1;92m" 
#define YELLOW  "\033[1;93m"  
#define BLUE    "\033[1;96m"
#define PURPLE  "\033[1;95m"
#define WHITE   "\[\033[0;37m\]"
#define CYAN    "\[\033[0;36m\]"

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
bool getAllMenu(nanodbc::connection conn, USER& user);
bool insertAllMenu(nanodbc::connection conn, USER& user);
bool insertAllUserMenu(nanodbc::connection conn, USER& user);
bool updateAllMenu(nanodbc::connection conn, USER& user);
bool updateAllUserMenu(nanodbc::connection conn, USER& user);
bool deleteAllMenu(nanodbc::connection conn, USER& user);

//main menus
bool adminMenu(nanodbc::connection conn, USER& user);
bool userMenu(nanodbc::connection conn, USER& user);

//login
void loginMenu(nanodbc::connection conn, USER& user);

void getBackToMenu(nanodbc::connection conn);
string enterText();
int enterInt();

PROJECT getProjectById(nanodbc::connection conn, int id);
TASK getTaskById(nanodbc::connection conn, int id);
WORKLOG getWorkLogById(nanodbc::connection conn, int id);