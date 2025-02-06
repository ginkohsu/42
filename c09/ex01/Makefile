CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRCDIR = ./srcs
OBJDIR = ./srcs
HEADDIR = ./includes

SRC = $(SRCDIR)/ft_putchar.c $(SRCDIR)/ft_swap.c $(SRCDIR)/ft_putstr.c $(SRCDIR)/ft_strlen.c $(SRCDIR)/ft_strcmp.c
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
HEADER = $(HEADDIR)/ft.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADER)
	$(CC) $(CFLAGS) -I$(HEADDIR) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
