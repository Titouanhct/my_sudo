/*
** EPITECH PROJECT, 2024
** my_strlowcase
** File description:
** transform all lowcase in upcase
*/
#include "my.h"

char *my_strlowcase(char *str)
{
    int count = 0;

    for (; str[count] != '\0'; count++) {
        if (str[count] > 'Z')
            break;
        if (str[count] >= 'A')
            str[count] = str[count] + 32;
    }
    return str;
}
