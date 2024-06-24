#include "headers/accounts.h"

void create_account(const char *username, const char *password, const int id) {
    FILE *database;
    database = fopen("database.txt", "w");

    if (database == NULL) {
        printf("Error: unable to fopen() file, FILE pointer is empty.");
        exit(EXIT_FAILURE);
    }

    Account new_account = {
        .username = {(char *)username},
        .password = {(char *)password},
        .id = {id}
    };
    
    fprintf(database, "%p:%p:%ls", new_account.username, new_account.password, new_account.id);
    fclose(database);

    printf("Account created: username: %p, password: %p, id: %ls", new_account.username, new_account.password, new_account.id);
    return;
}