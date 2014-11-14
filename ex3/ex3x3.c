/*
* Write a C program which receives two command line parameters, n and t. The parent 
* process has to initialize a counter, create two child processes and exit. Each one of the two 
*
* child processes has to increment the counter, print it and create again two child processes 
* and terminate immediately after. The process of creating childs stops after creating 2^n 
* leaves processes. So for example, if n=2, the parent creates two child processes, and each child creates two processes for a total number of 4 leaves processes. At this point process 
* creation stops. The last set of child processes (leaf child processes) have to increment their 
* counter and sleep for t seconds before printing it. Be careful, each process creates two child 
* processes but only leaf processes are allowed to wait. What’s the order in which processes 
* terminate? Is the order always the same?
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "sys/wait.h"

int main(int argc, char *argv[]){
  int cnt = 0;
  int* addr = &cnt;
  pid_t pid1;
  pid_t pid2;
  pid1 = fork();
  if(pid1 > 0){
    pid2 = fork();
    if(pid2 > 0){
      exit(0);
    } else {
      *addr++;
    }
  } else{
    *addr++;
  }
}

