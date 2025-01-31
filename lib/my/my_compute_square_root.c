/*
** EPITECH PROJECT, 2024
** square root
** File description:
** returns the square root of the nb given
*/
#include "my.h"

int my_compute_square_root(int nb)
{
    int numb = 0;

    if (nb <= 0){
        return 0;
    }
    while (my_compute_power_rec(numb, 2) < nb) {
        numb++;
        if (my_compute_power_rec(numb, 2) == 0)
            return 0;
        if (my_compute_power_rec(numb, 2) == nb) {
            return numb;
        }
    }
    return 0;
}
