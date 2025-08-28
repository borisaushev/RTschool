//!@file

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "../commands/square_solver/squareSolver.h"
#include "../commands/square_solver/output/outputFormatter.h"
#include "../commands/commands.h"
#include "controller.h"

/**
 * Finds file path (if specified)
 * @param file buffer to write found file path
 * @param argc main function argc
 * @param argv main function argv
 * @param fileFlag flag after which the file path is specified
 * @return one if file found, zero otherwise
 */
int getFilePath(char* file, const int argc, const char** argv, const char* fileFlag) {
    assert(file != NULL);
    assert(argv != NULL);
    assert(argc >= 0);

    for (int i = 1; i < argc - 1; ++i) {
        size_t index = i;
        assert(index < (sizeof(*argv) / sizeof(argv[0])));
        if (strcmp(argv[index], fileFlag) == 0) {
            const char* filePath = argv[i+1];
            strcpy(file, filePath);
            return 1;
        }
    }

    return 0;
}

/**
 * starts command reader
 * @param argc main function argc
 * @param argv main function argv
 * @return zero if all fine
 */
int startBorissScript(const int argc, const char **argv) {
    assert(argv != NULL);

    char file[MAX_LINE_LENGTH];
    if (getFilePath(file, argc, argv, FILE_FLAG)) {
        scriptFromFile(file, argc, argv);
    }
    else {
        scriptFromConsole(argc, argv);
    }

    return 0;
}


/**
 * starts command reader
 * @param argc main function argc
 * @param argv main function argv
 * @return zero if all fine
 */
int scriptFromFile(char* file, const int argc, const char **argv) {
    assert(argv != NULL);
    assert(argc >= 0);
    assert(file != NULL);

    FILE* fs = fopen(file, "r");
    if (fs == NULL) {
        printColored(RED, "Error opening file\n");
        exit(1);
    }
    runCommandsUntilStops(fs, argc, argv);

    return 0;
}


/**
 * starts command reader from console
 * @param argc main function argc
 * @param argv main function argv
 * @return zero if all fine
 */
int scriptFromConsole(const int argc, const char **argv) {
    assert(argc >= 0);
    assert(argv != NULL);

    runCommandsUntilStops(stdin, argc, argv);

    return 0;
}

int greetUser() {
    printColored(GREEN, "\n ___________________________________\n");
    printColored(GREEN, "|                                   |\n");
    printColored(GREEN, "| Вас приветствует BossBorissScript |\n");
    printColored(GREEN, "|___________________________________|\n\n");
    sleep(1);
    printColored(WHITE, "Pishy comandu\n");

    return 0;
}

/**
 * starts command reader from given stream
 * @param stream command source stream
 * @param argc main function argc
 * @param argv main function argv
 * @return zero if all fine
 */
int runCommandsUntilStops(FILE* stream, const int argc, const char **argv) {
    assert(stream != NULL);
    assert(argc >= 0);
    assert(argv != NULL);

    greetUser();

    command_t currentCommand = SQUARE_SOLVER;
    while ((currentCommand = getCommand(stream)) != STOP_PROGRAM) {
        processCommand(currentCommand, argc, argv);
        printColored(GREEN, "\nComandu napishi vro\n");
    }

    switch (currentCommand) {
        case STOP_PROGRAM: {
            printf("BorissScript obeys\n");
            return 0;
        }
        case NOT_A_COMMAND: {
            printColored(RED, "Invalid command\n");
            return 0;
        }
        case SQUARE_SOLVER: {return 0;}
        case ARSEN_SIGMA: {return 0;}
        case COUNTING_STARS: {return 0;}
        case SEE_THE_MONSTER: {return 0;}
        default: {
            #ifdef DEBUG
                printColored(RED, "Invalid command status, please fix\n");
            #endif //DEBUG
            return 1;
        }
    }
    return 0;
}

/**
 * gets next command from given stream
 * @param stream
 * @return zero if all fine
 */
command_t getCommand(FILE* stream) {
    assert(stream != NULL);

    char line[MAX_LINE_LENGTH];
    if (fgets(line, MAX_LINE_LENGTH-1, stream) == NULL) {
        if (feof(stream) || strlen(line) > MAX_LINE_LENGTH) {
            return STOP_PROGRAM;
        }
    }

    if (strcmp("square_solver\n", line) == 0) {
        return SQUARE_SOLVER;
    }
    else if (strcmp("arsen_sigma\n", line) == 0) {
        return ARSEN_SIGMA;
    }
    else if (strcmp("counting_stars\n", line) == 0) {
        return COUNTING_STARS;
    }
    else if (strcmp("see_the_monster\n", line) == 0) {
        return SEE_THE_MONSTER;
    }
    else {
        return NOT_A_COMMAND;
    }
}

/**
 * prcesses user command
 * @param command command
 * @param argc main function argc
 * @param argv main function argv
 * @return zero if all fine
 */
int processCommand(command_t command, const int argc, const char **argv) {
    assert(argc >= 0);
    assert(argv != NULL);

    switch (command) {
        case SQUARE_SOLVER:
            squareSolver(argc, argv);
            break;
        case ARSEN_SIGMA:
            arsen();
            break;
        case COUNTING_STARS:
            countTheStars();
            break;
        case SEE_THE_MONSTER:
            seeTheMonster();
            break;
        case STOP_PROGRAM:
            break;
        case NOT_A_COMMAND:
            printColored(RED, "invalid command");
            break;
        default:
            #ifdef DEBUG
                printColored(RED, "invalid command value");
            #endif //DEBUG

            exit(1);
    }

    return 0;
}