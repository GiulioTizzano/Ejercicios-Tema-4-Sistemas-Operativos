#include <stddef.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define NUM_THREADS 3

void *process(void *args) {
    char letter = *((char *)args);

    for (int i = 0; i < NUM_THREADS; i++) {
        printf("%c\n", letter);
        fflush(stdout);
        sleep(1); // Pausa de 1 segundo

        // Cambia la letra en función de la letra actual
        if (letter == 'A') {
            letter = 'B';
        } else if (letter == 'B') {
            letter = 'C';
        } else if (letter == 'C') {
            letter = 'A';
        }
    }

    pthread_exit(NULL);
}

int main(void) {
    pthread_t th_a, th_b, th_c;

    pthread_create(&th_a, NULL, process, "A");
    pthread_create(&th_b, NULL, process, "B");
    pthread_create(&th_c, NULL, process, "C");

    pthread_join(th_a, NULL);
    pthread_join(th_b, NULL);
    pthread_join(th_c, NULL);

    return 0;
}
