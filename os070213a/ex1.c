#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
sem_t sem0, sem1t4, sem1x4, sem5;

void *f0(void *arg){
  sem_wait(&sem0);
  fprintf(stdout,"0 ");
  fflush(stdout);
  sem_post(&sem1x4);

  sem_post(&sem1t4);
  sem_post(&sem1t4);
  sem_post(&sem1t4);
  sem_post(&sem1t4);
}
void *f1(void *arg){
  sem_wait(&sem1x4);
  sem_wait(&sem1t4);
  fprintf(stdout,"1");
  fflush(stdout);
  sem_post(&sem1x4);
  sem_post(&sem5);
}
void *f2(void *arg){
  sem_wait(&sem1t4);
  fprintf(stdout,"2");
  fflush(stdout);
  sem_post(&sem5);
}
void *f3(void *arg){
  sem_wait(&sem1t4);
  fprintf(stdout,"3");
  fflush(stdout);
  sem_post(&sem5);
}
void *f4(void *arg){
  sem_wait(&sem1x4);
  sem_wait(&sem1t4);
  fprintf(stdout,"4");
  fflush(stdout);
  sem_post(&sem1x4);
  sem_post(&sem5);
}
void *f5(void *arg){
  sem_wait(&sem5);
  sem_wait(&sem5);
  sem_wait(&sem5);
  sem_wait(&sem5);
  fprintf(stdout,"  5");
  fflush(stdout);
  sem_post(&sem0);
}
int main(){
  pthread_t t0,t1,t2,t3,t4,t5;

  sem_init(&sem0,0,0);
  sem_init(&sem1t4,0,0);
  sem_init(&sem1x4,0,0);
  sem_init(&sem5,0,0);
  for(;;){
    pthread_create(&t0,NULL,&f0,NULL);
    pthread_create(&t1,NULL,&f1,NULL);
    pthread_create(&t2,NULL,&f2,NULL);
    pthread_create(&t3,NULL,&f3,NULL);
    pthread_create(&t4,NULL,&f4,NULL);
    pthread_create(&t5,NULL,&f5,NULL);
    sem_post(&sem0);
    pthread_join(t0,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
    pthread_join(t4,NULL);
    pthread_join(t5,NULL);
    fprintf(stdout,"\n");
    fflush(stdout);
  }
}
