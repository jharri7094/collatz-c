#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

void ChildProcess(int n);
void ParentProcess();

int main(){
  int n;
  printf("Enter n: \n");
  scanf("%d", &n);
  printf("\n");
  pid_t pid;
  pid = fork();
  if(pid == 0){
    ChildProcess(n);
  }
  else{
    ParentProcess();
  }
  exit(0);

}
void ChildProcess(){
  printf("%d \n", n);
  while(n != 1){
    if(n % 2 == 0){
      n = n / 2;
    }
    else{
      n = 3*n + 1;
    }
    printf("%d \n", n);
  }
}

void ParentProcess(){
  int status;
  printf("START \n");
  wait(&status);
  printf("END \n");
}
