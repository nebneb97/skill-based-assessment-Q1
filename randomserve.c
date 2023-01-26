#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main(){
	int sockfd, newsockfd, portno = 8080;
	struct sockaddr_in serv_addr, cli_addr;
	socklen_t clilen;
	int u;

	//Create a socket
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	//Clear address structure
	memset((char*) &serv_addr, 0, sizeof(serv_addr));

	//Set address and port
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(8080);

	//Bind the socket to the address and port 
	bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));

	//Listen to incoming connections
	listen(sockfd, 5);
	clilen = sizeof(cli_addr);
	for (int i; i < 20; i++) {
	//Accept an incoming connection
	newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

	//Generate a random number between 100 and 999
	int rand_num =rand() %900 + 100;

	//Send the random number to the client 
	u = write(newsockfd, &rand_num, sizeof(rand_num));
	}

	//Closing socket
	close(newsockfd);
	close(sockfd);


	return 0;

}


