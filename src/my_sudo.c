/*
** EPITECH PROJECT, 2025
** my_sudo
** File description:
** my_sudo
*/
#include "sudo.h"

void destroy_remaining(sudo_t *sudo_st)
{
    if (sudo_st->flag_st->groups->l_gid != NULL)
        free(sudo_st->flag_st->groups->l_gid);
    if (sudo_st->flag_st->groups != NULL)
        free(sudo_st->flag_st->groups);
    if (sudo_st->flag_st->uid->name != NULL)
        free(sudo_st->flag_st->uid->name);
    if (sudo_st->flag_st->uid != NULL)
        free(sudo_st->flag_st->uid);
    free(sudo_st->flag_st);
    free(sudo_st);
}

void destroy_struct(sudo_t *sudo_st)
{
    if (sudo_st == NULL)
        return;
    if (sudo_st->pass != NULL)
        free(sudo_st->pass);
    free_array(sudo_st->caller_gs);
    if (sudo_st->flag_st == NULL)
        return;
    if (sudo_st->flag_st->fid_g != NULL)
        free(sudo_st->flag_st->fid_g);
    if (sudo_st->flag_st->fid_u != NULL)
        free(sudo_st->flag_st->fid_u);
    if (sudo_st->flag_st->shell != NULL)
    free(sudo_st->flag_st->shell);
    free_array(sudo_st->flag_st->env->env_l);
    free(sudo_st->flag_st->env);
    if (sudo_st->flag_st->gid->name != NULL)
        free(sudo_st->flag_st->gid->name);
    if (sudo_st->flag_st->gid != NULL)
        free(sudo_st->flag_st->gid);
    destroy_remaining(sudo_st);
}

int main(int ac, char **av)
{
    sudo_t *sudo_st = NULL;

    if (ac == 1)
        flag_h('a', av[0]);
    else if (strcmp(av[1], "-h") == 0)
        flag_h('h', av[0]);
    sudo_st = set_sudo();
    asprintf(&sudo_st->pass, "[my_sudo] password for %s: ",
        get_name("/etc/passwd", 0));
    pars_flag(av, sudo_st);
    my_exec(av[sudo_st->flag_st->command_id],
        &av[sudo_st->flag_st->command_id], sudo_st->flag_st);
    destroy_struct(sudo_st);
    return 0;
}
