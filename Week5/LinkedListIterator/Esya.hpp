#ifndef ESYA_HPP
#define ESYA_HPP

#include <iostream>
using namespace std;

class Esya{
	private:
		string isim;
		double hacim;
		double kilo;
	public:
		Esya(string isim, double kilo, double hacim){
			this->isim = isim;
			this->hacim = hacim;
			this->kilo = kilo;
		}
		Esya(){
			this->isim = "";
			this->hacim = 0;
			this->kilo = 0;
		}
		double getKilo(){
			return kilo;
		}
		bool operator!=(Esya &sag){
			return this->isim != sag.isim;
		}
		bool operator==(Esya &sag){
			return this->isim == sag.isim;
		}
		friend ostream& operator<<(ostream& ekran,Esya& sag){
			ekran<<"\n"<<sag.isim<<" "<<sag.kilo<<" kg Hacim: "<<sag.hacim;
			return ekran;
		}
};

#endif
