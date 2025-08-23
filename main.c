#include <stdio.h>
//добавить чтение из файла (можно через main)

#include "input/input.h"
#include "calculations/calculations.h"
#include "output/outputFormatter.h"
#include "tests/tests.h"

int solveEquationsUntilStop();

int main() {
    runTests();
    printf("Tests run successfully!\n\n");

    printf("Quadratic equation solver\n");
    printf("Ctrl+Z+Enter to stop\n\n");

    solveEquationsUntilStop();

    return 0;
}

int solveEquationsUntilStop() {
    equationData_t equationData;
    inputStatus_t programStatus = SUCCESS;
    while ((programStatus = getCoefficients(&equationData.inputData)) == SUCCESS) {
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
