hepsi: derle calistir

derle:
	mkdir -p lib
	mkdir -p bin
	g++ -I ./include/ -o ./lib/Ogrenci.o -c ./src/Ogrenci.cpp
	g++ -I ./include/ -o ./bin/Test ./lib/Ogrenci.o ./src/Test.cpp

calistir:
	./bin/Test
