#include <zmq.h>
#include <stdio.h>
#include <string.h>
static char * recieveMsg(void * socket) {
    char buffer[255];
    int size = zmq_recv (socket, buffer, 255, 0);
    buffer[size] = '\0';
    return strdup(buffer);
} 
