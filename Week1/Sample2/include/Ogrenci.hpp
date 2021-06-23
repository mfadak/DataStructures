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
		Ogrenci(int ys,double by){
			yas=ys;
			boy=by;
		}
		Ogrenci(){
			yas=0;
			boy=30;
		}
		void YasIlerle(int ys){
			yas+=ys;
		}
		void BoyUza(double by){
			boy+=by;
		}
		int getYas(){
			return yas;
		}
		double getBoy(){
			return boy;
		}
		~Ogrenci(){
			cout<<"Cagrildi"<<endl;
		}
		Ogrenci(int ys,double by,double kl){
			yas=ys;
			boy=by;
			kilo=kl;
		}
		double getKilo(){
			return kilo;
		}
		void YemekYe(Sebze yemek){
			kilo += yemek.getKalori()/1000;
		}
};

#endif
