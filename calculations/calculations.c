#include <float.h>
#include <math.h>

#include "..\input\input.h"
#include "calculations.h"

/**
 * @param value
 * @return if the value is zero
 */
int isZero(double value) {
    return fabs(value) < FLT_EPSILON;
}

/**
 * @param value
 * @return if the value is lewss then zero
 */
int lessThenZero(double value) {
    return value + FLT_EPSILON < 0;
}


/**
 * solves equation and writes roots values in parameter
 * @param equationData pointer to the data struct object to write roots in
 * @return 0 if all fine
 */
int solveEquation(equationData_t *equationData) {
    if (isZero(equationData->inputData.a)) {
        // a == 0, equation is linear or doesn't depend on X
        solveLinearEquation(equationData);
    }
    else {
        // a != 0, equation is quadratic
        solveSquareEquation(equationData);
    }

    return 0;
}

/**
 * solves square equation and writes roots in param pointer,
 * only called if a-koof is non-zero
 * @param equationData pointer to the data struct object to write roots in
 * @return zero if all fine
 */
int solveSquareEquation(equationData_t *equationData) {
    double a = equationData->inputData.a;
    double b = equationData->inputData.b;
    double c = equationData->inputData.c;

    double discriminant = (b * b) - (4 * a * c);
    if (lessThenZero(discriminant)) {
        // Discriminant < 0 -> no roots
        equationData->solutionsCount = ZERO;
        return 0;
    }

    if (isZero(discriminant)) {
        // Discriminant == 0 -> one root
        double x = -b / (2 * a);
        equationData->solutions[0] = x;
        equationData->solutionsCount = ONE;
    }
    else {
        // Discriminant > 0 -> two different roots
        double discriminantSqrt = sqrt(discriminant);
        double x1 = (-b + discriminantSqrt) / (2 * a);
        double x2 = (-b - discriminantSqrt) / (2 * a);

        equationData->solutions[0] = x1;
        equationData->solutions[1] = x2;
        equationData->solutionsCount = TWO;
    }

    return 0;
}

/**
 * solves linear equation and writes roots in param pointer,
 * only called if a-koof is zero
 * @param equationData pointer to the data struct object to write roots in
 * @return zero if all fine
 */
int solveLinearEquation(equationData_t *equationData) {
    double b = equationData->inputData.b;
    double c = equationData->inputData.c;
    if (b != 0) {
        // equation is linear
        double x = -c / b;
        equationData->solutions[0] = x;
        equationData->solutionsCount = ONE;
    }
    else {
        // equation doesn't depend on X
        if (c == 0) {
            // Infinite solutions
            equationData->solutionsCount = INF;
        } else {
            // no solutions
            equationData->solutionsCount = ZERO;
        }
    }

    return 0;
}