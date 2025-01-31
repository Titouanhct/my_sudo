/*
** EPITECH PROJECT, 2024
** Semester_1
** File description:
** my_apply_on_nodes
*/
#include <stdlib.h>
#include "my.h"

list_t *list_create(void)
{
    list_t *list = malloc(sizeof(list_t));

    if (list == NULL)
        return NULL;
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

int push_front(list_t *list, void *data)
{
    node_t *current;

    if (malloc(sizeof(node_t)) != NULL)
        current = malloc(sizeof(node_t));
    current->data = data;
    current->next = NULL;
    current->prev = NULL;
    if (list->head != NULL){
        list->head->prev = current;
        current->next = list->head;
    }
    if (list->tail == NULL)
        list->tail = current;
    list->head = current;
    list->size++;
    return 0;
}

int push_back(list_t *list, void *data)
{
    node_t *current = NULL;

    if (data == NULL)
        return 84;
    current = malloc(sizeof(node_t));
    if (current == NULL)
        return 84;
    current->data = data;
    current->next = NULL;
    current->prev = NULL;
    if (list->tail != NULL){
        list->tail->next = current;
        current->prev = list->tail;
    }
    if (list->head == NULL)
        list->head = current;
    list->tail = current;
    list->size++;
    return 0;
}

int destroy_nodes(list_t *list, node_t *current)
{
    if (!list)
        return 84;
    if (current){
        if (current->prev){
            current->prev->next = current->next;
        }
        if (current->next){
            current->next->prev = current->prev;
        }
        if (current == list->tail) {
            list->tail = current->prev;
        }
        if (current == list->head){
            list->head = current->next;
        }
    }
    list->size--;
    free(current);
    return 0;
}

static int my_list_size(node_t *begin)
{
    node_t *list;
    int i = 0;

    list = begin;
    for (; list != NULL; i++) {
        list = list->next;
    }
    return i;
}

void my_rev_list(node_t **head)
{
    node_t *list_d;
    node_t *list_f;
    void *temp;
    int len = my_list_size(*head);

    list_d = *head;
    list_f = *head;
    for (int i = 1; i < len; i++) {
        temp = list_d->data;
        list_f = *head;
        for (int n = 1; n < len; n++)
            list_f = list_f->next;
        list_d->data = list_f->data;
        list_f->data = temp;
        list_d = list_d->next;
        len--;
    }
}
