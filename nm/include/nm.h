/*
** EPITECH PROJECT, 2022
** nm_objdump
** File description:
** nm
*/

#pragma once
    #include <elf.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <elf.h>
    #include <unistd.h>
    #include <sys/mman.h>
    #include <sys/stat.h>
    #include <stdbool.h>
    #include <stdlib.h>

    typedef struct nm_s {
        Elf64_Ehdr *elf;
        Elf64_Shdr *shdr;
        const char *file_name;
        int file_size;
    } nm_t;

int check_elf_type(Elf64_Ehdr *elf);
bool check_elf_file(void *buffer);
