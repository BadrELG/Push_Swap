/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:03:29 by badr              #+#    #+#             */
/*   Updated: 2025/07/02 18:05:26 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Inverse de ra (rotate.c)
void	rra(t_list **list_a, int print)
{
	t_list	*before_last;
	t_list	*last;
	t_list	*tmp;

	if (!list_a || !*list_a || !(*list_a)->next)
		return ;
	tmp = *list_a;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	before_last = tmp;
	last = tmp->next;
	before_last->next = NULL;
	last->next = *list_a;
	*list_a = last;
	if (print)
		ft_putstr_fd("rra\n", 1);
}

// Inverse de rb (rotate.c)
void	rrb(t_list **list_b, int print)
{
	t_list	*before_last;
	t_list	*last;
	t_list	*tmp;

	if (!list_b || !*list_b || !(*list_b)->next)
		return ;
	tmp = *list_b;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	before_last = tmp;
	last = tmp->next;
	before_last->next = NULL;
	last->next = *list_b;
	*list_b = last;
	if (print)
		ft_putstr_fd("rrb\n", 1);
}

// les 2 à la fois
void	rrr(t_list **list_a, t_list **list_b)
{
	rra(list_a, 0);
	rrb(list_b, 0);
	ft_putstr_fd("rrr\n", 1);
}