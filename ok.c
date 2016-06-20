#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>

int prime(int x){
int n,i;
for(i=2;i<x/2;i++){
n = x%i;
if(n==0)return 0;
}
if(i==x/2)
return 1;
}
int gcd(int a,int b){
if(a==0)return b;
while(b!=0){
if(a>b) a =a -b;
else
b = b-a;
}
}


int main(){
char msg[100],str[100];int p,q,i,z,len,n,e,d,dflag=0,ch,t,j,c[100];
printf("Enter msg\n");
scanf("%s",msg);
len = strlen(msg);

printf("Enter prime");
scanf("%d%d",&p,&q);
n=p*q;
z=(p-1)*(q-1);
for(i=2;i<z;i++){
if(gcd(i,z)==1 && prime(i))
{
e=i;
break;
}}
printf("public %d, %d\n",e,n);
for(d=2;d<z;d++){
if((e*d)%z==1)
break;
}
printf("private %d, %d\n",d,n);
for(i=0;i<len;i++){
//if(msg[i]==' ')
//ch = 65;
//else if(isdigit(msg[i])){
ch = msg[i]-65;
//dflag=1;
//}
//else ch = msg[i]-65;
t=1;
for(j=1;j<=e;j++)
t =(t*ch)%n;

c[i]=t;

}
for(i=0;i<len;i++)
printf("public %d, %d\n",msg[i],c[i]);
for(i=0;i<len;i++){
ch=c[i];
t=1;
for(j=1;j<=d;j++)
t=(t*ch)%n;
//if(dflag)
//str[i]=t;
//else
str[i] = t+65;


}
str[i]='\0';
printf("Text is %s",str);
}
