/*
** EPITECH PROJECT, 2024
** my_lnbrlen
** File description:
** take a unsigned long long int and return its length
*/

int my_ullnbrlen(unsigned long long int nb)
{
    int count = 0;

    if (nb == 0)
        count++;
    for (; nb > 0; count++)
        nb /= 10;
    return count;
}
