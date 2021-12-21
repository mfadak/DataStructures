#include "Huffman.hpp"

int main(){
	Huffman *huffman = new Huffman("Data.txt");
	huffman->Encode();
	cout<<*huffman<<endl;
	delete huffman;
}
