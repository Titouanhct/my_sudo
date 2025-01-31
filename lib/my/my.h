/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** define your lib
*/
#include <stdint.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdarg.h>

#ifndef MY_H
    #define MY_H

typedef struct node_s {
    void *data;
    struct node_s *next;
    struct node_s *prev;
} node_t;

typedef struct list_s {
    node_t *head;
    node_t *tail;
    int size;
} list_t;

int my_putchar(char c);
int my_isneg(int nb);
int my_put_lnbr(unsigned long long int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
float my_compute_power_rec_f(float nb, int p);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int is_alpha_num(char c);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_isinstr(char *str, char to_find);
int verify(int start, int end_find, char *str, char const *f);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char **my_str_to_word_array(char const *str, char *ignore);
char *my_strdup(char const *src);
int my_show_word_array(char *const *tab);
int my_nbrlen(int nb);
int my_ullnbrlen(unsigned long long int nb);
char *copy_by_indx(char const *src, char *dest, int id_s, int id_f);
char *my_calloc(char *str, int len);
int mini_printf(const char *format, ...);
int my_array_len(char **tab);
void *my_putstrerr(char *str);
int my_cat(char *file);
char *m_ccat(char c1, char c2);
char *my_catchar(char *file);
list_t *list_create(void);
int push_front(list_t *list, void *data);
int push_back(list_t *list, void *data);
int destroy_nodes(list_t *list, node_t *current);
void free_array(char **array);
float get_float(char *delay_s);
int is_float(char *f_str);
char *float_to_str(float nb);

#endif
