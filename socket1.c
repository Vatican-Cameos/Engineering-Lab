#include<sys/socket.h>
#include<unistd.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<stdio.h>
int main(int argc,char *argv[])
{
 int create_socket,cont;
int bufsize=1024;
char *buffer=malloc(bufsize);
char fname[256];
struct sockaddr_in address;
if((create_socket=socket(AF_INET,SOCK_STREAM,0))>0)
printf("Socket was created");
address.sin_family=AF_INET;
address.sin_port=htons(15000);
inet_pton(AF_INET,argv[1],saddress.sin_addr);
if(connect(create_socket(struct sockaddr *)saddress,sizeof(address))==0)
printf("The connection was accepted with the server %s",argv[1]);
printf("Enter the filename to requst:");
scanf("%s",fname);
send(create_socket,fname,sizeof(fname),0);
printf("Request accepted....Receiving file...\n\n");
printf("The contents of file are...\n\n");
while((cont=recv(create_socket,buffer,bufsize,0))>0)
{
 write(1,buffer,cont);
}
printf("\n EOF\n");
return close(create_socket);
}

