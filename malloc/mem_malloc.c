/*
 ************************************************************
 *
 * File Name : mem_malloc.c
 * Discription : 
 * Author : D-Day (Email:305679820@qq.com)
 * Date : Tue Nov 19 13:33:21 CST 2013
 *
 ************************************************************
 */

#include <stdlib.h>
#include "mem_malloc.h"

/*
 * global var. is a pointer, and point first memory address.
 */
#ifndef _C51_COMPLIE_

void *mem_available_addr = NULL;
unsigned char real_mempool[_MAX_SUPPORT_MEMPOOL_SIZE_] = {0};

#else

xdata void *mem_available_addr = NULL;
xdata unsigned char real_mempool[_MAX_SUPPORT_MEMPOOL_SIZE_] = {0};

#endif

#define mem_available_addr_end (real_mempool + _MAX_SUPPORT_MEMPOOL_SIZE_ )

/*
 * init a memory pool
 * void *start_addr : A pointer point to the start address for memory pool
 * int size : size of the memory pool
 */
#ifndef _C51_COMPLIE_

void mem_initpool( void *start_addr, int size )

#else

code void mem_initpool( void *start_addr, int size ) compact

#endif
{
    if( size <= 0 && NULL == start_addr )
    {
        return ;
    }
    mem_available_addr = start_addr ;
#if (_MAX_SUPPORT_MEMPOOL_SIZE_ <= 128)
    mem_ctl_block_addr(mem_available_addr)->ctl_block = (unsigned char)size
        - mem_ctl_block_struct_offset;
    mem_ctl_block_addr(mem_available_addr)->ctl_block &= ~(1 << 7);
#else

#if (_MAX_SUPPORT_MEMPOOL_SIZE_ <= 1024*32)
    mem_ctl_block_addr(mem_available_addr)->ctl_block = (unsigned short)size
        - mem_ctl_block_struct_offset;
    mem_ctl_block_addr(mem_available_addr)->ctl_block &= ~(1 << 15);
#else
    mem_ctl_block_addr(mem_available_addr)->ctl_block = (unsigned int)size
        - mem_ctl_block_struct_offset;
    mem_ctl_block_addr(mem_available_addr)->ctl_block &= ~(1 << 31);
#endif

#endif
}

/*
 * function name: found_out_frist_availeable_memaddr
 * Description: found a frist availeable memory address.
 */
#ifndef _C51_COMPLIE_

static void *found_out_frist_availeable_memaddr(void *start_addr, int size)

#else

static code void *found_out_frist_availeable_memaddr(void *start_addr, int size) compact reentrant

#endif
{
    if(NULL == start_addr)
    {
        return NULL;
    }
    if(mem_ctl_avilable(start_addr) > 0)
    {
        return found_out_frist_availeable_memaddr((unsigned char*)start_addr
                + sizeof(_mem_ctl_block_t)
                + mem_ctl_size(start_addr),
                size);
    }
    else
    {
        if(mem_ctl_size(start_addr) >= size)
            return start_addr;
        else
        {
            return found_out_frist_availeable_memaddr((unsigned char*)start_addr
                    + mem_ctl_block_struct_offset
                    + mem_ctl_size(start_addr),
                    size);
        }
    }
}

/*
 * function name: mem_malloc
 * Description: malloc a memory area
 */
#ifndef _C51_COMPLIE_

void *mem_malloc( int size )

#else

code void *mem_malloc( int size ) compact

#endif
{
    unsigned char *backup_addr = NULL;
    unsigned char *available_addr = NULL;
    int backup_size = 0;
    if( size <= 0 && size >= _MAX_SUPPORT_MEMPOOL_SIZE_ )
    {
        return NULL;
    }
    if(NULL == mem_available_addr)
        mem_initpool(real_mempool, _MAX_SUPPORT_MEMPOOL_SIZE_);

    available_addr = (unsigned char*)found_out_frist_availeable_memaddr(mem_available_addr, size);

    backup_size = (mem_ctl_block_addr(available_addr)->ctl_block);

#if (_MAX_SUPPORT_MEMPOOL_SIZE_ <= 128)
    mem_ctl_block_addr(available_addr)->ctl_block = (unsigned char)size;
    mem_ctl_block_addr(available_addr)->ctl_block |= (1 << 7);
#else

#if (_MAX_SUPPORT_MEMPOOL_SIZE_ <= 1024*32)
    mem_ctl_block_addr(available_addr)->ctl_block = (unsigned short)size;
    mem_ctl_block_addr(available_addr)->ctl_block |= (1 << 15);
#else
    mem_ctl_block_addr(available_addr)->ctl_block = (unsigned int)size;
    mem_ctl_block_addr(available_addr)->ctl_block |= (1 << 31);
#endif

#endif

    backup_addr = available_addr + mem_ctl_block_struct_offset + size;
    backup_size -= size + mem_ctl_block_struct_offset;

#if (_MAX_SUPPORT_MEMPOOL_SIZE_ <= 128)
    mem_ctl_block_addr(backup_addr)->ctl_block = (unsigned char)backup_size;
    mem_ctl_block_addr(backup_addr)->ctl_block &= ~(1 << 7);
#else

#if (_MAX_SUPPORT_MEMPOOL_SIZE_ <= 1024*32)
    mem_ctl_block_addr(backup_addr)->ctl_block = (unsigned short)backup_size;
    mem_ctl_block_addr(backup_addr)->ctl_block &= ~(1 << 15);
#else
    mem_ctl_block_addr(backup_addr)->ctl_block = (unsigned int)backup_size;
    mem_ctl_block_addr(backup_addr)->ctl_block &= ~(1 << 31);
#endif

#endif
    return (void*)(available_addr + mem_ctl_block_struct_offset);
}

/*
 * function Name: crimple_memory
 * Description: crimple all the unused memory area
 */
#ifndef _C51_COMPLIE_

static void crimple_memory(void *mem_struct_addr)

#else

static code void crimple_memory(void *mem_struct_addr) compact reentrant

#endif
{
    // Current address point to memory contrl struct
    void *next_mem_struct_addr = mem_struct_addr 
        + mem_ctl_size(mem_struct_addr)
        + mem_ctl_block_struct_offset;
    if ( next_mem_struct_addr >= mem_available_addr_end )
        return ;
    if( mem_ctl_avilable(next_mem_struct_addr) > 0 )//used
    {
        crimple_memory(next_mem_struct_addr);
    }
    else //unused
    {
        if( mem_ctl_avilable(next_mem_struct_addr) == 0 )
        {
            if( mem_ctl_avilable(mem_struct_addr) == 0 )
            {
                ((_mem_ctl_block_t*)mem_struct_addr)->ctl_block = 
                    mem_ctl_size(next_mem_struct_addr)
                    + mem_ctl_size(mem_struct_addr)
                    + mem_ctl_block_struct_offset;
                ((_mem_ctl_block_t*)next_mem_struct_addr)->ctl_block = 0x00;
                crimple_memory(mem_struct_addr);
            }
            else
                crimple_memory(next_mem_struct_addr);
        }
    }
}

/*
 * function name: mem_free
 * Description: free a memory area
 */
#ifndef _C51_COMPLIE_

void mem_free( void *addr )

#else

code void mem_free( void *addr) compact

#endif
{
    if(NULL == addr)
    {
        return ;
    }
    if( NULL == mem_available_addr)
        return ;

#define mem_ctl_struct_addr (addr - mem_ctl_block_struct_offset)
#define next_mem_ctl_struct_addr (addr + mem_ctl_size(mem_ctl_struct_addr))

#if (_MAX_SUPPORT_MEMPOOL_SIZE_ <= 128)
    mem_ctl_block_addr(mem_ctl_struct_addr)->ctl_block &= ~(1 << 7);
#else

#if (_MAX_SUPPORT_MEMPOOL_SIZE_ <= 1024*32)
    mem_ctl_block_addr(mem_ctl_struct_addr)->ctl_block &= ~(1 << 15);
#else
    mem_ctl_block_addr(mem_ctl_struct_addr)->ctl_block &= ~(1 << 31);
#endif

#endif
    crimple_memory(mem_available_addr);
}
