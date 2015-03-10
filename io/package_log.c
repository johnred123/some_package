/******************************************************************************

  File Name     : package_log.c
  Version       : Initial Draft
  Author        : john kazmath (johnred123@github)
  Created       : 
  Last Modified :
  Description   : log api
  Function List :
              package_log_noting
              set_logfile
              suppress_logging
              package_log_func
  History       :
  1.Date        : 
    Author      : john kazmath (johnred123@github)
    Modification: Created file

******************************************************************************/
#include "package_log.h"

FILE *logfile = NULL;

void set_logfile(FILE *logfp)
{
    logfile = logfp;
}

