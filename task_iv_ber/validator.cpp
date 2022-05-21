#include "pch.h"
#include "validator.h"

#include <fstream>

ValidationResult validate(int argc, char *argv[])
{
    if (argc != 3)
    {
        return { false, "Invalid arguments number, two arguments expected!\nTry enter the paths of the two files to compare: <file_path_1> <file_path_2>" };
    }

    std::string filepath_1(argv[1]);
    std::string filepath_2(argv[2]);

    if (filepath_1.compare(filepath_2) == 0)
    {
        return { false, "You cannot compare the file `" + filepath_1 + "` with itself!\n" };
    }

    std::ifstream file_1(filepath_1);
    if (!file_1)
    {
        file_1.close();
        return { false, "The file does not exist: `" + filepath_1 + "`\n" };
    }

    std::ifstream file_2(filepath_2);
    if (!file_2)
    {
        file_2.close();
        return { false, "The file does not exist: `" + filepath_2 + "`\n" };
    }

    return { true, "" };
}