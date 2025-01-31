##
## EPITECH PROJECT, 2024
## makefile
## File description:
## makefile
##

NAME = my_sudo

SRCS =  src/my_sudo.c		\
		src/my_exec.c 		\
		src/parsing_flag.c 	\
		src/set_struct.c 	\
		src/get_etc_info.c 	\
		src/check_password.c \
		src/flag_h_exit.c	\
		src/setenv.c

CFLAGS = -Wall -Wextra -I ./include -lcrypt

all :
	make -C ./lib
	gcc -o $(NAME) $(SRCS) $(CFLAGS) -L ./lib -lmy
clean:
	rm -f $(NAME)

fclean: clean
	make fclean -C ./lib
	rm -rf *~

test: all
	sudo chmod g+s $(NAME)

unit_tests:	fclean $(NAME)
	gcc -o unit_tests tests/*.c -L./ -lmy -I./include --coverage -lcriterion

tests_run:	unit_tests
	./unit_tests

debug: CFLAGS += -g
debug: fclean all

re : fclean all
