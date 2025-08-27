#ifndef SIMPLE_EXAMPLE_TESTS_H
#define SIMPLE_EXAMPLE_TESTS_H

#include "../commands/square_solver/calculations/calculations.h"

typedef enum testResult {
    TEST_ERROR, TEST_SUCCESS, TEST_CASE_FAIL
} testResult_t;

typedef struct testStats {
    int failCount;
    int errorCount;
} testStats_t;

const char* const TEST_DATA_FILE_PATH = "C:/Users/bossb/CLionProjects/untitled/tests/test_data.txt";

int runTests();

int solveEquationTest(testStats_t* testStats);

int checkResultAndUpdate(testStats_t* testStats, equationData_t expectedData);

testResult_t assertSolutionEquals(equationData_t expectedSolution);

testResult_t assertDataEquals(equationData_t expectedSolution, equationData_t equationData);

int solveEquationTestWithFileData(testStats_t* testStats);

solutionsCount_t getSolutionsCount(int solutionsCount);

#endif //SIMPLE_EXAMPLE_TESTS_H