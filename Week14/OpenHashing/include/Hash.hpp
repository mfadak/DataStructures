#ifndef HASH_HPP
#define HASH_HPP

#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
	
	Node(int dt,Node *nx=NULL){
		this->data = dt;
		this->next = nx;
	}
};

class Hash{
	private:
		Node **Table;
		int capacity;
		int HashCode(int);
	public:
		Hash(int);
		void Add(int);
		bool Remove(int);
		void Clear();
		bool Search(int);
		bool isEmpty();
		void Print();
		~Hash();
};

#endif
