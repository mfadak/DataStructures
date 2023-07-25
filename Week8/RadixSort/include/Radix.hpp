#ifndef RADIX_HPP
#define RADIX_HPP

#include "Queue.hpp"

class Radix{
	private:	
		int* numbers;
		int length;
		Queue<int> **queues;
		
		int findMax();
	public:
		Radix(int*, int);
		int* Sort();
		~Radix();
};

#endif
