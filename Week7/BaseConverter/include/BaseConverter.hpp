#include "Stack.hpp"
#include <string>
class BaseConverter{
	private:
		int value;
		int base;
		string converted;
		
		string Convert();
	public:
		BaseConverter();
		int getValueBase10()const;
		friend ostream& operator<<(ostream&,BaseConverter&);	
		friend istream& operator>>(istream&,BaseConverter&);
};
