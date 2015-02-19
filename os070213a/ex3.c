#include <stdio.h>
int i;
int main() {
  for(i=0;i<2;i++){
    if(fork())
      fork();
  }
  printf ("%d\n", i);
  system("echo i++");
}

/*
i=0
3x
i=1
3x3x
i=2
9x
>2
9x
i++
*/
