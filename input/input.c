//! @file

#include "input.h"
#include "../output/outputFormatter.h"
#include "../secret_stuff/secret.h"

#include <stdio.h>
#include <string.h>

//!
//! @param line user input
//! @param assignedValuesCount assigned values count
//! @return
//!- STOPPED if user stops program manually
//!- INVALID_INPUT if user inputs wrong values
//!- LAST_LINE if user inputs correct values ended with EOF
//!
inputStatus_t getStatusCode(char line[MAX_LINE_LENGTH], int assignedValuesCount) {
    if (assignedValuesCount == EOF) {
        return STOPPED;
    }
    if (assignedValuesCount != NUMBER_OF_COEFFICIENTS) {
        return INVALID_INPUT;
    }
    if (line[strlen(line) - 1] == EOF_CONST) {
        return LAST_LINE;
    }

    return SUCCESS;
}

//!
//! gets line from input stream and parses koof values
//! @param coefficients pointer to struct object to write koffs into
//! @return input status depending on user input:
//! - STOPPED if user stops the program manually
//! - INVALID_INPUT if user inputs too big line
//! - getStatusCode() value otherwise
//!
inputStatus_t getCoefficients(equationInput_t *coefficients, FILE* stream) {
    if (stream == stdin) {
        printColored(CYAN, "Enter a, b, c coefficients separated by space: \n");
    }

    char line[MAX_LINE_LENGTH];

    if (fgets(line, MAX_LINE_LENGTH-1, stream) == NULL) {
        if (feof(stream)) {
            return STOPPED;
        }
        else if (strlen(line) > MAX_LINE_LENGTH) {
            return INVALID_INPUT;
        }
    }

    if (isASuperSecretWord(line)) {
        doSecretGangsterShit(line);
        return SECRET_WORD;
    }

    //it's a line, trying to parse it
    int assignedValuesCount = sscanf(line, "%lg %lg %lg",
        &coefficients->a, &coefficients->b, &coefficients->c);

    return getStatusCode(line, assignedValuesCount);
}

int isASuperSecretWord(char line[]) {
    for (size_t i = 0; i < sizeof(SECRET_WORDS)/MAX_LINE_LENGTH; i++) {
        if (strcmp(SECRET_WORDS[i], line) == 0) {
            return 1;
        }
    }

    return 0;
}
