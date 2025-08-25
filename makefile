CC=g++
CFLAGS= -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal\
		-Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum\
		-Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion\
		-Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op\
		-Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo\
		-Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla\
		-D_DEBUG -D_EJUDGE_CLIENT_SIDE\
		-I.

DEPS = ./calculations/calculations.h ./input/input.h ./output/outputFormatter.h ./tests/tests.h ./controller/controller.h
SRC = ./calculations/calculations.c ./input/input.c ./output/outputFormatter.c ./tests/tests.c ./controller/controller.c main.c

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

build: $(SRC)
	$(CC) -o $@ $^ $(CFLAGS)
	$(CC) $(SRC)

test: $(SRC)
	$(CC) -o $@ $^ $(CFLAGS) -DTESTS_ENABLED
	$(CC) $(SRC)

release: $(SRC)
	$(CC) -o $@ $^
	$(CC) $(SRC)

