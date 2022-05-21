#include "pch.h"

#include <fstream>
#include <string>

#include "fileCreator.h"
#include "logger.h"

// Przygotuj dwa identyczne pliki zawierające binarnie zapisaną wartość 0x55.
// Każdy plik po 100 Bajtów.
Files createFilesTest1()
{
    createFile(TEST1_FILE1_NAME, 100, 0x55);
    createFile(TEST1_FILE2_NAME, 100, 0x55);

    return {TEST1_FILE1_NAME, TEST1_FILE2_NAME};
}

// Przygotuj dwa pliki każdy po 100 bajtów.
// Pierwszy zawiera binarnie zapisaną wartość 0x55.
// Drugi plik różni się od pierwszego o dowolne 10 bitów.
Files createFilesTest2()
{
    createFile(TEST2_FILE1_NAME, 100, 0x55);
    createFile(TEST2_FILE2_NAME, 100, 0x55);

    // change first 5 bytes of file from:
    // 0x55 (01010101) to:
    // 0x53 (01010011)
    // diff is 2bx5=10b
    const int size = 5;
    const char buf[size] = { 0x53 };
    std::ofstream f(TEST2_FILE2_NAME, std::ios::binary | std::ios::out | std::ios::in);
    f.write(buf, size);

    return {TEST2_FILE1_NAME, TEST2_FILE2_NAME};
}

// Przygotuj dwa pliki każdy po 400 MB.
// Pierwszy zawiera binarnie zapisaną wartość 0x55.
// Drugi plik zawiera binarnie zapisaną wartość 0x50.
Files createFilesTest3()
{
    // 400 MB = 400000000 Bytes (in decimal)
    // 400 MB = 419430400 Bytes (in binary)
    createFile(TEST3_FILE1_NAME, 419430400, 0x55); // 01010101
    createFile(TEST3_FILE2_NAME, 419430400, 0x50); // 01010000

    return {TEST3_FILE1_NAME, TEST3_FILE2_NAME};
}

void createFile(const std::string name, const int count, const char value)
{
    saveLog("Creating file `" + name + "`...");
    std::fstream f;
    f.open(name.c_str(), std::ios::binary | std::ios::out);
    for (int i = 0; i < count; i++)
    {
        f.write((char*)&value, 1);
    }
    f.close();
    saveLog("File `" + name + "' was created");
}
