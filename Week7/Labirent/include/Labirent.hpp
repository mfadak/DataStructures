#ifndef LABIRENT_HPP
#define LABIRENT_HPP

#include <fstream>
#include <iomanip>
#include "Windows.h"
#include <sstream>

#include "Konum.hpp"
#include "Stack.hpp"
#define YUKSEKLIK 20
#define GENISLIK 50

class Labirent{
	public:
		char harita[YUKSEKLIK][GENISLIK];
		int x,y;
		Yon yon;
		Konum bitis;
		Stack<Konum> *yigit;
		
		Labirent(Konum, Konum);
		Konum mevcutKonum();
		bool adimAt(Konum, Konum);
		void ayarla(Konum,Yon);
		bool CikisaGeldimi();
		bool EngelVarmi(Konum);		
		string yaz();
};

#endif
