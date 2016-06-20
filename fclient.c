#include <stdio.h>
# include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#define fil "h1"
#define file2 "h2"
#define perms 0666
char fname[256];

int main(){
  int readfd,writefd;char buf[512];
  ssize_t n;
  writefd = open(fil,O_WRONLY,0);
  readfd = open(file2,O_RDONLY|O_NONBLOCK,0);


  printf("Enter the name man connection done");
  scanf("%s",fname);

  write(writefd,fname,strlen(fname));
  fsync(writefd);

  printf("waiting lol");

  while(n = read(readfd,buf,512)>0){
    write(1,buf,n);

  }
  close(writefd);
  close(readfd);
}
