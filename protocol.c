/**
	*This file is copyrighted with the CreativeCommons
	* CA-NC-SA license. Please keep this entry in respect
	* of the author's work. Thanks.
	*
	* @author Michal Dziczkowski <mcgiwer@prokonto.pl>
	*
	*/

#include "headers/global.h"

/* Network based functions */

/**
	* Function with:
	*
	* -> creates a socket
	* -> bind and listen on the given address and port
	*/

public void createSocket () {

	config();

	// @todo Do testing

	int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in socketCon;

	if(sizeof(tcp_socket) == 0) {
		printf ("\nNo socket configuration found. Please create one first. Aborting\n");
		return 1;
	}

	socketCon.sin_family = htonl(tcp_socket.family);
	socketCon.sin_addr = htonl(tcp_socket.address);
	socketCon.sin_port = htons(tcp_socket.port);

	bind(
		serverSocket,
		(struct sockaddr *) &socketCon,
		sizeof(socketCon)
	);

	int listening = listen(serverSocket, 10);

	if (listening < 0) {
		printf ("Socket does not listen");
		return 1;
	}
	else {
		printf("\n\n\tServer listening at: %s:%s\n", tcp_socket.address, tcp_socket.port);
	}
}

/**
	* Function with handles user requests
	*
	* @param string Reqest
	*
	*/

public string request(string req) {

	// TODO request handler
}

/**
	* Function with handles responses from the wrapper
	*
	* @param string Response
	*
	*/

public string response(string resp) {

	// TODO response handler
}
