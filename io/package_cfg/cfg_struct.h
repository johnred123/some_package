/******************************************************************************
  File Name     : cfg_struct.h
  Version       : Initial Draft
  Author        : huangliang
  Created       : 2015/2/9
  Last Modified :
  Description   : 配置文件语法树接口
  Function List :
  History       :
  1.Date        : 2015/2/9
    Author      : huangliang
    Modification: Created file

******************************************************************************/
#ifndef _CFG_STRUCT_H_
#define _CFG_STRUCT_H_
extern int yylineno;

typedef struct ast ast_t;

struct ast{
    int nodetype;
    ast_t *l;
    ast_t *r;
};

typedef struct numval numval_t;
struct numval{
    int nodetype;
    int number;
};

ast_t *newast(int nodetype, ast_t *l, ast_t *r);
ast_t *newnum(int num);

int eval(ast_t *);
void treefree(ast_t *);

void yyerror(char *s, ...);

#endif
