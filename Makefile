# **************************************************************************** #
#                                VARIABLES                                     #
# **************************************************************************** #

NAME = so_long

SRC = so_long.c \
	   niveau2.c \
	   floodfill.c \
	   parsing.c \
	   get_next_line/get_next_line.c \
	   get_next_line/get_next_line_utils.c
OBJ = $(SRC:.c=.o)
MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx.a
CC = cc
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address
RM = rm -f

# **************************************************************************** #
#                                RULES                                         #
# **************************************************************************** #

all: $(MLX_LIB) $(NAME)

$(MLX_LIB):
	@make -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -Lmlx -lmlx -lXext -lX11 -lm

clean: 
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

#.PHONY: all clean fclean re
