NAME = libft.a
CC = gcc
FLAGS = -Werror -Wextra -Wall -g
SRC = \
	ft_atoi.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_strncmp.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_strdup.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcmp.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_calloc.c \
	ft_memcpy.c \
	ft_strlcpy.c \
	ft_memmove.c \
	ft_strlcat.c \
	ft_strnstr.c \
	ft_memchr.c \
	ft_strjoin.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_split.c \
	ft_itoa.c \
	ft_substr.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_strtrim.c \
	ft_free_all.c \
	get_next_line.c \
	get_next_line_utils.c
	
SRC_BONUS = \
	ft_lstnew_bonus.c \
	ft_lstsize_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstmap_bonus.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)
	
%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@ -I.

bonus : $(OBJ) $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ_BONUS) $(OBJ)
		
clean :
	rm -f $(OBJ) $(OBJ_BONUS)

fclean : clean
	rm -f $(NAME)
	
re : fclean all
