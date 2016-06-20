#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#define FIFO "te1"
#define FIFO2 "te2"

int main(){
  int readfd,writefd;
  printf("Trying connection kid");
  ssize_t n;
  char fname[256];char buf[512];
  printf("Trying connection kid");
  readfd = open(FIFO2,O_RDONLY|O_NONBLOCK,0);
  writefd = open(FIFO,O_WRONLY,0);
  printf("Neter the file nameman");
  scanf("%s",fname);

  write(writefd,fname,255);
  printf("Waiting for response from server");

  while(n = read(readfd,buf,512)>0)
    write(writefd,buf,n);


    close(readfd);
    close(writefd);


}
