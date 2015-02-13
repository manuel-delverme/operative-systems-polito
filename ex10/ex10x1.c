#include <fcntl.h>

//Write a concurrent program able to sort data files using threads as follows.
//The input files include:
//• on the first line the total number of integer values;
//• on the following lines a number for each line; 

int main(){

  int fin;
  int fout;
  int i;

  for( i = 0; i < argc ; i += 2 ){
    fin = open(argv[i],O_TEXT);
    fout = open(argv[i+1],O_WRONLY);
    pthread_create(dostuff,fin,fout);
    //spawn thread with fin,fout
  }
}
void *dostuff(int fin,int fout){
  char buff[100];
  buff[0] = '\0';
  int size = 0;
  do{
    read(fin,buff,1);
    size *= 10;
    size += atoi(buff);
  }while(buff != '\n')
  vals = malloc(sizeof(int)*size);
  while(read(fin,buff,sizeof(buff))){
    if(buff != '\n'){
      val *= 10;
      val += atoi(buff);
    } else {

    }
  }

  write(fout,buff,sizeof(buff));
  close(fin);
  close(fout);
}
  /*
    • reads the corresponding input file
    • sort the corresponding integer vector in ascending order
    • store the result in the corresponding output file

    For example:
    ./thread_sort.exe file1.in file1.out file2.in file2.out file3.in file3.out
    It will create 3 threads :
    • Thread 1 will sort file1.in and it will store the result in file1.out
    • Thread 2 will sort file2.in and it will store the result in file2.out
    • Thread 3 will sort file3.in and it will store the result in file3.out
  */
}
