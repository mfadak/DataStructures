all: compile run

compile:
	g++ -I ./include/ -o ./lib/HeapTree.o -c ./src/HeapTree.cpp
	g++ -I ./include/ -o ./bin/Test ./lib/HeapTree.o ./src/Test.cpp
	
run:
	./bin/Test
