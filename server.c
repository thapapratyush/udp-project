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

    if (argc != 2){
        fprintf(stderr, "ERROR! Invalid number of arguments.\n");
        exit(1);
    } else {
        port = atoi(argv[1])        // since server is invoked by the command: <server> <port>
        printf("Port number- %d\n", port);
    }

    if ((list_s = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
        printf("ERROR! Socket could not be created.\n");
		exit(EXIT_FAILURE);
    }
}