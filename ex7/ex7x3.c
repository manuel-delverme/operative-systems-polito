#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>


void sig_handler(int sig_code);

int main(int argc, char *argv[]){
    pid_t producer = 0x1;
    pid_t consumer = NULL;
    char *fileName = "/tmp/qwpeo1o239021eiofile";
    FILE *communication_file;
    int status;
    char row[100];
    row[0] = '\0';
    
    signal(SIGCONT,sig_handler);

    consumer = fork();
    if( 0 != consumer){
	    producer = fork();
    }
    if(consumer < 0) exit(1);
    if(producer < 0) exit(1);

    if( 0 == producer){
    	pause();
    	//fprintf(stdout,"prod1\n");
    	communication_file  = fopen(fileName,"w"); 
	while( 0 != strcmp("end",row) ){
	    fprintf(stdout,"input:");
	    fscanf(stdin,"%s",row);
	    fprintf(communication_file,"%s\n",row);
	    fflush(communication_file);
	    kill(consumer,SIGCONT);
	    pause();
	    //fprintf(stdout,"prod2\n");
	}
    	fclose(communication_file);
    } else if ( 0 == consumer) {
    	communication_file  = fopen(fileName,"r"); 
	while( 0 != strcmp("end",row) ){
	    kill(consumer,SIGCONT);
	    pause();
	    //fprintf(stdout,"cons1\n");
	    fscanf(communication_file,"%s",row);
	    fprintf(stdout,"got: %s \n",row);
	    kill(producer,SIGCONT);
	}
	fclose(communication_file);
    } else {
	wait(&status);//bug me
	wait(&status);
    }
    return 0;
}

void sig_handler(int sig_code){
	if(SIGCONT == sig_code){
		return;
	}
}
