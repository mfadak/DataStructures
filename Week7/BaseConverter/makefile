all: compile run

compile:
	g++ -I ./include/ -o ./lib/BaseConverter.o -c ./src/BaseConverter.cpp
	g++ -I ./include/ -o ./bin/Test ./lib/BaseConverter.o ./src/Test.cpp
	
run:
	./bin/Test
