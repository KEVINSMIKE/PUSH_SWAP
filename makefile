# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mballo <mballo@learner.42.tech>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/22 09:25:16 by mballo            #+#    #+#              #
#    Updated: 2026/05/22 09:25:16 by mballo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
		radix.c \
		chunk_sort.c \
		ft_minimax.c \
		ft_algo.c
 
OBJS = $(SRCS:.c=.o)
 
all: $(NAME)
 
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
 
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
 
clean:
	rm -f $(OBJS)
 
fclean: clean
	rm -f $(NAME)
 
re: fclean all
 
.PHONY: all clean fclean re