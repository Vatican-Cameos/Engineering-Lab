#include<stdio.>

int binsrc(int x[30],int l,int h,int key){
int mid;
while(l<h)
{
mid=(l+h)/2;

if(x[mid]==key)
return mid;

if(x[mid]<key)
low=mid+1;

else
high=mid-1;
}
return -1;
}


int main()
{
printf("Enter n and array");
scanf("%d",
