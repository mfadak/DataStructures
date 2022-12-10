#ifndef HEAPTREE_HPP
#define HEAPTREE_HPP

#include <iostream>
using namespace std;

class HeapTree{
	private:
		int *items;
		int length;
		int capacity;
		
		int LeftChildIndex(int);
		int RightChildIndex(int);
		int ParentIndex(int);
		void HeapfyUp(int);
		void HeapfyDown(int);
		void Swap(int&,int&);
		bool IsEmpty();
		void Add(int);
		int RemoveMin();
	public:
		HeapTree(int*,int);
		int* Sort();
		~HeapTree();
};

#endif
