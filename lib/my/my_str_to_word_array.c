/*
** EPITECH PROJECT, 2024
** my_str_to_word_array
** File description:
** func that splits a string into words
*/
#include <stdlib.h>
#include "my.h"
#include "my_struct.h"

static int need_to_allow(char const *str, char *ignore)
{
    int len_tab = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if ((i == 0 || my_isinstr(ignore, str[i - 1]) == 1) &&
        my_isinstr(ignore, str[i]) == 0)
            len_tab++;
    }
    return len_tab;
}

static int my_str_word_array_2(str_to_t *all, char const *str, char *ignore)
{
    char *temp;
    int len_temp = 0;

    while (str[all->in_str + len_temp] != '\0' &&
        (my_isinstr(ignore, str[all->in_str + len_temp]) == 0))
        len_temp++;
    temp = malloc(sizeof(char) * (len_temp + 1));
    for (int j = 0; j < len_temp; j++) {
        temp[j] = str[all->in_str];
        all->in_str++;
    }
    temp[len_temp] = '\0';
    all->tab[all->in_tab] = temp;
    return all->in_str;
}

char **my_str_to_word_array(char const *str, char *ignore)
{
    str_to_t *all = malloc(sizeof(str_to_t));
    int len_tab = need_to_allow(str, ignore);
    char **tab = NULL;

    all->in_str = 0;
    all->in_tab = 0;
    all->tab = malloc(sizeof(char *) * (len_tab + 1));
    for (all->in_tab = 0; all->in_tab < len_tab;) {
        if (my_isinstr(ignore, str[all->in_str]) == 1) {
            all->in_str++;
            continue;
        }
        my_str_word_array_2(all, str, ignore);
        all->in_tab++;
    }
    all->tab[len_tab] = NULL;
    tab = all->tab;
    free(all);
    return tab;
}
