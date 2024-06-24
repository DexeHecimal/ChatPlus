// util functions are commonly type int for error handling upon being called via arithetic comparison.

#include "headers/utils.h"

struct sockaddr_in my_addr;
socklen_t addrlen;

int new_sock, sockfd, opt;

int create_and_bind(const int port, char const *address) {
    memset(&my_addr, 0, sizeof(my_addr)); // ensuring clean intialization removing overlapped options.
    addrlen = sizeof(address);
    opt = 1;

    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(port);
    my_addr.sin_addr.s_addr = inet_addr(address);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Error: socket() failed!\n");
        exit(EXIT_FAILURE);
    }  

    if (bind(sockfd, (struct sockaddr*)&my_addr, sizeof(struct sockaddr)) < 0) {
        printf("Error: \n");
        exit(EXIT_FAILURE);
    }

    // forcefully attaching socket to user defined port.
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        printf("Error: setsockopt() failed!\n");
        exit(EXIT_FAILURE);
    }

    // notification to user_loop().
    return printf("Log: create & bind suceeded...");
}

int listen_and_accept(const int port, char const *address) {
    if (listen(sockfd, MAX_SESSIONS) < 0) {
        printf("Error: listen() failed!");
        exit(EXIT_FAILURE);
    }

    if ((new_sock = accept(sockfd, (struct sockaddr*)&address, &addrlen)) < 0) {
        printf("Error: accept() failed!");
        exit(EXIT_FAILURE);
    }
    return printf("Server is listening on:\nAddress: %s,\nPort: %d", address, port);
}