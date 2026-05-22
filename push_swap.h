/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballo <mballo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 07:48:19 by mballo            #+#    #+#             */
/*   Updated: 2026/05/13 13:45:31 by mballo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
 
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
 
# define INT_MIN      -2147483648
# define INT_MAX       2147483647
# define LONG_MAX_VAL  9223372036854775807
 
typedef enum e_strategy
{
	STRAT_ADAPTIVE = 0,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX,
}	t_strategy;
 
typedef struct s_ops
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_ops;
 
typedef struct s_list
{
	int				nb;
	int				index;
	struct s_list	*next;
}	t_list;
 
typedef struct s_ps
{
	t_list		*a;
	t_list		*b;
	int			size;
	double		disorder;
	t_strategy	strategy;
	int			bench;
	t_ops		ops;
}	t_ps;
 
/* lst_management.c */
void	ft_swap(t_list **lst);
void	ft_push(t_list **lsta, t_list **lstb);
void	ft_rotate(t_list **lst);
void	ft_reverse_rotate(t_list **lst);
 
/* operate.c */
void	ft_sa(t_ps *ps);
void	ft_sb(t_ps *ps);
void	ft_ss(t_ps *ps);
void	ft_pa(t_ps *ps);
void	ft_pb(t_ps *ps);
 
/* operate2.c */
void	ft_ra(t_ps *ps);
void	ft_rb(t_ps *ps);
void	ft_rr(t_ps *ps);
void	ft_rra(t_ps *ps);
void	ft_rrb(t_ps *ps);
 
/* operate3.c */
void	ft_rrr(t_ps *ps);
 
/* parsing.c */
int		ft_is_valid_int(char *str);
long	ft_atoi(char *str);
int		ft_have_double(t_list **lst);
 
/* create_lst.c */
void	ft_lst_free(t_list **lst);
void	ft_lst_addfront(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);
t_list	*ft_create_lst(int argc, char **argv);
 
/* ft_lst_size.c */
int		ft_lst_size(t_list **lst);
int		ft_is_sort(t_list **lst);
void	ft_index(t_list **lst);
double	ft_desorder(t_list **lst);
 
/* affiche_management.c */
int		ft_strcmp(char *s1, char *s2);
char	*ft_get_strategy_name(t_ps *ps);
void	ft_print_bench(t_ps *ps);
 
/* ft_printf.c */
int		ft_printf_fd(int fd, const char *format, ...);
int		ft_find_arg(int fd, char c, va_list args);
int		ft_putfloat_fd(double nbr, int fd);
 
/* ft_printf_utils.c */
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *str, int fd);
int		ft_putnbr(int nbr, int fd);
int		ft_putnbrbase(int fd, long unsigned int nbr, char base);
int		ft_putaddress(int fd, long unsigned int c);
 
/* radix.c */
int		find_max(t_list *pa);
void	ft_radixsort(t_ps *head);
 
/* chunk_sort.c */
void	sort_medium(t_ps *head);
 
/* ft_minimax.c */
void	ft_minimax(t_ps *head);
 
/* ft_algo.c */
void	ft_algo(t_ps *ps);
 
#endif