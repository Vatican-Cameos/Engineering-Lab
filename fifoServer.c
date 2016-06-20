#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#define FIFO "te1"
#define FIFO2 "te2"
#define perms 0666


int main(){
  int readfd,writefd;

  ssize_t n;
  char buf[512];int fd;
  char fname[256];
  printf("error creating file");
  if(!mkfifo(FIFO,perms)<0)
    printf("error creating file");
  if(!mkfifo(FIFO2,perms)<0)
    printf("error creating file");

printf("Connection established waiting");
writefd = open(FIFO2,O_WRONLY|O_NONBLOCK,0);
  readfd = open(FIFO,O_RDONLY,0);



  read(readfd,fname,255);
  printf("GOt %s",fname);

  if(fd = open(fname,O_RDWR)<0){
    strcpy(buf,"NOT POSSIBLE KID");
    write(writefd,buf,512);
  }
  else{
    while(n = read(fd,buf,512)>0){
      write(writefd,buf,n);
    }

  }
  close(writefd);
  close(readfd);
  unlink(FIFO);
  unlink(FIFO2);

}
