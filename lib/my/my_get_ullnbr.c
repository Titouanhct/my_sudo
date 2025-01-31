/*
** EPITECH PROJECT, 2024
** my_get_ullnbr
** File description:
** take a ullint and return a char*
*/
#include "my.h"
#include <stdlib.h>

char *my_get_ullnbr(unsigned long long int nb)
{
    char *str = malloc(sizeof(char) * (my_ullnbrlen(nb)+1));

    if (nb == 0)
        return "0";
    for (int i = 0; nb != 0; i++){
        str[i] = 48 + (nb % 10);
        nb /= 10;
    }
    return str;
}
