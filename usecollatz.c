#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
  int n;
  int i = 1;
  printf("Enter integer n (between 1 and 100): ");
  scanf("%d", &n);
  while(i != 0){
    if((n >= 1) && (n <= 100)){
      i = 0;
    }
    else{
      printf("Invalid input. Please try again: ");
      scanf("%d", &n);
    }
  }
  printf("You entered %d \n", n);
  int pid2 = fork();
  char num[5];
  sprintf(num, "%d", n);
  if(pid2 == 0){
    char *args[] = {"./collatz1", num, NULL};
    execvp(args[0], args);
  }
  exit(0);
}

