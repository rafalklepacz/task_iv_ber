#include "pch.h"

#include<string>

#include "menu.h"
#include "logger.h"
#include "validator.h"
#include "fileCreator.h"
#include "berCalculator.h"

int main(int argc, char *argv[])
{
    openLog("task_iv_ber.log");

    printStartupInfo(argc, argv);

    ValidationResult validationResult = validate(argc, argv);
    if (validationResult.isValid)
    {
        BerResult result = calculate(argv[1], argv[2]);
        printResult(result);
    }
    else
    {
        saveLog("No valid arguments were given and error message is: " + validationResult.error);
        saveLog("Select an option from the menu below");

        MenuItem menuItem = getUserMenuItem();

        saveLog("You chose the option: " + std::to_string(menuItem));

        Files createdFiles;
        switch (menuItem)
        {
            case Test1:
                createdFiles = createFilesTest1();
                break;
            case Test2:
                createdFiles = createFilesTest2();
                break;
            case Test3:
                createdFiles = createFilesTest3();
                break;
            default:
                return 0;
        }

        saveLog("Now, restart app with the command => " + (std::string)argv[0] + " " + createdFiles.file1 + " " + createdFiles.file2);
    }

    closeLog();

    return 0;
}
