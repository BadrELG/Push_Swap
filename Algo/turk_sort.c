/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:55:14 by badr              #+#    #+#             */
/*   Updated: 2025/07/04 19:26:54 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Tri pour 3 éléments ou moins
void sort_small(t_stack *stack_a)
{
    int top, middle, bottom;
    
    if (stack_a->size <= 1)
        return;
        
    if (stack_a->size == 2)
    {
        if (stack_a->top->value > stack_a->top->next->value)
            sa(stack_a, 1);
        return;
    }
    
    // Pour 3 éléments
    top = stack_a->top->value;
    middle = stack_a->top->next->value;
    bottom = stack_a->top->next->next->value;
    
    if (top > middle && middle < bottom && top < bottom)
        sa(stack_a, 1);
    else if (top > middle && middle > bottom)
    {
        sa(stack_a, 1);
        rra(stack_a, 1);
    }
    else if (top > middle && middle < bottom && top > bottom)
        ra(stack_a, 1);
    else if (top < middle && middle > bottom && top < bottom)
    {
        sa(stack_a, 1);
        ra(stack_a, 1);
    }
    else if (top < middle && middle > bottom && top > bottom)
        rra(stack_a, 1);
}

// Finalisation du tri (rotation pour amener le plus petit élément au sommet)
void finalize_sort(t_stack *stack_a)
{
    int min_pos;
    
    min_pos = get_min_position(stack_a);
    
    // Rotation pour amener le plus petit élément au sommet
    if (min_pos <= stack_a->size / 2)
    {
        while (min_pos-- > 0)
            ra(stack_a, 1);
    }
    else
    {
        while (min_pos++ < stack_a->size)
            rra(stack_a, 1);
    }
}

// Algorithme Turk Sort complet
void sort_turk(t_stack *stack_a, t_stack *stack_b)
{
    // Cas particuliers pour les petites tailles
    if (is_sorted(stack_a))
        return;
        
    if (stack_a->size <= 3)
    {
        sort_small(stack_a);
        return;
    }
    
    // Attribuer des indices à chaque élément
    index_stack(stack_a);
    
    // Pousser tous les éléments vers B par chunks
    push_chunks_to_b(stack_a, stack_b);
    
    // Repousser les éléments vers A dans l'ordre
    while (stack_b->size > 0)
    {
        // Mettre à jour les positions
        update_positions(stack_a);
        update_positions(stack_b);
        
        // Calculer les positions cibles et les coûts
        get_target_positions(stack_a, stack_b);
        calculate_costs(stack_a, stack_b);
        
        // Exécuter le mouvement optimal
        execute_cheapest_move(stack_a, stack_b);
    }
    
    // Finaliser le tri (rotation pour mettre le plus petit au sommet)
    finalize_sort(stack_a);
}

int find_closest_in_chunk(t_stack *stack, int chunk_min, int chunk_max)
{
    int position = -1;
    find_closest_chunk_element(stack, chunk_min, chunk_max, &position);
    return position;
}