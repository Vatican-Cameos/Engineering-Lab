#include<stdio.h>
#include<iostream>
using namespace std;

int min(int a,int b){
  if(a<b)
  return a;
  return b;
}
int main(){
  int cap,out,inp[25],i=0;int ch;int nsec=0,cont;
  cout<<"Enter the capactiy";
  cin>>cap;
  cout<<"Enter the output rate";
  cin>>out;

  do{
    cout<<"Enter the number of packers at second";
    cin>>inp[i];
    i++;
    cout<<"Enter 0 to exit";
    cin>>ch;
  }while(ch!=0);
nsec = i;
cont =0;
cout<<"SEC\t packets recd \t packers sent\t ouputrate \t cont";
for(int i=0;i<nsec;i++){
  cont += inp[i];
  if(cont>cap)
    cont=  cap;
  cout<<i<<inp[i]<<cont<<min(out,cont);
  cont = cont-min(out,cont);
  cout<<cont<<"\n";

}
while(cont!=0){
  if(cont>cap)
    cont=  cap;

  cout<<i<<inp[i]<<cont<<min(out,cont);
  cont =cont-min(out,cont);
  cout<<cont<<"\n";

}

}
