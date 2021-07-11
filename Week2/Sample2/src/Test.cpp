#include "Kisi.hpp"

int main(){
	Kisi *ahmet = new Kisi("Ahmet",35);
	Kisi *mehmet = new Kisi("Mehmet",55);
	cout<<*ahmet;
	cout<<*mehmet;
	Sayi *yasYedek = ahmet->yas;
	ahmet->yas = mehmet->yas;
	mehmet->yas = yasYedek;
	cout<<*ahmet;
	cout<<*mehmet;
	delete ahmet;
	delete mehmet;
	return 0;
}
