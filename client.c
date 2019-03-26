#include <sys/socket.h>       /*  Definitions of sockets    */
#include <sys/types.h>        /*  Socket types              */
#include <arpa/inet.h>        /*  inet funtions             */
#include <unistd.h>           /*  misc. UNIX functions      */
#include "helper.h"           /*  Our own helper functions  */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>


//  Global constant
#define MAX_LINE           (1000)

//  Function declarations

int main(int argc, char *argv[]) {

    int       	  conn_s;                 //  connection socket         
    short int 	  port;                   //  port number               
    struct    	  sockaddr_in servaddr;   //  socket address structure  
    char          buffer[MAX_LINE];       // character buffer          
    char*         ip_address;             //  Holds remote IP address   
    char*         remote_port;            //  Holds remote port         
    char*     	  endptr;                 //  for strtol() 

}