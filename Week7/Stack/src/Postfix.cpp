#include "Postfix.hpp"

bool Postfix::IsPriorityLow(char op1,char op2){
	if(op1 == '(') return false;
	else if(op2 == '(') return false;
	else if(op2 == ')') return true;
	else if(op1 == '*' || op1 == '/') return true;
	else if(op2 == '*' || op2 == '/') return false;
	else return true;	
}
void Postfix::CopyPostfix(Stack<char>* stack,string& postfix){
	postfix += stack->top();
	postfix += " ";
	stack->pop();
}
string Postfix::infixToPostfix(string infix){
	int length = infix.length();
	Stack<char> *stack = new Stack<char>();
	string postfix = "";
	
	for(int i=0;i<length;i++){
		if(isdigit(infix[i])){
			while(isdigit(infix[i])){
				postfix += infix[i];
				i++;
			}
			postfix += " ";
			i--;
		}
		else if(infix[i] == '('){
			stack->push(infix[i]);
		}
		else if(infix[i] == '*' || infix[i] == '+' || infix[i] == '-' || infix[i] == '/'){
			while(!stack->isEmpty() && stack->top() != '('){
				if(IsPriorityLow(stack->top(),infix[i])){
					CopyPostfix(stack,postfix);
				}
				else break;
			}
			stack->push(infix[i]);
		}
		else if(infix[i] == ')'){
			while(!stack->isEmpty() && stack->top() != '('){
				CopyPostfix(stack,postfix);
			}
			if(!stack->isEmpty()) stack->pop();
		}
	}
	while(!stack->isEmpty()){
		CopyPostfix(stack,postfix);
	}
	delete stack;
	return postfix;
}
double Postfix::StringToDouble(string str){
	stringstream ss(str);
	double num;
	ss>>num;
	return num;
}

Postfix::Postfix(string infix){
	value = infixToPostfix(infix);
}
double Postfix::Calculate(){
	double result;
	int length = value.length();
	Stack<double> *stack = new Stack<double>();
	for(int i=0;i<length;i++){
		if(isspace(value[i])) continue;
		if(isdigit(value[i])){
			string numberStr = "";
			while(isdigit(value[i])){
				numberStr += value[i];
				i++;
			}
			double number;
			number = StringToDouble(numberStr);
			stack->push(number);
			i--;
			continue;
		}
		else{
			double number2 = stack->top();
			stack->pop();
			double number1 = stack->top();
			stack->pop();
			switch(value[i]){
				case '+':
					stack->push(number1+number2);
				break;
				case '-':
					stack->push(number1-number2);
				break;
				case '*':
					stack->push(number1*number2);
				break;
				case '/':
					stack->push(number1/number2);
				break;
			}
		}
	}
	if(!stack->isEmpty()){
		result = stack->top();
		stack->pop();
	}
	delete stack;
	return result;
}
string Postfix::GetPostfixValue()const{
	return value;
}
ostream& operator<<(ostream& screen, Postfix& rgt){
	screen<<rgt.value<<endl;
	return screen;
}
