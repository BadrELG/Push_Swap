/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:40:05 by badr              #+#    #+#             */
/*   Updated: 2025/07/02 17:48:47 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Met le premier element de la liste B au début de la liste A
void    pa(t_list **list_a, t_list **list_b)
{
    t_list *list_tmp;

    if (!list_b)
        return ;
    list_tmp = *list_b;
    *list_b = (*list_b)->next;
    ft_lstadd_front(list_a, list_tmp);
    ft_putstr_fd("pa\n", 1);
}

// Met le premier element de la liste A au début de la liste B
void    pb(t_list **list_a, t_list **list_b)
{
    t_list *list_tmp;

    if (!list_a)
        return ;
    list_tmp = *list_a;
    *list_a = (*list_a)->next;
    ft_lstadd_front(list_b, list_tmp);
    ft_putstr_fd("pb\n", 1);
}