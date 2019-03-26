#include <sys/socket.h>       /*  socket definitions        */
#include <sys/types.h>        /*  socket types              */
#include <arpa/inet.h>        /*  inet (3) funtions         */
#include <unistd.h>           /*  misc. UNIX functions      */

#include "helper.h"           /*  Helper functions  */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/*  Global constants  */
#define MAX_LINE           (1000)

// function declarations
// empty for now

int main(int argc, char *argv[]) {
    int       list_s;                //  listening socket          
    int       conn_s;                //  connection socket         
    short int port;                  //  port number               
    struct    sockaddr_in servaddr;  //  socket address structure  
    char      buffer[MAX_LINE];      //  character buffer          
    char     *endptr;                //  for strtol() 
}