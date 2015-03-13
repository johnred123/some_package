/******************************************************************************

  File Name     : crc32.c
  Version       : Initial Draft
  Author        : john kazmath (johnred123@github)
  Created       : 
  Last Modified :
  Description   : crc32 check sum
  Function List :
                  get_crc16
  History       :
  1.Date        : 
    Author      : john kazmath (johnred123@github)
    Modification: Created file

******************************************************************************/

#include <stdlib.h>

/*
 * Prototype    : get_crc16
 * Description  : get the value of  low 16bit crc
 * Input        : unsigned char *buffer
 *                unsigned int size
 * Output       : None
 * Return Value : unsigned short int
 * Calls        : 
 * Called By    : 
 * 
 * History        :
 * 1.Date         : 
 *    Author       : john kazmath (johnred123@github)
 *    Modification : Created function
 */
unsigned short int get_crc16(unsigned char *buffer, unsigned int size, int init_flag)
{
    if(buffer == NULL) return 0;
    static int crc = 0;
    if(init_flag == 1)
        crc = 0;
    crc = crc32(crc, (char*)buffer, size);
    return (unsigned short int)(0xffff&crc);
}
