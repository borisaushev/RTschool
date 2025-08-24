#include "controller.h"

#include <assert.h>

#include "../input/input.h"
#include "../calculations/calculations.h"
#include "../output/outputFormatter.h"

/**
 *
 * @param argc console arguments count
 * @param argv console args
 * @return zero if all fine
 */
int startSolver(int argc, char **argv) {
    if (argc == 2) {
        char* filePath = argv[1];
        solveFromFile(filePath);
    }
    else {
        solveFromConsoleInput();
    }

    return 0;
}

/**
 * Solves equations from file, stored as 3 coof's per line separated by space
 * @param file file path as string
 * @return - zero if all fine - one if file didn't open
 */
int solveFromFile(char* file) {
    FILE* fileStream = fopen(file, "r");

    // Check if the file was opened successfully
    if (fileStream == NULL) {
        printColored("Error opening file", RED);
        return 1;
    }

    printColored("Quadratic equation solver from file\n", GREEN);
    solveEquationsUntilStop(fileStream);

    return 0;
}

/**
 * Gets console input and solves the equation itself untill user stops it
 * @return zero if all fine
 */
int solveFromConsoleInput() {
    printColored("Quadratic equation solver\n", GREEN);
    printColored("Add file path as argument to solve equations from a file\n", WHITE);
    printColored("Ctrl+Z+Enter to stop\n\n", WHITE);

    solveEquationsUntilStop(stdin);

    return 0;
}

/**
 *
 * @param stream stream, from which the data is read
 * @return input status
 */
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
            printf("invalid input");
            return INVALID_INPUT;
        case STOPPED:
            printf("program stopped");
            return STOPPED;
        case SUCCESS:
            return SUCCESS;
        default:
            printf("invalid program status");
            assert(0);
            return INVALID_INPUT;
    }
}
