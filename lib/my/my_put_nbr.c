/*
** EPITECH PROJECT, 2024
** my_put_nbr.c
** File description:
** diplay anumber
*/
#include "my.h"
#include <stdint.h>

union byte64 {
    long long int nb;
    uint64_t nb_bytes;
};

int my_put_nbr(long long int nb)
{
    union byte64 byte64_u;

    byte64_u.nb = nb;
    if (byte64_u.nb_bytes == 0x8000000000000000)
        nb = 0;
    if (nb == -2147483648) {
        my_putstr("-2147483648");
        return 0;
    }
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
        my_put_nbr(nb);
    } else if (nb < 10) {
        my_putchar(nb + 48);
    } else {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    return 0;
}
