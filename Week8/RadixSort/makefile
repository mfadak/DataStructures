all: compile run

compile:
	g++ -I ./include/ -o ./lib/Radix.o -c ./src/Radix.cpp
	g++ -I ./include/ -o ./bin/Test ./lib/Radix.o ./src/Test.cpp
	
run:
	./bin/Test
