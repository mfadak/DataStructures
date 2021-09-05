all: compile run

compile:
	g++ -I ./include/ -o ./lib/Postfix.o -c ./src/Postfix.cpp
	g++ -I ./include/ -o ./bin/Test ./lib/Postfix.o ./src/Test.cpp
	
run:
	./bin/Test
