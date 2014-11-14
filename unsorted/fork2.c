#include  <stdio.h>
#include  <stdlib.h>
#include  <unistd.h>

int main(){
    pid_t pid1;
    pid_t pid2;
    pid1 = fork();
    printf("get getpid %d getppid %d\n",getpid(),getppid());
    if( 0 == pid1 ){
        printf("child1\n");
    } else {
        printf("parent of: %d forking again\n",pid1);
        pid2 = fork();
        if( 0 == pid2 ){
            printf("child2\n");
        } else {
            printf("parent of:%d\n",pid2);
        }
    }
    exit(0);
}
