/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:46:41 by badr              #+#    #+#             */
/*   Updated: 2025/07/02 18:06:06 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "LibFt/libft.h"
# include <limits.h>

// Commands

void	pa(t_list **list_a, t_list	**list_b);
void	pb(t_list **list_a, t_list **list_b);
void	sa(t_list **list_a, int print);
void	sb(t_list **list_b, int print);
void	ss(t_list **list_a, t_list **list_b);
void	ra(t_list **list_a, int print);
void	rb(t_list **list_b, int print);
void	rr(t_list **list_a, t_list **list_b);
void	rra(t_list **list_a, int print);
void	rrb(t_list **list_b, int print);
void	rrr(t_list **list_a, t_list **list_b);

#endif