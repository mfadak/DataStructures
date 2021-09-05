#ifndef POSTFIX_HPP
#define POSTFIX_HPP

#include "Stack.hpp"
#include <cctype>
#include <cstdlib>
#include <sstream>

class Postfix{
	private:
		string value;
		
		bool IsPriorityLow(char,char);
		void CopyPostfix(Stack<char>*,string&);
		string infixToPostfix(string);
		double StringToDouble(string);
		
	public:
		Postfix(string);
		double Calculate();
		string GetPostfixValue()const;
		friend ostream& operator<<(ostream&, Postfix&);
};

#endif
