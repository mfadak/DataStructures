#include <cstdlib>
#include "HeapTree.hpp"

int main(){
	int *array = new int[25];
	cout<<"Array before ordered:"<<endl;
	for(int i=0;i<25;i++){
		array[i] = rand()%100+1;
		cout<<array[i]<<" ";
	}
	
	HeapTree *heap = new HeapTree(array,25);
	delete [] array;
	array = heap->Sort();
	cout<<endl<<"Ordered Array:"<<endl;
	for(int i=0;i<25;i++){
		cout<<array[i]<<" ";
	}
	cout<<endl;
	delete [] array;
	delete heap;
	return 0;
}
