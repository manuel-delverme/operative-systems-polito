#include <semaphore.h>

int readcount, writecount;
sem_t mutex_readcount, mutex_writercount, mutex_3, mutex_writer, mutex_reader;

void reader(){
  sem_wait(&mutex_3);
  sem_wait(&mutex_reader);
  sem_wait(&mutex_readcount);
  readcount++;
  if (readcount == 1)
    sem_wait(&mutex_writer);
  sem_post(&mutex_readcount);
  sem_post(&mutex_reader);
  sem_post(&mutex_3);

  // reading is performed

  sem_wait(&mutex_readcount);
  readcount--;
  if (readcount == 0) 
    sem_post(&mutex_writer);
  sem_post(&mutex_readcount);
}
void writer(){
  sem_wait(&mutex_writercount);
  writecount++;
  if (writecount == 1) 
    sem_wait(&mutex_reader);
  sem_post(&mutex_writercount);

  sem_wait(&mutex_writer);
  // writing is performed
  sem_post(&mutex_writer);

  sem_wait(&mutex_writercount);
  writecount--;
  if (writecount == 0) 
    sem_post(&mutex_reader);
  sem_post(&mutex_writercount);
}
main(){
  readcount = 0;
  writecount = 0;

  sem_init(&mutex_readcount,0,1);
  sem_init(&mutex_writercount,0,1);
  sem_init(&mutex_3,0,1);
  sem_init(&mutex_writer,0,1);
  sem_init(&mutex_reader,0,1);
}
