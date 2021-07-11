#include "Sayi.hpp"

Sayi::Sayi(int dgr){
	pdeger = new int(dgr);
}
Sayi::Sayi(){
	pdeger = new int(0);
}
ostream& operator<<(ostream& ekran,Sayi& sag){
	ekran<<*sag.pdeger<<endl;
	return ekran;
}
Sayi::~Sayi(){
	delete pdeger;
}
