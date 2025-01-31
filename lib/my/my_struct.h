/*
** EPITECH PROJECT, 2024
** struct
** File description:
** struct
*/
#include <stdint.h>
#include <stdio.h>

#ifndef MY_STRUCT_H
    #define MY_STRUCT_H

typedef struct format_s {
    int error;
    char *err_msg;
    int convert;
    int pad0;
    int padl;
    int space;
    int sign;
    int star;
    int width;
    int precision;
    char *length_modif;
}format_t;

typedef struct str_to_s {
    char **tab;
    int in_tab;
    int in_str;
} str_to_t;

#endif //MY_STRUCT_H
