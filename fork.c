#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
  printf("Before Forking");
  fork();
  printf("After Forking");
  return 0;
}
