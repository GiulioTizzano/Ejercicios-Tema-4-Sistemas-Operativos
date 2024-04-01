#include <stddef.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define NUM_THREADS 3

void *process(void *args) {
    printf("%s\n", (char *)args);
    fflush(stdout);
    pthread_exit(0);
}

int main(void) {
    pthread_t th_a[NUM_THREADS], th_b[NUM_THREADS], th_c[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&th_a[i], NULL, process, "A");
    }
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&th_b[i], NULL, process, "B");
    }
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&th_c[i], NULL, process, "C");
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(th_a[i], NULL);
        pthread_join(th_b[i], NULL);
        pthread_join(th_c[i], NULL);
    }

    return 0;
}
