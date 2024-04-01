#include <stddef.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>


// Este programa crea 8 procesos, el resultado tendría que ser la impresión de los valores del 0 al 7 en un 
// orden arbitrario.
void * process(void * args) {
    int num = *(int *)args;
    printf("%d", num);
    pthread_exit(0);
}

int main(void) {
    for(int i = 0; i < 8; i++) {
        pthread_t th[i];
        pthread_create(&th[i], NULL, process, (void *) &i);
        sleep(1);
    }
}