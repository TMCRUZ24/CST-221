/*
Tyson M. Cruz
05/10/2020
CST221 - Operating Systems Concepts
Professor Michael Landreth

Producers and Consumers
This program uses a 'struct' data structure to emulate a shared
memory space. The struct includes an array, and the program
populates the array using a for-loop while tracking the number
of elements as they're being produced, and the 'upper' boundary
(element number). Meanwhile, the 'consumer' is consuming data
from the lower boundary while tracking the number of elements as
they're being consumed, and the lower boundary element number. The
'sleep()' function is used to emulate the time it takes for
processes to complete before beginning the next process on the
shared memory space.
*/

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<errno.h>

int theProduct;

//Shared circular buffer to store simulated processes
struct CIRCULAR_BUFFER{
	int count;
	int lower;
	int upper;
	int buffer[100];
};

//Initialize buffer
struct CIRCULAR_BUFFER queue;


int produce(){
	return theProduct++;
}

void consume(int i){
	printf("Lower: %i\n", i);
}


/***********DEFINE get() AND put()**************/
//put() function adds item to the buffer
void put(int i){
	queue.count++;
	queue.upper = i;
	queue.buffer[i] = i;
}

//get() function removes item from the buffer
int get(){
	sleep(3);
	queue.count--;
	queue.lower++;
	return queue.buffer[queue.lower];
}

//function that regulates the items added to the buffer
void* producer(void *arg){
	int i;
	while(1){
		sleep(2);
		i = produce();
		put(i);
		printf("Upper: %i\n", queue.upper);
		printf("Total: %i\n", queue.count);
	}
}

//function that regulates removing items from the buffer
void consumer(){
	int i;
	while(1){
		i = get();
		consume(i);
	}
}

/**************************main() funtion********************************/

int main()
{
	theProduct = 0;

	pthread_t newThread;

	pthread_create(&newThread, NULL, producer, NULL);

	consumer();

}
