all: compile run

compile:
	g++ -I ./include/ -o ./lib/DoubleHashing.o -c ./src/DoubleHashing.cpp
	g++ -I ./include/ -o ./bin/Test ./lib/DoubleHashing.o ./src/Test.cpp

run:
	./bin/Test
