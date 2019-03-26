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

    if (argc != 3){
        fprintf(stderr, "ERROR! Invalid number of arguments.\n");
        exit();
    } else {
        port = argv[1];
        ip_address = argv[2];
        printf("Port number %d and IP address received %s", port, ip_address);
    }

	if(conn_s = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
        fprintf(stderr, "ERROR! Unable to create socket.\n");
        exit(EXIT_FAILURE);
    }

	if(bind(soc, (struct sockaddr*) &servaddr, sizeof(servaddr)) < 0 ){
		fprintf(stderr, "ERROR! Could not bind name to the given socket.\n");
        exit(EXIT_FAILURE);
	}

	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(port);
	servaddr.sin_addr.s_addr = INADDR_ANY;

    //if stdin is s then send the character string over to the server
    if (getc(stdin) == s){
        fgets(buffer, MAX_LINE, stdin);
        sendto(conn_s, buffer, MAX_LINE, &servaddr, sizeof(struct sockaddr_in))
    }
    //if stdin is q then quit the program
    if (getc(stdin) == q){
        exit(EXIT_SUCCESS);     //quit successfully as it was asked for by the user
    }
}