/******************************************************************************
  File Name     : package_socket.c
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

#include "package_socket.h"

/*
 * Prototype    : creat_block_tcp_ipv4_socket
 * Description  : creat a tcp socket within block
 * Input        : g_servers_options_t *p_sopt  
 * Output       : None
 * Return Value : int
 * Calls        : 
 * Called By    : 
 * 
 * History        :
 * 1.Date         : 
 *    Author       : john kazmath (johnred123@github)
 *    Modification : Created function
 */
int creat_block_tcp_ipv4_socket(g_servers_options_t *p_sopt)
{
    struct timeval timeo = {0};
    struct sockaddr_in serverAddr = {0};
    if(p_sopt == NULL)
        return -1;
    p_sopt->sockets = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    
    if(p_sopt->sockets < 0)
        return -1;
    if(p_sopt->timeout == 0)
        timeo.tv_sec = defulat_socket_timeout;
    else
        timeo.tv_sec = p_sopt->timeout;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(p_sopt->port);
    serverAddr.sin_addr.s_addr = inet_addr(p_sopt->ipaddrs);
    memset(serverAddr.sin_zero, 0x00, 8);

    //send timeout
    setsockopt(p_sopt->sockets, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeo, sizeof(struct timeval));
    //received timeout 
    setsockopt(p_sopt->sockets, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeo, sizeof(struct timeval));
    
    return connect(p_sopt->sockets, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
}

int package_send(int socket, char *buf, int len)
{
    int ret = 0;
    
    if(buf == NULL)return -1;
    
    ret = send(socket, buf, len, 0);
    if(ret < 0  && errno == EAGAIN)
    {
        fprintf(stderr, "[%s]%s\n", "error", "Send timeout");
        return -1;
    }
    return ret;
}

int package_read(int socket, char *buf, int len)
{
    int ret = 0;
    
    if(buf == NULL)return -1;
    
    memset(buf, 0x00, len);

    ret = recv(socket, buf, len, 0);
    if(ret < 0  && errno == EAGAIN)
    {
        fprintf(stderr, "[%s]%s\n", "error", "Read timeout");
        return -1;
    }
    return ret;
}


