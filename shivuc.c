#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#define FIFO1 "mob"
#define FIFO2 "mob1"
int main(){
  int readfd,writefd;
  printf("Trying connection kid");
  ssize_t n;
  char fname[256];char buf[512];
writefd=open(FIFO1,O_WRONLY,0);
readfd=open(FIFO2,O_RDONLY,0);
  printf("Trying connection kid");
  
 
  printf("Neter the file nameman");
  scanf("%s",fname);

  write(writefd,fname,strlen(fname));
  printf("Waiting for response from server");

  while((n = read(readfd,buf,512))>0)
    write(1,buf,n);


    close(readfd);
    close(writefd);
return 0;

}
