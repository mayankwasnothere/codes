#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <unistd.h>
#define MAX 1024
#define PORT 8080

int main()
{
    int sockfd;
    struct sockaddr_in servaddr, cli;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
    {
        printf("Socket creation failed.\n");
        exit(0);
    }

    printf("Socket creation successfull.\n");
    
    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        printf("connection with the server failed.\n");
        exit(0);
    }

    printf("Connected with server successfully.\n");

    char buffer[MAX];

    printf("Enter something to send to the server:\n");
    scanf("%s", buffer);

    send(sockfd, buffer, strlen(buffer), 0);

    int n = 0;

    n = recv(sockfd, buffer, MAX, 0);
    buffer[n] = '\0';

    printf("From the server:\n");
    printf("%s", buffer);
    printf("\n");

    close(sockfd);
}