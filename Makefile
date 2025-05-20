CC = gcc
ASM = nasm
CFLAGS = -Wall -Wextra -O2 -Iinclude
ASMFLAGS = -f elf64
LDFLAGS = -no-pie

BIN = bin
OBJ = obj

TARGETS = $(BIN)/main $(BIN)/benchmarks $(BIN)/test_numbers $(BIN)/test_strings $(BIN)/test_arrays

all: $(TARGETS)

$(BIN)/main: $(OBJ)/main.o $(OBJ)/numbers.o $(OBJ)/strings.o $(OBJ)/arrays.o | $(BIN)
 $(CC) $(LDFLAGS) -o $@ $^

$(BIN)/benchmarks: $(OBJ)/benchmarks.o $(OBJ)/numbers.o $(OBJ)/strings.o $(OBJ)/arrays.o | $(BIN)
 $(CC) $(LDFLAGS) -o $@ $^

$(BIN)/test_%: $(OBJ)/test_%.o $(OBJ)/numbers.o $(OBJ)/strings.o $(OBJ)/arrays.o | $(BIN)
 $(CC) $(LDFLAGS) -o $@ $^

$(OBJ)/%.o: c/%.c | $(OBJ)
 $(CC) $(CFLAGS) -c -o $@ $<

$(OBJ)/%.o: tests/%.c | $(OBJ)
 $(CC) $(CFLAGS) -c -o $@ $<

$(OBJ)/%.o: asm/%.asm | $(OBJ)
 $(ASM) $(ASMFLAGS) -o $@ $<

$(BIN):
 mkdir -p $(BIN)

$(OBJ):
 mkdir -p $(OBJ)

clean:
 rm -rf $(BIN) $(OBJ)

test: $(BIN)/test_numbers $(BIN)/test_strings $(BIN)/test_arrays
 $(BIN)/test_numbers
 $(BIN)/test_strings
 $(BIN)/test_arrays

bench: $(BIN)/benchmarks
 $(BIN)/benchmarks

.PHONY: all clean test bench
