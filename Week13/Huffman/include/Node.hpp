#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
using namespace std;

struct Node{
	char chracter;
	int freq;
	string code;
	
	Node *left;
	Node *right;
	
	Node(char ch,int frq,Node *lf=NULL,Node *rg=NULL);
	bool isLeaf()const;
	bool operator==(Node&);
	bool operator!=(Node&);
	bool operator>(Node&);
};

#endif
