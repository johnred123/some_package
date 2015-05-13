#ifndef _PACKAGE_LINK_LIST_H_

#define _PACKAGE_LINK_LIST_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

typedef struct package_slink_list_node package_slink_list_node_t;

struct package_slink_list_node {
    void *data;
    package_slink_list_node_t *next_node;
};

typedef struct package_dlink_list_node package_dlink_list_node_t;

struct package_dlink_list_node{
    package_dlink_list_node_t *header_node;
    void *data;
    package_dlink_list_node_t *next_node;
};

#endif
