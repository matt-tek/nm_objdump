/*
** EPITECH PROJECT, 2022
** nm_objdump
** File description:
** utils
*/

#include "objdump.h"

int exit_error(const char *error)
{
    fprintf(stderr, "%s\n", error);
    exit(84);
}

void print_hexa(char *str, int size)
{
    int i = 0;

    while (i < 16) {
        if (i < size)
            printf("%02x", str[i]);
        else
            printf(" ");
        i++;
    }
    printf(" ");
}