hepsi: derle calistir

derle:
	rm -rf lib
	rm -rf bin
	mkdir lib
	mkdir bin
	g++ -I ./include/ -o ./lib/Ogrenci.o -c ./src/Ogrenci.cpp
	g++ -I ./include/ -o ./bin/Test ./lib/Ogrenci.o ./src/Test.cpp

calistir:
	./bin/Test
