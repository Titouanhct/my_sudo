/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** my_catchar
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

char *my_catchar(char *file)
{
    int fd = open(file, O_RDONLY);
    long long int size = file_size(file);
    char *str = malloc(sizeof(char) * (size + 1));
    int err = 0;

    if (str == NULL || fd == -1){
        my_putstrerr("my_catchar open failure\n");
        return NULL;
    }
    err = read(fd, str, size);
    if (err == -1){
        my_putstrerr("my_catchar read failure\n");
        return NULL;
    }
    close(fd);
    str[size] = '\0';
    return str;
}
