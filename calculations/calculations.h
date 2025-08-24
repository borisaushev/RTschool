#ifndef CALCULATIONS_H
#define CALCULATIONS_H

#include "../input/input.h"

const int MAX_SOLUTIONS = 2;

typedef enum solutionsCount {
    ZERO, ONE, TWO, INF
} solutionsCount_t;

typedef struct equationData {
    equationInput_t inputData;
    double solutions[MAX_SOLUTIONS];
    solutionsCount_t solutionsCount;
} equationData_t;


int solveEquation(equationData_t *equationData);

int solveSquareEquation(equationData_t *equationData);

int solveLinearEquation(equationData_t *equationData);

int lessThenZero(double value);

int isZero(double value);

int equals(double n1, double n2);

#endif //CALCULATIONS_H