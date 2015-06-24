#include "bufc_control.h"

typedef enum {
    bufc_empty = -4,
    bufc_full = -3,
    bufc_notempty = -2,
    bufc_error = -1,
    bufc_ok = 0,
} bufc_return_e;

static bufc_crtlblock_t *bufc = NULL;

/*
    Function Name: bufc_input
    Description: copy 'size' of the data from 'buf' to inside buffer
    Arguments:
    Returns:
*/
static int bufc_input(uint8_t *buf, uint32_t size)
{
    if(buf == NULL || bufc == NULL)
        return bufc_error;
    if((bufc->unread + size) > bufc->maxsize) {
        return bufc_full;
    }

    memcpy(bufc->buffers+ bufc->unread, (const void*)buf, size);
    bufc->unread += size;

    return bufc_ok;
}

/*
    Function Name: bufc_output
    Description: copy 'size' of the data from inside buffer to 'buf'
    Arguments:
    Returns:
*/
static int bufc_output(uint8_t *buf, uint32_t size)
{
    if(buf == NULL || bufc == NULL)
        return bufc_error;
    if(((int32_t)bufc->unread - (int32_t)size) < 0) {
        return bufc_empty;
    }
    memcpy(buf, bufc->buffers, size);

    memcpy(bufc->buffers, bufc->buffers+size, bufc->unread-size);

    return bufc_error;
}

bufc_crtlblock_t* bufc_init_cb(uint8_t *buf, uint32_t size)
{
    bufc_crtlblock_t *ret = NULL;
    if(buf == NULL) {
        return NULL;
    }

    ret = (bufc_crtlblock_t *)malloc(sizeof(bufc_crtlblock_t));
    if(ret == NULL) {
        /* error for malloc */
        return NULL;
    }
    memset(ret, 0x00, sizeof(bufc_crtlblock_t));

    ret->output = bufc_output;
    ret->input = bufc_input;
    ret->buffers = buf;
    ret->maxsize = size;
    ret->unread = 0;
    bufc = ret;
    return ret;
}

int bufc_deinit_cb(bufc_crtlblock_t **cb)
{
    if(cb == NULL && *cb == NULL)
        return bufc_error;
    free((void*) (*cb));
    *cb = NULL;
    return bufc_ok;
}
