#include <assert.h>

#include "../input/input.h"
#include "../calculations/calculations.h"
#include "../tests/tests.h"

int runTests() {
    solveEquationTest();

    return 0;
}

int solveEquationTest() {
    equationData_t data1 = { {1, 0, -1}, {1,-1}, TWO};
    equationData_t data2 = { {1, 2, 1}, {-1,0}, ONE};
    equationData_t data3 = { {1, 0, 1}, {0,0}, ZERO};
    equationData_t data4 = { {0, 0, 0}, {0,0}, INF};

    assertSolutionEquals(data1);
    assertSolutionEquals(data2);
    assertSolutionEquals(data3);
    assertSolutionEquals(data4);

    return 0;
}

int assertSolutionEquals(equationData_t expectedSolution) {
    equationData_t equationData = {expectedSolution.inputData};
    solveEquation(&equationData);

    assertDataEquals(expectedSolution, equationData);

    return 0;
}

int assertDataEquals(equationData_t expectedSolution, equationData_t equationData) {
    assert(expectedSolution.solutionsCount == equationData.solutionsCount);

    assert(expectedSolution.inputData.a == equationData.inputData.a);
    assert(expectedSolution.inputData.b == equationData.inputData.b);
    assert(expectedSolution.inputData.c == equationData.inputData.c);

    switch (expectedSolution.solutionsCount) {
        case ZERO: {
            return 0;
        }
        case INF: {
            return 0;
        }
        case ONE: {
            assert(expectedSolution.solutions[0] == equationData.solutions[0]);
            return 0;
        }
        case TWO: {
            assert(expectedSolution.solutions[0] == equationData.solutions[0]);
            assert(expectedSolution.solutions[1] == equationData.solutions[1]);
            return 0;
        }
    }

    return 0;
}
