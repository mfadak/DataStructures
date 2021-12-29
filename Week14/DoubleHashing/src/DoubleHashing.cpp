#include "DoubleHashing.hpp"

int DoubleHashing::Hash1(int number){
	return number % capacity;
}
int DoubleHashing::Hash2(int number){
	return R - (number % R);
}
bool DoubleHashing::isFull(){
	return size == capacity;
}
bool DoubleHashing::isPrime(int number)
{
	if (number <= 1) return false;
		  
	for (int i = 2; i < number; i++)
		if (number % i == 0) return false;
	return true;
}
DoubleHashing::DoubleHashing(int capacity){
	Table = new int[capacity];
	size=0;
	this->capacity = capacity;
	R = capacity-1;
	while(!isPrime(R)) R--;
	Clear();
}
void DoubleHashing::Add(int number){
	if(Search(number)) return;
	if(isFull()) throw "Error";
	int index = Hash1(number);
	if(Table[index] != -1){
		int step = Hash2(number);
		int i=1;
		while(true){
			int nIndex = (index+i*step) % capacity;
			if(Table[nIndex] == -1){
				Table[nIndex] = number;
				break;				
			}
			i++;
		}
	}
	else{
		Table[index] = number;
	}
	size++;
}
bool DoubleHashing::Search(int number){
	if(size == 0) return false;
	int index = Hash1(number);
	if(Table[index] == number) return true;
	int step = Hash2(number);
	int i=1;
	while(i<=size){
		int nIndex = (index+i*step) % capacity;
		if(Table[nIndex] == number) return true;
		i++;
	}
	return false;
}
bool DoubleHashing::Remove(int number){
	if(size == 0) return false;
	int index = Hash1(number);
	if(Table[index] == number){
		Table[index] = -1;
		size--;
		return true;
	}
	int step = Hash2(number);
	int i=1;
	while(i<=size){
		int nIndex = (index+i*step) % capacity;
		if(Table[nIndex] == number){
			Table[index] = -1;
			size--;
			return true;
		}
		i++;
	}
	return false;
}
void DoubleHashing::Clear(){
	for(int i=0;i<capacity;i++){
		Table[i] = -1;
	}
}
void DoubleHashing::Print(){
	for(int i=0;i<capacity;i++){
		if(Table[i] != -1) cout<<"Table["<<i<<"]:"<<Table[i]<<endl;
		else cout<<"Table["<<i<<"]:"<<endl;
	}
}
DoubleHashing::~DoubleHashing(){
	delete [] Table;
}
