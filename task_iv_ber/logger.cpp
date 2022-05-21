#include "pch.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>

#include "logger.h"

std::fstream logFile; // handler for log file

void openLog(std::string fileName)
{
    logFile.open(fileName.c_str(), std::ios_base::app);
    if (!logFile.good())
    {
        std::cout << "Cannot open log file: " << fileName.c_str() << std::endl;
    }
    std::stringstream msg;
    msg << std::string(10, '=') << " Log file opened " << std::string(10, '=') << std::endl;
    saveLog(msg.str());
}

void closeLog(void)
{
    std::stringstream msg;
    msg << std::string(10, '=') << " Log file closed " << std::string(10, '=') << std::endl;
    saveLog(msg.str());
    logFile.close();
}

void saveLog(std::string msg)
{
    time_t now = time(nullptr);

    std::stringstream logLine;
    logLine << std::endl << std::put_time(localtime(&now), "[%H:%M:%S %d-%m-%Y]: ") << msg;

    logFile << logLine.str();
    logFile.flush();

    std::cout << logLine.str();
    std::cout.flush();
}
