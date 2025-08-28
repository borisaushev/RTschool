#ifndef BOSSBORISS_CONTROLLER_H
#define BOSSBORISS_CONTROLLER_H

#include <stdio.h>

typedef enum command {
    SQUARE_SOLVER, ARSEN_SIGMA, COUNTING_STARS, SEE_THE_MONSTER,
    STOP_PROGRAM,
    NOT_A_COMMAND
} command_t;

int greetUser();

int getFilePath(char* file, const int argc, const char** argv, const char* fileFlag);

int startBorissScript(int argc, const char **argv);

int scriptFromFile(char* file, const int argc, const char **argv);

int scriptFromConsole(int argc, const char **argv);

int runCommandsUntilStops(FILE* stream, const int argc, const char **argv);

command_t getCommand(FILE* stream);

int processCommand(command_t command, const int argc, const char **argv);

#endif //BOSSBORISS_CONTROLLER_H