#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <iostream>
using namespace std;
template <typename Object>
class Queue{
	private:
		int front;
		int back;
		int capacity;
		int length;
		Object *items;
		
		void reserve(int newCapacity){
			Object *temp = new Object[newCapacity];
			for(int i=front,j=0;j<length; j++){
				temp[j] = items[i]; 
				i = (i + 1) % capacity;
			}
			capacity = newCapacity;
			delete[] items;
			items = temp;
			front = 0;
			back = length - 1;
		}
	public:
		Queue(){
			capacity=1;
			front=0;
			back=-1;
			length=0;			
			items=new Object[capacity];
		}
		void clear(){			
			front=0;
			back=-1;
			length=0;
		}
		int count() const{
			return length;
		}
		bool isEmpty() const {
			if(length == 0) return true;
			return false;
		}
		/// Kuyrukta en öndeki elemanı getirir
		const Object& peek(){
			if(isEmpty()) throw "Empty List";
			return items[front];
		}
		void enqueue(const Object& item){
			if(length == capacity) reserve(2*capacity);
			back = (back + 1) % capacity;
			items[back] = item;
			length++;
		}
		void dequeue(){
			if(isEmpty()) throw "Empty List";			
			front = (front + 1) % capacity;
			length--;
		}
		~Queue(){
			delete[] items;
		}		
};
#endif
