/* --------------------------------------------------------------------------
 * File: clientSocket.c
 * Author: Sahid Rojas & Esteban Alvarado
 * Description: This module provides a simple interface to connect a C client
 *              to any language using TCP Sockets
 * Version: 2.4 (2019)
 * Instituto Tecnologico de Costa Rica 
 *---------------------------------------------------------------------------*/

#ifndef CLIENT_CLIENTSOCKET_H
#define CLIENT_CLIENTSOCKET_H

#ifdef __WIN32__
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
#else
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#endif

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include<stdio.h>

#define INVALID_SOCKET (SOCKET)(~0)
#define SOCKET_ERROR (-1)
/*
 * This method opens a communication using Sockets. Receive the IP address,
 * the communication port and the message to send. Once the message is sent,
 * the socket is closed.
 */
int send_Message(char ip_addr[] ,int port,char *msg);
/*
 * Method that opens a communication channel through Sockets and once it
 * receives the message closes it.
 */
char* recv_Message(int port);

#endif //CLIENT_CLIENTSOCKET_H
