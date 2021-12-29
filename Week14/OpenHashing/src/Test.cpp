#include "Hash.hpp"

int main(){
	int arr[]={20, 5, 13, 0, 7};
	Hash *hash = new Hash(11);
	for(int i=0;i<5;i++){
		hash->Add(arr[i]);
	}
	hash->Print();
	delete hash;
	return 0;
}
