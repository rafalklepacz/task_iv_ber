#pragma once
#include "pch.h"

enum MenuItem
{
    Unknown = 0,
    Test1 = 1,
    Test2 = 2,
    Test3 = 3,
    Exit = 4
};

void printStartupInfo(int argc, char *argv[]);
void printMenu();
MenuItem getUserMenuItem();