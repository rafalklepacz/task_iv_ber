#include "pch.h"

#include <fstream>
#include <string>

uint8_t hammingDistance(uint8_t n1, uint8_t n2);
void createFile1(const std::string name, const int count, const char value);

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
        std::cerr << "Invalid arguments number, two arguments expected!" << std::endl;
        std::cerr << "Try enter the paths of the two files to compare: <file_path_1> <file_path_2>" << std::endl;
        return -1;
    }

    std::string filepath_1(argv[1]);
    std::string filepath_2(argv[2]);

    if (filepath_1.compare(filepath_2) == 0)
    {
        std::cerr << "You cannot compare the file `" << filepath_1 << "` with itself!" << std::endl;
        return -1;
    }

    std::ifstream file_1(filepath_1);
    if (!file_1)
    {
        std::cerr << "The file does not exist: " << filepath_1 << std::endl;
        file_1.close();
        return -1;
    }

    std::ifstream file_2(filepath_2);
    if (!file_2)
    {
        std::cerr << "The file does not exist: " << filepath_2 << std::endl;
        file_2.close();
        return -1;
    }

    // TODO:

    std::cout << (int)hammingDistance(0xFF, 0x01) << std::endl;
    createFile1("test1_file1.bin", 100, 0x55);

    file_1.close();
    file_2.close();

    return 0;
}

uint8_t hammingDistance(uint8_t n1, uint8_t n2)
{
    uint8_t x = n1 ^ n2; // XOR
    uint8_t setBits = 0;
    while (x > 0)
    {
        setBits += x & 1;
        x >>= 1;
    }
    return setBits;
}

void createFile1(const std::string name, const int count, const char value)
{
    std::fstream f;
    f.open(name.c_str(), std::ios::binary | std::ios::out);
    for (int i = 0; i < count; i++)
    {
        f.write((char *)&value, 1);
    }
    f.close();
}
