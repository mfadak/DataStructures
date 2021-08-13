#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
using namespace std;

template <typename Object>
class Node{
	public:
		Object data;
		Node<Object> *next;
		Node<Object> *prev;
		
		Node(const Object data,Node<Object> *next=NULL,Node<Object> *prev=NULL){
			this->data = data;
			this->next = next;
			this->prev = prev;
		}
};


#endif
