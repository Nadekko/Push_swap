CC = cc

CFLAGS = -Wall -Werror -Wextra -g3

DEF_COLOR = \033[0;39m
YELLOW = \033[0;93m

SRCS =  algo_sort.c algo_utils.c \
		set_group.c set_group_utils.c \
		set_target.c set_top.c \
		main.c

COMMON_SRCS = ft_itoa.c ft_split.c \
		error_utils.c input_utils.c \
		lst_init.c lst_utils.c \
		do_push.c do_reverse.c do_rotate.c do_swap.c \

BONUS_SRCS = checker_push_swap.c \
			./get_next_line/get_next_line_utils.c ./get_next_line/get_next_line.c

OBJS = $(SRCS:.c=.o)

COMMON_OBJS = $(COMMON_SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

FT_PRINTF = ./ft_printf/libftprintf.a

NAME = push_swap

BONUS_NAME = checker

all: $(NAME)
	@echo "$(YELLOW)PUSH SWAP COMPILED!$(DEF_COLOR)"


$(NAME) : $(OBJS) $(COMMON_OBJS) $(FT_PRINTF)
			$(CC) $(CFLAGS) -c $(SRCS) $(COMMON_SRCS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(COMMON_OBJS) $(FT_PRINTF)

bonus: $(BONUS_NAME)

$(BONUS_NAME) : $(BONUS_OBJS) $(COMMON_OBJS) $(FT_PRINTF)
			$(CC) $(CFLAGS) -c -g3 $(BONUS_SRCS) $(COMMON_SRCS)
			$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS) $(COMMON_OBJS) $(FT_PRINTF)

$(FT_PRINTF): 
		make -C ft_printf

clean :
		rm -f $(OBJS) $(COMMON_OBJS) $(BONUS_OBJS)
		rm -f get_next_line.o get_next_line_utils.o
		make -C ft_printf clean

fclean : clean
		rm -f $(NAME) $(BONUS_NAME) 
		make -C ft_printf fclean

re : fclean all

.PHONY : all bonus clean fclean re
