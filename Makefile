# **************************************************************************** #
#                                VARIABLES                                     #
# **************************************************************************** #

NAME = so_long

SRC = so_long.c \
	   collectibles.c \
	   exit_process.c \
	   free_functions.c \
	   generate_map.c \
	   handle_key.c \
	   next_levels.c \
	   parsing_init.c \
	   parsing_verifs.c \
	   parsing.c \
	   render_graphics.c \
	   utils.c \
	   levels_directions.c \
	   floodfill_global.c \
	   floodfill_loc.c \
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
