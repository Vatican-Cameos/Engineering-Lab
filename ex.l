%{
#include <stdio.h>
#include <stdlib.h>
int cno = 0, wno = 0, lno = 0; /*counts of characters, words and lines */
%}

%%
[hi] { printf("Hello"); }
%%
void main()
{ printf("Enter");
yylex();
}
