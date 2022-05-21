#include "pch.h"

#include <fstream>
#include <sstream>

#include "berCalculator.h"
#include "logger.h"

BerResult calculate(std::string filePath1, std::string filePath2)
{
    std::fstream f1, f2; // handlers to files
    BerResult result = {0, 0, 0, 0, 0};

    saveLog("Calculating BER...");

    f1.open(filePath1.c_str(), std::ios::binary | std::ios::in);
    f2.open(filePath2.c_str(), std::ios::binary | std::ios::in);
    char a = 0x00,
         b = 0x00;
    result.startTime = clock();

    while (!f1.eof())
    {
        f1 >> a;       // read 1 char from file 1
        f2 >> b;       // read 1 char from file 2
        if (!f1.eof()) // till the end of the 1st file
        {
            result.errorBits += getHammingDistance(a, b); // add to the [errorBits] the number of different bits
            result.totalBits += 8;                        // add to the [totalBits] the number of compared bits
        }
    }

    result.ber = (float)(result.errorBits / result.totalBits); // calculate ber
    result.stopTime = clock();
    saveLog("BER calculation is done");
    return result;
}

// uint8_t getHammingDistance(uint8_t n1, uint8_t n2)
// {
//     uint8_t dist = 0;
//     // The ^ operators sets to 1 only the bits that are different
//     for (uint8_t val = n1 ^ n2; val > 0; ++dist)
//     {
//         // We then count the bit set to 1 using the Peter Wegner way
//         val = val & (val - 1); // Set to zero val's lowest-order 1
//     }

//     // Return the number of differing bits
//     return dist;
// }

uint8_t getHammingDistance(uint8_t n1, uint8_t n2)
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

void printResult(BerResult result)
{
    std::string leftPadding = std::string(23, ' ');
    std::stringstream message;
    message << "BER results: " << std::endl;
    message << leftPadding << "BER: " << result.ber << std::endl;
    message << leftPadding << "TotalBits: " << result.totalBits << std::endl;
    message << leftPadding << "ErrorBits: " << result.errorBits << std::endl;
    message << leftPadding << "Calculation time: " << ((double)result.stopTime - result.startTime) / CLOCKS_PER_SEC << "s" << std::endl;

    saveLog(message.str());
}
