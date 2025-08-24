#ifndef SIMPLE_EXAMPLE_CONTROLLER_H
#define SIMPLE_EXAMPLE_CONTROLLER_H

int startSolver(int argc, char **argv);

int solveEquationsUntilStop(FILE* stream);

int solveFromConsoleInput();

int solveFromFile(char* file);

#endif //SIMPLE_EXAMPLE_CONTROLLER_H