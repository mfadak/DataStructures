#include "Radix.hpp"

int main(){
	int sayilar[] = {167,32,19,356,478,951,5,98,301,7,490};
	Radix *radix = new Radix(sayilar,11);
	int *sirali = radix->Sort();
	cout<<"Siralanmadan Onceki Hali:"<<endl;
	for(int i=0;i<11;i++){
		cout<<sayilar[i]<<" ";
	}
	cout<<endl<<endl<<"Siralandiktan Sonraki Hali:"<<endl;
	for(int i=0;i<11;i++){
		cout<<sirali[i]<<" ";
	}
	
	delete [] sirali;
	delete radix;
	return 0;
}
