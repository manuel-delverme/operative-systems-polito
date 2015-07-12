#include <semaphore.h>
#include <stdio.h>

int readcount, writecount;
sem_t mutex_readcount, mutex_writercount, mutex_3, mutex_writer, mutex_reader;

void reader(){
  //????
  fprintf(stdout,"readers:w_m3 %d\n",readcount);
  sem_wait(&mutex_3);
  //readers bottleneck here
  fprintf(stdout,"readers:w_mr %d\n",readcount);
  sem_wait(&mutex_reader);
  //protect readcount
  fprintf(stdout,"readers:w_mrc %d\n",readcount);
  sem_wait(&mutex_readcount);
  readcount++;
  fprintf(stdout,"readers:rc++ %d\n",readcount);
  //if i'm the first one
  if (readcount == 1){
    //make sure no writing is being done
    fprintf(stdout,"readers:w_wr %d\n",readcount);
    sem_wait(&mutex_writer);
  } else {
    fprintf(stdout,"readers:not waiting for writer %d\n",readcount);
  }
  //release readcount
  sem_post(&mutex_readcount);
  //let other readers parallel read
  sem_post(&mutex_reader);
  //????
  sem_post(&mutex_3);

  // reading is performed
  fprintf(stdout,"readers: %d\n",readcount);
  sleep(1);
  //fscanf(stdin,"%s",(void*)NULL);

  //protect readcount
  sem_wait(&mutex_readcount);
  readcount--;
  //if im the last one
  //writer could be starved!!!!
  if (readcount == 0)
    //release RO
    sem_post(&mutex_writer);
  //release readcount
  sem_post(&mutex_readcount);
}
void writer(){
  //protect writercount
  sem_wait(&mutex_writercount);
  writecount++;
  //if im the first one
  if (writecount == 1)
    //set write only
    sem_wait(&mutex_reader);
  //release readercount
  sem_post(&mutex_writercount);

  sem_wait(&mutex_writer);
  fprintf(stdout,"writers %d\n",&writecount);
  // writing is performed
  sem_post(&mutex_writer);

  sem_wait(&mutex_writercount);
  writecount--;
  //if im the last one
  if (writecount == 0)
    //lift write only
    sem_post(&mutex_reader);
  sem_post(&mutex_writercount);
}
void spam_write(void *args){
  for(;;){
    sleep(1);
    writer();
  }
}
void spam_read(void *args){
  reader();
}
main(){
  readcount = 0;
  writecount = 0;

  sem_init(&mutex_readcount,0,1);
  sem_init(&mutex_writercount,0,1);
  sem_init(&mutex_3,0,1);
  sem_init(&mutex_writer,0,1);
  sem_init(&mutex_reader,0,1);

  pthread_t trash;
  pthread_create(&trash,0,spam_write);
  fprintf(stdout,"initd\n");
  for(;;){
    pthread_create(&trash,0,spam_read);
  }
  pthread_join(trash);
  fprintf(stdout,"out\n");
}
