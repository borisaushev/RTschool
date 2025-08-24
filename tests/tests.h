#ifndef SIMPLE_EXAMPLE_TESTS_H
#define SIMPLE_EXAMPLE_TESTS_H

#include "../calculations/calculations.h"

const char* const TEST_DATA_FILE_PATH = "C:/Users/bossb/CLionProjects/untitled/tests/test_data.txt";

int runTests();

int solveEquationTest();

int assertSolutionEquals(equationData_t expectedSolution);

int assertDataEquals(equationData_t expectedSolution, equationData_t equationData);

int solveEquationTestWithFileData();

solutionsCount_t getSolutionsCount(int solutionsCount);

#endif //SIMPLE_EXAMPLE_TESTS_H