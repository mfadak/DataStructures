#include "Labirent.hpp"

int main(){
	Labirent *labirent = new Labirent(Konum(0,20),Konum(19,11));
	
	labirent->yigit->push(Konum(labirent->x,labirent->y,ASAGI));
	labirent->ayarla(Konum(labirent->x,labirent->y,ASAGI).Asagi(),ASAGI);	
	while(!labirent->CikisaGeldimi()){
		int denemeYonSayisi=1;
		Konum oncekiKonum = labirent->yigit->top();
		Konum mevcutKonum = labirent->mevcutKonum();
		
		Konum ileri = mevcutKonum.AyniYon();
		
		if(!labirent->adimAt(mevcutKonum,ileri)){
			int i=0;
			bool sonuc = false;
			Konum yeni = mevcutKonum;
			while(!sonuc && denemeYonSayisi<5){	
				yeni = mevcutKonum.SaatYonu((Yon)((mevcutKonum.yon+i)%4));		
								
				i++;
				denemeYonSayisi++;
				if(yeni.yon == mevcutKonum.TersYon()){
					sonuc=false;
				}
				else{
					sonuc = labirent->adimAt(mevcutKonum,yeni);
				}
			}
			if(denemeYonSayisi == 5){
				labirent->yigit->pop();
				labirent->ayarla(oncekiKonum,oncekiKonum.TersYon());
			}
		}
		
	}
	
	cout<<"CIKISA GELDI"<<endl;
	
	getchar();
	
	delete labirent;
	return 0;
}
