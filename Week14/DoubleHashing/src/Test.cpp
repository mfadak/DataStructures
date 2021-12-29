#include "DoubleHashing.hpp"

int main(){
	int arr[]={20, 5, 13, 0, 7};
	DoubleHashing *hash = new DoubleHashing(7);
	for(int i=0;i<5;i++){
		hash->Add(arr[i]);
	}
	hash->Print();
	delete hash;
	return 0;
}
