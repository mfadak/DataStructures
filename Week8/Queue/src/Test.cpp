#include "Queue.hpp"
#include "Person.hpp"

int main(){
	Queue<Person> *group = new Queue<Person>();
	Person *p1 = new Person("Mehmet",85);
	Person *p2 = new Person("Ceren",35);
	Person *p3 = new Person("Hamza",90);
	
	group->enqueue(*p1);
	group->enqueue(*p2);
	group->enqueue(*p3);
	
	group->dequeueMax();
	
	cout<<group->peek()<<endl;
	cout<<group->peekMax()<<endl;
	
	delete p1;
	delete p2;
	delete p3;
	delete group;
	return 0;
}
