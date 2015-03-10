%{
    #include "cfg_struct.h"
    #include "cfg_bison.tab.h"
%}

%option noyywrap

%%
[0-9]+ {yylval.b = atoi(yytext); return VALUE;}
\n  {return EOL;}
%%
