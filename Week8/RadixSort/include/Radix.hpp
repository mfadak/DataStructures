#ifndef RADIX_HPP
#define RADIX_HPP

#include "Queue.hpp"
#include <cmath>

class Radix{
	private:	
		int* numbers;
		int length;
		Queue<int> **queues;
		int maxStep;
		
		int MaxStepNumber();
		int StepCount(int);
		int* QueueCurrentLengths();
	public:
		Radix(int*, int);
		int* Sort();
		~Radix();
};

#endif
