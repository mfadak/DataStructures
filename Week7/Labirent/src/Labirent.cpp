#include "Labirent.hpp"

Labirent::Labirent(Konum baslangic, Konum bitis){
	FILE* fp = fopen("Harita.txt", "r");
	unsigned char karakter = 0;
	int satir=0,sutun=0;
	x = baslangic.x;
	y = baslangic.y;
	this->bitis = bitis;
	yon = ASAGI;
	yigit = new Stack<Konum>();
	yigit->push(Konum(-1,-1,yon));
	while (!feof(fp)) {
	   karakter = getc(fp);
	   if(karakter == 255) break;
	   if(karakter == 10){
		 satir++;
		 sutun=0;
	   }
	   else{
			harita[satir][sutun] = karakter;
			sutun++;
	   }
	}
}
Konum Labirent::mevcutKonum(){
	return Konum(x,y,yon);
}
bool Labirent::adimAt(Konum mevcut, Konum ileri){
	if(!EngelVarmi(ileri)){
		yigit->push(mevcut);
		ayarla(ileri,ileri.yon);
		return true;
	}
	return false;
}
void Labirent::ayarla(Konum konum,Yon yon){
	system("cls");
	this->x = konum.x;
	this->y = konum.y;
	this->yon = yon;
	harita[konum.x][konum.y] = '-';
	cout<<yaz();
	Sleep(30);
}
bool Labirent::CikisaGeldimi(){
	return x == bitis.x && y == bitis.y;
}
bool Labirent::EngelVarmi(Konum konum){			
	if(konum.x >= YUKSEKLIK || konum.x < 0 || konum.y >= GENISLIK || konum.y < 0) return false;
	return harita[konum.x][konum.y] == '#' || harita[konum.x][konum.y] == '-';
}
	
string Labirent::yaz(){
	char YonChr[] = {31,17,30,16};
	stringstream ss;
	for(int satir=0;satir<YUKSEKLIK;satir++){
		ss<<setw(10);
		for(int sutun=0;sutun<GENISLIK;sutun++){
			if(satir == x && sutun == y){
				ss<<YonChr[yon];
			}
			else{
				 if(harita[satir][sutun] == '-') ss<<' ';
				 else ss<<harita[satir][sutun];
			}
		}	
		ss<<endl;				
	}
	return ss.str();
}
