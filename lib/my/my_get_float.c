/*
** EPITECH PROJECT, 2024
** My_radar
** File description:
** get_float
*/
#include "my.h"

int is_float(char *f_str)
{
    int len_int = 0;

    if (f_str == NULL)
        return 0;
    for (; f_str[len_int] != '.' && f_str[len_int] != '\0'; len_int++);
    for (int i = 0; f_str[i] != '.' && f_str[i] != '\0'; i++)
        if ('9' < f_str[i] && '0' > f_str[i])
            return 0;
    if (f_str[len_int] == '\0')
        return 1;
    for (int i = len_int + 1; f_str[i] != '\0'; i++)
        if ('9' < f_str[i] && '0' > f_str[i])
            return 0;
    return 1;
}

float get_float(char *f_str)
{
    int len_int = 0;
    float power = 0;
    float nb_f = 0;

    for (; f_str[len_int] != '.' && f_str[len_int] != '\0'; len_int++);
    for (int i = 0; f_str[i] != '.' && f_str[i] != '\0'; i++){
        if ('9' < f_str[i] && '0' > f_str[i])
            return 0.0;
        power = my_compute_power_rec_f(10.0, len_int - i - 1);
        nb_f += (f_str[i] - 48) * power;
    }
    if (f_str[len_int] == '\0')
        return nb_f;
    for (int i = len_int + 1; f_str[i] != '\0'; i++){
        if ('9' < f_str[i] && '0' > f_str[i])
            return 0.0;
        power = my_compute_power_rec_f(0.1, i - len_int);
        nb_f += (f_str[i] - 48) * power;
    }
    return nb_f;
}
