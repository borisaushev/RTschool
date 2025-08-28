#include "commands/square_solver/squareSolver.h"
#include "tests/tests.h"
#include <windows.h>

#include "controller/controller.h"
// .\make_output\build.exe --SQUARE_FILE "C:\Users\bossb\CLionProjects\untitled\tests\textdata.txt"

int main(int argc, const char* argv[]) {
    system("chcp 65001");
    #ifdef TESTS_ENABLED
        runTests();
    #endif // TESTS_ENABLED

    startBorissScript(argc, argv);
    //startSolver(argc, argv);

    printf("\n\\--------------");
    printf("COMMIT RN VRO");
    printf("--------------\n");

    return 0;
}
