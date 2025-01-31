/*
** EPITECH PROJECT, 2024
** my_swap
** File description:
** swap the content of two int
*/

void my_swap(int *a, int *b)
{
    int swap;

    swap = *a;
    *a = *b;
    *b = swap;
}
