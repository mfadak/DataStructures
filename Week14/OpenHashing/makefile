all: compile run

compile:
	g++ -I ./include/ -o ./lib/Hash.o -c ./src/Hash.cpp
	g++ -I ./include/ -o ./bin/Test ./lib/Hash.o ./src/Test.cpp

run:
	./bin/Test
