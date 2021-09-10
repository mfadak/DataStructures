all: compile run

compile:
	g++ -I ./include/ -o ./lib/Person.o -c ./src/Person.cpp
	g++ -I ./include/ -o ./bin/Test ./lib/Person.o ./src/Test.cpp

run:
	./bin/Test
