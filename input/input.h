#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>

const int NUMBER_OF_COEFFICIENTS = 3;
const int MAX_LINE_LENGTH = 256;
const int EOF_CONST = 26;
const char SECRET_WORDS[3][MAX_LINE_LENGTH] = {"arsen_sigma\n", "accept_your_destiny\n", "sinners_fate\n"};

typedef enum inputStatus {
    SUCCESS, LAST_LINE, STOPPED, INVALID_INPUT, SECRET_WORD
} inputStatus_t;

typedef enum inputType {
    USER_FILE, CONSOLE
} inputType_t;

typedef enum readLineStatus {
    SUCCESSFUL, LINE_TOO_LONG
} readLineStatus_t;

typedef struct equationInput {
    double a, b, c;
} equationInput_t;

inputStatus_t getCoefficients(equationInput_t *coefficients, FILE* stream);

inputStatus_t getStatusCode(char line[MAX_LINE_LENGTH], int assignedValuesCount);

int getLine(char(*line)[MAX_LINE_LENGTH]);

int isASuperSecretWord(char line[]);

#endif //INPUT_H