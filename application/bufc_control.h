#ifndef _IO_CONTROL_H_
#define _IO_CONTROL_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int32_t (*bufc_func_input)(uint8_t *buf, uint32_t len);
typedef int32_t (*bufc_func_output)(uint8_t *buf, uint32_t len);

typedef struct {
    bufc_func_output output;
    bufc_func_input input;
    uint8_t *buffers;
    uint32_t maxsize;
    uint32_t unread;
} bufc_crtlblock_t;

bufc_crtlblock_t* bufc_init_cb(uint8_t *buf, uint32_t size);
int bufc_deinit_cb(bufc_crtlblock_t **cb);

#endif
