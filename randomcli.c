#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
int main(){

	int sockfd, portno = 8080;
	struct sockaddr_in serv_addr;
	int n;
	int rand_num;

	//Create a socket
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	//Clear address structure
	memset((char *) &serv_addr, 0, sizeof(serv_addr));

	//Set address and port
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr("10.0.2.15");
	serv_addr.sin_port = htons(8080);

	//Connect to server
	connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));

	//Read the random number from the server
	n = read(sockfd, &rand_num, sizeof(rand_num));

	//Print random number
	printf("Random number is: %d\n", rand_num);

	//Close the socket
	close(sockfd);

	return 0;
}
