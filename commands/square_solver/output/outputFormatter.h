#ifndef OUTPUT_H
#define OUTPUT_H

#include "../calculations/calculations.h"

const char COLOR_SUFFIX[] = "\033[0m";

typedef enum textColor {
    BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE
} textColor_t;

int printSolution(equationData_t equationData);

int printColored(textColor_t textColor, const char format[],  ...)  __attribute__ ((format (printf, 2, 3)));

const char* getColorPrefix(textColor_t textColor);

#endif //OUTPUT_H