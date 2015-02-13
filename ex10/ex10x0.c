#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void *print_message_function( void *ptr ) {
  char *message;
  message = (char *) ptr;
  printf("%s \n", message);
  return;
}

int main() {
  pthread_t thread;
  const char *message = "Thread : Hello World!";
  int iret;
  iret = pthread_create( &thread, NULL, print_message_function, (void*) message);
  pthread_join( thread, NULL);// we have to wait thread ends
  printf("Thread returns: %d\n",iret);
  exit(0);
}
