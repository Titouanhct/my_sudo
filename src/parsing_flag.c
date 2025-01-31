/*
** EPITECH PROJECT, 2025
** my_sudo
** File description:
** parsing_flag
*/
#include "sudo.h"

static
void add_l_group(flag_keeper_t *f_st, int gid)
{
    __gid_t *n_l_gid = malloc(sizeof(__gid_t) * (f_st->groups->len + 1));

    if (n_l_gid == NULL)
        exit(84);
    for (unsigned long i = 0; i < f_st->groups->len; i++)
        n_l_gid[i + 1] = f_st->groups->l_gid[i];
    n_l_gid[0] = gid;
    f_st->groups->len += 1;
    free(f_st->groups->l_gid);
    f_st->groups->l_gid = n_l_gid;
}

static
void set_group_info(char **line, flag_keeper_t *f_st)
{
    if (f_st->fid_u == NULL)
        free(f_st->gid->name);
    f_st->gid->id = atoi(line[2]);
    add_l_group(f_st, f_st->gid->id);
}

static
void set_user_info(char **line, flag_keeper_t *f_st)
{
    free(f_st->uid->name);
    f_st->uid->name = my_strdup(line[0]);
    f_st->uid->id = atoi(line[2]);
    free(f_st->gid->name);
    f_st->gid->id = atoi(line[3]);
    free(f_st->groups->l_gid);
    free(f_st->groups);
    f_st->groups = set_group(f_st->uid->name, f_st->gid);
}

static
void get_group_info(char *srch, flag_keeper_t *f_st)
{
    char *str = my_catchar("/etc/group");
    char **tab = NULL;
    char **line = NULL;

    if (str == NULL || srch == NULL)
        exit(84);
    tab = my_str_to_word_array(str, "\n");
    free(str);
    for (int i = 0; tab != NULL && tab[i] != NULL; i++){
        line = my_str_to_word_array(tab[i], ":");
        if (my_strcmp(line[0], srch) == 0 || my_strcmp(line[2], srch) == 0){
            set_group_info(line, f_st);
            free_array(line);
            free_array(tab);
            return;
        }
        free_array(line);
    }
    free_array(tab);
    exit_wrong_grp(srch);
}

static
bool valid_user(int flag, char **av)
{
    if (av[flag + 1] == NULL)
        flag_h('a', av[0]);
    if (check_if_exist(av[flag + 1], "/etc/passwd") == 1) {
        mini_printf("my_sudo: unknown user %s\n", av[flag +1]);
        printf("my_sudo: error initializing audit plugin sudoers_audit\n");
        exit(84);
    }
    return true;
}

void get_passwd_info(char *srch, flag_keeper_t *f_st)
{
    char *str = my_catchar("/etc/passwd");
    char **tab = NULL;
    char **line = NULL;

    if (str == NULL || srch == NULL)
        exit(84);
    tab = my_str_to_word_array(str, "\n");
    free(str);
    for (int i = 0; tab != NULL && tab[i] != NULL; i++){
        line = my_str_to_word_array(tab[i], ":");
        if (my_strcmp(line[0], srch) == 0 || my_strcmp(line[2], srch) == 0){
            set_user_info(line, f_st);
            free_array(line);
            free_array(tab);
            return;
        }
        free_array(line);
    }
    free_array(tab);
    exit(84);
}

void set_shell(char *srch, flag_keeper_t *f_st)
{
    char *str = my_catchar("/etc/passwd");
    char **tab = NULL;
    char **line = NULL;

    if (str == NULL || srch == NULL)
        exit(84);
    tab = my_str_to_word_array(str, "\n");
    free(str);
    for (int i = 0; tab != NULL && tab[i] != NULL; i++){
        line = my_str_to_word_array(tab[i], ":");
        if (my_strcmp(line[0], srch) == 0){
            f_st->shell = strdup(line[my_array_len(line) - 1]);
            free_array(line);
            free_array(tab);
            return;
        }
        free_array(line);
    }
    free_array(tab);
    exit(84);
}

int check_flag(int flag, flag_keeper_t *flag_st, char **av)
{
    if ((av[flag][1] == 'u' && flag_st->fid_u) ||
        (av[flag][1] == 'g' && flag_st->fid_g) || (av[flag][1] == 'E' &&
        flag_st->env->env_is_called) || (av[flag][1] == 's' && flag_st->shell))
        flag_h('a', av[0]);
    if (av[flag][1] == 'u' || av[flag][1] == 'g'){
        if (av[flag][1] == 'u' && valid_user(flag, av))
            flag_st->fid_u = my_strdup(av[flag + 1]);
        if (av[flag][1] == 'g')
            flag_st->fid_g = my_strdup(av[flag + 1]);
        return 1;
    }
    if (av[flag][1] == 's')
        flag_st->shell = strdup("true\0");
    if (av[flag][1] == 'E')
        flag_st->env->env_is_called = true;
    return 0;
}

void handle_permissions(sudo_t *sudo_st)
{
    if (sudo_st->flag_st->env->env_is_called)
        set_env(sudo_st->flag_st);
    if (sudo_st->flag_st->fid_u != NULL)
        get_passwd_info(sudo_st->flag_st->fid_u, sudo_st->flag_st);
    if (sudo_st->flag_st->fid_g != NULL)
        get_group_info(sudo_st->flag_st->fid_g, sudo_st->flag_st);
    if (sudo_st->flag_st->shell){
        free(sudo_st->flag_st->shell);
        set_shell(sudo_st->flag_st->uid->name, sudo_st->flag_st);
    }
    sudo_st->flag_st->gid->name = get_name("/etc/group", 1);
    check_permission(sudo_st);
    setgroups(sudo_st->flag_st->groups->len, sudo_st->flag_st->groups->l_gid);
    setgid(sudo_st->flag_st->gid->id);
    setuid(sudo_st->flag_st->uid->id);
}

void pars_flag(char **av, sudo_t *sudo_st)
{
    int count = 0;

    for (int pars = 1; av[pars] != NULL; pars++){
        if (av[pars][0] != '-')
            break;
        if (strlen(av[pars]) != 2 || strstr("-g-u-s-E", av[pars]) == NULL)
            flag_h('a', av[0]);
        pars += check_flag(pars, sudo_st->flag_st, av);
        sudo_st->flag_st->command_id = 1 + pars;
    }
    for (int i = sudo_st->flag_st->command_id; av[i] != NULL; i++)
        count++;
    if (count == 0 && !sudo_st->flag_st->shell)
        flag_h('a', av[0]);
    handle_permissions(sudo_st);
}
