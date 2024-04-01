#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include<stdlib.h>
#include <signal.h>


void sigusr1_manejador(int sig) {
    execl("/bin/ps", "-l", (char*)0);
}


void main(void) {
    int pid = fork();
    if(pid == 0) {
        signal(SIGUSR1, sigusr1_manejador);
    }
    
    while(wait(NULL) > 0);
}

