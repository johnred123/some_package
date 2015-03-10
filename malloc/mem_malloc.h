/*
 ************************************************************
 *
 * File Name : mem_malloc.h
 * Discription : 
 * Author : D-Day (Email:305679820@qq.com)
 * Date : Tue Nov 19 13:33:21 CST 2013
 *
 ************************************************************
 */

#ifndef _MALLOC_H_

#define _MALLOC_H_

//#define _C51_COMPLIE_

#define _MAX_SUPPORT_MEMPOOL_SIZE_ 960

/*
 * struct for memory contrl block
 *   whatever type of member ctl_block, the highset bit is flag to a memory area
 *   is available or unavailable(1 unavailable, 0 available), the other bit is
 *   size of the area.
 */
typedef struct mem_ctl_block
{
#if (_MAX_SUPPORT_MEMPOOL_SIZE_ <= 128)
    unsigned char ctl_block;
#else
    
#if (_MAX_SUPPORT_MEMPOOL_SIZE_ <= 1024*32)
    unsigned short ctl_block;
#else
    unsigned int ctl_block;
#endif
    
#endif
} _mem_ctl_block_t;

#define mem_ctl_block_struct_offset sizeof(_mem_ctl_block_t)

#define mem_ctl_block_addr(p) ((_mem_ctl_block_t*)p)
#if (_MAX_SUPPORT_MEMPOOL_SIZE_ <= 128)

#define mem_ctl_avilable(p) (unsigned char)(mem_ctl_block_addr(p)->ctl_block & (1 << 7))
#define mem_ctl_size(p) (unsigned char)(mem_ctl_block_addr(p)->ctl_block & ~(1<< 7))

#else
#if (_MAX_SUPPORT_MEMPOOL_SIZE_ <= 1024*32)

#define mem_ctl_avilable(p) (unsigned short)(mem_ctl_block_addr(p)->ctl_block & ( 1 << 15))
#define mem_ctl_size(p) (unsigned short)(mem_ctl_block_addr(p)->ctl_block & ~(1<< 15))

#else

#define mem_ctl_avilable(p) (unsigned int)(mem_ctl_block_addr(p)->ctl_block & ( 1 << 31))
#define mem_ctl_size(p) (unsigned int)(mem_ctl_block_addr(p)->ctl_block & ~(1<<31))

#endif
#endif

#ifndef _C51_COMPLIE_

extern void *mem_malloc( int size );
extern void mem_free( void *addr );

#else

extern code void *mem_malloc( int size ) compact;
extern code void mem_free( void *addr) compact;

#endif

#endif /* _MALLOC_H_ */
