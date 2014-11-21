#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sig_handler(int sig_code);


int main(int argc, char *argv[]){
    pid_t pid;
    pid_t ppid;
    
    signal(SIGCONT,sig_handler);

    pid = fork();
    pid = fork();
    pid = fork();
    while(1){
	if(pid != 0){
		printf("I'm the parent of %d\n",pid);
		//fflush(stdout);
		sleep(1);
		//printf("[p] killing %d\n",pid);
		kill(pid,SIGCONT);
		//printf("[p] waiting for %d\n",pid);
		pause();
	} else {
		pause();
		printf("[c] I'm the child\n");
		//fflush(stdout);
		ppid = getppid();
		sleep(1);
		//printf("[c] killing %d\n",ppid);
		kill(ppid,SIGCONT);
	}
    }
}

void sig_handler(int sig_code){
	return;
}
