#include "Text.hpp"

int main(){
	string content;
	cout<<"Content: ";
	getline(cin,content);
	Text *text = new Text(content);
	if(text->CheckParentheses()) cout<<"Parentheses are match";
	else cout<<"Parentheses are not match";
	delete text;
	return 0;
}
