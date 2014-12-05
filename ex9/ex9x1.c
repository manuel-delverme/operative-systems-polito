#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sig_handler(int sig_code);

int main(int argc, char *argv[])
{
    pid_t teacher_pid;
    pid_t assistant_pid;
    int teass_pipe[2];
    FILE *teacher_file,
    FILE *assistant_file;
    char id[20], surname[20], name[20];
    int mark, mark_other;

    if(argc != 2){
    	exit(1);
    }
    teacher_file = fopen(argv[0],"r");
    assistant_file = fopen(argv[1],"r");
    
    //signal(SIGCONT,sig_handler);
    if(!pipe(teass_pipe)){
    	exit(1);
    }

    teacher_pid = fork();
    if(0 != teacher_pid){

	filein = fopen(argv[1],"r");
	fileOut = fopen(argv[2],"w");

    	while(EOF != fscanf(argv[0],"%s %s %s %d",id, surname, name, &mark){
		write(pipe[1],id,strlen(id));
		write(pipe[1],surname,strlen(surname));
		write(pipe[1],name,strlen(name));
		read(pipe[0],&mark_other,1);
		mark += mark_other;
		fprintf(fileOut,"%s %s %s %d",id, surname, name, &mark);
	}
	fprintf(wpipe,"%s",EOF, surname, );

	fclose(wpipe);
	fclose(rpipe);


    } else {
    	assistant_pid = fork();
	if( 0 == assistant_pid){
		//while not done
		    //wait for data
		    //read stdin for mark
		    //send mark back

	}
    }
    exit(0);



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
		fflush(stdout);
		ppid = getppid();
		sleep(1);
		//printf("[c] killing %d\n",ppid);
		kill(ppid,SIGCONT);
	}
    }
}

void sig_handler(int sig_code){
	fprintf(stdout,"ciao");
	return;
}
