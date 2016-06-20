#include <stdio.h>
#include <fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include <unistd.h>
#include <string.h>
#define FIFO1 "mob"
#define FIFO2 "mob1"
#define PERMS 0666
 char fname[256];

int main(){
  int readfd,writefd;

  ssize_t n;
  char buf[512];int fd;
 
if(mkfifo(FIFO1,PERMS)<0)
printf("Cant create fifo file\n");
if(mkfifo(FIFO2,PERMS)<0)
printf("Cant  create fifo file\n");
  printf("Connection established waiting");
  readfd = open(FIFO1,O_RDONLY,0);
  writefd = open(FIFO2,O_WRONLY,0);


  read(readfd,fname,255);
  printf("GOt %s",fname);

  if((fd = open(fname,O_RDWR))<0){
    strcpy(buf,"NOT POSSIBLE KID");
    write(writefd,buf,strlen(buf));
  }
  else{
    while((n = read(fd,buf,512))>0)
      write(writefd,buf,n);
    
  }
	close(readfd);
	 unlink(FIFO1);
  	close(writefd);
 	 unlink(FIFO2);

}
