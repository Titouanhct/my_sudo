/*
** EPITECH PROJECT, 2024
** my_strlen
** File description:
** display the range of a string
*/
#include "my.h"

int my_strlen(char const *str)
{
    int compt = 0;

    while (str[compt] != '\0') {
        compt++;
    }
    return compt;
}
