#ifndef EASY_NETWORK_H
#define EASY_NETWORK_H

#include <winsock2.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "debug.h"

//flag -lws2_32
#pragma comment(lib,"ws2_32.lib")

#define Data WSADATA
#define Socket SOCKET
#define Info struct sockaddr_in
#define Ip const char*
#define Port short

//Initialize Winsock API
void init(Data d, Debug doDebug);

//Create the socket
Socket new(Debug doDebug);

//Set the info of the server to connect to
Info set_info(Ip ip, Port port);

//Close the socket
void close_socket(Socket s, Debug doDebug);

//Cleanup Winsock
void cleanup(Debug doDebug);

#endif /* EASY_NETWORK_H */