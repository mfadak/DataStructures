#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <iostream>
using namespace std;

class Exception{
	private:
		string message;
	public:
		Exception(const string &msg):message(msg) { }
		string Message()const;
};
#endif
