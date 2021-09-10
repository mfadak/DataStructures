#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
using namespace std;

template <typename Object>
class Node{
	public:
		Object item;
		Node<Object> *next;
		
		Node(Object item,Node<Object> *next=NULL){
			this->item = item;
			this->next = next;
		}
};

template <typename Object>
class Queue{
	private:
		Node<Object> *front;
		Node<Object> *back;		
		int length;
		
		Node<Object>* previousMaxNode(){
			Node<Object> *prev = NULL;
			Node<Object> *tmp = front;
			Object max=front->item;
			while(tmp->next != NULL){
				if(tmp->next->item > max){
					max = tmp->next->item;
					prev=tmp;
				}
				tmp = tmp->next;
			}
			return prev;
		}
	public:
		Queue(){
			front=back=NULL;
			length=0;
		}
		int count()const{
			return length;
		}
		bool isEmpty()const{
			return length == 0;
		}
		void enqueue(const Object& item){
			Node<Object> *last = new Node<Object>(item);
			if(isEmpty()) front = back = last;
			else{
				back->next = last;
				back = back->next;
			}
			length++;
		}
		void dequeue(){
			if(isEmpty()) throw "Queue is Empty";
			Node<Object> *tmp = front;
			front=front->next;
			delete tmp;
			length--;
		}		
		void dequeueMax(){
			if(isEmpty()) throw "Queue is Empty";
			Node<Object> *prev = previousMaxNode();
			Node<Object> *tmp;
			if(prev == NULL) dequeue();
			else{
				if(prev->next == back) back=prev;
				tmp=prev->next;
				prev->next = prev->next->next;
				delete tmp;
				length--;
			}
		}
		void clear(){
			while(!isEmpty())dequeue();
		}
		Object& peek()const{
			if(isEmpty()) throw "Queue is Empty";
			return front->item;
		}
		Object& peekMax(){
			if(isEmpty()) throw "Queue is Empty";
			Node<Object> *prev = previousMaxNode();
			if(prev == NULL) return peek();
			return prev->next->item;
		}
		~Queue(){
			clear();
		}
};

#endif
