#include "HeapTree.hpp"

int HeapTree::LeftChildIndex(int index){
	return 2*index+1;
}
int HeapTree::RightChildIndex(int index){
	return 2*index+2;
}
int HeapTree::ParentIndex(int index){
	return (index-1)/2;
}
void HeapTree::HeapfyUp(int index){
	int parentIndex;
	if(index != 0){
		parentIndex = ParentIndex(index);
		if(items[parentIndex] > items[index]){
			Swap(items[parentIndex],items[index]);
			HeapfyUp(parentIndex);
		}
	}
}
void HeapTree::HeapfyDown(int index){
	int leftChildIndex,rightChildIndex,minIndex;
	leftChildIndex = LeftChildIndex(index);
	rightChildIndex = RightChildIndex(index);
	
	if(rightChildIndex >= length){
		if(leftChildIndex >= length) return;
		else minIndex = leftChildIndex;
	}
	else{
		if(items[leftChildIndex] <= items[rightChildIndex])
			minIndex = leftChildIndex;
		else
			minIndex = rightChildIndex;
	}
	if(items[index] > items[minIndex]){
		Swap(items[minIndex],items[index]);
		HeapfyDown(minIndex);
	}
}
void HeapTree::Swap(int& x,int& y){
	int tmp = x;
	x=y;
	y=tmp;
}
	
HeapTree::HeapTree(int capacity){
	items = new int[capacity];
	this->capacity = capacity;
	length=0;
}
bool HeapTree::IsEmpty(){
	return length == 0;
}
void HeapTree::Add(int item){
	if(length == capacity) throw "Capacity Error";
	items[length] = item;
	length++;
	HeapfyUp(length-1);
}
int HeapTree::RemoveMin(){
	if(IsEmpty()) throw "No element found";
	int minItem = items[0];
	items[0] = items[length - 1];
	length--;
	if(length > 0) HeapfyDown(0);
	return minItem;
}
HeapTree::~HeapTree(){
	delete [] items;
}
