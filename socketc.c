#include<stdio.h>
#include<netinet/in.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<unistd.h>


int main(int argc,char *argv[]){
int create_socket,new_socket,fd,cont,addrlen;
char fname[255];
int bufsize = 1024;
char *buf = malloc(bufsize);
struct sockaddr_in address;

if((create_socket = socket(AF_INET,SOCK_STREAM,0))>0)
printf("Socket created");
address.sin_family = AF_INET;
address.sin_port = htons(15000);
inet_pton(AF_INET,argv[1],&address.sin_addr);

if(connect(create_socket,(struct sockaddr *) &address, sizeof(address))==0)
printf("Connected");
printf("GIVE FILE NAME");
scanf("%s",fname);

send(create_socket,fname,sizeof(fname),0);

while((cont = recv(create_socket,buf,bufsize,0))>0)
write(1,buf,cont);

return close(create_socket);
}
