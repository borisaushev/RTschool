#include <stdio.h>
//добавить чтение из файла (можно через main)

#include <stdlib.h>

#include "input/input.h"
#include "calculations/calculations.h"
#include "output/outputFormatter.h"
#include "tests/tests.h"

int solveEquationsUntilStop(FILE* stream);

int solveFromConsoleInput();

int solveFromFile(char* file);

int main(int argc, char* argv[]) {
    runTests();
    printf("Tests run successfully!\n\n");

    if (argc == 2) {
        char* filePath = argv[1];
        printf("\narg: %s\n", filePath);
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
