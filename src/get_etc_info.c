/*
** EPITECH PROJECT, 2025
** my_sudo
** File description:
** get_etc_info
*/
#include <sudo.h>

char *get_etc_info(char *srch, int id_info, char *path)
{
    char *str = my_catchar(path);
    char **tab = NULL;
    char **line = NULL;

    if (str == NULL || srch == NULL)
        exit(84);
    tab = my_str_to_word_array(str, "\n");
    free(str);
    for (int i = 0; tab != NULL && tab[i] != NULL; i++){
        line = my_str_to_word_array(tab[i], ":");
        if (my_strcmp(line[0], srch) == 0 || my_strcmp(line[2], srch) == 0){
            str = my_strdup(line[id_info]);
            free_array(line);
            free_array(tab);
            return str;
        }
        free_array(line);
    }
    free_array(tab);
    exit(84);
}

int check_if_exist(char *srch, char *path)
{
    char *str = my_catchar(path);
    char **tab = NULL;
    char **line = NULL;

    if (str == NULL || srch == NULL)
        exit(84);
    tab = my_str_to_word_array(str, "\n");
    free(str);
    for (int i = 0; tab != NULL && tab[i] != NULL; i++){
        line = my_str_to_word_array(tab[i], ":");
        if (my_strcmp(line[0], srch) == 0){
            free_array(line);
            free_array(tab);
            return 0;
        }
        free_array(line);
    }
    free_array(tab);
    return 1;
}
