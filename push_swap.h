/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:46:41 by badr              #+#    #+#             */
/*   Updated: 2025/07/04 19:33:50 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

typedef struct s_node
{
    int             value;     // Valeur réelle de l'élément
    int             index;     // Position finale dans le tableau trié
    int             position;  // Position actuelle dans la pile
    int             target_pos; // Position cible dans l'autre pile
    int             cost_a;    // Coût pour positionner dans la pile A
    int             cost_b;    // Coût pour positionner dans la pile B
    struct s_node   *next;
} t_node;

typedef struct s_stack
{
    t_node  *top;
    int     size;
} t_stack;

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
int	*parse_args(int ac, char **av);
static int	clean_tab(char **tab, char **tmp, int k);
char	**split_args(int ac, char **av);


/* Fonctions de stack_utils.c */
t_stack	*init_stack(void);
void	add_top(t_stack *stack, int value);
void	update_positions(t_stack *stack);
void	free_stack(t_stack *stack);
int		is_sorted(t_stack *stack);

/* Fonctions de stack_index.c */
void	index_stack(t_stack *stack);
int		get_chunk_count(int size);
int		get_chunk_min(int size, int chunk_count, int chunk_num);
int		get_chunk_max(int size, int chunk_count, int chunk_num);

/* Fonctions de chunk.c */
int		is_in_chunk(int index, int chunk_min, int chunk_max);
int		calculate_rotation_cost(int position, int stack_size);
int		get_node_index(t_node *node);
int		find_first_in_chunk(t_stack *stack, int chunk_min, int chunk_max);
int		find_closest_chunk_element(t_stack *stack_a, int chunk_min, int chunk_max, int *position);
int		find_closest_in_chunk(t_stack *stack, int chunk_min, int chunk_max);

/* Fonctions de push_chunk.c */
void	rotate_to_top(t_stack *stack, int position);
void	optimize_b_position(t_stack *stack_b, int chunk_min, int chunk_max);
void	push_and_optimize(t_stack *stack_a, t_stack *stack_b, int chunk_min, int chunk_max);
void	process_chunk(t_stack *stack_a, t_stack *stack_b, int chunk_min, int chunk_max);
void	push_chunks_to_b(t_stack *stack_a, t_stack *stack_b);

/* Fonctions de target_position.c */
int		get_min_position(t_stack *stack);
int		find_target_position(t_stack *stack_a, int b_index);
void	get_target_positions(t_stack *stack_a, t_stack *stack_b);

/* Fonctions de cost_and_execute.c */
void	calculate_costs(t_stack *stack_a, t_stack *stack_b);
t_node	*find_cheapest(t_stack *stack_b);
void	execute_rotations(t_stack *stack_a, t_stack *stack_b, int cost_a, int cost_b);
void	execute_cheapest_move(t_stack *stack_a, t_stack *stack_b);

/* Fonctions de turk_sort.c */
void	sort_small(t_stack *stack_a);
void	finalize_sort(t_stack *stack_a);
void	sort_turk(t_stack *stack_a, t_stack *stack_b);
#endif