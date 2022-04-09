#include <iostream>
#include <fstream>
#include <string>

#include "pch.h"

int main(int argc, char *argv[])
{
    std::cout << "BER Calc v1.0" << std::endl;
    std::cout << "argc = " << argc << std::endl;
    int iter = 0;
    for (iter = 0; iter < argc; iter++)
    {
        std::cout << "argv[" << iter << "] = " << argv[iter] << std::endl;
    }

    if (argc != 3)
    {
        std::cerr << "Invalid arguments number, two arguments expected!!!" << std::endl;
        std::cerr << "Try enter the paths of the two files to compare: <file_path_1> <file_path_2>" << std::endl;
        return -1;
    }
    
    std::string firstFilePath(argv[1]);
    std::ifstream firstFileStream(firstFilePath);
    if (!firstFileStream)
    {
        std::cerr << "The file does not exist: " << firstFilePath << std::endl;
        firstFileStream.close();
        return -1;
    }

    std::string secondFilePath(argv[2]);
    std::ifstream secondFileStream(secondFilePath);
    if (!secondFileStream)
    {
        std::cerr << "The file does not exist: " << secondFilePath << std::endl;
        secondFileStream.close();
        return -1;
    }

    // TODO: 

    firstFileStream.close();
    secondFileStream.close();

    return 0;
}
