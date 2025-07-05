CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

SRC = push_swap.c \
		check_input.c initializer.c  operations.c \
		op_higher.c  parse_args.c  radix_sort.c utils.c utils_atolfree.c

OBJ = $(SRC:.c=.o)

HEADER = push_swap.h

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I. -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_PATH) all

clean:
	make -C $(LIBFT_PATH) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft
