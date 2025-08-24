#include "controller/controller.h"
#include "tests/tests.h"


int main(int argc, char* argv[]) {

    #ifdef TESTS_ENABLED
        runTests();
    #endif // TESTS_ENABLED

    startSolver(argc, argv);

    return 0;
}
