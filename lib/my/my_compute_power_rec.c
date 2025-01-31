/*
** EPITECH PROJECT, 2024
** my compute power rec
** File description:
** return the power p of a number nb with rec method
*/
#include "my.h"

int my_compute_power_rec(int nb, int p)
{
    int result = nb;

    if (p < 0) {
        return 0;
    }
    if (p == 0) {
        return 1;
    }
    if (p > 1) {
        p--;
        result *= my_compute_power_rec(nb, p);
        if (result > 2147483647)
            return 0;
        return result;
    }
    return result;
}

float my_compute_power_rec_f(float nb, int p)
{
    float result = nb;

    if (p < 0) {
        return 0;
    }
    if (p == 0) {
        return 1;
    }
    if (p > 1) {
        p--;
        result *= my_compute_power_rec_f(nb, p);
        if (result > 2147483647)
            return 0;
    }
    return result;
}
