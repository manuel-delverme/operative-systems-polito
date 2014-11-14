#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    char *fileName;
    FILE *execFile;
    int n,i;
    char row[500][5000];

    if(argc != 3)
	exit(1);
    fileName = argv[1];
    execFile  = fopen(fileName,"r"); 
    n =  atoi(argv[2]);

    while( fgets(row,sizeof(row[0]),execFile)){
    	execvp(row,"");
	sleep(n);
    }
    row[i] = (char*) 0;
    execvp(row);
    return 0;
}

