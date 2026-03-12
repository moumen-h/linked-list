CC = gcc
TARGET = build/main.out

$(TARGET): build/main.o build/node.o
	$(CC) $^ -o $@

build/main.o: main.c
	mkdir -p build/
	$(CC) -c $< -o $@

build/node.o: node.c
	mkdir -p build/
	$(CC) -c $< -o $@

clean:
	rm -rf build/
