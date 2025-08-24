#include "controller.h"

#include "../input/input.h"
#include "../calculations/calculations.h"
#include "../output/outputFormatter.h"

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

int solveFromFile(char* file) {
    FILE* fileStream = fopen(file, "r");

    // Check if the file was opened successfully
    if (fileStream == NULL) {
        printf("Error opening file");
        return 1;
    }

    printf("Quadratic equation solver from file\n");
    solveEquationsUntilStop(fileStream);

    return 0;
}

int solveFromConsoleInput() {
    printf("Quadratic equation solver\n");
    printf("Add file path as argument to solve equations from a file\n");
    printf("Ctrl+Z+Enter to stop\n\n");

    solveEquationsUntilStop(stdin);

    return 0;
}

int solveEquationsUntilStop(FILE* stream) {
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
        default:
            printf("invalid program status");
            return -1;
    }
}
