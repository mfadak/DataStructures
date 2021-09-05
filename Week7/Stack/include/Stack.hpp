#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
using namespace std;

template <typename Object>
class Node{
	public:
		Object item;
		Node<Object> *next;
		
		Node(const Object& item,Node<Object> *next=NULL){
			this->item = item;
			this->next = next;
		}
};

template <typename Object>
class Stack{
	private:
		Node<Object> *topOfStack;
		
	public:
		Stack(){
			topOfStack=NULL;
		}
		bool isEmpty()const{
			return topOfStack == NULL;
		}
		void push(const Object& item){
		 topOfStack	= new Node<Object>(item,topOfStack);
		}
		void pop(){
			if(isEmpty()) throw "Stack is Empty";
			Node<Object> *tmp = topOfStack;
			topOfStack = topOfStack->next;
			delete tmp;
		}
		const Object& top()const{
			if(isEmpty()) throw "Stack is Empty";
			return topOfStack->item;
		}
		void makeEmpty(){
			while(!isEmpty()) pop();
		}
		~Stack(){
			makeEmpty();
		}

};

#endif
