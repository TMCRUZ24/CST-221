/*
Tyson M. Cruz
02/13/2020
CST221 - Operating Systems Concepts
Professor Michael Landreth
*/

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <semaphore.h>
#include <unistd.h>

pthread_t threads[3];
pthread_mutex_t lock;
int i = 0;

void* work(void* arg){
    pthread_mutex_lock(&lock);

    //Critical Section
    printf("\nJob %d has started\n", i);
    sleep(2);
    printf("\nJob %d has finished\n", i);
    pthread_mutex_unlock(&lock);
    i++;
    return NULL;
}

int main(){
    int error;

    //Initialize mutex else throw error message
    if(pthread_mutex_init(&lock, NULL) != 0){
        printf("\n Intialize mutex failed\n");
        return 1;
    }

    //Initialize threads and call work function for each one
    while(i<3){
        error = pthread_create(&(threads[i]), NULL, &work, NULL);
        if(error != 0){
            printf("\nNext thread can't be created :[%s]", strerror(error));
            printf("\nWaiting...\n");
            sleep(1);
        }
    }

    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    pthread_join(threads[2], NULL);

    //Destroy mutex to conserve memory
    pthread_mutex_destroy(&lock);

    return 0;
}
