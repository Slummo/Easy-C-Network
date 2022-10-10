#include "server.h"

void bind_info(Socket s, Info serverInfo, Debug doDebug)
{
    if(bind(s, (struct sockaddr*)&serverInfo, sizeof(serverInfo)) == SOCKET_ERROR)
    debug(doDebug, 0, "[-]Error in bind().", WSAGetLastError());
    else debug(doDebug, 1, "[+]Binded succesfully to the listening socket.\n", 0);
}

void listen_mode(Socket s, Debug doDebug)
{
    //SOMAXCONN = Max number of connection in the queue
    if(listen(s, SOMAXCONN) == SOCKET_ERROR)
    debug(doDebug, 0, "[-]Error in listen().", WSAGetLastError());
    else debug(doDebug, 1, "[+]Socket set to listen succesfully.\n", 0);
}

Socket acc(Socket listeningSocket, Info clientInfo, Debug doDebug)
{
    int clientSize = sizeof(clientInfo);
    Socket connectedSocket = accept(listeningSocket, (struct sockaddr*)&clientInfo, &clientSize);
    if (connectedSocket == INVALID_SOCKET)
    debug(doDebug, 0, "[-]Error in accept().", WSAGetLastError());
    else debug(doDebug, 1, "[+]Accepted a new connection.\n[+]Connection estabilished between the new socket and the client socket.\n", 0);
    return connectedSocket;
}