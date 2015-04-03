/******************************************************************************

  File Name     : myrand.c
  Version       : Initial Draft
  Author        : john kazmath (johnred123@github)
  Created       : 
  Last Modified :
  Description   : get a rand value without lib
  Function List :
                  myrand
                  mysrand
  History       :
  1.Date        : 
    Author      : john kazmath (johnred123@github)
    Modification: Created file

******************************************************************************/

#include <time.h>
#include <stdlib.h>

/*
 * Prototype    : time_rand
 * Description  : creat random number type of int by number
 * Input        : int *buf  
 *                int num   
 * Output       : None
 * Return Value : 
 */
void time_rand(int *buf, int num)
{
    if(buf == NULL)return ;
    srand((unsigned int)time(NULL));
    for(; num >= 0; num --){
        ((int *)buf)[num] = rand();
    }
    return ;
}
