/*
** EPITECH PROJECT, 2024
** my_strncpy
** File description:
** copies n characters form a string to another
*/
#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int count_len_src = 0;
    int i = 0;

    for (count_len_src = 0; src[count_len_src] != '\0'; count_len_src++);
    for (; n > count_len_src; n--);
    for (i = 0; i < n; i++) {
        dest[i] = src[i];
    }
    return dest;
}
