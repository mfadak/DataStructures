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

int MinGetir(int& x,int& y){
	return x < y ? x : y;
}

string MinGetir(string& x,string& y){
	return x < y ? x : y;
}

Sayi& MinGetir(Sayi &s1,Sayi &s2){
	return s1 < s2 ? s1 : s2;
}

int main(){
	int a=10,b=21;
	cout<<"Min Tamsayi:"<<MinGetir(a,b)<<endl;
	
	string str1="Uzay", str2="Yer";
	cout<<"Min String:"<<MinGetir(str1,str2)<<endl;
	
	Sayi *sayi1 = new Sayi(100);
	Sayi *sayi2 = new Sayi(200);
	cout<<"Min Sayi Nesnesi:"<<MinGetir(*sayi1,*sayi2)<<endl;
	
	
	delete sayi1;
	delete sayi2;
	return 0;
}
