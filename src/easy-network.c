#include "easy-network.h"

void init(Data d, Debug doDebug)
{
    if (WSAStartup(MAKEWORD(2,2),&d) != 0)
    debug(doDebug, 0, "[-]Error in WSAStartup().", WSAGetLastError());
    else debug(doDebug, 1, "[+]WinSock initialized.\n", 0);
}

Socket new(Debug doDebug)
{
    Socket s = socket(AF_INET, SOCK_STREAM, 0);
    if(s == INVALID_SOCKET)
    debug(doDebug, 0, "[-]Error in socket().", WSAGetLastError());
    else debug(doDebug, 1, "[+]Socket created.\n", 0);
    return s;
}

Info set_info(Ip ip, Port port)
{
    Info serverInfo;
    serverInfo.sin_addr.s_addr = inet_addr(ip);
    serverInfo.sin_family = AF_INET;
    serverInfo.sin_port = htons(port);
    return serverInfo;
}

void close_socket(Socket s, Debug doDebug)
{
    if(closesocket(s) == INVALID_SOCKET)
    debug(doDebug, 0, "[-]Error in closesocket().", WSAGetLastError());
    else debug(doDebug, 1, "[+]Socket closed succesfully.\n", 0);
}

void cleanup(Debug doDebug)
{
    if(WSACleanup() == SOCKET_ERROR)
    debug(doDebug, 0, "[-]Error in WSACleanup().", WSAGetLastError());
    else debug(doDebug, 1, "[+]Winsock cleanup was succesful.\n", 0);
}