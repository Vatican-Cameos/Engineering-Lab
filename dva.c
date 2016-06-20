#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>
struct node{
int dist[10];
int from[10];

}rt[10];

int main(){
int i,j,k,mat[10][10],n;

printf("Enter the nodes");
scanf("%d",&n);
printf("Enter the cost matrix");

for(i=0;i<n;i++){
for(j=0;j<n;j++){
scanf("%d",&mat[i][j]);
rt[i].dist[j] = mat[i][j];
rt[i].from[j]=j;
}
}
for(i =0;i<n;i++){
for(j =0;j<n;j++){
for(k =0;k<n;k++){
if(rt[i].dist[j] > (mat[i][k]+rt[k].dist[j])){
rt[i].dist[j] = rt[i].dist[k] + rt[k].dist[j];
rt[i].from[j] = k;
}
}}}

for(i =0;i<n;i++){

printf("FOR NODE %d\n",i+1);
for(j=0;j<n;j++){
printf(" to %d via %d distance %d\n",j+1,rt[i].from[j],rt[i].dist[j]);
}
}
}
