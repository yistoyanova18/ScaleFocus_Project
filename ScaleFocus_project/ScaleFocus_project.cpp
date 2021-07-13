#include <iostream>
#include <string>
#include <nanodbc.h>
#include <exception>
#include <vector>
#include "Structures.h"
#include "Functions.h"

using namespace std;

//bool deleteUserById(nanodbc::connection conn, const int& id)
//{
//	nanodbc::statement statement(conn);
//	nanodbc::prepare(statement, NANODBC_TEXT(R"(
//        DELETE 
//            FROM ScaleFocus_Project.dbo.[User]
//            WHERE Id = ?
//    )"));
//
//	statement.bind(0, &id);
//
//	auto result = execute(statement);
//
//	return result.affected_rows() != 0;
//
//}

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

void loginMenu(nanodbc::connection conn, USER& user)
{
	string username, pass;
enter:
	cout << "Enter your username and password please" << endl;
	cout << "Username: ";
	getline(cin, username);
	cout << "Password: ";
	getline(cin, pass);

	/*username = "admin";
	pass = "adminpass";*/

	user = login(conn, username, pass);

	if (user.id > 0)
	{

		if (username == "admin" and pass == "adminpass")
		{
			adminMenu(conn);
		}
		else
		{
			userMenu(conn);
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

void getBackToMenu(nanodbc::connection conn)
{
	int choice;
	cout << endl;
	cout << "Type '0' to return back to the menu\n";
	cin >> choice;

	if (choice == 0)
	{
		system("cls");
	}
	else
	{
		cout << "Invalid entered value!" << endl;
		getBackToMenu(conn);
	}
}

int main()
{
	try
	{
		nanodbc::string connstr = NANODBC_TEXT("DRIVER={ODBC Driver 17 for SQL Server};Server=UNIVERSE\\SQLEXPRESS;DATABASE=ScaleFocus_Project;Trusted_Connection=yes;"); // an ODBC connection string to your database

		nanodbc::connection conn(connstr);

		bool queryResult = false;
		int id;
		USER currentUser{};

		loginMenu(conn, currentUser);

		return EXIT_SUCCESS;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
}
