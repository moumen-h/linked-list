CC = gcc
TARGET = build/main.out

$(TARGET): build/main.o build/node.o
	$(CC) $^ -o $@

build/main.o: main.c
	$(CC) -c $< -o $@

build/node.o: node.c
	$(CC) -c $< -o $@

clean:
	rm -f build/*
