#ifndef SIMPLE_EXAMPLE_CONTROLLER_H
#define SIMPLE_EXAMPLE_CONTROLLER_H
#include <stdio.h>
#include "../input/input.h"

const char* const FILE_FLAG = "--FILE";

int startSolver(int argc, const char **argv);

inputStatus_t solveEquationsUntilStop(FILE* stream);

int solveFromConsoleInput();

int solveFromFile(const char* file);

#endif //SIMPLE_EXAMPLE_CONTROLLER_H