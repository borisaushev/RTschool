CC=g++
CFLAGS= -Wshadow \
		-Winit-self \
		-Wredundant-decls \
		-Wcast-align \
		-Wundef \
		-Wfloat-equal \
		-Winline \
		-Wunreachable-code \
		-Wmissing-declarations \
		-Wmissing-include-dirs \
		-Wswitch-enum\
		-Wswitch-default \
		-Weffc++ \
		-Wmain \
		-Wextra \
		-Wall \
		-g \
		-pipe \
		-fexceptions \
		-Wcast-qual \
		-Wconversion \
		-Wctor-dtor-privacy \
		-Wempty-body \
		-Wformat-security \
		-Wformat=2 \
		-Wignored-qualifiers \
		-Wlogical-op \
		-Wno-missing-field-initializers \
		-Wnon-virtual-dtor \
		-Woverloaded-virtual \
		-Wpointer-arith \
		-Wsign-promo \
		-Wstack-usage=8192 \
		-Wstrict-aliasing \
		-Wstrict-null-sentinel \
		-Wtype-limits \
		-Wwrite-strings \
		-Werror=vla\
		-D_EJUDGE_CLIENT_SIDE\
		-I.

DEPS = ./commands/square_solver/calculations/calculations.h \
 	   ./commands/square_solver/input/input.h \
 	   ./commands/square_solver/output/outputFormatter.h \
 	   ./tests/tests.h \
 	   ./controller/controller.h \
 	   ./commands/commands.h \
 	   ./commands/square_solver/squareSolver.h \

SRC = ./commands/square_solver/calculations/calculations.c \
	  ./commands/square_solver/input/input.c \
	  ./commands/square_solver/output/outputFormatter.c \
	  ./tests/tests.c \
	  ./controller/controller.c \
	  ./commands/commands.c \
	  ./commands/square_solver/squareSolver.c \
	  main.c

build: $(SRC)
	$(CC) -o make_output/$@ $^ $(CFLAGS) -D_DEBUG
	$(CC) $(SRC) -o make_output

test: $(SRC)
	$(CC) -o make_output/$@ $^ $(CFLAGS) -DTESTS_ENABLED -D_DEBUG
	$(CC) $(SRC) -o make_output

release: $(SRC)
	$(CC) -o make_output/$@ $^
	$(CC) $(SRC) -o make_output
