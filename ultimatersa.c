#include<stdio.h>
#include<string.h>


int prime(int x){
int n,i;
for( i=2;i<x/2;i++){
n = x % i;
if(n==0)return 0;

if(i==x/2)return 1;
}
}


int gcd(int a,int b)
{
 if(a==0)
return b;
while(b!=0)
{
if(a>b)
a=a-b;
else
b=b-a;
}
return a;
}

int main(){
int i;char msg[100];char str[100];int p,q,z,n,d,e,len,t,j;int ch;int c[100];
printf("Enter the msg");
scanf("%s",msg);
len = strlen(msg);
printf("Enter 2 prime");
scanf("%d%d",&p,&q);
if(prime(p)&&prime(q)){
n = p*q;

}
z = (p-1)*(q-1);
printf("%d" , n);
for( i = 2; i<z; i++)
if(gcd(i,z)==1 && prime(i)){
e=i;
break;
}
printf("%d" , e);
for(d=2; d<z ; d++){
if((e*d)%z==1){
break;
}
}
printf("%d" , d);
for( i=0;i<len;i++){

ch = msg[i];
t=1;


for( j=1;j<=e;j++){
t =(t*ch) % n;
c[i]=t;
printf("%d",c[i]);
}
}
for(i=0;i<len;i++)
printf("%c\t %d\n",msg[i],c[i]);
printf("Decrypting shit");

for( i=0;i<len;i++){
ch = c[i];
t=1;
for( j=1;j<=d;j++)
t=(t*d)%n;
str[i] = t;

}
str[i]= '\0';
printf("Decrypted text is %s",str);
}
