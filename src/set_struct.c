/*
** EPITECH PROJECT, 2025
** my_sudo
** File description:
** set_struct
*/
#include "sudo.h"

info_id_t *set_id_info(char *name, int id)
{
    info_id_t *info_idst = malloc(sizeof(info_id_t));

    if (info_idst == NULL)
        exit(84);
    info_idst->id = id;
    info_idst->name = my_strdup(name);
    return info_idst;
}

int nb_groups(char *u_name, char **tab, int gid)
{
    char **line = NULL;
    char **is_ab_user = NULL;
    int len = 0;

    for (int j = 0; tab[j] != NULL; j++){
        line = my_str_to_word_array(tab[j], ":");
        if (atoi(line[2]) == gid || line[3] == NULL){
            free(line);
            continue;
        }
        is_ab_user = my_str_to_word_array(line[3], ",");
        if (is_in_array(is_ab_user, u_name) == 1)
            len++;
        free_array(is_ab_user);
        free_array(line);
    }
    return len + 1;
}

void set_l_gid(char *u_name, char **tab, int gid, __gid_t *l_gid)
{
    char **line = NULL;
    char **is_ab_user = NULL;
    int in_l_gid = 1;

    for (int j = 0; tab[j] != NULL; j++){
        line = my_str_to_word_array(tab[j], ":");
        if (atoi(line[2]) == gid || line[3] == NULL){
            free(line);
            continue;
        }
        is_ab_user = my_str_to_word_array(line[3], ",");
        if (is_in_array(is_ab_user, u_name)){
            l_gid[in_l_gid] = atoi(line[2]);
            in_l_gid++;
        }
        free_array(is_ab_user);
        free_array(line);
    }
    l_gid[0] = gid;
}

groups_t *set_group(char *u_name, info_id_t *gid)
{
    groups_t *group = malloc(sizeof(groups_t));
    char *file = my_catchar("/etc/group");
    char **tab = NULL;

    if (file == NULL || group == NULL)
        exit(84);
    tab = my_str_to_word_array(file, "\n");
    group->len = nb_groups(u_name, tab, gid->id);
    group->l_gid = malloc(sizeof(__gid_t) * group->len);
    if (group->l_gid == NULL)
        exit(84);
    set_l_gid(u_name, tab, gid->id, group->l_gid);
    free_array(tab);
    free(file);
    return group;
}

static
void set_l_groups(char *u_name, char **tab, char **groups)
{
    char **line = NULL;
    char **is_ab_user = NULL;
    int in_l_gid = 2;

    for (int j = 0; tab[j] != NULL; j++){
        line = my_str_to_word_array(tab[j], ":");
        if (atoi(line[2]) == (int)getgid() || line[3] == NULL){
            free(line);
            continue;
        }
        is_ab_user = my_str_to_word_array(line[3], ",");
        if (is_in_array(is_ab_user, u_name)){
            groups[in_l_gid + 1] = my_strdup(line[2]);
            groups[in_l_gid] = my_strdup(line[0]);
            in_l_gid += 2;
        }
        free_array(is_ab_user);
        free_array(line);
    }
}

static
char **set_groups(char *u_name)
{
    char **groups = NULL;
    char *file = my_catchar("/etc/group");
    char **tab = NULL;
    int len = 0;

    if (file == NULL)
        exit(84);
    tab = my_str_to_word_array(file, "\n");
    len = nb_groups(u_name, tab, (int)getgid()) * 2 + 1;
    groups = malloc(sizeof(char *) * len);
    if (groups == NULL)
        exit(84);
    groups[0] = get_name("/etc/group", 1);
    asprintf(&groups[1], "%d", getuid());
    groups[len - 1] = NULL;
    set_l_groups(u_name, tab, groups);
    free_array(tab);
    free(file);
    return groups;
}

static
flag_keeper_t *set_flag_st(void)
{
    flag_keeper_t *flag_st = malloc(sizeof(flag_keeper_t));

    if (flag_st == NULL)
        exit(84);
    flag_st->command_id = 1;
    flag_st->env = malloc(sizeof(env_t));
    flag_st->env->env_is_called = false;
    flag_st->env->env_l = NULL;
    flag_st->shell = NULL;
    flag_st->fid_g = NULL;
    flag_st->fid_u = NULL;
    flag_st->gid = set_id_info("root", 0);
    flag_st->uid = set_id_info("root", 0);
    flag_st->groups = set_group("root", flag_st->gid);
    return flag_st;
}

sudo_t *set_sudo(void)
{
    sudo_t *sudo_st = malloc(sizeof(sudo_t));

    if (sudo_st == NULL)
        exit(84);
    sudo_st->autorized = false;
    sudo_st->flag_st = set_flag_st();
    sudo_st->caller_gs = set_groups(get_name("/etc/passwd", 0));
    return sudo_st;
}
