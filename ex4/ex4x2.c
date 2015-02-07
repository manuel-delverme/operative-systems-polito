#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void forkandwait(int *v,int n,int i){
    fprintf(stdout,"r %d\n",i);
    int status;
    if(n == i){
        fprintf(stdout,"res: %d\n",v[i]);
        exit(--i);
    } else {
        if(fork()){
            //parent
            fprintf(stdout,"p%d wait\n",i);
            wait(&status);
            fprintf(stdout,"p%d out: %d\n",i,v[status>>8]);
            exit(--i);
        } else {
            //child
            fprintf(stdout,"c%d forking\n",i);
            forkandwait(v,n,++i);
        }
    }
}
int main(int argc,char *argv[]){
    //get n from argv
    //malloc v[n]
    //read vs from stdin
    //print n,n-1,n-2,.....,2
    //print 1
    //
    //create n-1 processes
    //sync w/wait function
    //print v[n]
    //parent prints the v[n] left out
    
    printf("p1\n");
    int n = 0;
    int i = 0;
    int *v;
    if(argc != 2) exit(-1);

    n = atoi(argv[1]);
    v = (int*) malloc(sizeof(int) * n);

    for(i=0;i<n;i++){
        fprintf(stdout,"number %d pls \n", i);
        fscanf(stdin,"%d",&v[i]);
    } 
    fprintf(stdout,"recursion\n");
    forkandwait(v,n,0);
    exit(1);
}
