# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 12:47:22 by tdutel            #+#    #+#              #
#    Updated: 2023/01/17 13:04:30 by tdutel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap
HEADERD = libft/includes/
HEADER = push_swap.h
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = 	push_swap.c 	check_main.c	stack_init.c	stack_tools.c	\
		ft_swap.c 		ft_push.c		ft_rotate.c 	ft_reverse.c	\
		sort_tab.c		sort_tools.c	radix_sort.c	free_process.c

LIBPATH = libft/
OBJ = $(SRC:.c=.o)



all : lib
	make $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -l ft -L $(LIBPATH) -o $@

%.o : %.c $(HEADER) Makefile
	$(CC) -I $(HEADERD) $(CFLAGS) -o $@ -c $<

lib : 
	$(MAKE) -C libft/

clean :
	rm -f $(OBJ)
	$(MAKE) clean -C libft/

fclean : 
	$(MAKE) clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft/

re : fclean
	make all

debug :
	$(MAKE) all CFLAGS="-Wall -Werror -Wextra -g"


.PHONY: all lib clean fclean re debug
