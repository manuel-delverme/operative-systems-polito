#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sig_handler(int sig_code);

int main(int argc, char *argv[]){
    pid_t producer;
    pid_t consumer;
    char *fileName = "/tmp/qwpeo1o239021eiofile";
    FILE *communication_file;
    char row[100];
    row[0] = "\0";
    
    signal(SIGCONT,sig_handler);

    consumer = fork();
    producer = fork();

    if(consumer < 0) exit(1);
    if(producer < 0) exit(1);

    if( 0 == producer){
    	pause();
    	communication_file  = fopen(fileName,"w"); 
	while( "end" != row){
	    fscanf(stdin,"%s",&row);
	    printf("%s",row);
	    fwrite(row,sizeof(char),sizeof(row),communication_file);
	    fflush(communication_file);
	    kill(consumer,SIGCONT);
	    pause();
	}
    } else if ( 0 == consumer) {
    	communication_file  = fopen(fileName,"r"); 
	kill(producer,SIGCONT);
	while("end" != row){
	    kill(consumer,SIGCONT);
	    pause();
	    fgets(row,sizeof(row),communication_file);
	    printf("%s \n",row);
	    kill(producer,SIGCONT);
	}
    } else {
	waitpid(producer);
	waitpid(consumer);
    }
    return 0;
}

void sig_handler(int sig_code){
	if(SIGCONT == sig_code){
		return;
	}
}
