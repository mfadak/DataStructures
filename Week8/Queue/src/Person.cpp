#include "Person.hpp"

		Person::Person(){
			name="";
			weight=0;
		}
		Person::Person(string name,double weight){
			this->name = name;
			this->weight = weight;
		}
		ostream& operator<<(ostream& screen,Person& rgt){
			screen<<rgt.name<<" "<<rgt.weight<<endl;
			return screen;
		}
		bool Person::operator>(Person& rgt){
			return this->weight > rgt.weight;
		}
