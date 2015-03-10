/******************************************************************************

  File Name     : package_log.h
  Version       : Initial Draft
  Author        : john kazmath (johnred123@github)
  Created       : 
  Last Modified :
  Description   : log api (need libevent)
  Function List :
  History       :
  1.Date        : 
    Author      : john kazmath (johnred123@github)
    Modification: Created file

******************************************************************************/
#ifndef _PACKAGE_LOG_H_
#define _PACKAGE_LOG_H_

#include <stdio.h>
#include <stdlib.h>

#include "config.h"

#define PACKAGE_LOG_DEBUG 0
#define PACKAGE_LOG_MSG   1
#define PACKAGE_LOG_WARN  2
#define PACKAGE_LOG_ERR   3

extern FILE *logfile;

#define log_func(severity,fmt,arg...)\
{\
    const char *s;\
    if (!logfile)\
        return;\
    switch ((severity)){\
        case PACKAGE_LOG_DEBUG: s = "debug"; break;\
        case PACKAGE_LOG_MSG:   s = "msg";   break;\
        case PACKAGE_LOG_WARN:  s = "warn";  break;\
        case PACKAGE_LOG_ERR:   s = "error"; break;\
        default:               s = "?";     break; /* never reached */\
    }\
    fprintf(logfile, "[%s]"fmt"\n", s, ##arg);\
}while(0)

#endif /* _PACKAGE_LOG_H_ */
