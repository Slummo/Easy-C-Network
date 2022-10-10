#include "client.h"
//flag -lws2_32

void conn(Socket s, Info serverInfo, Debug doDebug)
{
    if (connect(s, (struct sockaddr *)&serverInfo , sizeof(serverInfo)) == SOCKET_ERROR)
    debug(doDebug, 0, "[-]Error in connect().", WSAGetLastError());
    else debug(doDebug, 1, "[+]Connected succesfully to the server.\n", 0);
}