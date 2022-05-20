#include "pch.h"

#include <fstream>
#include <string>

void createFile(const std::string name, const int count, const char value)
{
    std::fstream f;
    f.open(name.c_str(), std::ios::binary | std::ios::out);
    for (int i = 0; i < count; i++)
    {
        f.write((char *)&value, 1);
    }
    f.close();
}
