#pragma GCC diagnostic ignored "-Wdeprecated"
#include <cstdlib>
#include "DoublyLinkedList.hpp"

int main()
{
	DoublyLinkedList<string> *isimler = new DoublyLinkedList<string>();
	int sec=0;
	string isim;
	int konum;
	
	do{
		system("CLS");
		cout<<"1.Isim Ekle"<<endl;
		cout<<"2.Isim Sil"<<endl;
		cout<<"3.Konumdan Isim Sil"<<endl;
		cout<<"4.Konuma Isim Ekle"<<endl;
		cout<<"5.Konum Bul"<<endl;
		cout<<"6.Isim Sayisi"<<endl;
		cout<<"7.Ilk Isim"<<endl;
		cout<<"8.Son Isim"<<endl;
		cout<<"9.Isimleri Listele"<<endl;
		cout<<"10.Isimleri Temizle"<<endl;
		cout<<"11.Isimleri Belli Konumdan Tersten Yazdir"<<endl;
		cout<<"12.Listeyi Tersten Yazdir"<<endl;
		cout<<"13.Cikis"<<endl;
		cout<<"Secim:";
		cin>>sec;
		system("CLS");
		switch(sec){
			case 1:
				cout<<"Isim:";
				cin.ignore();
				getline(cin,isim);
				isimler->add(isim);
			break;
			case 2:
				cout<<"Isim:";
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
					cout<<"Isim:";
					cin.ignore();
					getline(cin,isim);
					isimler->insert(konum,isim);
			break;
			case 5:
					cout<<"Isim:";
					cin.ignore();
					getline(cin,isim);
					cout<<"Konum:"<<isimler->indexOf(isim);
					cin.ignore();
					cin.get();
			break;
			case 6:			
				cout<<"Isim Sayisi:"<<isimler->Count()<<endl;
				cin.ignore();
				cin.get();
			break;	
			case 7:
					cout<<"Ilk Isim:"<<isimler->first()<<endl;
					cin.ignore();
					cin.get();
			break;	
			case 8:
					cout<<"Son Isim:"<<isimler->last()<<endl;
					cin.ignore();
					cin.get();
			break;	
			case 9:			
				cout<<"ISIMLER:"<<endl;
				cout<<*isimler<<endl;
				cin.ignore();
				cin.get();
			break;	
			case 10:
				isimler->clear();
				cout<<endl<<"Tum isimler silindi."<<endl;
				cin.ignore();
				cin.get();
			break;
			case 11:
				cout<<"Konum:";
				cin>>konum;
				isimler->printNodesFromPositionInReverseOrder(konum);
				cin.ignore();
				cin.get();
			break;
			case 12:
				isimler->printReverseOrder();
				cin.ignore();
				cin.get();
			break;
			case 13:
			break;
			default:
				cout<<endl<<"Yanlis tercih!"<<endl;
				cin.ignore();
				cin.get();
			break;
		}
		system("CLS");
	}while(sec != 13);
	delete isimler;
}
