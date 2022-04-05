#include <iostream>
using namespace std;

template <typename Tur>
class Kutu{
	public:
		Tur icerik;
		Kutu(Tur icerik){
			this->icerik = icerik;
		}
		Kutu(){
			this->icerik = Tur();
		}
		friend ostream& operator<<(ostream& ekran,Kutu& sag){
			ekran << sag.icerik;
			return ekran;
		}

};

int main(){
	int a=100;
	
	Kutu<int> *kutu1 = new Kutu<int>(a);
	cout<<*kutu1<<endl;
	
	string str="Uzay";	
	Kutu<string> *kutu2 = new Kutu<string>(str);
	cout<<*kutu2<<endl;
	
	Kutu<Kutu<int>> *kutu3 = new Kutu<Kutu<int>>(*kutu1);
	cout<<*kutu3<<endl;
	
	delete kutu1;
	delete kutu2;
	delete kutu3;
	return 0;
}
