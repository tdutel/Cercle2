# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 13:39:41 by tdutel            #+#    #+#              #
#    Updated: 2023/02/18 12:18:19 by tdutel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
HEADERD = libft/includes/
HEADER = pipex.h
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC =	pipex.c	pipex_utils.c

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
