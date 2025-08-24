#include <assert.h>

#include "../input/input.h"
#include "../calculations/calculations.h"
#include "tests.h"


int runTests() {
    solveEquationTest();
    solveEquationTestWithFileData();

    printf("Tests run successfully!\n\n");

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

    assert(equals(expectedSolution.inputData.a, equationData.inputData.a));
    assert(equals(expectedSolution.inputData.b, equationData.inputData.b));
    assert(equals(expectedSolution.inputData.c, equationData.inputData.c));

    switch (expectedSolution.solutionsCount) {
        case ZERO: {
            break;
        }
        case INF: {
            break;
        }
        case ONE: {
            assert(equals(expectedSolution.solutions[0], equationData.solutions[0]));
            break;
        }
        case TWO: {
            assert(equals(expectedSolution.solutions[0], equationData.solutions[0]));
            assert(equals(expectedSolution.solutions[1], equationData.solutions[1]));
            break;
        }
        default: {
            printf("Wrong solutionsCount\n");
            assert(0);
        }
    }

    return 0;
}

int solveEquationTestWithFileData() {
    FILE* fileStream = fopen(TEST_DATA_FILE_PATH, "r");

    // Check if the file was opened successfully
    assert(fileStream != NULL);

    char inputLine[MAX_LINE_LENGTH];
    double a = 0, b = 0, c = 0;
    int rootsCount = 0;
    double x1 = 0, x2 = 0;

    while (fgets(inputLine, MAX_LINE_LENGTH-1, fileStream) != NULL) {
        //parsing koof-values
        sscanf(inputLine, "%lg %lg %lg",
                &a, &b, &c);

        //reading next line with answers
        fgets(inputLine, MAX_LINE_LENGTH-1, fileStream);

        //parsing expected roots values
        sscanf(inputLine, "%d %lg %lg",
                &rootsCount, &x1, &x2);

        equationData_t expectedData = {{a,b,c},
            {x1, x2}, getSolutionsCount(rootsCount)};
        //checking if solver works as expected
        assertSolutionEquals(expectedData);

        //skipping unused line
        fgets(inputLine, MAX_LINE_LENGTH-1, fileStream);
    }

    return 0;
}

solutionsCount_t getSolutionsCount(int solutionsCount) {
    switch (solutionsCount) {
        case 0:
            return ZERO;
        case 1:
            return ONE;
        case 2:
            return TWO;
        case -1:
            return INF;
        default:
            printf("unexpected solutions count in file test data");
            assert(0);
    }
}