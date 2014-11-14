#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    char *fileName;
    FILE *execFile;
    int n;
    char *row;
    char *tokens;
    pid_t pid;
   
    if(argc != 3)
	exit(1);
    fileName = argv[1];
    execFile  = fopen(fileName,"r"); 
    n =  atoi(argv[2]);

    while(NULL != fgets(row,sizeof(row),execFile)){

    	printf("pre %s\n", row);


	for (int i = 0; i < len; i++) {
	    if (str[i] == '\0') {
		printf("'\\0'");
	    } else {
		printf("%c", str[i]);
	    }
	}
	tokens =  strtok(row, " ");
	while (tokens) {
	    printf("Token: %s\n", tokens);
	    tokens = strtok(NULL, " ");
	}
    	//printf("tok %s\n", tokens);
/*   	pid = fork();
	if( 0 == pid){
    		row[] = NULL;
 		execvp(row);
	}
	sleep(n);
*/
    }
    return 0;
}
