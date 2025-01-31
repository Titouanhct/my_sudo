/*
** EPITECH PROJECT, 2025
** my_sudo
** File description:
** is_in_array
*/
#include "my.h"

int is_in_array(char **tab, char *str)
{
    if (tab == NULL || str == NULL)
        return 0;
    for (int i = 0; tab[i] != NULL; i++)
        if (my_strcmp(tab[i], str) == 0)
            return 1;
    return 0;
}
