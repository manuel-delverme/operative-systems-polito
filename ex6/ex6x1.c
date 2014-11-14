#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
  char *fileName;
  FILE *execFile;
  int n;
  char row[100];

  if(argc != 3)
    exit(1);
  fileName = argv[1];
  execFile  = fopen(fileName,"r"); 
  n =  atoi(argv[2]);
  while( fgets(row,sizeof(row),execFile)){
  	system(row);
	sleep(n);
  }
  return 0;
}

