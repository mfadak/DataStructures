#include "LinkedList.hpp"

int main(){
	LinkedList<string> *isimler = new LinkedList<string>();
	int sec,konum;
	string isim;
	
	do{
		system("CLS");
		cout<<"1.isim Ekle"<<endl;
		cout<<"2.isim Sil"<<endl;
		cout<<"3.Konumdan isim Sil"<<endl;
		cout<<"4.Konuma isim Ekle"<<endl;
		cout<<"5.Konum Bul"<<endl;
		cout<<"6.isim Sayisi"<<endl;
		cout<<"7.ilk isim"<<endl;
		cout<<"8.son isim"<<endl;
		cout<<"9.isimleri listele"<<endl;
		cout<<"10.isimleri temizle"<<endl;
		cout<<"11.isim Ara"<<endl;
		cout<<"12.Cikis"<<endl;
		cout<<"Secim:";
		cin>>sec;
		switch(sec){
			case 1:
				cout<<"isim:";
				cin.ignore();
				getline(cin,isim);
				isimler->add(isim);
			break;
			case 2:
				cout<<"isim:";
				cin.ignore();
				getline(cin,isim);
				isimler->remove(isim);
			break;
			case 3:
				cout<<"Konum:";
				cin>>konum;
				isimler->removeAt(konum);
				break;
			case 4:
				cout<<"Konum:";
				cin>>konum;
				cout<<"isim:";
				cin.ignore();
				getline(cin,isim);
				isimler->insert(konum,isim);
				break;
			case 5:
				cout<<"isim:";
				cin.ignore();
				getline(cin,isim);
				cout<<"Konum:"<<isimler->indexOf(isim)<<endl;
				cin.ignore();
				cin.get();
				break;
			case 6:
				cout<<"isim Sayisi:"<<isimler->size()<<endl;
				cin.ignore();
				cin.get();
				break;
			case 7:
				cout<<"ilk isim:"<<isimler->first()<<endl;
				cin.ignore();
				cin.get();
				break;
			case 8:
				cout<<"son isim:"<<isimler->last()<<endl;
				cin.ignore();
				cin.get();
				break;
			case 9:
				cout<<"isimler:"<<endl;
				cout<<*isimler;
				cin.ignore();
				cin.get();
				break;
			case 10:
				isimler->clear();
				break;
			case 11:
				cout<<"isim:";
				cin.ignore();
				getline(cin,isim);
				if(isimler->find(isim)) cout<<"isim var"<<endl;
				else cout<<"isim yok"<<endl;
				cin.ignore();
				cin.get();
				break;
			case 12:
				break;
			default:
				cout<<"Hatali Secim"<<endl;
				cin.ignore();
				cin.get();
				break;		
		}
	}while(sec != 12);
	
	
	
	delete isimler;
	return 0;
}
