#include <cstdlib>
#include "LinkedList.hpp"
#include "Esya.hpp"
int main()
{
	LinkedList<Esya> *esyalar = new LinkedList<Esya>();
	esyalar->add(Esya("Masa",30,20));
	esyalar->add(Esya("Sandalya",15,10));
	esyalar->add(Esya("Kitap",2,5));
	esyalar->add(Esya("Defter",1,5));
	Iterator<Esya> itr = esyalar->iterator();
	
	double maksKilo;
	cout<<"Maks Kilo:";
	cin>>maksKilo;
	
	while(itr.hasNext()){
		Esya esya = itr.next();
		if(esya.getKilo() > maksKilo) itr.remove();
	}
	cout<<*esyalar;
	delete esyalar;
	return 0;
}
