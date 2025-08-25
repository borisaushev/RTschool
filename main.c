#include "controller/controller.h"
#include "tests/tests.h"
#include <windows.h>
// .\build.exe --FILE "C:\Users\bossb\CLionProjects\untitled\tests\textdata.txt"


int main(int argc, const char* argv[]) {
    system("chcp 65001");
    #ifdef TESTS_ENABLED
        runTests();
    #endif // TESTS_ENABLED

    startSolver(argc, argv);

    return 0;
}
