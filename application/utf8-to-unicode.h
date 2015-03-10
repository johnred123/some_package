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

void utf8_to_unicode ( unsigned char *cpInput , int Len );

#endif
