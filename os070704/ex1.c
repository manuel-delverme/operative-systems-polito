#include <stdio.h>
int main(){
  int i;
  //twice and follow the child
  for (i=0; i<2 && !fork(); i++){
    if (fork())
      system("echo -n i+$i");
    execlp("echo","system","-n","i++",0);
  }
}
/*
 * i=0
 * echo i+
 * echo i++
 * echo i++
 */
