/*
** EPITECH PROJECT, 2024
** my_ulnbrlen.c
** File description:
** take a ulint and return his length
*/

int my_ulnbrlen(unsigned long int nb)
{
    int count = 0;

    if (nb == 0)
        count++;
    for (; nb > 0; count++)
        nb /= 10;
    return count;
}
