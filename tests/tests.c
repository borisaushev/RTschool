#include <assert.h>

#include "../input/input.h"
#include "../calculations/calculations.h"
#include "../tests/tests.h"

int runTests() {
    solveEquationTest();

    return 0;
}

int solveEquationTest() {
    equationInput_t data1 = {1, 0, -1};
    equationInput_t data2= {1, 2, 1};
    equationInput_t data3 = {1, 0, 1};

    assertTwoRoots(data1, 1, -1);
    assertOneRoot(data2, -1);
    assertNoRoots(data3);

    return 0;
}

int assertTwoRoots(equationInput_t input, double expSol1, double expSol2) {
    equationData_t equationData = {input};
    solveEquation(&equationData);

    assert(equationData.solutionsCount == TWO);
    assert(equationData.solutions[0] == expSol1);
    assert(equationData.solutions[1] == expSol2);

    return 0;
}

int assertOneRoot(equationInput_t input, double expSol) {
    equationData_t equationData = {input};
    solveEquation(&equationData);

    assert(equationData.solutionsCount == ONE);
    assert(equationData.solutions[0] == expSol);

    return 0;
}

int assertNoRoots(equationInput_t input) {
    equationData_t equationData = {input};
    solveEquation(&equationData);

    assert(equationData.solutionsCount == ZERO);

    return 0;
}
