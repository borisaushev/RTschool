CC=g++
CFLAGS=-I.
DEPS = ./calculations/calculations.h ./input/input.h ./output/outputFormatter.h ./tests/tests.h
OBJ = ./calculations/calculations.c ./input/input.c ./output/outputFormatter.c ./tests/tests.c main.c

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

build: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	$(CC) $(OBJ)