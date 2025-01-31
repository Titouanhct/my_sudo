/*
** EPITECH PROJECT, 2024
** put_str
** File description:
** display a string
*/
#include "my.h"

int my_putstr(char const *str)
{
    int compt = 0;

    while (str[compt] != '\0') {
        my_putchar(str[compt]);
        compt++;
    }
    return compt;
}
