#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
using namespace std;

class Person{
	public:
		string name;
		double weight;
		Person();
		Person(string,double);
		friend ostream& operator<<(ostream&,Person&);
		bool operator>(Person&);
};

#endif
