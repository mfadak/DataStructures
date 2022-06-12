#include "Konum.hpp"

Konum::Konum(int x,int y, Yon yon){
	this->x = x;
	this->y = y;
	this->yon = yon;
}
Konum::Konum(int x,int y){
	this->x = x;
	this->y = y;
	this->yon = ASAGI;
}
Konum::Konum(){
	x=0;
	y=0;
	yon=ASAGI;
}
Konum Konum::AyniYon(){
	switch(yon){
		case YUKARI:
			return Yukari();
		case SAG:
			return Sag();
			case ASAGI:
			return Asagi();
		default:
			return Sol();
	}
}
Konum Konum::SaatYonu(Yon yn){
	switch(yn){
		case YUKARI:
			return Sag();
		case SAG:
			return Asagi();
		case ASAGI:
			return Sol();
		default:
			return Yukari();
	}
}
Konum Konum::Asagi(){
	return Konum(x+1,y,ASAGI);
}
Konum Konum::Yukari(){
	return Konum(x-1,y,YUKARI);
}
Konum Konum::Sol(){
	return Konum(x,y-1,SOL);
}
Konum Konum::Sag(){
	return Konum(x,y+1,SAG);
}	
Yon Konum::TersYon(){
	if(yon == ASAGI) return YUKARI;
	if(yon == YUKARI) return ASAGI;
	if(yon == SOL) return SAG;
	if(yon == SAG) return SOL;
	return YUKARI;
}
