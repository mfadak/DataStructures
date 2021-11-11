#include "BaseConverter.hpp"

string BaseConverter::Convert(){
	int vl=value;
	string digits = "0123456789ABCDEF";
	string str="";
	Stack<int> *stack = new Stack<int>();

	while(vl > 0){
		int remain = vl % base;
		stack->push(remain);
		vl = vl / base;
	}
	
	while(!stack->isEmpty()){
		str = str + digits[stack->top()];
		stack->pop();
	}
	delete stack;
	return str;
}
BaseConverter::BaseConverter(){
	cin>>*this;
	converted=Convert();
}
int BaseConverter::getValueBase10()const{
	return value;
}
ostream& operator<<(ostream& screen,BaseConverter &rgt){
	screen<<"("<<rgt.value<<")10"<<"="<<"("<<rgt.converted<<")"<<rgt.base;
	return screen;
}	
istream& operator>>(istream& in,BaseConverter &rgt){
	cout<<"Value:";
	in>>rgt.value;
	cout<<"Base:";
	in>>rgt.base;
	return in;
}
