#include "Ogrenci.hpp"

int main(){
	Ogrenci o1(5,135,52);	
	cout<<"Ogrenci :"<<endl;
	cout<<"Yas :"<<o1.getYas()<<endl;	
	cout<<"Boy :"<<o1.getBoy()<<endl;	
	cout<<"Kilo :"<<o1.getKilo()<<endl;
	Sebze fasulye(1200);
	o1.YemekYe(fasulye);
	cout<<"Ogrenci :"<<endl;
	cout<<"Yas :"<<o1.getYas()<<endl;	
	cout<<"Boy :"<<o1.getBoy()<<endl;	
	cout<<"Kilo :"<<o1.getKilo()<<endl;
	return 0;
}
