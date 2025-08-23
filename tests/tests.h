#ifndef SIMPLE_EXAMPLE_TESTS_H
#define SIMPLE_EXAMPLE_TESTS_H

int runTests();

int solveEquationTest();

int assertSolutionEquals(equationData_t expectedSolution);

int assertDataEquals(equationData_t expectedSolution, equationData_t equationData);

#endif //SIMPLE_EXAMPLE_TESTS_H