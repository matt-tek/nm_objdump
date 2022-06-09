/*
** EPITECH PROJECT, 2022
** nm_objdump
** File description:
** main
*/

#include "nm.h"

int main(int ac, char **av)
{
    int fd;
    nm_t nm;

    if (ac != 2) {
        fprintf(stderr, "Usage: %s <file>\n", av[0]);
        return 0;
    }
    close(fd);
    return 0;
}