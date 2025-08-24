#include <float.h>
#include <math.h>

#include "../input/input.h"
#include "calculations.h"

/**
 * @param value double value
 * @return if the value is zero
 */
int isZero(double value) {
    return fabs(value) < FLT_EPSILON;
}

/**
 * Compares 2 double values correctly
 * @param n1 value 1
 * @param n2 value 2
 * @return if 2 values are equal
 */
int equals(double n1, double n2) {
    return fabs(n1 - n2) < FLT_EPSILON;
}

/**
 * @param value double value
 * @return if the value is less then zero
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
    if (!isZero(b)) {
        // equation is linear
        double x = -c / b;
        equationData->solutions[0] = x;
        equationData->solutionsCount = ONE;
    }
    else {
        // equation doesn't depend on X
        if (isZero(c)) {
            // Infinite solutions
            equationData->solutionsCount = INF;
        } else {
            // no solutions
            equationData->solutionsCount = ZERO;
        }
    }

    return 0;
}