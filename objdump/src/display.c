/*
** EPITECH PROJECT, 2022
** nm_objdump
** File description:
** display
*/

#include "objdump.h"
#include "flags.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

static const char *type_name(int type) {
    switch (type) {
        case BFD_NO_FLAGS:
            return "BFD_NO_FLAGS";
        case HAS_RELOC:
            return "HAS_RELOC";
        case EXEC_P:
            return "EXEC_P";
        case HAS_LINENO:
            return "HAS_LINENO";
        case HAS_DEBUG:
            return "HAS_DEBUG";
        case HAS_SYMS:
            return "HAS_SYMS";
        case HAS_LOCALS:
            return "HAS_LOCALS";
        case DYNAMIC:
            return "DYNAMIC";
        case WP_TEXT:
            return "WP_TEXT";
        case D_PAGED:
            return "D_PAGED";
    }
    return "Unknown";
}

void write_header_info(obj_t *obj)
{
    printf("\n%s:     file format %s\n", obj->file_name, "elf64-x86-64");
    printf("architecture: %s, flags 0x%08x:\n", "x86-64", obj->elf->e_flags);
    printf("%s\n", type_name(obj->elf->e_type));
    printf("start address 0x%016lx\n\n", obj->elf->e_entry);
}

void print_section_info(obj_t *obj)
{
    printf("==== section info ====\n");
    printf("%s %u\n", "Size of program headers:", obj->elf->e_phentsize);
    printf("%s %u\n", "Number of program headers:", obj->elf->e_phnum);
    printf("%s %u\n", "Size of section headers:", obj->elf->e_shentsize);
    printf("%s %u\n", "Number of section headers:", obj->elf->e_shnum);
    printf("%s %u\n", "Section header string table index:",
        obj->elf->e_shstrndx);
}

void print_line(unsigned char *buffer, size_t *index, size_t end, obj_t *obj)
{
    char buf[BUFSIZ] = {0};
    size_t old_index = *index;
    size_t writted = 0;

    // printf(" %04lx ", obj->shdr->sh_addr + *index);
      printf(" %04x ", (int)(obj->shdr->sh_addr + *index - obj->shdr->sh_offset));
    while (old_index < end && old_index < (16 + *index)) {
        if (((old_index - *index) % 4) == 0 && old_index != *index)
            writted += snprintf(buf + writted, BUFSIZ - writted, " ");
        writted += snprintf(buf + writted, BUFSIZ - writted, "%02hhx", buffer[old_index]);
        old_index++;
    }
    writted += snprintf(buf + writted, BUFSIZ - writted, "%*s", (int)writted - 37, "");
    old_index = *index;
    printf("%s", buf);
    writted = 0;
    while (old_index < end && old_index < (16 + *index)) {
        writted += snprintf(buf + writted, BUFSIZ - writted, "%c", isprint(buffer[old_index]) ? buffer[old_index] : '.');
        old_index++;
    }
    writted += snprintf(buf + writted, BUFSIZ - writted, "%*s", (int)writted - 16, "");
    printf("%s\n", buf);
    *index = old_index;
}

void print_section_data(void *buffer, obj_t *obj)
{
    char *str = (char *)(buffer + obj->shdr[obj->elf->e_shstrndx].sh_offset);
    size_t j = 0;
    for (int i = 0; i < obj->elf->e_shnum; i++) {
        if (obj->shdr[i].sh_type == SHT_NULL 
            || obj->shdr[i].sh_type == SHT_NOBITS
            || strcmp(str + obj->shdr[i].sh_name, ".strtab") == 0
            || strcmp(str + obj->shdr[i].sh_name, ".symtab") == 0
            || strcmp(str + obj->shdr[i].sh_name, ".shstrtab") == 0)
            continue;
        printf("\nContents of section %s:\n", str + obj->shdr[i].sh_name);
        j = 0;
        while (j < obj->shdr[i].sh_size) {
            print_line((buffer + obj->shdr[i].sh_offset), &j, obj->shdr[i].sh_size, obj);
        }
    }
}

void display_all(void *buffer, obj_t *obj)
{
    write_header_info(obj);
    print_section_data(buffer, obj);
}



// void print_section_name(my_nmt *nm, Elf64_Shdr *sh)
// {
    // if (sh->sh_type == SHT_NULL || sh->sh_type == SHT_NOBITS
    //     || strcmp(nm->shstr + sh->sh_name, ".strtab") == 0
    //     || strcmp(nm->shstr + sh->sh_name, ".symtab") == 0
    //     || strcmp(nm->shstr + sh->sh_name, ".shstrtab") == 0)
//         return;
//     printf("Contents of section %s:\n", nm->shstr + sh->sh_name);
//     print_hexa_content(nm, sh);
// }
