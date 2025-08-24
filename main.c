#include "controller/controller.h"
#include "tests/tests.h"
// .\build.exe -FILE "C:\Users\bossb\CLionProjects\untitled\tests\textdata.txt"


int main(int argc, char* argv[]) {

    #ifdef TESTS_ENABLED
        runTests();
    #endif // TESTS_ENABLED

    startSolver(argc, argv);

    return 0;
}
