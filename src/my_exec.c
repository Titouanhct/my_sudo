/*
** EPITECH PROJECT, 2025
** my_sudo
** File description:
** my_exec
*/
#include "sudo.h"

char *get_name(char *path, int wich_id)
{
    int num = getuid();
    char *uid = NULL;

    if (wich_id == 1)
        num = getgid();
    uid = my_int_str(num);
    return get_etc_info(uid, 0, path);
}

int my_exec(char *arg0, char **l_arg, flag_keeper_t *flag_st)
{
    if (flag_st->shell != NULL && arg0 == NULL){
        if (execvpe(flag_st->shell, l_arg, flag_st->env->env_l) == -1){
            perror("execvpe");
            exit(84);
        }
        return 0;
    }
    if (execvpe(arg0, l_arg, flag_st->env->env_l) == -1){
        perror("execlp");
        exit(84);
    }
    return 0;
}
