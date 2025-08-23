#include <stdio.h>
#include "..\calculations\calculations.h"
#include "outputFormatter.h"

/**
 * Prints the answer
 * @param equationData all info about equation and ints solutions
 * @return zero if all fine
 */
int printSolution(equationData_t equationData) {
    double a = equationData.inputData.a, b = equationData.inputData.b, c = equationData.inputData.c;

    printf("Equation %g*x^2 %g*x %g ", a, b, c);

    switch (equationData.solutionsCount) {
        case ZERO:
            printf("has no solutions\n");
            break;
        case ONE:
            printf("has 1 solutions: %g\n", equationData.solutions[0]);
            break;
        case TWO:
            printf("has 2 solutions: %g, %g\n",
                   equationData.solutions[0], equationData.solutions[1]);
            break;
        case INF:
            printf("has infinitely many solutions\n");
            break;
    }
    printf("\n");

    return 0;
}