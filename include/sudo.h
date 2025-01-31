/*
** EPITECH PROJECT, 2025
** my_sudo
** File description:
** sudo
*/
#ifndef _GNU_SOURCE
    #define _GNU_SOURCE
#endif

#ifndef INCLUDED_SUDO_H
    #define INCLUDED_SUDO_H
    #include "my.h"
    #include <ctype.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <errno.h>
    #include <crypt.h>
    #include <getopt.h>
    #include <stdbool.h>
    #include <termios.h>
    #include <grp.h>
    #include <pwd.h>

typedef struct info_id_s {
    int id;
    char *name;
} info_id_t;

typedef struct groups_s {
    __gid_t *l_gid;
    size_t len;
} groups_t;

typedef struct env_s {
    char **env_l;
    bool env_is_called;
} env_t;

typedef struct flag_keeper_s {
    info_id_t *uid;
    info_id_t *gid;
    groups_t *groups;
    char *fid_g;
    char *fid_u;
    char *shell;
    env_t *env;
    int command_id;
} flag_keeper_t;

typedef struct sudo_s {
    flag_keeper_t *flag_st;
    bool autorized;
    char *pass;
    char **caller_gs;
} sudo_t;

int my_exec(char *arg0, char **l_arg, flag_keeper_t *flag_st);
void pars_flag(char **av, sudo_t *sudo_st);
sudo_t *set_sudo(void);
char *get_etc_info(char *srch, int id_info, char *path);
char *get_name(char *path, int wich_id);
bool is_in_array(char **tab, char *str);
groups_t *set_group(char *u_name, info_id_t *gid);
void pars_sudoers(char *name, char **tab);
void flag_h(char h, char *arg_0);
void check_permission(sudo_t *sudo_st);
int check_if_exist(char *srch, char *path);
void set_env(flag_keeper_t *flag_st);
void exit_wrong_grp(char *srch);

#endif
