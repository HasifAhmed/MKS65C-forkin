#include <stdio.h> //printf()
#include <unistd.h> //fork() getpid() getppid()
#include <sys/types.h> //getpid() getppid()
#include <sys/wait.h> //wait() waitpid()
int main(){
  int parent = getpid();
  printf("I am parent %d\n",parent);
  int first = fork();
  int second = fork();
  if(getpid() != parent && getppid() == parent){
    printf("Child %d\n",getpid());
  }
}
