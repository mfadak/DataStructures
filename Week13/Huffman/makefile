all: compile run

compile:
  g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp
	g++ -I ./include/ -o ./lib/Huffman.o -c ./src/Huffman.cpp
	g++ -I ./include/ -o ./bin/Test ./lib/Node.o ./lib/Huffman.o ./src/Test.cpp
	
run:
	./bin/Test
