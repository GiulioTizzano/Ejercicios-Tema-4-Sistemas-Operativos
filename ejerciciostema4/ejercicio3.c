#include <stddef.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>


void * process(void * args) {
    printf("%s", (char*)args);
    fflush(stdout);
    pthread_exit(0);
}

// phthread_create(&thread, NULL, start_routine, arg);

// El primer parámetro es un puntero variable de tipo thread
// que se utiliza para almacenar el identificador del hilo
// creado.

// El segundo parámetro se utiliza para especificar los atributos
// del hilo que se está creando, si es NULL => se usan los
// atributos por defecto.

// El tercer parámetro es un puntero a la función que se ejecutará
// en el nuevo hilo.

// El cuarto argumento es el argumento que se le pasará
// a la función al empezar la start_routine.



void main(void) {
    pthread_t th_a,th_b; // variable tipo thread
    pthread_create(&th_a, NULL, process, "Hello");
    pthread_create(&th_b, NULL, process, "world");
    sleep(1);
}

// El resultado del programa es la ejecución paralela de 
// hello y world.