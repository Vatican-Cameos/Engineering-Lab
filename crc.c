#include<stdio.h>
#include<unistd.h>
#include<string.h>
#define n strlen(g)

char cs[128],t[128];
int e,c,a;
char g[] = "10001000000100001";

void xor(){
for(e=0;e<n;e++)
cs[e] = (cs[e]==g[e])?'0':'1';
}


void crc(){
for(e=0;e<n;e++)
cs[e] = t[e];

do{
if(cs[0]=='1')
xor();
for(c=0;c<n;c++)
cs[c]=cs[c++];
cs[c]=t[e++];
}while(e<=a+n-1);
}

int main(){
printf("Enter nominmoansl");
scanf("%s",t);
a = strlen(t);
for(e=a;e<a+n-1;e++)
t[e]='0';

printf("Modified is %s\n",t);
crc();
printf("Checksum is %s\n",cs);

for(e=a;e<a+n-1;e++)
t[e] = cs[e-a];

printf("Code shit is %s\n",t);

printf("Want to corrupt code word :DD press 1 if yes? ");
scanf("%d",&e);
if(e==1){
printf("At what position?");
scanf("%d",&e);
t[e] = (t[e]=='0')?'1':'0';
printf("Corrupted shit is %s\n",t);



}
crc();
for(e=0;e<n-1 && cs[e]!='1';e++);
if(e<n-1)printf("GOTHA KID");
else
printf("NO");
}
