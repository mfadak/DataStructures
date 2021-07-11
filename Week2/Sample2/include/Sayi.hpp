#ifndef SAYI_HPP
#define SAYI_HPP

#include <iostream>
using namespace std;

class Sayi{
	private:
		int *pdeger;
	public:
		Sayi(int);
		Sayi();
		friend ostream& operator<<(ostream&,Sayi&);
		~Sayi();
};

#endif
