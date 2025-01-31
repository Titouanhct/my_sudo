/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** free_array
*/
#include "my.h"
#include <stdlib.h>

void free_array(char **array)
{
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}
