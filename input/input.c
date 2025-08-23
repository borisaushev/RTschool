#include "input.h"
#include <stdio.h>

int getLine(char(*line)[MAX_LINE_LENGTH]) {
    char inputChar = 0;
    //Reading next char until new line or EOF or limit of symbols reached
    for (int i = 0; i < MAX_LINE_LENGTH; i++) {
        scanf("%c", &inputChar);
        (*line)[i] = inputChar;

        //If we get new line or EOF - just stop
        if (inputChar == '\n' || inputChar == EOF) {
            return i+1;
        }
    }
    //we didnt get new line or EOF and reached limit
    return MAX_LINE_LENGTH+1;
}

inputStatus_t getCoefficients(equationInput_t *coefficients) {
    printf("Enter a, b, c coefficients separated by space: \n");
    double a = 0, b = 0, c = 0;

    char line[MAX_LINE_LENGTH];
    int length = getLine(&line);

    if (length > MAX_LINE_LENGTH) {
        return INVALID_INPUT;
    }

    //it's a line, trying to parse it
    int assignedValuesCount = sscanf(line, "%lg %lg %lg", &a, &b, &c);

    //validating parsed values
    if (assignedValuesCount != NUMBER_OF_COEFFICIENTS) {
        return INVALID_INPUT;
    }

    coefficients->a = a;
    coefficients->b = b;
    coefficients->c = c;

    //reached last line of values
    if (line[length-1] == EOF) {
        printf("hee");
        return LAST_LINE;
    }

    return SUCCESS;
}

