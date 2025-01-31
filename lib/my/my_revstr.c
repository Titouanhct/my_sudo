/*
** EPITECH PROJECT, 2024
** my_revstr
** File description:
** return the sting reversed
*/
#include "my.h"

char *my_revstr(char *str)
{
    int count_len_str = 0;
    int i = 0;
    char temp = str[0];

    for (count_len_str = 0; str[count_len_str] != '\0'; count_len_str++);
    for (count_len_str -= 1; count_len_str > i; count_len_str--) {
        temp = str[count_len_str];
        str[count_len_str] = str[i];
        str[i] = temp;
        i++;
    }
    return str;
}
