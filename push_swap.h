/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:46:41 by badr              #+#    #+#             */
/*   Updated: 2025/07/02 19:12:11 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "libft/libft.h"
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

// Parsing

int	ft_check_doubles(int *tab, int size);
int valid_nbr(char *str);
int	ft_ultimate_atoi(char *str, int *error_flag);
int	count_args(int ac, char **av);
static int	clean_tab(char **tab, char **tmp, int k);
char	**split_args(int ac, char **av);

#endif