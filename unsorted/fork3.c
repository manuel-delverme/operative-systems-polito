#include  <stdio.h>
#include  <stdlib.h>
#include  <unistd.h>

int main(){
    int x,y;
    x = 4;
    if(fork()){
      //i'm the parent
      x = 15;
      y = 5;
      sleep(5);
    } else {
      // i'm a child
      y = -5;
    }
    fprintf(stdout, "x = %d y = %d process %d PPID %d\n",x,y,getpid(),getppid());
    exit(0);
}
