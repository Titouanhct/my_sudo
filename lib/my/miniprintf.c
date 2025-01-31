/*
** EPITECH PROJECT, 2024
** miniprintf
** File description:
** do the same thing as printf but with less option
*/
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include "my.h"

int put_arg(const char *format, int i, va_list list)
{
    int var = 0;

    if (format[i + 1] == '%')
        return my_putchar('%');
    if (format[i + 1] == 'd'){
        var = va_arg(list, int);
        my_put_lnbr(var);
        return my_nbrlen(var);
    }
    if (format[i + 1] == 's')
        return my_putstr(va_arg(list, char *));
    if (format[i + 1] == 'c')
        return my_putchar(va_arg(list, int));
    if (format[i + 1] == 'i') {
        var = va_arg(list, int);
        my_put_lnbr(var);
        return my_nbrlen(var);
    }
    return 84;
}

int mini_printf(const char *format, ...)
{
    int count_char = 0;
    va_list list;

    va_start(list, format);
    for (int i = 0; format[i] != '\0'; i++){
        if (format[i] == '%' && (format[i + 1] == '%' ||
            format[i + 1] == 'd' || format[i + 1] == 's' ||
            format[i + 1] == 'c' || format[i + 1] == 'i')){
            count_char += put_arg(format, i, list);
            i++;
            continue;
        }
        my_putchar(format[i]);
        count_char++;
    }
    return count_char;
}
