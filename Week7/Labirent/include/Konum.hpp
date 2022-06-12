#ifndef KONUM_HPP
#define KONUM_HPP

typedef enum{ ASAGI, SOL, YUKARI, SAG}Yon;


struct Konum{
	int x,y;
	Yon yon;
	Konum(int,int,Yon);
	Konum(int,int);
	Konum();
	Konum AyniYon();
	Konum SaatYonu(Yon);
	Konum Asagi();
	Konum Yukari();
	Konum Sol();
	Konum Sag();
	Yon TersYon();
};

#endif
