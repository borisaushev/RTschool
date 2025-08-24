#include <stdio.h>
#include "../calculations/calculations.h"
#include "outputFormatter.h"

#include <assert.h>
#include <stdarg.h>
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
            printColored("has no solutions\n", RED);
            break;
        case ONE:
            printColored("has 1 solutions: %g\n", YELLOW, equationData.solutions[0]);
            break;
        case TWO:
            printColored("has 2 solutions: %g, %g\n", GREEN,
                   equationData.solutions[0], equationData.solutions[1]);
            break;
        case INF:
            printColored("has infinitely many solutions\n", WHITE);
            break;
        default:
            printColored("invalid solutions count\n", RED);
            assert(0);
    }
    printf("\n");

    return 0;
}

int printColored(const char format[], textColor_t textColor, ...) {
    assert(strlen(format) <= MAX_LINE_LENGTH);

    char result[MAX_LINE_LENGTH];
    result[0] = '\0';

    va_list args;
    va_start(args, textColor);
    vsprintf(result, format, args);
    va_end(args);

    printf("%s%s%s\n", getColorPrefix(textColor), result, COLOR_SUFFIX);

    return 0;
}

const char* getColorPrefix(textColor_t textColor) {
    switch (textColor) {
        case BLACK:
            return "\033[30m";
        case RED:
            return "\033[31m";
        case GREEN:
            return "\033[32m";
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