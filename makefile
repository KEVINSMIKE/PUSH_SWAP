NAME = libushswap.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = 	ft_printf.c \
		ft_printf_utils.c

OBJS = $(SRCS:.c=.o)

# règle principale
all: $(NAME)

# création de la lib
$(NAME): $(OBJS)
	rm -f $(NAME)
	ar rcs $(NAME) $(OBJS)

# compilation .c → .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# nettoyage objets
clean:
	rm -f $(OBJS)

# nettoyage complet
fclean: clean
	rm -f $(NAME)

# recompile tout
re: fclean all

.PHONY: re all clean fclean 