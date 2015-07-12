#include <stdio.h>
int main(int argc, char ** argv){
    int i=1;
    if (atoi(argv[1]) < argc){
        printf("%d\n", -i++);
        if(fork()){
            execlp(argv[0],argv[0],argv[i],0);
        }
        printf("NEVER GOING TO HAPPEN\n");
    } else {
        printf("%d\n",i);
    }
}
