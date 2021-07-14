#include <iostream>
#include <string>
#include <nanodbc.h>
#include <exception>
#include <vector>
#include <conio.h>
#include "Structures.h"
#include "Functions.h"

using namespace std;

void loginMenu(nanodbc::connection conn, USER& user)
{
	string username, pass;
	char ch;

	cout << u8"		       ╭─━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━─╮" << endl;
	cout << u8"                                            ᴸᴼᴳᴵᴺ" << endl;
	cout << "                                      Username: ";
	username = enterText();
	cout << "                                      Password: ";

	ch = _getch();

	//Displays the user passowrd with * 
	while (ch != 13) 
	{
		if (ch == 8) 
		{
			if (pass.length() > 0)
			{
				cout << "\b \b";
				pass.pop_back();
			}
		}
		else 
		{
			cout << '*';
			pass += ch;
		}

		ch = _getch();
	}

	cout << endl;
	cout << u8"		       ╰─━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━─╯" << endl;


	user = login(conn, username, pass);

	if (user.id > 0)
	{

		if (username == "admin" and pass == "adminpass")
		{
			adminMenu(conn, user);
		}
		else
		{
			if (!userMenu(conn, user)) 
			{
				return;
			}
		}
	}
	else
	{
		system("cls");
		cout << endl;
		cout << RED << "                          Incorrect username or password! Try again!" << RESET << endl;
		cout << endl;
		loginMenu(conn, user);
	}
}

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

void getBackToMenu(nanodbc::connection conn)
{
	int choice;
	cout << endl;

	do {
		cout << u8"        ҉ Type '0' to return back to the menu: ";
		choice = enterInt();
		cout << endl;

		if (choice == 0)
		{
			system("cls");
			break;
		}
		else
		{
			cout << RED << "                 Invalid entered value!" << RESET << endl;
			cout << endl;
		}
	} while (true);
}