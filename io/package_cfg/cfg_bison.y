%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "cfg_struct.h"
%}

%union {
    ast_t *a;
    int b;
}

%token EOL VALUE

%type <b> VALUE
%type <a> exp

%%

total: 
	| total exp  EOL {
		printf("%d\n", eval($2));
		treefree($2);
	}
;

exp: VALUE {$$ = newnum($1);}
	| exp '=' VALUE { $$ = newast('=', $1, $3);}
;

%%

#if 1
main(int argc, char **argv)
{
    yyparse();
}
#endif

yyerror(char *s, ...)
{
  	va_list ap;
  	va_start(ap, s);

    fprintf(stderr, "%d:error ", yylineno);
    vfprintf(stderr, s, ap);
    fprintf(stderr, "\n");
}
