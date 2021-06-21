#ifndef OGRENCI_HPP
#define OGRENCI_HPP

#include <iostream>
using namespace std;
class Ogrenci{
	private:
		int yas;
		double boy;
	public:
		Ogrenci(int,double);
		Ogrenci();
		void YasIlerle(int);
		void BoyUza(double);
		int getYas();
		double getBoy();
		~Ogrenci();
};

#endif
