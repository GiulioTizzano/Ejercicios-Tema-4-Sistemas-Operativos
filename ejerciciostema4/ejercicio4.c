#include <stddef.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>


void * process(void * args) {
    int thread_number = *((int *)args);
    printf("Soy el hilo %d \n", thread_number);
    fflush(stdout);
    pthread_exit(0);
}

pthread_t thread_creator(void) {
    pthread_t new_threads[8];
    int index[8];
    pthread_t hilos;

    for(int i = 0; i < 8; i++) {
        index[i] = i + 1;
        hilos = pthread_create(&new_threads[i], NULL, process, &index[i]);
        sleep(2);
    }
    return hilos;
}


int main(void) {
    thread_creator();
}