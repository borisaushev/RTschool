//! @file

#include "controller.h"
#include "../input/input.h"
#include "../calculations/calculations.h"
#include "../output/outputFormatter.h"

#include <assert.h>
#include <string.h>

//!
//!@param argc console arguments count
//!@param argv console args
//!@return zero if all fine
//!
int startSolver(int argc, const char **argv) {
    for (int i = 1; i < argc - 1; ++i) {
        if (strcmp(argv[i], FILE_FLAG) != 0) {
           const  char* filePath = argv[i+1];
            solveFromFile(filePath);
            return 0;
        }
    }

    solveFromConsoleInput();

    return 0;
}

//!
//! Solves equations from file, stored as 3 coof's per line separated by space
//! @param file file path as string
//! @return - zero if all fine - one if file didn't open
//!
int solveFromFile(const char* file) {
    FILE* fileStream = fopen(file, "r");

    // Check if the file was opened successfully
    if (fileStream == NULL) {
        printColored(RED, "Error opening file");
        return 1;
    }

    printColored(GREEN, "Quadratic equation solver from file\n");
    solveEquationsUntilStop(fileStream);

    return 0;
}

//!
//!Gets console input and solves the equation itself untill user stops it
//!@return zero if all fine
//!
int solveFromConsoleInput() {
    printColored(GREEN, "Quadratic equation solver\n");
    printColored(WHITE, "Add file path as argument to solve equations from a file\n");
    printColored(WHITE, "Ctrl+Z+Enter to stop\n\n");

    solveEquationsUntilStop(stdin);

    return 0;
}

//!
//!@param stream stream, from which the data is read
//!@return input status
//!
inputStatus_t solveEquationsUntilStop(FILE* stream) {
    equationData_t equationData;
    inputStatus_t programStatus = SUCCESS;
    while ((programStatus = getCoefficients(&equationData.inputData, stream)) == SUCCESS) {
        solveEquation(&equationData);
        printSolution(equationData);
    }

    switch (programStatus) {
        case LAST_LINE:
            solveEquation(&equationData);
            printSolution(equationData);
            return STOPPED;

        case INVALID_INPUT:
            printColored(RED, "invalid input");
            return INVALID_INPUT;

        case STOPPED:
            printColored(WHITE, "program stopped");
            return STOPPED;

        case SUCCESS:
            return SUCCESS;

        default:
            printColored(RED, "invalid program status");
            assert(0);
            return INVALID_INPUT;
    }
}
