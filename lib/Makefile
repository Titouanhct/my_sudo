##
## EPITECH PROJECT, 2024
## makefile
## File description:
## makefile
##

NAME = libmy.a

SRCS =  my/my_compute_power_rec.c   \
	my/my_compute_square_root.c \
	my/my_find_prime_sup.c      \
	my/my_getnbr.c              \
	my/my_isneg.c               \
	my/my_is_prime.c            \
	my/my_putchar.c             \
	my/my_put_nbr.c             \
	my/my_put_lnbr.c            \
	my/my_putstr.c              \
	my/my_revstr.c              \
	my/my_showmem.c             \
	my/my_showstr.c             \
	my/my_show_word_array.c     \
	my/my_sort_int_array.c      \
	my/my_strcapitalize.c       \
	my/my_strcat.c              \
	my/my_strcmp.c              \
	my/my_strcpy.c              \
	my/my_strdup.c              \
	my/my_str_isalpha.c         \
	my/my_str_islower.c         \
	my/my_str_isnum.c           \
	my/my_str_isprintable.c     \
	my/my_str_isupper.c         \
	my/my_strlen.c              \
	my/my_strlowcase.c          \
	my/my_strncmp.c             \
	my/my_strncpy.c             \
	my/my_strstr.c              \
	my/my_str_to_word_array.c   \
	my/my_strupcase.c           \
	my/my_swap.c                \
	my/my_nbrlen.c              \
	my/my_ulnbrlen.c 			\
	my/my_ullnbrlen.c			\
	my/my_get_ullnbr.c			\
	my/count_percent.c			\
	my/miniprintf.c			\
	my/my_array_len.c		\
	my/my_putsterr.c		\
	my/my_cat.c				\
	my/m_ccat.c				\
	my/my_catchar.c			\
	my/base_list.c 			\
	my/free_array.c			\
	my/my_get_float.c		\
	my/float_to_str.c		\
	my/my_strcatdup.c		\
	my/my_int_str.c 		\
	my/is_in_array.c 		\

OBJ = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Iinclude/

all : $(NAME)

$(NAME): $(OBJ)
	ar rc libmy.a ./my/*.o
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -rf *~

unit_tests:	fclean $(NAME)
	gcc -o unit_tests tests/*.c -L./ -lmy -I./include --coverage -lcriterion

tests_run:	unit_tests
	./unit_tests

debug: CFLAGS += -g
debug: fclean all

re : fclean all
