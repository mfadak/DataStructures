#ifndef DOUBLEHASHING_HPP
#define DOUBLEHASHING_HPP

#include <iostream>
using namespace std;

class DoubleHashing{
	private:
		int *Table;
		int size;
		int capacity;
		int R;
		
		int Hash1(int);
		int Hash2(int);
		bool isFull();
		bool isPrime(int);
	public:
		DoubleHashing(int);
		void Add(int);
		bool Search(int);
		bool Remove(int);
		void Clear();
		void Print();
		~DoubleHashing();
		
};

#endif
