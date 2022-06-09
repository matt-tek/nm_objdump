/*
** EPITECH PROJECT, 2022
** nm_objdump
** File description:
** objdump
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

    typedef struct obj_s {
        Elf32_Ehdr *elf32;
        Elf32_Shdr *shdr32;
        Elf64_Ehdr *elf;
        Elf64_Shdr *shdr;
        const char *file_name;
        int file_size;
    } obj_t;

    bool check_elf_file(void *buffer);
    int check_elf_type(Elf64_Ehdr *elf);
    int exit_error(const char *error);
    void write_header_info(obj_t *obj);
    void print_section_info(obj_t *obj);
    int open_file(char *file);
    void load_file(int fd, obj_t *obj);
    void print_section_data(void *buffer, obj_t *obj);
    void display_all(void *buffer, obj_t *obj);
    