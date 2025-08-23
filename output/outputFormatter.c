#include <stdio.h>
#include "..\calculations\calculations.h"

int printSolution(equationData_t equationData) {
    switch (equationData.solutionsCount) {
        case ZERO:
            printf("Equation has no solutions\n");
            break;
        case ONE:
            printf("Equation has 1 solutions: %g\n", equationData.solutions[0]);
            break;
        case TWO:
            printf("Equation has 2 solutions: %g, %g\n",
                equationData.solutions[0], equationData.solutions[1]);
            break;
        case INF:
            printf("Equation has infinitely many solutions\n");
            break;
    }
    printf("\n");

    return 0;
}