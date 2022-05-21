#pragma once
#include "pch.h"

struct ValidationResult
{
    bool isValid;
    std::string error;
};

ValidationResult validate(int argc, char *argv[]);
