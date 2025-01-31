/*
** EPITECH PROJECT, 2024
** my_is_prime
** File description:
** verify if a number is prime or not
*/
#include "my.h"

int my_is_prime(int nb)
{
    int i;

    if (nb <= 1 || nb > 2147483647) {
        return 0;
    }
    for (i = 2; i < nb; i++) {
        if (nb % i == 0) {
            return 0;
        }
    }
    return 1;
}
