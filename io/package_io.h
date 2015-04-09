/******************************************************************************
  File Name     : package_io.h
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
#ifndef _PACKAGE_IO_H_
#define _PACKAGE_IO_H_

#include "package_log.h"
#include <stdint.h>

int io_getArrayFormString(const char *buf, int lenArray, void*array_buf);
int io_flipArray(uint8_t *buf, int lenArray);
void io_printfarray(const uint8_t *array, int len);
int io_getfilesize(FILE *fp);
void *io_copyfiletoram(FILE *fp);

#endif /* _PACKAGE_IO_H_ */
