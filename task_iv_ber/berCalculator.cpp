#include "pch.h"

uint8_t getHammingDistance(uint8_t n1, uint8_t n2)
{
    uint8_t dist = 0;
    // The ^ operators sets to 1 only the bits that are different
    for (uint8_t val = n1 ^ n2; val > 0; ++dist)
    {
        // We then count the bit set to 1 using the Peter Wegner way
        val = val & (val - 1); // Set to zero val's lowest-order 1
    }

    // Return the number of differing bits
    return dist;
}

// uint8_t getHammingDistance(uint8_t n1, uint8_t n2)
// {
//     uint8_t x = n1 ^ n2; // XOR
//     uint8_t setBits = 0;
//     while (x > 0)
//     {
//         setBits += x & 1;
//         x >>= 1;
//     }
//     return setBits;
// }
