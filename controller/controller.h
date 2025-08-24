#ifndef SIMPLE_EXAMPLE_CONTROLLER_H
#define SIMPLE_EXAMPLE_CONTROLLER_H
#include <stdio.h>
#include "../input/input.h"

int startSolver(int argc, char **argv);

inputStatus_t solveEquationsUntilStop(FILE* stream);

int solveFromConsoleInput();

int solveFromFile(char* file);

#endif //SIMPLE_EXAMPLE_CONTROLLER_H