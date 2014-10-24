#include  <stdio.h>
#include  <stdlib.h>
#include  <unistd.h>

int main(){
    pid_t pid;
    pid = fork();
    while(0 != pid){
        pid = fork();
        printf(" [%d] fuck the system \t",pid);
    }
    exit(0);
}
