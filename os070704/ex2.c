/*
 * 2. Implement,
 * using semaphores,
 * a single producer and
 * 3 consumers processes that communicates
 * through a common buffer of unlimited size.
 */

#include <semaphore.h>
int buffer[2];
sem_t semWrite;
sem_t semRead;

void* producer(void* args){
  sem_wait(semWrite);
  //produce
  sem_post(semRead);
}
void* consumer(void* args){
  //consume
}

int main(){

}
