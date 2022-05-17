#include <cstdlib>
#include "LinkedList.hpp"

int main()
{
	LinkedList<string> *names = new LinkedList<string>();
	int choice=0;
	string name;
	int position;
	do{
		system("CLS");
		cout<<"[1]\tAdd Name"<<endl;
		cout<<"[2]\tRemove Name"<<endl;
		cout<<"[3]\tRemove From Position"<<endl;
		cout<<"[4]\tInsert Name"<<endl;
		cout<<"[5]\tFind Position"<<endl;
		cout<<"[6]\tNumber of Names"<<endl;
		cout<<"[7]\tFirst Name"<<endl;
		cout<<"[8]\tLast Name"<<endl;
		cout<<"[9]\tList Names"<<endl;
		cout<<"[10]\tClear Names"<<endl;
		cout<<"[11]\tExit"<<endl;
		cout<<"Choice:";
		cin>>choice;
		system("CLS");
		switch(choice){
			case 1:
				cout<<"Name:";
				cin.ignore();
				getline(cin,name);
				names->add(name);
			break;
			case 2:
				cout<<"Name:";
				cin.ignore();
				getline(cin,name);
				names->remove(name);	
			break;
			case 3:
				cout<<"Position:";
				cin>>position;
				names->removeAt(position);
			break;
			case 4:
				cout<<"Position:";
				cin>>position;
				cout<<"Name:";
				cin.ignore();
				getline(cin,name);
				names->insert(position,name);
			break;
			case 5:
				cout<<"Name:";
				cin.ignore();
				getline(cin,name);
				cout<<"Konum:"<<names->indexOf(name);
				cin.get();
			break;
			case 6:			
				cout<<"Number of Names"<<names->Count()<<endl;
				cin.ignore();
				cin.get();
			break;	
			case 7:
				cout<<"First Name:"<<names->first()<<endl;
				cin.ignore();
				cin.get();
			break;	
			case 8:
				cout<<"Last Name:"<<names->last()<<endl;
				cin.ignore();
				cin.get();
				
			break;	
			case 9:			
				cout<<"Names:"<<endl;
				cout<<*names<<endl;
				cin.ignore();
				cin.get();
			break;	
			case 10:
				names->clear();
				cout<<endl<<"All names removed"<<endl;
				cin.ignore();
				cin.get();
			break;
			case 11:
			break;
			default:
				cout<<endl<<"Wrong choice!!"<<endl;
				cin.ignore();
				cin.get();
			break;
		}
		system("CLS");
	}while(choice != 11);
	delete names;
}
