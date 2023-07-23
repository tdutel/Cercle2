# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 11:42:08 by tdutel            #+#    #+#              #
#    Updated: 2023/01/04 17:26:09 by tdutel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADERD = includes/
HEADERF = ft_printf.h		libft.h		get_next_line.h

CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCD = srcs/

# files
SRCF = 	ft_atoi.c		ft_bzero.c		ft_calloc.c		ft_isalnum.c	\
		ft_isalpha.c	ft_isascii.c	ft_isdigit.c	ft_isprint.c	\
		ft_itoa.c		ft_memchr.c		ft_memcmp.c		ft_memcpy.c		\
		ft_memmove.c	ft_memset.c		ft_putchar_fd.c	ft_putendl_fd.c	\
		ft_putnbr_fd.c	ft_putstr_fd.c	ft_split.c		ft_strchr.c		\
		ft_strdup.c		ft_striteri.c	ft_strjoin.c	ft_strlcat.c	\
		ft_strlcpy.c	ft_strlen.c		ft_strmapi.c	ft_strncmp.c	\
		ft_strnstr.c	ft_strrchr.c	ft_strtrim.c	ft_substr.c		\
		ft_tolower.c	ft_toupper.c

SRCF += 	ft_lstadd_back_bonus.c	ft_lstadd_front_bonus.c	ft_lstmap_bonus.c	\
		ft_lstlast_bonus.c		ft_lstnew_bonus.c		ft_lstsize_bonus.c	\
		ft_lstdelone_bonus.c	ft_lstclear_bonus.c		ft_lstiter_bonus.c	\
		ft_printf.c				ft_function.c			ft_putfunction.c	\
		get_next_line_utils.c 	get_next_line.c			ft_atoi_long.c

SRC = $(addprefix $(SRCD), $(SRCF))
HEADER = $(addprefix $(HEADERD), $(HEADERF))

OBJ = $(SRC:.c=.o)



all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o : %.c $(HEADER) Makefile
	$(CC) -I $(HEADERD) $(CFLAGS) -o $@ -c $<

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all


check :
		@echo "SRC -> $(SRC)"	

.PHONY: all clean fclean re check