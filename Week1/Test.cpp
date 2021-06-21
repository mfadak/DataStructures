#include "Ogrenci.hpp"
int main(){
	Ogrenci o1,o2(5,135);
	cout<<"Ogrenci 1:"<<endl;
	cout<<"Yas :"<<o1.getYas()<<endl;	
	cout<<"Boy :"<<o1.getBoy()<<endl;
	cout<<"Ogrenci 2:"<<endl;
	cout<<"Yas :"<<o2.getYas()<<endl;	
	cout<<"Boy :"<<o2.getBoy()<<endl;
	o1.YasIlerle(15);
	o2.BoyUza(25);
	
	cout<<"---------------"<<endl<<"Ogrenci 1:"<<endl;
	cout<<"Yas :"<<o1.getYas()<<endl;	
	cout<<"Boy :"<<o1.getBoy()<<endl;
	cout<<"Ogrenci 2:"<<endl;
	cout<<"Yas :"<<o2.getYas()<<endl;	
	cout<<"Boy :"<<o2.getBoy()<<endl;
	return 0;
}
