#pragma once
#include "pch.h"

const std::string TEST1_FILE1_NAME = "test1_file1.bin";
const std::string TEST1_FILE2_NAME = "test1_file2.bin";

const std::string TEST2_FILE1_NAME = "test2_file1.bin";
const std::string TEST2_FILE2_NAME = "test2_file2.bin";

const std::string TEST3_FILE1_NAME = "test3_file1.bin";
const std::string TEST3_FILE2_NAME = "test3_file2.bin";

struct Files
{
    std::string file1;
    std::string file2;
};

Files createFilesTest1();
Files createFilesTest2();
Files createFilesTest3();
void createFile(const std::string name, const int count, const char value);
