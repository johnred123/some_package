/*
 * =====================================================================================
 *
 *       Filename:  utf8-to-unicode.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012-4-22 18:07:24
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  D-Day (), 305679820@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */


/* ----- function define ----- */
#ifndef _UTF8_TO_UNICODE_H_

#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../malloc/mem_malloc.h"

#define _UTF8_TO_UNICODE_H_

#define MAXSIZE 140

#define IS_AF(c)  ((c >= 'A') && (c <= 'F'))
#define IS_af(c)  ((c >= 'a') && (c <= 'f'))
#define IS_09(c)  ((c >= '0') && (c <= '9'))

#define ISVALIDHEX(c)  IS_AF(c) || IS_af(c) || IS_09(c)
#define ISVALIDDEC(c)  IS_09(c)
#define CONVERTDEC(c)  (c - '0')

#define CONVERTHEX_alpha(c)  (IS_AF(c) ? (c - 'A'+10) : (c - 'a'+10))
#define CONVERTHEX(c)   (IS_09(c) ? (c - '0') : CONVERTHEX_alpha(c))

void utf8_to_unicode ( unsigned char *cpInput , int Len );

#endif
