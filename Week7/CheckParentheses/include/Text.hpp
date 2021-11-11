#include "Stack.hpp"
#include <string>
class Text{
	private:
		string content;
		Stack<char> *stack;
		
	public:
		Text(string);
		bool CheckParentheses();
		~Text();
};
