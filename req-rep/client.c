#include <zmq.h>
#include <string.h>
#include <stdio.h>
#include  "../headers/helper.h"
int main (void)
{
    printf ("Connecting to hello world server…\n");
    void *context = zmq_ctx_new ();
    void *requester = zmq_socket (context, ZMQ_REQ);
    zmq_connect (requester, "tcp://192.168.18.37:5555");

    int request_nbr;
    for (request_nbr = 0; request_nbr != 10; request_nbr++) {
        printf ("Sending Hello…\n");
        zmq_send (requester, "Hello", 5, 0);
        char  * buffer = recieveMsg(requester);

        printf ("Received World %s\n", buffer);
    }
    zmq_close (requester);
    zmq_ctx_destroy (context);
    return 0;
}