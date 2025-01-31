/*
** EPITECH PROJECT, 2024
** my_strtr
** File description:
** return the first occurence of a word
*/
#include <unistd.h>
#include <stdio.h>

static int verify(int start, int end_find, char *str, char const *f)
{
    int i = 0;
    int n = 0;

    for (i = start; i < end_find; i++) {
        if (str[i] != f[n])
            return 0;
        n++;
    }
    return 1;
}

char *my_strstr(char *str, char const *to_find)
{
    int len_str = 0;
    int len_to_find = 0;
    int start_find = 0;

    for (len_str = 0; str[len_str] != '\0'; len_str++);
    for (len_to_find = 0; to_find[len_to_find] != '\0'; len_to_find++);
    for (start_find = 0; len_to_find <= len_str; start_find++) {
        if (verify(start_find, len_to_find, str, to_find) != 0)
            return &str[start_find];
        len_to_find++;
    }
    return NULL;
}

int my_isinstr(char *str, char to_find)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == to_find)
            return 1;
    return 0;
}
