/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** m_ccat
*/
#include <stdlib.h>

char *m_ccat(char c1, char c2)
{
    char *str = malloc(sizeof(char) * 3);

    str[0] = c1;
    str[1] = c2;
    str[3] = '\0';
    return str;
}
