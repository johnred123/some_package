/******************************************************************************

  File Name     : crc32.h
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
#ifndef _CRC32_H_
#define _CRC32_H_

unsigned long crc32(unsigned long crc, const unsigned char *buf, unsigned int len);
unsigned short int get_crc16(unsigned char *buffer, unsigned int size, int init_flag);

#endif /* _CRC32_H_ */
