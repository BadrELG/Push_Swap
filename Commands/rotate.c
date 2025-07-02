/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 17:49:40 by badr              #+#    #+#             */
/*   Updated: 2025/07/02 18:02:16 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Décale d'un cran tout les éléments de la liste A (Le premier devient le dernier)
void    ra(t_list **list_a, int print)
{
    t_list *tmp;

    if (!list_a || !*list_a || !(*list_a)->next)
        return ;
    tmp = *list_a;
    *list_a = (*list_a)->next;
    tmp->next = NULL;
    ft_lstadd_back(list_a, tmp);
    if (print)
        ft_putstr_fd("ra\n", 1);
}

// Décale d'un cran tout les éléments de la liste B (Le premier devient le dernier)
void    rb(t_list **list_b, int print)
{
    t_list *tmp;

    if (!list_b || !*list_b || !(*list_b)->next)
        return ;
    tmp = *list_b;
    *list_b = (*list_b)->next;
    tmp->next = NULL;
    ft_lstadd_back(list_b, tmp);
    if (print)
        ft_putstr_fd("rb\n", 1);
}

// Fait les deux à la fois
void    rr(t_list **list_a, t_list **list_b)
{
    ra(list_a, 0);
    rb(list_a, 0);
    ft_putstr_fd("rr\n", 1);
}