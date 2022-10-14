#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#define MAX 1024
#define PORT 8080

int main()
{
    int sockfd, connfd, len;
    struct sockaddr_in servaddr, cli;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
    {
        printf("socket creation failed.\n");
        exit(0);
    }
    printf("Socket created successfully.\n");

    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    if ((bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
    {
        printf("socket bind failed.\n");
        exit(0);
    }

    printf("Binding done successfully.\n");

    if ((listen(sockfd, 5)) != 0)
    {
        printf("Error while listening.\n");
        exit(0);
    }

    printf("Listening for incoming connection.\n");

    len = sizeof(cli);

    connfd = accept(sockfd, (struct sockaddr *)&cli, &len); // blocking function

    if (connfd < 0)
    {
        printf("server accept failed.\n");
        exit(0);
    }

    int n = 0;

    char buffer[MAX];

    n = recv(connfd, buffer, MAX, 0);
    buffer[n] = '\0';

    printf("from the client:\n");
    printf("%s\n", buffer);

    printf("Enter something to send to the client:\n");
    scanf("%s", buffer);

    send(connfd, buffer, strlen(buffer), 0);

    close(connfd);
    close(sockfd);
}
