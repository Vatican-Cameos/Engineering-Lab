#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#define FIFO1 "pip1"
#define FIFO2 "pip2"

int main(){
int readfd,writefd,fd;char buf[512];
ssize_t n;char fname[255];

writefd = open(FIFO1,O_WRONLY,0);
readfd = open(FIFO2, O_RDONLY,0);

printf("Connection done\n");
printf("Enter name\n");
scanf("%s",fname);
write(writefd,fname,255);

while((n=read(readfd,buf,512))>0)
write(1,buf,n);

close(readfd);
close(writefd);
}
