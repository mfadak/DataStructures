#include <iostream>
using namespace std;

class Sayi{
	public:
		int deger;
		Sayi(int deger){
			this->deger = deger;
		}
		Sayi(){
			deger=0;
		}
		bool operator<(Sayi& sag){
			return this->deger < sag.deger;
		}
		friend ostream& operator<<(ostream& ekran,Sayi& sag){
			ekran << sag.deger;
			return ekran;
		}
};

template <typename Tur>
Tur MinGetir(Tur& t1, Tur& t2){
	return t1 < t2 ? t1 : t2;
}

int main(){
	int a=10,b=21;
	cout<<"Min Tamsayi:"<<MinGetir<int&>(a,b)<<endl;
	
	string str1="Uzay", str2="Yer";
	cout<<"Min String:"<<MinGetir<string&>(str1,str2)<<endl;
	
	Sayi *sayi1 = new Sayi(100);
	Sayi *sayi2 = new Sayi(200);
	cout<<"Min Sayi Nesnesi:"<<MinGetir<Sayi&>(*sayi1,*sayi2)<<endl;
	
	
	delete sayi1;
	delete sayi2;
	return 0;
}
