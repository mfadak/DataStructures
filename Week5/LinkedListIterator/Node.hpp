#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
using namespace std;

template <typename Object>
class Node{
	public:	
		Object item;
		Node<Object> *next;
		Node(const Object& item=Object(),Node<Object> *nx=NULL){
			this->item=item;
			next=nx;
		}
};
#endif
