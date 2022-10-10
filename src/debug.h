#ifndef __DEBUG__
#define __DEBUG__

#include <stdlib.h>
#include <stdio.h>

#define Debug int

void debug(Debug doDebug, int success, char* msg, int errorCode);

#endif