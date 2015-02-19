#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <pthread.h>
pthread_mutex_t locka, lockb, lockc, lockd, locke, lockf, lockg, lockh, locki;
sem_t semi,sema,semb,semc,semd,semef,semg,semh,semi;

void *fa(void *arg){
  pthread_mutex_lock(&locka);
  fprintf(stdout,"a");
  pthread_mutex_unlock(&lockb);
  pthread_mutex_unlock(&lockc);
  pthread_mutex_unlock(&lockd);
}

void *fb(void *arg){
  pthread_mutex_lock(&lockb);
  fprintf(stdout,"b");
  sem_post(&semi);
}
void *fc(void *arg){
  pthread_mutex_lock(&lockc);
  fprintf(stdout,"c");
  sem_post(&semef);
  sem_post(&semef);
  //sem_wait(&semef);
  //sem_wait(&semef);
}
void *fd(void *arg){
  pthread_mutex_lock(&lockd);
  fprintf(stdout,"d");
  pthread_mutex_unlock(&lockh);
}
void *fe(void *arg){
  sem_wait(&semef);
  fprintf(stdout,"e");
  sem_post(&semg);
}
void *ff(void *arg){
  sem_wait(&semef);
  fprintf(stdout,"f");
  sem_post(&semg);
}
void *fg(void *arg){
  sem_wait(&semg);
  sem_wait(&semg);
  fprintf(stdout,"g");
  sem_post(&semi);
}
void *fh(void *arg){
  pthread_mutex_lock(&lockh);
  fprintf(stdout,"h");
  sem_post(&semi);
}
void *fi(void *arg){
  sem_wait(&semi);
  sem_wait(&semi);
  sem_wait(&semi);
  fprintf(stdout,"i");
  exit(0);
}

int main(){
  pthread_t ta,tb,tc,td,te,tf,tg,th,ti;

  sem_init(&sema,0,0);
  sem_init(&semb,0,0);
  sem_init(&semc,0,0);
  sem_init(&semd,0,0);
  sem_init(&semef,0,0);
  sem_init(&semg,0,0);
  sem_init(&semh,0,0);
  sem_init(&semi,0,0);

  pthread_mutex_init(&locka,NULL);
  pthread_mutex_init(&lockb,NULL);
  pthread_mutex_init(&lockc,NULL);
  pthread_mutex_init(&lockd,NULL);
  pthread_mutex_init(&locke,NULL);
  pthread_mutex_init(&lockf,NULL);
  pthread_mutex_init(&lockg,NULL);
  pthread_mutex_init(&lockh,NULL);
  pthread_mutex_init(&locki,NULL);

  pthread_mutex_lock(&locka);
  pthread_mutex_lock(&lockb);
  pthread_mutex_lock(&lockc);
  pthread_mutex_lock(&lockd);
  pthread_mutex_lock(&locke);
  pthread_mutex_lock(&lockf);
  pthread_mutex_lock(&lockg);
  pthread_mutex_lock(&lockh);
  pthread_mutex_lock(&locki);

  pthread_create(&ta,NULL,&fa,(void*)NULL);
  pthread_create(&tb,NULL,&fb,(void*)NULL);
  pthread_create(&tc,NULL,&fc,(void*)NULL);
  pthread_create(&td,NULL,&fd,(void*)NULL);
  pthread_create(&te,NULL,&fe,(void*)NULL);
  pthread_create(&tf,NULL,&ff,(void*)NULL);
  pthread_create(&tg,NULL,&fg,(void*)NULL);
  pthread_create(&th,NULL,&fh,(void*)NULL);
  pthread_create(&ti,NULL,&fi,(void*)NULL);

  pthread_mutex_unlock(&locka);

  pthread_join(ti,NULL);
}
