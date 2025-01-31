/*
** EPITECH PROJECT, 2024
** my_strcapitalize
** File description:
** put an upcase at the start of every word
*/
#include "my.h"

int is_alpha_num(char c)
{
    if ((c < 'a' || c > 'z') && (c > '9' || c < '0') &&
        (c > 'Z' || c < 'A'))
        return 1;
    return 0;
}

char *my_strcapitalize(char *str)
{
    int count = 0;

    for (; str[count] != '\0'; count++) {
        if (count == 0 && str[count] >= 'a' && str[count] <= 'z')
            str[count] -= 32;
        if (is_alpha_num(str[count -1]) == 1 && str[count] >= 'a'
            && str[count] <= 'z')
            str[count] -= 32;
        if (is_alpha_num(str[count -1]) == 0 && str[count] >= 'A'
            && str[count] <= 'Z')
            str[count] += 32;
    }
    return str;
}
