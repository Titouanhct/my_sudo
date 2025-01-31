/*
** EPITECH PROJECT, 2025
** My_radar
** File description:
** int_to_str
*/
#include "my.h"
#include <stdlib.h>

int len_float(float nb)
{
    int len = 1;

    if (nb < 0)
        nb *= -1;
    for (; nb >= 1; len++)
        nb /= 10;
    return len;
}

char *float_to_str(float nb)
{
    char *str = malloc(sizeof(len_float(nb) + 1));
    int parcour = 0;

    if (str == NULL)
        return "NULL";
    str[0] = '0';
    if (nb < 0.0){
        str[0] = '-';
        nb *= -1;
        parcour++;
    }
    for (; nb >= 1; parcour++){
        str[parcour] = ((int)nb % 10 + 48);
        nb /= 10.0;
    }
    str[parcour] = '\0';
    return my_revstr(str);
}
