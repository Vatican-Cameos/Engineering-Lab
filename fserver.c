#include <stdio.h>
# include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#define fil "hh"
#define file2 "hhh"
#define perms 0666
char fname[256];

int main(){
  int readfd,writefd;
  int fd;ssize_t n;char buf[512];
  printf("Creating fifo files");
  if(mkfifo(fil,perms)<0)
    printf("ERROR");
  if(mkfifo(file2,perms)<0)
      printf("ERROR");



  readfd = open(fil,O_RDONLY);
  writefd = open(file2,O_WRONLY);

  read(readfd,fname,255);
  printf("GOT %s",fname);

  if(fd = open(fname,O_RDONLY)<0){
    strcpy(buf,"errorman");
    write(writefd,buf,strlen(buf));
    fsync(writefd);
}
  else{
    while((n=read(fd,buf,512))>0){
      write(writefd,buf,n);
      fsync(writefd);
    }
  }
  close(readfd);
  unlink(fil);
  close(writefd);
  unlink(file2);
}
