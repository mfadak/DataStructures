#include "Postfix.hpp"

int main(){
	string infix;
	cout<<"Type Infix:";
	cin>>infix;
	Postfix *postfix = new Postfix(infix);
	cout<<"Postfix: "<<*postfix<<endl;
	cout<<"Result: "<<postfix->Calculate()<<endl;
	
	delete postfix;
	return 0;
}
