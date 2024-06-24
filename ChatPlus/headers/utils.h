#pragma once

#include "main.h"

#define MAX_SESSIONS 100

// listening available methods.
extern int listen_and_accept(const int port, const char *address);
extern int create_and_bind(const int port, const char *address);

extern struct sockaddr_in my_addr;
extern socklen_t addrlen;

extern int new_sock, sockfd, opt;


