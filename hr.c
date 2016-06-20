#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    int n,t,i,j,h=1;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d",&n);
        h=1;
        for(j=0;j<n;j++){
            if(n%2==0)
                h+=1;
            else
                h*=2;
        }
        printf("%d\n",h);
    }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
