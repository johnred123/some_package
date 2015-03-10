/******************************************************************************

  File Name     : cfg.c
  Version       : Initial Draft
  Author        : huangliang
  Created       : 2015/2/9
  Last Modified :
  Description   : 处理配置文件
  Function List :
  History       :
  1.Date        : 2015/2/9
    Author      : huangliang
    Modification: Created file

******************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "cfg_struct.h"

ast_t *newast(int nodetype, ast_t *l, ast_t *r)
{
    ast_t *a = malloc(sizeof(ast_t));
    if(!a){
        yyerror("out of space");
        exit(0);
    }
    a->nodetype = nodetype;
    a->l = l;
    a->r = r;
    return a;
}

ast_t *newnum(int b)
{
    numval_t *a = malloc(sizeof(numval_t));
    if(!a){
        yyerror("out of space");
        exit(0);
    }
    a->nodetype = 'K';
    a->number = b;
    return (ast_t *)a;
}

int eval(ast_t *a)
{
    int v;
    switch(a->nodetype){
        case 'K': v = ((numval_t *)a)->number; break;
        default: printf("internal error: bad node %c\n", a->nodetype);
    }
    return v;
}

void treefree(ast_t*a)
{
    switch(a->nodetype){
        case '=': treefree(a->r);
                  treefree(a->l);
        case 'K': free(a);break;
    }
}
