# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 11:10:49 by matde-ol          #+#    #+#              #
#    Updated: 2024/01/05 15:20:11 by matde-ol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc

DIR_LIB = Libft/
DIR_INC = Libft/
DIR_SRC = src/
DIR_OBJ = obj/

CFLAGS = -Werror -Wextra -Wall -g3
IFLAGS = -I$(DIR_INC)
LFLAGS = -L$(DIR_LIB) -lft

SRC = \
		fdf.c \
		check_data.c \
		init_tab.c \
		calc_utils.c \
		init_color.c \
		other_ft_del.c \
		clear_error.c \
		manage_window.c \
		calc_coord.c
		
LIBFT = $(DIR_LIB)/libft.a

OBJ = $(addprefix $(DIR_OBJ),$(SRC:.c=.o))

all : $(NAME)

$(LIBFT) :
	make bonus -C $(DIR_LIB)

$(NAME) : $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(IFLAGS) $(OBJ) MacroLibX-master/libmlx.so -lSDL2 $(LFLAGS) -o $@

$(DIR_OBJ)%.o : $(DIR_SRC)%.c
	@mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	make -C $(DIR_LIB) clean
	rm -rf $(DIR_OBJ)

fclean: clean
	make -C $(DIR_LIB) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
