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

#include <stdint.h>

uint32_t crc32(uint32_t crc, const uint8_t *buf, uint32_t len);
uint16_t get_crc16(uint8_t *buffer, uint32_t size, int init_flag);

#endif /* _CRC32_H_ */
