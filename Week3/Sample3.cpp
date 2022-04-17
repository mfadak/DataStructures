#include <iostream>
using namespace std;

class Kisi{
	private:
		string isim;
		int yas;
	public:
		Kisi(string isim,int yas){
			this->isim = isim;
			this->yas = yas;
		}
		friend ostream& operator<<(ostream& ekran,Kisi& sag){
			ekran<<sag.isim<<" ("<<sag.yas<<")"<<endl;
			return ekran;
		}
};
int main(){
	Kisi **kisiler = new Kisi*[3];
	kisiler[0] = new Kisi("Ahmet",55);
	kisiler[1] = new Kisi("Mehmet",18);
	kisiler[2] = new Kisi("Ali",32);
		
	for(int i=0;i<3;i++){
		cout<<*kisiler[i];
		delete kisiler[i];
	}
	delete [] kisiler;
	return 0;
}
