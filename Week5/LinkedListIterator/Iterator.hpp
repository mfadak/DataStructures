#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>
using namespace std;

#include "Node.hpp"

template <typename Object>
class Iterator{
	private:
		Node<Object> *head;	
		Node<Object> *current;
		Node<Object> *prev;
	
	public:
		Iterator(){
			head=NULL;
			current=NULL;
			prev=NULL;
		}
		Iterator(Node<Object> *head){
			this->current=head->next;
			this->head = head;
			prev=NULL;
		}
		bool hasNext(){
			return current != NULL;
		}
		Object next(){
			if(current == NULL) throw "NULL Reference";
			prev=current;
			current = current->next;
			return prev->item;
		}
		void remove(){
			if(prev == NULL) throw "NULL Reference";
			Node<Object> *itr=head;
			for(;itr->next != prev;itr=itr->next){ }
			Node<Object> *del = itr->next;
			itr->next = itr->next->next;
			delete del;	
			prev=NULL;
		}
};

#endif
