/*
** EPITECH PROJECT, 2022
** nm_objdump
** File description:
** parser
*/
#include "objdump.h"

void load_file(int fd, obj_t *obj)
{
    void *buffer;
    
    obj->file_size = lseek(fd, 0, SEEK_END);
    if (obj->file_size == -1)
        exit_error("lseek");
    buffer = mmap(NULL, obj->file_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (buffer == MAP_FAILED)
        exit_error("mmap");
    if (!check_elf_file(buffer))
        exit_error("Not an ELF file");
    else {
        obj->elf = (Elf64_Ehdr *)buffer;
        obj->shdr = (Elf64_Shdr *)(buffer + obj->elf->e_shoff);
        if (check_elf_type(obj->elf) == 1) {
            obj->elf32 = (Elf32_Ehdr *)buffer;
            obj->shdr32 = (Elf32_Shdr *)(buffer + obj->elf32->e_shoff);
        }
    }
    display_all(buffer, obj);
}

int open_file(char *file)
{
    int fd;
    struct stat s;

    fd = open(file, O_RDONLY);
    if (fd == -1)
        exit_error("open error");
    fstat(fd, &s);
    if (s.st_size == 0)
        exit_error("file is empty");
    return (fd);
}

