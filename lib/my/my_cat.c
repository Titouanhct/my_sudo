/*
** EPITECH PROJECT, 2024
** cat
** File description:
** open and write what's in the file
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my.h"

static long long file_size(char *file)
{
    int fd = 0;
    char buffer[4096];
    long long size = 0;
    int somme = 0;

    fd = open(file, O_RDONLY);
    if (fd == -1)
        return -1;
    for (somme = 1; somme > 0; size += somme)
        somme = read(fd, buffer, 4095);
    if (somme == -1)
        return -1;
    close(fd);
    return size;
}

int my_cat(char *file)
{
    int fd = open(file, O_RDONLY);
    long long int size = file_size(file);
    char *str = malloc(sizeof(char) * (size + 1));
    int err = 0;

    if (str == NULL || fd == -1){
        my_putstrerr("my_cat failure\n");
        return 84;
    }
    err = read(fd, str, size);
    if (err == -1){
        my_putstrerr("my_cat failure\n");
        return 84;
    }
    close(fd);
    str[size] = '\0';
    write(1, str, my_strlen(str));
    return 0;
}
