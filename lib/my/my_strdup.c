/*
** EPITECH PROJECT, 2024
** my_strdup
** File description:
** functions that allowed memory and copies the string given as argument in it
*/
#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    char *cpy;
    int i;

    for (i = 0; src[i] != '\0'; i++);
    cpy = malloc(sizeof(char) * (i + 1));
    for (i = 0; src[i] != '\0'; i++)
        cpy[i] = src[i];
    cpy[i] = src[i];
    return cpy;
}
