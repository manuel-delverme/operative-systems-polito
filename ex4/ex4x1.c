#include <stdio.h>
int main(int argc,char *argv[]){
    printf("p1\n");
    if(fork()){
        //p1l
        int status;
        printf("p1l1\n");
        wait(&status);
        printf("p1l2\n");
    } else {
        //p1r
        printf("p1r1\n");
        exit(0);
        printf("p1r2\n");
    }
    // p2
    if(fork()){
        //p2l
        printf("p2l1\n");
        int status;
        wait(&status);
        printf("p2l2\n");
    } else {
        //p2r
        printf("p2r1\n");
        exit(0);
        printf("p2r2\n");
    }
    // p3
    printf("p3\n");
    exit(0);
}
