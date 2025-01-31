/*
** EPITECH PROJECT, 2024
** my_int_str.c
** File description:
** convert an int to and char *
*/

#include "my.h"
#include <stdlib.h>

char *put_inside_str(char *str, int nb)
{
    int i = 0;
    int res;

    for (; nb > 0; i++) {
        res = nb % 10;
        str[i] = res + '0';
        nb /= 10;
    }
    return str;
}

char *my_int_str(unsigned long int nb)
{
    unsigned long long int res = 0;
    int j = 0;
    char *str;

    res = nb;
    if (res == 0)
        return "0";
    for (; res > 0; j++)
        res /= 10;
    str = malloc(sizeof(char) * (8));
    str = put_inside_str(str, nb);
    str[j] = '\0';
    my_revstr(str);
    return str;
}
