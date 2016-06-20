/*ANAND BHAT   |
  1JS07IS005   |
  6th ISE      |
  JSSATE B'LORE|
  LAB:10       |
_______________|*/

#include <iostream.h>
#include <fstream.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#define M 4
#define MBY2 (int)ceil((float)M/2)

struct node
{  int level;
   int usage;
   int numbers[M+1];
   struct node* children[M+2];
   struct node* parent;
   struct node* right;
};
typedef struct node* NODE;

NODE getnode()
{
NODE temp;
int i;
temp=(NODE)malloc(sizeof(struct node));
if(temp==NULL)
    {
    cout<< "insuffcient memory\n";
    getch(); exit(0);
    }
temp->level=0; temp->usage=0;
for(i=0;i<=M;i++)
    {
    temp->children[i]=NULL;
    temp->numbers[i]=999;
    }
temp->children[M+1]=NULL;
temp->parent=NULL;
temp->right=NULL;
return temp;
}

void display(NODE head)
{
NODE a[100],cur;
int i=0,j=0,k,level;
cur=head;
a[i]=cur;i++;
while (a[j]->children[1] != NULL)
    {
    for(k=0;k<= (a[j]->usage)-1;k++)
	{
	a[i]=a[j]->children[k] ;
	i++;
	}
    if(a[j]->children[a[j]->usage]!=NULL)
	{
	a[i]=a[j]->children[k] ; i++;}
	j++;
	}
    i--;
    level=head->level;
    cout<<"\n level--> "<<level<<endl;
    for(k=0;k<=i;k++)
	{
	if(level != a[k]->level)
	    {
	    cout << "\n";
	    level = a[k]->level;
	    cout<<"\n level--> "<<level<<endl;
	    }
	for(j=0;j<a[k]->usage;j++)
	    if (j == a[k]->usage-1)
		cout << a[k]->numbers[j]<<"\t";
	    else cout << a[k]->numbers[j] << "," ;
		cout << "\t" ;
	}
    cout << "\n";
}

void main()
{
NODE head=NULL,cur,temp,up,prev,newup,first=NULL,temp2;
char ch;
int num,i,j,k,poi;
clrscr();
for(;;)
    {
    cout<<"Main Menu\n"<<"-----------------\n";
    cout << "1:insert\n 2:search\n 3:displaytree\n 4:list_bottom\n 5:exit\nenter choice::";
    cin >> ch;
    switch(ch)
	{
	case '1':cout << "\nEnter the element:\n";
		 cin >> num;
		 if(head == NULL)
		     {
		     head=getnode();
		     head->usage=1;
		     head->numbers[0]=num;
		     first=head;
		     break;
		     }
		 else
		     {
		     cur=head;
		     while(cur != NULL)
			 {
			 prev=cur;
			 for(i=0,j=0;i<=(cur->usage)-1;i++)
			     if(num > cur->numbers[i]) j++ ;
				 cur=cur->children[j];
			 }
		      cur=prev;
		      poi=j;
		      if(cur->numbers[poi] == num)
			  {
			  cout << "element already present\n";
			  break;
			  }
		      if (poi <= cur->usage)
			  {
			  for(i=cur->usage;i>=poi+1;i--)
			      {
			      cur->numbers[i]=cur->numbers[i-1];
			      cur->children[i+1]=cur->children[i];
			       }
			  }
		      cur->numbers[poi]=num;
		      cur->children[poi+1]=NULL;
		      cur->usage++;

		      while(cur!=NULL)
			  {
			  if(cur->usage <= M)
			      {
			      if(cur->parent==NULL)break;
			      cur=cur->parent;
			      continue;
			      }
			  temp=getnode();
			  for(k=MBY2,j=0;k<M;k++,j++)
			      {
			      temp->numbers[j]=cur->numbers[k+1];
			      cur->numbers[k+1]=999;
			      temp->children[j]=cur->children[k+1];
			      cur->children[k+1]=NULL;
			      }
			  temp->children[2]=cur->children[5];
			  cur->children[5]=NULL;
			  cur->usage=3;
			  temp->usage=2;
			  temp->level=cur->level;
			  if(cur->children[0] != NULL)
			      {
			      for(i=0;i<=(cur->usage)-1;i++)
				  (cur->children[i])->parent=cur;
			      for(i=0;i<=(temp->usage);i++)
				  (temp->children[i])->parent=temp;
			      }

			  if (cur->level == 0)
			      {
			      temp2=cur->right;
			      cur->right=temp;
			      temp->right=temp2;
			      }
			  if (cur->parent == NULL)
			      {
			      up=getnode();
			      up->level=(cur->level)+1;
			      up->usage=1;
			      up->numbers[0]=cur->numbers[(cur->usage)-1];
			      up->children[0]=cur;
			      up->children[1]=temp;
			      cur->parent = temp->parent = up;
			      head=up;
			      if(cur->level!=0)
				  {
				  cur->numbers[2]=999;
				  cur->usage--;
				  }
			      break;
			      }
			  else
			      {
			      up=cur->parent;
			      temp->parent=up;
			      newup=getnode();
			      i=0;
			      while (up->numbers[i] < cur->numbers[0])
				  {
				  newup->numbers[i] = up->numbers[i];
				  newup->children[i] = up->children[i];
				  i++;
				  }
			      newup->children[i]=cur;
			      newup->numbers[i]= cur->numbers[(cur->usage)-1];
			      if(cur->level!=0)
				  {
				  cur->numbers[2]=999;
				  cur->usage--;
				  }
			      newup->children[i+1] = temp;
			      i++;
			      j=i-1;
			      while(j <= (up->usage)-1)
				  {
				  newup->numbers[i] = up->numbers[j];
				  newup->children[i+1] = up->children[j+1];
				  i++,j++;
				  }
			      up->usage=i;
			      newup->usage=i;
			      for(i=0;i<=(newup->usage)-1;i++)
				  {
				  up->numbers[i] = newup->numbers[i];
				  up->children[i] = newup->children[i];
				  }
			      up->children[newup->usage]=newup->children[newup->usage];
			      free(newup);
			      cur=up;
			      continue;
			      }
			  }
		      }
		  break;
	 case '2':cout << "enter the key\n";
		  cin >> num;
		  cur=head;
		  while (cur != NULL)
		      {
		      for(i=0,j=0;i<=(cur->usage)-1;i++)
			  if(num > cur->numbers[i]) j++ ;
			      prev=cur;
		      cur=cur->children[j];
		      }
		  cur=prev;
		  poi=j;
		  if(cur->numbers[poi] == num)
		      cout << "Element found\n";
		  else
		      cout << "Not found\n";
		  break;
	 case '3':display(head);
		  break;
	 case '4':temp=first;
		  while (temp!=NULL)
		      {
		      for(i=0;i<=(temp->usage)-1;i++)
			  if((temp->right==NULL)&&i==(temp->usage)-1)
			      cout<<temp->numbers[i] ;
			  else
			      cout<<temp->numbers[i] << ",";
			  temp=temp->right;
		      }
		   cout << "\n";
		   break;
	 default:exit(0);
       }
    }
}
