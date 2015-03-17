/******************************************************************************
  File Name     : package_socket.h
  Version       : Initial Draft
  Author        : john kazmath (johnred123@github)
  Created       : 
  Last Modified :
  Description   : Get a array form buffer
  Function List :
  History       :
  1.Date        : 
    Author      : john kazmath (johnred123@github)
    Modification: Created file

******************************************************************************/
#ifndef _PACKAGE_SOCKET_H_
#define _PACKAGE_SOCKET_H_

#define defulat_socket_timeout 1 //sec

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

typedef struct g_servers_options
{
    int sockets;
    int port;
    char *ipaddrs;
} g_servers_options_t;

int creat_block_tcp_ipv4_socket(g_servers_options_t *p_sopt);
int package_send(int socket, char *buf, int len);
int package_read(int socket, char *buf, int len);

#endif
