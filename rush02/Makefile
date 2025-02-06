cc = cc
CFLAGS = -Wall -Wextra -Werror

NAME = rush-02

SRC = main.c ft_putstr.c ft_strchr.c ft_strcmp.c ft_strtok.c helpers.c read_file.c  search.c str_maker.c ternary_callers.c ft_strdup.c something_wrong.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c ft_lib.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean re
