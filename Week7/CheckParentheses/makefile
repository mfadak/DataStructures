all: compile run

compile:
	g++ -I ./include/ -o ./lib/Text.o -c ./src/Text.cpp
	g++ -I ./include/ -o ./bin/Test ./lib/Text.o ./src/Test.cpp
	
run:
	./bin/Test
