#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[]){
  int N = atoi(argv[1]);
  char *cN;
  int i;
  cN = malloc(sizeof(char)*10101);
  for(i=0;i<N;i++){
    if(!fork()){
      if((i % 2)==0)){
        execvp(argv[0],
      }

    }
  }


  exit(0);
}
