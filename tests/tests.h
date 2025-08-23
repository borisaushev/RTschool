#ifndef SIMPLE_EXAMPLE_TESTS_H
#define SIMPLE_EXAMPLE_TESTS_H

int runTests();

int solveEquationTest();

int assertTwoRoots(equationInput_t input, double expSol1, double expSol2);

int assertOneRoot(equationInput_t input, double expSol);

int assertNoRoots(equationInput_t input);

#endif //SIMPLE_EXAMPLE_TESTS_H