# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdutel <tdutel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 14:41:47 by tdutel            #+#    #+#              #
#    Updated: 2023/01/28 13:46:36 by tdutel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ******** VARIABLES ******** #

# ---- Final Executable --- #

NAME			=	so_long

# ---- Directories ---- #

DIR_OBJS		=	bin/

DIR_SRCS		=	srcs/

DIR_HEADERS		=	includes/

# ---- Libs variables ---- #

LIBFT            =   libft/libft.a

MLX              =   mlx/libmlx.a

# ---- Files ---- #

HEADERS_LIST	=	${NAME}.h assets_path.h

SRCS_LIST		=	${NAME}.c		parsing_map.c	parse_check_map.c 	check_valid_map.c \
				display_manager.c	display_edge.c	display_assets.c 	display_player.c  \
					move_file.c		utils.c			error_exit.c

HEADERS			=	${HEADERS_LIST:%.h=${DIR_HEADERS}%.h}

OBJS			=	${SRCS_LIST:%.c=${DIR_OBJS}%.o}

# ---- Compilation ---- #

CC				=	cc

CFLAGS			=	-Wall -Wextra -Werror

FRAMEWORKS		=	-Llibft -Lmlx -lft -lmlx

# ---- OS Variables ---- #

UNAME			=	$(shell uname -s)

ifeq ($(UNAME), Linux)
FRAMEWORKS		+= -lXext -lX11 -lm -lz
endif

ifeq ($(UNAME), Darwin)
FRAMEWORKS		+=	-framework OpenGL -framework AppKit
endif

# ---- Commands ---- #

RM				=	rm -rf

MKDIR			=	mkdir -p

# ********* RULES ******** #

all				:	${NAME}

# ---- Variables Rules ---- #

${NAME}			:	${OBJS} ${HEADERS} ${LIBFT} ${MLX}
					${CC} ${CFLAGS} -I ${DIR_HEADERS} ${OBJS} ${FRAMEWORKS} -o ${NAME}

# ---- Lib rules ---- #

${LIBFT}		:
					make -C libft

${MLX}		:
					make -C mlx

# ---- Compiled Rules ---- #

${OBJS}			:	| ${DIR_OBJS}

${DIR_OBJS}%.o	:	${DIR_SRCS}%.c ${HEADERS}
					${CC} ${CFLAGS} -I ${DIR_HEADERS} -c $< -o $@

${DIR_OBJS}		:
					${MKDIR} ${DIR_OBJS}

# ---- Usual Rules ---- #

clean			:
					${RM} ${OBJS}

fclean			:	clean
					${RM} ${NAME}

re				:	fclean all

debug :	fclean
	$(MAKE) all CFLAGS="-Wall -Werror -Wextra -g"

norme :
	norminette srcs/ includes/

.PHONY:	all clean fclean re debug
