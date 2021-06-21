#ifndef OGRENCI_HPP
#define OGRENCI_HPP

#include <iostream>
using namespace std;

class Ogrenci{
	private:
		int yas;
		double boy;
		double kilo;
	public:
		Ogrenci(int,double,double);
		Ogrenci();
		void YasIlerle(int);
		void BoyUza(double);
		int getYas();
		double getBoy();
		void yemekYe(Sebze);
		double getKilo()const; 
		~Ogrenci();
};

#endif
