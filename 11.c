#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
int prime(int x)
{
 int n,i;
for(i=2;i<x/2;i++)
{
 n=x%i;
if(n==0)
return 0;}
if(i==x/2)
return 1;

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
int main()
{
 int dflag=0,flag=0,len,n,z,a,b,d,p,q,e,j=0,ch,i;
char msg[50],str[20];
unsigned int t,c[100];
double temp;
char dummyString[30];
printf("Enter the message to b encrypted\n");
scanf("%s",msg);
strcpy(dummyString,msg);
len=strlen(msg);
do
{
 printf("Enter 2 prime numbers\n");
scanf("%d%d",&p,&q);
if(prime(p)&&prime(q))
{
flag=1;
n=p*q;
}
}
while(flag!=1);
z=(p-1)*(q-1);
for(i=2;i<z;i++)
if(gcd(i,z)==1&&prime(i))
{
e=i;
break;
}
printf("Value of e is:%d :public key is:{%d,%d}\n",e,e,n);
for(d=2;d<z;d++)
if((e*d)%z==1)
break;
printf("Private key:{%d,%d}\n",d,n);
printf("The cipher text is....\n");
for(i=0;i<len;i++)
{
 if(msg[i]==' ')
ch=65;
else if(isdigit(msg[i]))
{
 ch=msg[i];
dflag=1;
}
else
ch=msg[i]-65;
t=1;
for(j=1;j<=e;j++)
t=(t*ch)%n;
c[i]=t;
printf("%d",c[i]);
}
printf("\n MESSAGE \t CIPHER\n");
for(i=0;i<len;i++)
printf("%c\t %d\n",msg[i],c[i]);
printf("Decrypting...\n");
for(i=0;i<len;i++)
{
 t=1;
ch=c[i];
for(j=1;j<=d;j++)
t=(t*ch)%n;
if(dflag==1)
str[i]=t;
else
str[i]=t+65;
}
str[i]='\0';
printf("\n Decrypted text is %s\n",str);
return 0;
}


