/*
** EPITECH PROJECT, 2024
** count_percent.c
** File description:
** return nbr of percent
*/

int count_percent(char const *format)
{
    int count = 0;

    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%' && format[i + 1] != '%')
            count++;
    }
    return count;
}
