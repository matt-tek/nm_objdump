/*
** EPITECH PROJECT, 2022
** nm_objdump
** File description:
** main
*/

#include "objdump.h"
#include <unistd.h>
#include <string.h>

obj_t *init_struct(void)
{
    obj_t *obj = malloc(sizeof(obj_t));

    obj->elf32 = NULL;
    obj->elf = NULL;
    obj->shdr32 = NULL;
    obj->shdr = NULL;
    obj->file_name = NULL;
    obj->file_size = 0;
    return (obj);
}

int main(int ac, char **av)
{
    int fd;
    obj_t *obj = init_struct();

    if (ac != 2) {
        fprintf(stderr, "Usage: %s <file>\n", av[0]);
        return 0;
    }
    obj->file_name = strdup(av[1]);
    fd = open_file(av[1]);
    load_file(fd, obj);
    close(fd);
    return 0;
}

// int main (int ac, char **av)
// {
//     int fd ;
//     void * buf ;
//     struct stat s ;
//     fd = open (av[1], O_RDONLY ) ;
//     if (fd != -1) {
//     fstat(fd ,&s) ;
//     buf = mmap (NULL, s.st_size , PROT_READ , MAP_PRIVATE , fd , 0) ;
//     if ( buf != -1) {
//     printf (" mmap (%s) : %08xn%s\n", av[1], buf, buf) ;
//     munmap (buf, s.st_size ) ;
//     } else {
//         perror(" mmap ") ;
//     }
//         close (fd);
//     }
// }

    // fd = open(av[1], O_RDONLY);
    // if (fd != -1) {
    //     fstat(fd, &s);
    //     buf = mmap(NULL, s.st_size, PROT_READ, MAP_PRIVATE , fd , 0) ;
    //     if (buf != MAP_FAILED) {
    //         printf ("mmap (%s) : %08x\n", av[1] , buf);
    //         elf = buf;
    //         printf ("Section Header Table : addr = %08x , nb = %d, name section = %08x\n", elf->e_shoff, elf->e_shnum, elf->e_shstrndx);
    //     } else
    //         perror ("mmap");
    //     check_elf_type(elf);
    //     close (fd);
    // }