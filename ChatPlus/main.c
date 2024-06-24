#include "headers/main.h"

void user_loop(const int port, const char *address) {
    if (create_and_bind(port, address) < 0) {
        printf("Error: create_and_bind() failed!\n");
        exit(EXIT_FAILURE);
    }

    if (listen_and_accept(port, address) < 0) {
        printf("Error: listen_and_accept() failed!\n");
        exit(EXIT_FAILURE);
    }

    while(1) {
        /*
            Currently working on understanding concurrent fd servers...
        */
    }
}

int main(int argc, char *args[]) {
    if (argc < 3) {
        printf("Error: missing parameters!\nExample usage: %s [port] [address] [threads]\n", args[0]);
        exit(1);
    }

    user_loop(atoi(args[1]), args[2]);
    return 0;
}
  