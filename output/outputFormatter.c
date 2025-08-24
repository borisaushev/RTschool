#include <stdio.h>
#include "../calculations/calculations.h"
#include "outputFormatter.h"

#include <assert.h>
#include <string.h>

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
        default:
            printf("invalid solutions count\n");
            assert(0);
    }
    printf("\n");

    return 0;
}

int printColored(const char str[], textColor_t textColor) {
    assert(strlen(str) <= MAX_LINE_LENGTH);

    char res[MAX_LINE_LENGTH];
    res[0] = '\0';

    strcat(res, getColorPrefix(textColor));
    strcat(res, str);
    strcat(res, COLOR_SUFFIX);

    printf("%s\n", res);

    return 0;
}

const char* getColorPrefix(textColor_t textColor) {
    switch (textColor) {
        case BLACK:
            return "\033[30m";
        case RED:
            return "\033[31m";
        case GREEN:
            return "\033[33m";
        case YELLOW:
            return "\033[33m";
        case BLUE:
            return "\033[34m";
        case MAGENTA:
            return "\033[35m";
        case CYAN:
            return "\033[36m";
        case WHITE:
            return "\033[37m";
        default:
            assert(0);
    }
}