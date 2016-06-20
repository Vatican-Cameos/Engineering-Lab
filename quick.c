#include<stdio.h>

int quicksort(int x[30],int f,int l)
{
int i,j,temp,pivot;
if(f<l)
{

i=f;
j=l;
pivot=f;
while(i<j)
{
while(x[i]<=x[pivot]&&i<l)i++;
while(x[j]>=x[pivot])j--;


if(i<j)
{
temp=x[i];
x[i]=x[j];
x[j]=temp;
}
}
temp=x[j];
x[j]=x[pivot];
x[pivot]=temp;
quicksort(x,f,j-1);
quicksort(x,j+1,l);
}
}


void main()
{
int n,a[30],i;
printf("Enter n");
scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%d",&a[i]);
quicksort(a,0,n-1);
for(i=0;i<n;i++)
printf("%d",a[i]);
}

