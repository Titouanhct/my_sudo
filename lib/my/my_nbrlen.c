/*
** EPITECH PROJECT, 2024
** my_nbrlen
** File description:
** know the number of integers in it
*/

int my_nbrlen(int nb)
{
    int count = 0;

    if (nb < 0) {
        nb = nb * -1;
        count++;
    }
    if (nb == 0)
        return 1;
    while (nb > 0) {
        nb /= 10;
        count++;
    }
    return count;
}

int my_lnbrlen(long long int nb)
{
    int count = 0;

    if (nb < 0) {
        nb = nb * -1;
        count++;
    }
    if (nb == 0)
        return 1;
    while (nb > 0) {
        nb /= 10;
        count++;
    }
    return count;
}
