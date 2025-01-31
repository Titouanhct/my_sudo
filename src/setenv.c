/*
** EPITECH PROJECT, 2025
** my_sudo
** File description:
** setenv
*/
#include "sudo.h"

void set_env(flag_keeper_t *flag_st)
{
    char *file = my_catchar("/etc/environment");
    char **tab;
    char **line;

    if (file == NULL){
        flag_st->env = NULL;
        return;
    }
    tab = my_str_to_word_array(file, "\n");
    free(file);
    for (int i = 0; tab && tab[i]; i++){
        line = my_str_to_word_array(tab[i], "\"");
        flag_st->env->env_l = malloc(sizeof(char *) * my_array_len(tab));
        asprintf(&flag_st->env->env_l[0], "%s%s", line[0], line[1]);
        free_array(line);
    }
    free_array(tab);
}
