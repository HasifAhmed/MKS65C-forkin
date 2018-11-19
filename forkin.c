#include <stdio.h> //printf() 
#include <unistd.h> //fork() getpid() getppid() close() read()
#include <sys/types.h> //getpid() getppid()
#include <sys/wait.h> //wait() waitpid()
#include <fcntl.h> //open()
#include <stdlib.h> //abs()
#include <errno.h> //strerror
#include <string.h>//strerror
extern int errno;
int main(){
  printf("I am %d and my parent is %d\n",getpid(), getppid());

  int child = fork();
if(child == -1){
    printf("%s\n", strerror(errno));
  }
  if( child != 0){
    child = fork();
  }
  if(child == 0){
    printf("Child %d\n",getpid());

    int sleeptime;
    int fd = open("/dev/random", O_RDONLY );
    //printf("fd: %d\n",fd);

    int readbytes = read(fd,&sleeptime,sizeof(int));
    int success = close(fd);
    //printf("Success of closing file: %d\n",success);

    sleeptime = (abs(sleeptime) % 16) + 5;
    //printf("%d\n",sleeptime);
    sleep(sleeptime);
    printf("Done Sleeping!\n");
    return sleeptime;
  } else {

    int status;
    int cid = wait(&status);
    printf("%d finished first. It slept for %d seconds\n",cid, status / 256);
    printf("Finished!!!\n");
    return 0;
  }


}
