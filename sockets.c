#include<stdio.h>
#include<netinet/in.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<unistd.h>


int main(){
int create_socket,new_socket,fd,cont,addrlen;
char fname[255];
int bufsize = 1024;
char *buf = malloc(bufsize);
struct sockaddr_in address;

if((create_socket = socket(AF_INET,SOCK_STREAM,0))>0)
printf("Socket created");

address.sin_family = AF_INET;
address.sin_addr.s_addr = INADDR_ANY;
address.sin_port = htons(15000);

if(bind(create_socket,(struct sockaddr *) &address , sizeof(address))==0)
printf("Binding done");

listen(create_socket,3);
addrlen = sizeof(struct sockaddr_in);

new_socket = accept(create_socket,(struct sockaddr *) &address , &addrlen);
if(new_socket>0)
printf("Connected to client %d", inet_ntoa(address.sin_addr));

recv(new_socket,fname,255,0);
printf("REQUEST");
if((fd=open(fname,O_RDONLY))>0)
printf("opened file");

while((cont = read(fd,buf,bufsize))>0)
send(new_socket,buf,cont,0);
printf("LOL SENDKING K ");
close(new_socket);
return close(create_socket);




}
