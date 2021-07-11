#ifndef KISI_HPP
#define KISI_HPP

#include "Sayi.hpp"

class Kisi{
	private:
		string isim;
	public:	
		Sayi *yas;
		Kisi(string,int);
		friend ostream& operator<<(ostream&,Kisi&);
		~Kisi();
};

#endif
