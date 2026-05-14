
NAME = push_swap
 
CC = cc
CFLAGS = -Wall -Wextra -Werror
 
SRCS =	main_push_swap.c \
		parsing.c \
		create_lst.c \
		lst_management.c \
		ft_lst_size.c \
		operate.c \
		operate2.c \
		operate3.c \
		affiche_management.c \
		ft_printf.c \
		ft_printf_utils.c \
		algo.c
 
OBJS = $(SRCS:.c=.o)
 
# règle principale
all: $(NAME)
 
# compilation du binaire
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
 
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
 
.PHONY: all clean fclean re
