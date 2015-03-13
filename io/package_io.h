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

int io_getArrayFormString(const char *buf, int lenArray, void*array_buf);
int io_flipArray(unsigned char *buf, int lenArray);
void io_printfarray(const unsigned char *array, int len);

#endif /* _PACKAGE_IO_H_ */
