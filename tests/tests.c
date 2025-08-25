//! @file

#include <assert.h>

#include "../input/input.h"
#include "../calculations/calculations.h"
#include "tests.h"

#include <stdlib.h>

//!
//! runs all tests
//! @return zero if all fine
//!
int runTests() {
    testStats_t testStats = {.failCount = 0, .errorCount = 0};

    solveEquationTest(&testStats);
    solveEquationTestWithFileData(&testStats);

    printf("failed tests: %d \nerrors in tests: %d\n",
        testStats.failCount, testStats.errorCount);
    if (testStats.failCount != 0 || testStats.errorCount != 0) {
        printf("Tests failed\n");
        exit(1);
    }
    printf("Tests run successfully!\n\n");

    return 0;
}

int solveEquationTest(testStats_t* testStats) {
    equationData_t testData[] = {
        { {1, 0, -1}, {1,-1}, TWO},
        { {1, 2, 1}, {-1,0}, ONE},
        { {1, 0, 1}, {0,0}, ZERO},
        { {0, 0, 0}, {0,0}, INF},
    };

    for (size_t i = 0; i < sizeof(testData) / sizeof(equationData_t); i++) {
        equationData_t testEquationData = testData[i];
        checkResultAndUpdate(testStats, testEquationData);
    }

    return 0;
}

//!
//! Solves equation with given data, and compares solution with given equation data
//! @param expectedSolution expected equationData objects after equation solved
//! @return zero if all fine, one if fail
//!
testResult_t assertSolutionEquals(equationData_t expectedSolution) {
    equationData_t equationData = {expectedSolution.inputData};
    solveEquation(&equationData);

    return assertDataEquals(expectedSolution, equationData);
}


//!
//! fails if corresponding values in 2 given values differ
//! @param expectedSolution first value
//! @param equationData second value
//! @return zero if all fine
//!
testResult_t assertDataEquals(const equationData_t expectedSolution, const equationData_t equationData) {
    if(expectedSolution.solutionsCount != equationData.solutionsCount
        || !equals(expectedSolution.inputData.a, equationData.inputData.a)
        || !equals(expectedSolution.inputData.b, equationData.inputData.b)
        || !equals(expectedSolution.inputData.c, equationData.inputData.c)) {
        return TEST_CASE_FAIL;
    }

    switch (expectedSolution.solutionsCount) {
        case ZERO: {
            return TEST_SUCCESS;
        }
        case INF: {
            return TEST_SUCCESS;
        }
        case ONE: {
            if (!equals(expectedSolution.solutions[0], equationData.solutions[0])) {
                return TEST_CASE_FAIL;
            }
            return TEST_SUCCESS;
        }
        case TWO: {
            if (!equals(expectedSolution.solutions[0], equationData.solutions[0])
             || !equals(expectedSolution.solutions[1], equationData.solutions[1])) {
                return TEST_CASE_FAIL;
            }
            return TEST_SUCCESS;
        }
        default: {
            printf("Wrong solutionsCount\n");
            return TEST_ERROR;
        }
    }

    return TEST_SUCCESS;
}

int checkResultAndUpdate(testStats_t *testStats, equationData_t expectedData) {
    testResult_t result = assertSolutionEquals(expectedData);
    switch (result) {
        case TEST_SUCCESS:
            break;
        case TEST_CASE_FAIL:
            testStats->failCount++;
            break;
        case TEST_ERROR:
            testStats->errorCount++;
            break;
        default:
            break;
    }

    return 0;
}

int solveEquationTestWithFileData(testStats_t* testStats) {
    FILE* fileStream = fopen(TEST_DATA_FILE_PATH, "r");

    // Check if the file was opened successfully
    if(fileStream == NULL) {
        testStats->errorCount++;
        return 0;
    }

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
        checkResultAndUpdate(testStats, expectedData);

        //skipping unused line
        fgets(inputLine, MAX_LINE_LENGTH-1, fileStream);
    }

    return TEST_SUCCESS;
}

//---------------------------------------------------
//! Returns solutionsCount integer equivalent
//! @param solutionsCount solutionsCount value
//! @return integer equivalent of it, or TEST_ERROR if error
//---------------------------------------------------

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
            return ZERO;
    }
}