/*
** EPITECH PROJECT, 2024
** my_strcpy
** File description:
** copies a string into another
*/
#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = src[i];
    return dest;
}
