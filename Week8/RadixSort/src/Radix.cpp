#include "Radix.hpp"

Radix::Radix(int *numbers, int length){
	this->numbers = new int[length];
	this->length = length;
	for(int i=0;i<length;i++){ this->numbers[i] = numbers[i]; }
	queues = new Queue<int>*[10];
	for(int j=0;j<10;j++){ queues[j] = new Queue<int>(); }
}
int Radix::findMax() {
    int max = numbers[0];
    for (int i = 1; i < length; ++i) {
        if (numbers[i] > max)
            max = numbers[i];
    }
    return max;
}
int* Radix::Sort(){
	int max = findMax();
    int exp = 1; // basamak yeri

   while (max / exp > 0) {
        // Basamak değerine göre ilgili kuyruğa ata
        for (int i=0;i<length;i++) {
            int digit = (numbers[i] / exp) % 10;
            queues[digit]->enqueue(numbers[i]);
        }

        // Kuyruktan sayıları alıp diziyi güncelleştir.
        int index = 0;
        for (int i = 0; i < 10; ++i) {
            while (!queues[i]->isEmpty()) {
                numbers[index++] = queues[i]->peek();
                queues[i]->dequeue();
            }
        }

        // Diğer basamak değerine ilerle
        exp *= 10;
    }
	return numbers;
}
Radix::~Radix(){	
	delete [] numbers;
	for(int i=0;i<10;i++) delete queues[i];
	delete [] queues;
}
