#pragma once
#include "pch.h"

struct BerResult
{
    float ber;
    double errorBits;
    double totalBits;
    clock_t startTime;
    clock_t stopTime;
};

BerResult calculate(std::string filePath1, std::string filePath2);
void printResult(BerResult result);
uint8_t getHammingDistance(uint8_t n1, uint8_t n2);
