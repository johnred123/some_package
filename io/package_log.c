/******************************************************************************

  File Name     : package_log.c
  Version       : Initial Draft
  Author        : john kazmath (johnred123@github)
  Created       : 
  Last Modified :
  Description   : log api
  Function List :
              package_log_noting
              package_log_init
              suppress_logging
              package_log_func
  History       :
  1.Date        : 
    Author      : john kazmath (johnred123@github)
    Modification: Created file

******************************************************************************/
#include "package_log.h"

FILE *package_logfile = NULL;

void package_log_init(FILE *logfp)
{
    package_logfile = logfp;
}

