/*
** EPITECH PROJECT, 2025
** my_sudo
** File description:
** flag_h exit
*/
#include "sudo.h"

void flag_h(char h, char *arg_0)
{
    printf("usage: %s -h\nusage: %s [-ugEs] [command [args ...]]\n"
        , arg_0, arg_0);
    if (h == 'h') {
        exit(0);
    } else
        exit(84);
}

void exit_wrong_grp(char *srch)
{
    mini_printf("my_sudo: unknown group %s\n", srch);
    printf("my_sudo: error initializing audit plugin sudoers_audit\n");
    exit(84);
}
