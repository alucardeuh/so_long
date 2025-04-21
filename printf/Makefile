NAME = libftprintf.a

SRC = ft_print_putchar.c ft_print_putstr.c ft_print_dec.c ft_print_unsigned.c ft_print_hex_l.c ft_print_hex_u.c ft_print_ptr.c ft_printf.c ft_print_pourcent.c ft_itoa.c ft_strdup.c

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all:	$(NAME)

.c.o:
	gcc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
