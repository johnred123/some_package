/******************************************************************************
 
  File Name     : package_thread.h
  Version       : Initial Draft
  Author        : john kazmath (johnred123@github)
  Created       : 
  Last Modified :
  Function List : package_pthread_init
                  package_pthread_suspend
                  package_pthread_resume
  History       :
  1.Date        : 
    Author      : john kazmath (johnred123@github)
    Modification: Created file

******************************************************************************/
#ifndef _PACKAGE_THREAD_H_
#define _PACKAGE_THREAD_H_

#include <unistd.h>
#include <pthread.h>

void package_pthread_init(void);
void package_pthread_suspend(void);
void package_pthread_resume(void);

#endif /* endif for file package_thread.h */
