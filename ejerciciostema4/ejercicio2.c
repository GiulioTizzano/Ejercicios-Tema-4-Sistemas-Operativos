#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include<stdlib.h>
#include <signal.h>
#include <fcntl.h>

void main(void) {
    execl("./B", "./B", (char*)0);
}