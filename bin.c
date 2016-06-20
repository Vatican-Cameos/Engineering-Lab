#include<stdio.h>

int binsrc(int x[30],int l,int h,int key){
int mid;
while(l<=h)
{
mid=(l+h)/2;

if(x[mid]==key)
return mid;

if(x[mid]<key)
l=mid+1;

else
h=mid-1;
}
return -1;
}


int main()
{int a[20],suc,n,i;
printf("Enter n and array");
scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%d",&a[i]);
suc=binsrc(a,0,n-1,10);
printf("FOUND AT position %d",suc+1);
}


