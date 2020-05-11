/*
Tyson M. Cruz
02/06/2020
CST221 - Operating Systems Concepts
Professor Michael Landreth

Semaphore Implementation
In this scenario, we created a simulation where stoplights at an intersection must be synchronized.
Synchronization is imperative because we don't want a situation where lights can change independently
of their counterparts, otherwise this would cause accidents in an intersection.

In this example, two separate threads are created and work independently of one another; however,
they share the same memory space (in this example, in the form of a global variable "msg"). However,
with the use of the semaphore, only one thread can modify the value of the variable at any given moment.
*/


#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

char light[48];
sem_t semaphore;
char *red = "Red Light";
char *yellow = "Yellow Light";
char *green = "Green Light";
char *msg;

//Function used for first thread
void firstLight(void *ptr){

    while(1){
        sem_wait(&semaphore); //Blocks other processes and begins critical section
        msg = (char *)ptr;
        sprintf(light, "%s", msg);
        printf("First Light: %s\n", light);
        sem_post(&semaphore); //End of critical section and  releases semaphore

        sleep(10);

        sem_wait(&semaphore); //Blocks other processes and begins critical section
        msg = (char *)green;
        sprintf(light, "%s", msg);
        printf("First Light: %s\n", light);
        sem_post(&semaphore); //End of critical section and  releases semaphore

        sleep(8);

        sem_wait(&semaphore); //Blocks other processes and begins critical section
        msg = (char *)yellow;
        sprintf(light, "%s", msg);
        printf("First Light: %s\n", light);
        sem_post(&semaphore); //End of critical section and  releases semaphore

        sleep(2);
    }
    pthread_exit(0);
}

//Function used for second thread
void secondLight(void *ptr){

    while(1){
        sem_wait(&semaphore); //Blocks other processes and begins critical section
        msg = (char *)ptr;
        sprintf(light, "%s", msg);
        printf("Second Light: %s\n", light);
        sem_post(&semaphore); //End of critical section and  releases semaphore

        sleep(8);

        sem_wait(&semaphore); //Blocks other processes and begins critical section
        msg = (char *)yellow;
        sprintf(light, "%s", msg);
        printf("Second Light: %s\n", light);
        sem_post(&semaphore);//End of critical section and  releases semaphore

        sleep(2);

        sem_wait(&semaphore); //Blocks other processes and begins critical section
        msg = (char *)red;
        sprintf(light, "%s", msg);
        printf("Second Light: %s\n", light);
        sem_post(&semaphore); //End of critical section and  releases semaphore

        sleep(10);
    }
    pthread_exit(0);
}

int main(int argc, char *argv  []){

    //Declare threads
    pthread_t light1;
    pthread_t light2;

    //Initialize semaphore, used for threads, shared between 2 threads
    sem_init(&semaphore, 0, 1);

    //Initialize two threads
    pthread_create(&light1, NULL, (void *)&firstLight, (void *)red);
    pthread_create(&light2, NULL, (void *)&secondLight, (void *)green);

    pthread_join(light1, NULL);
    pthread_join(light2, NULL);

    sem_destroy(&semaphore);

    return 0;
}
