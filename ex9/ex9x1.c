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
    FILE * teacher_file;
    FILE * assistant_file;
    FILE * fileIn;
    FILE * fileOut;
    char id[20], surname[20], name[20];
    int mark, mark_other;

    if(argc != 2){
    	exit(1);
    }
    teacher_file = fopen(argv[0],"r");
    assistant_file = fopen(argv[1],"r");
    
    signal(SIGCONT,sig_handler);
    if(!pipe(teass_pipe)){
    	exit(1);
    }

    teacher_pid = fork();
    if(0 != teacher_pid){

	fileIn = fopen(argv[1],"r");
	fileOut = fopen(argv[2],"w");

    	while(EOF != fscanf(fileIn,"%s %s %s %d",id, surname, name, &mark)){
		write(pipe[1],id,sizeof(id));
		write(pipe[1],surname,strlen(surname));
		write(pipe[1],name,strlen(name));
		read(pipe[0],&mark_other,sizeof(mark_other));
		mark += mark_other;
		fprintf(fileOut,"%s %s %s %d",id, surname, name, &mark);
	}
	write(pipe[0],EOF,1);

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
}

void sig_handler(int sig_code){
	//
	return;
}
