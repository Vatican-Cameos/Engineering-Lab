%{
#include<stdio.h>
#include<stdlib.h>
%}
%token A B
%%
S:A A A A A A A A any B
|
;
any:A any
|
;
%%
main()
{
printf("TEL IT KAI");
yyparse();
printf("CORRECTA");
}
yylex()
{
char c;
c=getchar();
if(c=='a')return A;
if(c=='b')return B;
if(c=='\n')return 0;
return c;
}

yyerror()
{
printf("NOOF");
exit(0);
}
