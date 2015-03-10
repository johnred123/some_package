/******************************************************************************
  File Name     : package_io.c
  Version       : Initial Draft
  Author        : john kazmath (johnred123@github)
  Created       : 
  Last Modified :
  Description   : io functions
  Function List :
  History       :
  1.Date        : 
    Author      : john kazmath (johnred123@github)
    Modification: Created file

******************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * Prototype    : io_getArrayFormString
 * Description  : Get a array from string
 * Input        : const char *buf
 *                unsigned char lenArray
 * Output       : None
 * Return Value : int
 * Calls        : 
 * Called By    : 
 * 
 * History        :
 * 1.Date         : 
 *    Author       : john kazmath (johnred123@github)
 *    Modification : Created function
 */
int io_getArrayFormString(const char *buf, int lenArray, void *array_buf)
{
    int temp_val = 0;
    if(buf == NULL || array_buf == NULL)
        return -1;
    memset(array_buf, 0x00, lenArray);
    for(;lenArray >= 0; lenArray --){
        if(strlen(buf) < (lenArray * 2)){
            lenArray = strlen(buf)/2;
        }
        sscanf(buf+(lenArray*2), "%02x", &temp_val);
        ((unsigned char*)array_buf)[lenArray] = (unsigned char)temp_val;
    }
}

/*
 * Prototype    : io_printfarray
 * Description  : printf a array from string
 * Input        : const unsigned char *array
 *                int len
 * Output       : None
 * Return Value : int
 * Calls        : 
 * Called By    : 
 * 
 * History        :
 * 1.Date         : 
 *    Author       : john kazmath (johnred123@github)
 *    Modification : Created function
 */
void io_printfarray(const unsigned char *array, int len)
{
    int loop = 0;
    if(len <= 0)return;
    for(loop = 0; loop < len; loop++){
        if(loop%16 == 0 && loop != 0)
            fprintf(stderr,"\n");
        fprintf(stderr,"%02X ",array[loop]);
    }
    fprintf(stderr, "\n");
}

/*
 * Prototype    : io_flipArray
 * Description  : flipped over a array
 * Input        : const char *buf
 *                unsigned char lenArray
 * Output       : None
 * Return Value : int
 * Calls        : 
 * Called By    : 
 * 
 * History        :
 * 1.Date         : 
 *    Author       : john kazmath (johnred123@github)
 *    Modification : Created function
 */
int io_flipArray(char *buf, int lenArray)
{
    int loop = 0;
    if(buf == NULL)
        return -1;
    unsigned char *tempbuf = calloc(1,lenArray);
    lenArray -= 1;
    if(tempbuf == NULL)
        return -1;
    for(; loop <= lenArray; loop ++){
        tempbuf[loop] = buf[lenArray - loop];
    }
    memcpy(buf, tempbuf, loop);
    free(tempbuf);
    return 0;
}
