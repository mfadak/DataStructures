#include "Queue.hpp"
#include <cmath>

int BasamakSayisi(int sayi){
	sayi = abs(sayi);
	int basamak=0;
	while(sayi>0){
		basamak++;
		sayi /= 10;
	}
	return basamak;
}
int EnYuksekBasamakSayisi(int *items,int length){
	int max=0;
	for(int i=0;i<length;i++){
		if(BasamakSayisi(items[i])>max) max = BasamakSayisi(items[i]);
	}
	return max;
}

int* RadixSort(int *items,int length){
	Queue<int> **queues = new Queue<int>*[10];
	for(int i=0;i<10;i++) queues[i] = new Queue<int>();
	int maksBasamak = EnYuksekBasamakSayisi(items,length);
	int sayiIndex=0;
	for(int i=0;i<maksBasamak;i++){
		for(int index=0;index<10;index++){
			if(sayiIndex<length){				
				int basamakDegeri = items[sayiIndex]%10;
				queues[basamakDegeri]->enqueue(items[sayiIndex++]);			
			}
			else
			{
				for(int len=queues[index]->count();len>0;len--){
					int sayi = queues[index]->peek();
					queues[index]->dequeue();
					int basamakDegeri = (sayi/(int)pow(10,i))%10;
					queues[basamakDegeri]->enqueue(sayi);
				}
			}
		}
	}
	int* sirali = new int[length];
	sayiIndex=0;
	for(int index=0;index<10;index++){
		while(!queues[index]->isEmpty()){
			int sayi = queues[index]->peek();
			sirali[sayiIndex++] = sayi;
			queues[index]->dequeue();
		}
	}
	
	for(int i=0;i<10;i++) delete queues[i];
	delete [] queues;
	return sirali;
}

int main(){
	int sayilar[] = {167,32,19,356,478,951,5,98,301,7};
	int *sirali = RadixSort(sayilar,10);
	cout<<"Siralanmadan Onceki Hali:"<<endl;
	for(int i=0;i<10;i++){
		cout<<sayilar[i]<<" ";
	}
	cout<<endl<<endl<<"Siralandiktan Sonraki Hali:"<<endl;
	for(int i=0;i<10;i++){
		cout<<sirali[i]<<" ";
	}
	
	delete [] sirali;
	return 0;
}
