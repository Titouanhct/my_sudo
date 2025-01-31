/*
** EPITECH PROJECT, 2024
** my_getnbr
** File description:
** take a string and display a number
*/
#include "my.h"

int my_getnbr2(long int nb, int count_s, char const *str, int i)
{
    while (str[i] >= '0' && str[i] <= '9') {
        nb = nb * 10 + (str[i] - 48);
        i++;
        if (nb > 2147483648) {
            return 0;
        }
    }
    if (count_s % 2 != 0) {
        nb *= -1;
    }
    if (nb > 2147483647) {
        return 0;
    }
    return nb;
}

int my_getnbr(char const *str)
{
    int count_s = 0;
    long int numb = 0;
    int i = 0;

    while ((str[i] < 48) || (str[i] > 57)) {
        if (str[i] == '-') {
            count_s++;
            i++;
            continue;
        }
        if (str[i] != '+') {
            return 0;
        }
        i++;
    }
    numb = my_getnbr2(numb, count_s, str, i);
    return numb;
}
