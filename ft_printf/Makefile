CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = ft_printf.c ft_printf_aff.c ft_printf_nbr.c ft_printf_utils.c ft_printf_unsign.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
