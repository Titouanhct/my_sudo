/*
** EPITECH PROJECT, 2024
** my find prime
** File description:
** return the next or equal prime number
*/
#include "my.h"

int my_find_prime_sup(int nb)
{
    int count = nb;

    if (nb < 0 || nb > 2147483647)
        return 0;
    while (count < 2147483647 || my_is_prime(count) != 1)
        count++;
    return count;
}
