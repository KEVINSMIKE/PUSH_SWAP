/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballo <mballo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 12:56:43 by mballo            #+#    #+#             */
/*   Updated: 2026/05/13 14:00:26 by mballo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_lst_free(t_list **lst)
{
    t_list  *next_node;
    t_list  *tmp;

    if (!lst || !*lst)
        return ;
    tmp = *lst;
    while (tmp)
    {
        next_node = tmp->next;
        free(tmp);
        tmp = next_node;
    }
    *lst = NULL;
}

void    ft_lst_addfront(t_list **lst, t_list *new)
{
    if (!lst || !new)
        return ;
    new->next = *lst;
    (*lst) = new;
}
t_list  *ft_lstnew(int content)
{
    t_list  *new;

    new = malloc(sizeof(t_list));
    if (!new)
        return (NULL);
    new->nb = content;
    new->next = NULL;
    return (new);

}

t_list  *ft_create_lst(int argc, char **argv)
{
    int i;
    long value;
    t_list  *lst;
    t_list  *node;

    lst = NULL;
    i = argc - 1;
    while (i >= 0)
    {
        if (ft_is_valid_int(argv[i]) == 0)
        {
            ft_putstr_fd("Error\n", 2);
            ft_lst_free(&lst);
            return (NULL);
        }
        value = ft_atoi(argv[i]);
        if (value == LONG_MAX_VAL)
        {
            ft_lst_free(&lst);
            return (NULL);
        }
        node = ft_lstnew(value);
        ft_lst_addfront(&lst,node);
        i--;
        }
    return (lst);
}

