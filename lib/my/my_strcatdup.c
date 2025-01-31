/*
** EPITECH PROJECT, 2024
** my_ls
** File description:
** my_strcatdup
*/

#include "my.h"
#include <stddef.h>
#include <stdlib.h>

char *my_strcatdup(char *dest, char *src)
{
    int l = my_strlen(dest);
    int i = my_strlen(src);
    char *r_value = malloc(sizeof(char)* (i + l + 1));

    if (src == NULL) {
        return NULL;
    } else {
        my_strcpy(r_value, dest);
        my_strcat(r_value, src);
    }
    return r_value;
}
