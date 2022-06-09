/*
** EPITECH PROJECT, 2022
** nm_objdump
** File description:
** check
*/

#include "nm.h"
#include <string.h>

int check_elf_type(Elf64_Ehdr *elf)
{
    if (elf->e_ident[EI_CLASS] == ELFCLASS32) {
        return (1);
    }
    if (elf->e_ident[EI_CLASS] == ELFCLASS64) {
        return (2);
    }
    return (0);
}

bool check_elf_file(void *buffer)
{
    if (buffer == NULL)
        return false;
    if (strcmp((char *)buffer, "ELF") != 0)
        return true;
    return false;
}