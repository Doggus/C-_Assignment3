CC=g++
LIBS=-lm

main: main.o HuffmanTree.o HuffmanNode.o
	$(CC) -o main main.o HuffmanTree.o HuffmanNode.o  -std=c++11

main.o: main.cpp
	$(CC) -c main.cpp -std=c++11

HuffmanTree.o: HuffmanTree.h HuffmanTree.cpp
	$(CC) -c HuffmanTree.cpp -std=c++11

HuffmanNode.o: HuffmanNode.h HuffmanNode.cpp
	$(CC) -c HuffmanNode.cpp -std=c++11

run:
	./main
