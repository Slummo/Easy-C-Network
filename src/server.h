#ifndef SERVER_H
#define SERVER_H

#include "easy-network.h"

//Bind the info of the server to the socket
void bind_info(Socket s, Info serverInfo, Debug doDebug);

//Set the socket to listen for clients connections
void listen_mode(Socket s, Debug doDebug);

//Accept the client's connection and return a new connected socket
Socket acc(Socket listeningSocket, Info clientInfo, Debug doDebug);

#endif /* SERVER_H */