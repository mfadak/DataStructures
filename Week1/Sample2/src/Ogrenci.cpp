#include "Ogrenci.hpp"

Ogrenci::Ogrenci(int ys,double by){
	yas=ys;
	boy=by;
}
Ogrenci::Ogrenci(){
	yas=0;
	boy=30;
}
void Ogrenci::YasIlerle(int ys){
	yas+=ys;
}
void Ogrenci::BoyUza(double by){
	boy+=by;
}
int Ogrenci::getYas(){
	return yas;
}
double Ogrenci::getBoy(){
	return boy;
}
Ogrenci::~Ogrenci(){
  	cout<<"Cagrildi"<<endl;
}
Ogrenci::Ogrenci(int ys,double by,double kl){
	yas=ys;
	boy=by;
	kilo=kl;
}
double Ogrenci::getKilo(){
	return kilo;
}
void Ogrenci::YemekYe(Sebze yemek){
	kilo += yemek.getKalori()/1000;
}
