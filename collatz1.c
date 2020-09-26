#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

void ChildProcess(int n);
void ParentProcess();

int main(int argc, char *argv[]){
  int n;
  n = atoi(argv[1]);
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
void ChildProcess(int n){
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
  printf("\nSTART \n");
  wait(&status);
  printf("END \n");
  exit(0);
}
