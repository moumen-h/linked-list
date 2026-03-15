CC = gcc
BUILD_DIR = build
BIN = $(BUILD_DIR)/main.out
SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, $(BUILD_DIR)/%.o, $(SRC))

.PHONY: all clean run

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $^ -o $@

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $@

run: $(BIN)
	./$<

clean:
	rm -rf $(BUILD_DIR)
