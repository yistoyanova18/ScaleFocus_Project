#include <iostream>
#include <string>
#include <nanodbc.h>
#include <exception>
#include <vector>
#include "Structures.h"

using namespace std;



int main()
{
	try
	{
		nanodbc::string connstr = NANODBC_TEXT("DRIVER={ODBC Driver 17 for SQL Server};SERVER=UNIVERSE\\SQLEXPESS;DATABASE=ScaleFocus_Project;Trusted_Connection=yes;"); // an ODBC connection string to your database

		nanodbc::connection conn(connstr);

		/*do
		{
			runProgram(conn);
		} while (runProgram(conn));*/

		return EXIT_SUCCESS;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
}
