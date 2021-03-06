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
    struct    sockaddr_in clientaddr;//  client address 
    struct    sockaddr_in servaddr;  //  socket address structure  
    char      buffer[MAX_LINE];      //  character buffer          

    if (argc != 2){
        fprintf(stderr, "ERROR! Invalid number of arguments.\n");
        exit(1);
    } else {
        port = atoi(argv[1])        // since server is invoked by the command: <server> <port>
        printf("Port number- %d\n", port);
    }

    if ((list_s = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
        printf("ERROR! Socket could not be created.\n");
		exit(EXIT_FAILURE);         //exit with a failure since the server can no longer proceed
    }

    memset(&servaddr, 0, sizeof(servaddr));     //create the server adress structure

    servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(port);
	servaddr.sin_addr.s_addr = htonl(argv[1]);

    if((bind(list_s, (struct sockaddr*) &servaddr, sizeof(servaddr))) < 0 ){
		printf("ERROR! Failed to bind to the socket provided.\n");
		exit(EXIT_FAILURE); 
	}

    while(1){
        //try to receive the size of the message from the client
        if(recvfrom(list_s, buffer, MAX_LINE, 0, (struct sockaddr*) &clientaddr, sizeof(struct sockaddr_in))) <= 0){
            printf("ERROR! Could not receive from the given client address.\n");
		    exit(EXIT_FAILURE); 
        }

        // Try to write to the client.
        //TODO: add a check to see if the buffer only contains a new line character in which case the message should not be sent back. 
        if((sendto(list_s, buffer, len, 0, (struct sockaddr*) &clientaddr, sizeof(struct sockaddr_in))) <= 0 ){
            printf("ERROR! Could not send to the given client address.\n");
		    exit(EXIT_FAILURE); 
        }
    }
    return 0;
}