#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#define FIFO1 "pip1"
#define FIFO2 "pip2"

int main(){
int readfd,writefd,fd;
ssize_t n;char fname[255];
char buf[512];
if(mkfifo(FIFO1,0666)<0)
printf("Failed");
if(mkfifo(FIFO2,0666)<0)
printf("Failed");

printf("Trying to establish");

readfd = open(FIFO1,O_RDONLY);
writefd = open(FIFO2,O_WRONLY);

printf("Established");

read(readfd,fname,255);

if((fd = open(fname,O_RDWR))<0){
strcpy(buf,"cannot open f");
write(writefd,buf,strlen(buf));
}
while((n=read(fd,buf,512))>0)
write(writefd,buf,n);

close(readfd);
unlink(FIFO1);
close(writefd);
unlink(FIFO2);

}
