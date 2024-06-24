#pragma once

#include "main.h"

typedef struct {
    char *username[24];
    char *password[64];
    int id[5];
} Account;

extern void create_account(const char *username, const char *password, const int id);