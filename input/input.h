#ifndef INPUT_H
#define INPUT_H

const int NUMBER_OF_COEFFICIENTS = 3;
const int MAX_LINE_LENGTH = 256;

typedef enum inputStatus {
    SUCCESS, LAST_LINE, STOPPED, INVALID_INPUT
} inputStatus_t;

typedef enum readLineStatus {
    SUCCESSFUL, LINE_TOO_LONG
} readLineStatus_t;

typedef struct equationInput {
    double a, b, c;
} equationInput_t;

inputStatus_t getCoefficients(equationInput_t *coefficients);

int getLine(char(*line)[MAX_LINE_LENGTH]);

#endif //INPUT_H