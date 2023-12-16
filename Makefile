# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 11:10:49 by matde-ol          #+#    #+#              #
#    Updated: 2023/12/12 10:53:47 by matde-ol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc

DIR_LIB	= -LLibft/ -Lminilibx-linux/
DIR_SRC = src/
DIR_OBJ = obj/

LIBFT = Libft/libft.a
MINILIBX-LINUX = minilibx-linux/minilibx-linux.a


CFLAGS = -Werror -Wextra -Wall
IFLAGS = -ILibft/ -Iminilibx-linux/
LFLAGS = $(MINILIB-LINUX) $(DIR_LIB) -lft

SRC = \
	


OBJ = $(addprefix $(DIR_OBJ),$(SRC:.c=.o))

all : $(NAME)

$(LIBFT) :
	make -C Libft bonus
	
$(MINILIBX-LINUX) :
	make -C minilibx-linux

$(NAME) : $(MINILIBX-LINUX) $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(IFLAGS) $(OBJ) $(LFLAGS) -o $@

$(DIR_OBJ)%.o : $(DIR_SRC)%.c
	@mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	make -C Libft clean
	make -C minilibx-linux clean
	rm -rf $(DIR_OBJ)

fclean: clean
	make -C Libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re