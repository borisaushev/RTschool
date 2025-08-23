#include <stdio.h>

#include "input/input.h"
#include "calculations/calculations.h"
#include "output/outputFormatter.h"

int solveEquationsUntilStop();

int main() {
    printf("Quadratic equation solver\n");
    printf("Ctrl+D+Enter to stop\n\n");

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
