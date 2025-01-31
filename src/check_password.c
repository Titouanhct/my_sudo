/*
** EPITECH PROJECT, 2025
** sudo
** File description:
** fread
*/

#include "sudo.h"

bool passwords_are_equals(const char *passwd_pushed, char *True_password,
    sudo_t *sudo_st)
{
    char *crypt_passwd = crypt(passwd_pushed, True_password);

    if (strcmp(crypt_passwd, True_password) == 0){
        sudo_st->autorized = true;
        return true;
    }
    sudo_st->autorized = false;
    return false;
}

bool check_password(const char *passwd_pushed, sudo_t *sudo_st)
{
    char *str = my_catchar("/etc/shadow");
    char **tab = NULL;
    char **line = NULL;

    if (str == NULL || get_name("/etc/passwd", 0) == NULL)
        exit(84);
    tab = my_str_to_word_array(str, "\n");
    free(str);
    for (int i = 0; tab != NULL && tab[i] != NULL; i++){
        line = my_str_to_word_array(tab[i], ":");
        if (my_strcmp(line[0], get_name("/etc/passwd", 0)) == 0 &&
        passwords_are_equals(passwd_pushed, line[1], sudo_st)) {
            free_array(line);
            free_array(tab);
            return true;
        }
        free_array(line);
    }
    free_array(tab);
    return false;
}

static
void parse_grp(char *line, sudo_t *sudo_st, int *res)
{
    char **tab = my_str_to_word_array(line, "\t ");

    if (is_in_array(sudo_st->caller_gs, &tab[0][1])
        || (tab[0][2] == '#' && is_in_array(sudo_st->caller_gs, &tab[0][2])))
        *res = 1;
}

static
void parse_usr(char *line, int *res)
{
    char **tab = my_str_to_word_array(line, "\t ");

    if (strcmp(tab[0], get_name("/etc/passwd", 0)) == 0
        || (tab[0][0] == '#' && atoi(&tab[0][1]) == (int)getuid())) {
        *res = 1;
    }
}

int check_is_in_sudoers(sudo_t *sudo_st)
{
    char *str = my_catchar("/etc/sudoers");
    char **tab = NULL;
    int res = 0;

    if (str == NULL)
        exit(84);
    tab = my_str_to_word_array(str, "\n");
    free(str);
    for (int i = 0; tab != NULL && tab[i] != NULL; i++){
        if (tab[i][0] == '%')
            parse_grp(tab[i], sudo_st, &res);
        else
            parse_usr(tab[i], &res);
    }
    return res;
}

static void check_autorized(int res, sudo_t *sudo_st, int counter)
{
    if (counter == 3) {
        mini_printf("my_sudo: %d incorrect password attempts\n", counter);
        exit(84);
    }
    if (sudo_st->autorized == true && res == 1)
        return;
    if (sudo_st->autorized == true && res == 0) {
        mini_printf("%s is not in the sudoers file.\n",
            get_name("/etc/passwd", 0));
        exit(84);
    }
}

void check_permission(sudo_t *sudo_st)
{
    int counter = 0;
    int res = check_is_in_sudoers(sudo_st);

    if ((int)getuid() == 0) {
        sudo_st->autorized = true;
        return;
    }
    for (; counter < 3; counter++){
        if (check_password(getpass(sudo_st->pass), sudo_st) == 1)
            sudo_st->autorized = true;
        else
            sudo_st->autorized = false;
        if (sudo_st->autorized == true)
            break;
        if (sudo_st->autorized == false && counter < 2)
            write(1, "Sorry, try again.\n", 19);
    }
    check_autorized(res, sudo_st, counter);
}
