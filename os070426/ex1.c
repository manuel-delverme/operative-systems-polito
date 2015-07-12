#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

sem_t s1,s2,s3,s4l,s5,s6l;
sem_t s4r,s6r;
pthread_t t1,t2,t3,t4,t5,t6;

void *f1(void* args){
  for(;;){
    sem_wait(&s1);
    printf("1");
    sem_post(&s2);
    sem_post(&s3);
  }
}
void *f2(void* args){
  for(;;){
    sem_wait(&s2);
    printf("2");
    sem_post(&s4l);
  }
}
void *f3(void* args){
  for(;;){
    sem_wait(&s3);
    printf("3");
    sem_post(&s4r);
    sem_post(&s5);
  }
}
void *f4(void* args){
  for(;;){
    sem_wait(&s4l);
    sem_wait(&s4r);
    printf("4");
    sem_post(&s6l);
  }
}
void *f5(void* args){
  for(;;){
    sem_wait(&s5);
    printf("5");
    sem_post(&s6r);
    printf("\npost s1\n");
    sem_post(&s1);
    printf("\nposted s1\n");
  }
}
void *f6(void* args){
  for(;;){
    sem_wait(&s6l);
    sem_wait(&s6r);
    printf("6\n");
  }
}
main(){
  sem_init(&s1,0,0);
  sem_init(&s2,0,0);
  sem_init(&s3,0,0);
  sem_init(&s4l,0,0);
  sem_init(&s4r,0,0);
  sem_init(&s5,0,0);
  sem_init(&s6l,0,0);
  sem_init(&s6r,0,0);
  pthread_create(&t1,0,&f1,(void*)NULL);
  pthread_create(&t2,0,&f2,(void*)NULL);
  pthread_create(&t3,0,&f3,(void*)NULL);
  pthread_create(&t4,0,&f4,(void*)NULL);
  pthread_create(&t5,0,&f5,(void*)NULL);
  pthread_create(&t6,0,&f6,(void*)NULL);
  printf("\npost s1\n");
  sem_post(&s1);
  printf("\nposted s1\n");
  int trash;
  pthread_join(t6,(void*)NULL);
}
