#include "pch.h"

#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

#include "menu.h"
#include "logger.h"

void printStartupInfo(int argc, char* argv[])
{
	std::stringstream msg;
	msg << std::endl << std::string(15, '-') << std::endl;
	msg << "BER Calc v1.0" << std::endl;
	msg << "argc = " << argc << std::endl;

	int iter = 0;
	for (iter = 0; iter < argc; iter++)
	{
		msg << "argv[" << iter << "] = " << argv[iter] << std::endl;
	}
	msg << std::string(15, '-') << std::endl;
	saveLog(msg.str());
}

void printMenu()
{
	std::stringstream msg;
	msg << std::endl << std::string(15, '-') << std::endl;
	msg << " Main menu" << std::endl;
	msg << std::string(15, '-') << std::endl;
	msg << "[1] Prepare two identical files containing the binary value of 0x55. Each file is 100B." << std::endl;
	msg << "[2] Prepare two files, 100B each. The first contains the binary value of 0x55, second file differs from the first by any 10b." << std::endl;
	msg << "[3] Prepare two files, 400MB each. The first contains the binary value of 0x55, second file contains the binary value of 0x50." << std::endl;
	msg << std::string(15, '-') << std::endl;
	msg << "[4] EXIT" << std::endl;
	msg << std::string(15, '-') << std::endl;
	msg << "Type a option number and press ENTER: ";

	saveLog(msg.str());
}

MenuItem getUserMenuItem()
{
	MenuItem item = Unknown;
	int input = 0;
	while (item == Unknown)
	{
		printMenu();

		std::cin >> input;

		if (input <= 0 || input > 4)
		{
			std::cout << std::endl << "!!! Unknown choice. Try again !!!" << std::endl;

			std::cin.clear();
			std::cin.ignore();
			std::cin.sync();

			std::cout << std::endl << "Press ENTER key to continue... ";
			getchar();

			continue;
		}

		item = (MenuItem)input;
	}
	return item;
}
