#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>


int main(int argc, char *argv[]){
  int communication_pipe[2];
  int i=0;
  char buf[100];
  pid_t producer;
  pid_t consumer;

  if(-1 == pipe(communication_pipe)){
    exit(-1);
  }
  producer = fork();
  if(0 == producer){
    //producer
    close(communication_pipe[0]);
    for(;;){
      for(i=0;i<100;i++) buf[i] = '\0';
      if(-1 == read(0,buf,sizeof(buf))){
        exit(-1);
      }
      if(0 == strcmp(buf,"end")){
        exit(0);
      }
      write(communication_pipe[1],buf,strlen(buf));
    }

  } else {
    close(communication_pipe[1]);
    consumer = fork();
    if(0 == consumer){
      //consumer
      for(;;){
        for(i=0;i<100;i++) buf[i] = '\0';
        if(-1 == read(communication_pipe[0],buf,sizeof(buf))){
          exit(-1);
        }
        if(0 == strcmp(buf,"end")){
          exit(0);
        }
        fprintf(stdout,"strlen(buf) = %d\n",strlen(buf));
        write(1,buf,strlen(buf));
      }
    }
    wait(NULL);
    wait(NULL);
    exit(0);
  }
}
