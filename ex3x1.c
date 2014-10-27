#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "sys/wait.h"


int main(int argc, char **argv){
  pid_t pid;
  int retrCode;
  unsigned int sleepTime;

  pid = fork();
  if( 0 == pid){
    fprintf(stdout,"child pid is %d\n",getpid());
    printf("gieb 8bit:");
    scanf("%d",&retrCode);
    return retrCode;
  } else {
    printf("param is: %s\n",argv[1]);
    sleepTime = atoi(argv[1]);
    printf("sleeping %d secs\n",sleepTime);
    sleep(sleepTime);
    wait(&retrCode);
    printf("retr %d\n", retrCode);
    printf("child was %d\n", pid);
  }
  printf("out:  %d\n",pid);
  exit(0);
}
