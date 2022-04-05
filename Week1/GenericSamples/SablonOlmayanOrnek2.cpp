#include <iostream>
using namespace std;

class Kutu{
	public:
		int icerik;
		Kutu(int icerik){
			this->icerik = icerik;
		}
		Kutu(){
			this->icerik = int();
		}
		friend ostream& operator<<(ostream& ekran,Kutu& sag){
			ekran << sag.icerik;
			return ekran;
		}

};

int main(){
	int a=100;
	
	Kutu *kutu1 = new Kutu(a);
	cout<<*kutu1;
	
	delete kutu1;
	return 0;
}
