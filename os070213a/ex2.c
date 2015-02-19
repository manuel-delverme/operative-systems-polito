/*
Write the solution of the Readers&Writers with precedence to readers and comment the function of each semaphore.
What does precedence to the readers mean?
What happens to the readers arriving when a writer is writing?
What happens when the writer ends its operation?
*/

sem_t write, mutex;
int readcount;

void read(){
  /*
   * block 1:
   *
   * keep track of nr_readers <-- has to be done serialized (shared memory)
   * check no writing <-- only the first does since it's serialized and the first one stops the reader
   * sets read only
   *
   * block 2:
   * parallel reading
   *
   * block 3
   * remove self from readers
   * release readonly
   */
  sem_wait(mutex);
  readcount++;
  if(readcount==1)
    sem_wait(write);

  sem_post(mutex);

  //do the reading
  //critical section

  sem_wait(mutex);
  readcount--;
  if(readcount==0)
    sem_post(write);
  sem_post(mutex);
}
void write(){
  sem_wait(write);

  //writing

  sem_post(write);
}
int main(){
  sem_init(&write,0,1);
  sem_init(&mutex,0,1);
  readcount = 0;
}
