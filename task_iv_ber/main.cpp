#include "pch.h"

#include <fstream>
#include <string>

#include "berCalculator.h"

uint8_t hammingDistance1(uint8_t n1, uint8_t n2);
uint8_t hammingDistance2(uint8_t n1, uint8_t n2);

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

    std::cout << (int)getHammingDistance(0xFF, 0x01) << std::endl;

    file_1.close();
    file_2.close();

    return 0;
}

// https://www.positioniseverything.net/cpp-read-binary-file
// #include <iostream>
// #include <sys/stat.h>
// #include <unistd.h>
// #include <unistd.h>using std::cout; using std::cerr;
// using std::endl; using std::string;int main() {
// string filename(“filename”);
// auto in_file = fopen(filename.c_str(), “rb”);
// if (!in_file) {
// perror(“fopen”);
// exit(EXIT_FAILURE);
// }struct stat sb{};
// if (stat(filename.c_str(), &sb) == -1) {
// perror(“stat”);
// exit(EXIT_FAILURE);
// }
// u_char* file_contents = new u_char[sb.st_size];
// fread(file_contents, sb.st_size, 1, in_file);
// for (int i = 0; i < sb.st_size; ++i) {
// printf(“%02X “, file_contents[i]);
// if (i % 10 == 0 && i != 0){
// cout << ‘n’;
// }
// }

// delete [] file_contents;
// exit(0);
// }