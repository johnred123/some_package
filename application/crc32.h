/******************************************************************************

  File Name     : crc32.h
  Version       : Initial Draft
  Author        : john kazmath (johnred123@github)
  Created       : 2015/2/10
  Last Modified :
  Description   : crc32 check sum
  Function List :
                  get_crc16
                  crc32 (in library)
  History       :
  1.Date        : 2015/2/10
    Author      : john kazmath (johnred123@github)
    Modification: Created file

******************************************************************************/
#ifndef _CRC32_H_
#define _CRC32_H_

#include <zlib.h>

unsigned short int get_crc16(unsigned char *buffer, unsigned int size, int init_flag);

#endif /* _CRC32_H_ */
