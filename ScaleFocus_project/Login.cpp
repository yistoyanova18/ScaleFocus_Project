#include <iostream>
#include <string>
#include <nanodbc.h>
#include <exception>
#include <vector>
#include "Structures.h"
#include "Functions.h"

using namespace std;

void loginMenu(nanodbc::connection conn, USER& user)
{
	string username, pass;
	cout << u8"		       ╭─━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━─╮" << endl;
	cout << u8"                                            ᴸᴼᴳᴵᴺ" << endl;
	cout << "                                      Username: ";
	username = enterText();
	cout << "                                      Password: ";
	pass = enterText();
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
			if (!userMenu(conn, user)) {
				return;
			}
		}
	}
	else
	{
		cout << endl;
		cout << "Incorrect username or password! Try again!" << endl;
		cout << endl;
		loginMenu(conn, user);
	}
}

string enterText()
{
	string text;
	//getline(cin, text);
	cin >> text;
	return text;
}

int enterInt()
{
	string num;
	//getline(cin, num);
	cin >> num;
	return stoi(num);
}

void getBackToMenu(nanodbc::connection conn)
{
	int choice;
	cout << endl;

	do {
		cout << "Type '0' to return back to the menu\n";
		choice = enterInt();

		if (choice == 0)
		{
			system("cls");
			break;
		}
		else
		{
			cout << "Invalid entered value!" << endl;
		}
	} while (true);
}