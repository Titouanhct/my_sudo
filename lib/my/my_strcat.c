/*
** EPITECH PROJECT, 2024
** my_strcat
** File description:
** idk
*/
#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int z = 0;

    for (; dest[i] != '\0'; i++);
    for (; src[z] != '\0'; z++)
        dest[i + z] = src[z];
    return dest;
}
