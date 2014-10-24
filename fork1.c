#include  <stdio.h>
#include  <stdlib.h>
#include  <unistd.h>

int main(){
    pid_t pid;
    //fprintf(stdout,"getpid() -> %d , getppid() -> %d \n",getpid(),getppid() );
    pid = fork();
    if(0 == pid){
        fprintf(stdout,"pid = 0 -> child\n");
    } else {
        fprintf(stdout,"pid = %d -> child\n",pid);
    }
    exit(0);
}
