/******************************************************************************
 
  File Name     : package_thread.c
  Version       : Initial Draft
  Author        : john kazmath (johnred123@github)
  Created       : 
  Last Modified :
  Function List :
  History       :
  1.Date        : 
    Author      : john kazmath (johnred123@github)
    Modification: Created file

******************************************************************************/
#include <unistd.h>
#include <pthread.h>

static pthread_mutex_t package_pthread_mutex;
static pthread_cond_t package_pthread_cond;
static int package_pthread_resume_flag = 0;

void package_pthread_init()
{
    pthread_mutex_init(&package_pthread_mutex,NULL);
    pthread_cond_init(&package_pthread_cond,NULL);
}

void package_pthread_suspend()
{
    pthread_mutex_lock(&package_pthread_mutex);
    package_pthread_resume_flag--;
    pthread_mutex_unlock(&package_pthread_mutex);
}

void package_pthread_resume()
{
    pthread_mutex_lock(&package_pthread_mutex);
    package_pthread_resume_flag++;
    pthread_cond_signal(&package_pthread_cond);
    pthread_mutex_unlock(&package_pthread_mutex);
}

#if 0
void *thread_run()
{
    while(1)
    {
        pthread_mutex_lock(&package_pthread_mutex);
        while(package_pthread_resume_flag <= 0)  
        {
            pthread_cond_wait(&package_pthread_cond,&package_pthread_mutex);
        }

        pthread_mutex_unlock(&package_pthread_mutex);  

        //actual work  
        printf("i am running!\n");  
    }  

}  

int main(int argc,char *argv[])  
{  
    char ch;
    pthread_t p1;  
    package_pthread_init();  
    pthread_create(&p1,NULL,(void *)thread_run,NULL);  

    while(1)  
    {  
        scanf("%c",&ch);  
        switch(ch)  
        {  
            case 's':  
                package_pthread_suspend();  
                break;  
            case 'r':  
                package_pthread_resume();  
                break;  
            default:  
                break;  
        }  
    }
    return 0;
}  
#endif
