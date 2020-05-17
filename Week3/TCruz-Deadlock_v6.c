/*
Tyson M. Cruz
05/17/2020
CST221 - Operating Systems Concepts
Professor Michael Landreth

In this exercise, I created a function that implemented a mutex that would
lock the shared resource while in use (in this case, the function implementation).
The main function creates three threads that call the function to process
the implementation. While one thread is using the function, the other two
threads wait (sleep) and try again. After all three threads have processed
the function, the threads are released from memory and the mutex is destroyed.
*/

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <semaphore.h>
#include <unistd.h>

pthread_t threads[10];
pthread_mutex_t lock;
int i = 0;

void* work(void* arg){
    pthread_mutex_lock(&lock);

    //Critical Section
    printf("\nJob %d has started\n", i);
    sleep(3);
    printf("\nJob %d has finished\n", i);
    i++;
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main(){
    int error;

    //Initialize mutex else throw error message
    if(pthread_mutex_init(&lock, NULL) != 0){
        printf("\n Initialize mutex failed\n");
        return 1;
    }

    //Initialize threads and call work function for each one
    while(i<10){
        error = pthread_create(&(threads[i]), NULL, &work, NULL);
        if(error != 0){
            printf("\nNext thread can't be created :[%s]", strerror(error));
            printf("\nWaiting...\n");
            sleep(2);
        }
    }

    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    pthread_join(threads[2], NULL);
    pthread_join(threads[3], NULL);
    pthread_join(threads[4], NULL);
    pthread_join(threads[5], NULL);
    pthread_join(threads[6], NULL);
    pthread_join(threads[7], NULL);
    pthread_join(threads[8], NULL);
    pthread_join(threads[9], NULL);

    //Destroy mutex to conserve memory
    pthread_mutex_destroy(&lock);

    return 0;
}
