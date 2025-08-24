#include "controller/controller.h"
#include "output/outputFormatter.h"
#include "tests/tests.h"

int main(int argc, char* argv[]) {
    runTests();

    startSolver(argc, argv);

    return 0;
}
