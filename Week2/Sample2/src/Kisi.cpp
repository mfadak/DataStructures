#include "Kisi.hpp"

Kisi::Kisi(string isim,int ys){
	this->isim = isim;
	yas = new Sayi(ys);
}
Kisi::~Kisi(){
	delete yas;
}
ostream& operator<<(ostream& ekran,Kisi& sag){
	ekran<<sag.isim<<" "<<*sag.yas<<endl;
	return ekran;
}
