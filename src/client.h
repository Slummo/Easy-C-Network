#ifndef CLIENT_H
#define CLIENT_H

#include "easy-network.h"

//Connect to the server
void conn(Socket s, Info serverInfo, Debug doDebug);

#endif /* CLIENT_H */