#include "Text.hpp"

Text::Text(string content){
	this->content = content;
	stack = new Stack<char>();
}
bool Text::CheckParentheses(){
	if (content == "") return true;

	for (int i = 0; i < content.length(); i++)
	{
		char current = content[i];
		if (current == '{' || current == '(' || current == '[')
		{
			stack->push(current);
		}

		if (current == '}' || current == ')' || current == ']')
		{
			if (stack->isEmpty()) return false;

			char topParentheses = stack->top();
			if (current == '}' && topParentheses == '{' || current == ')' && topParentheses == '(' || current == ']' && topParentheses == '[')
				stack->pop();
			else 
				return false;
		}

	}

	return stack->isEmpty();
}
Text::~Text(){
	delete stack;
}	
