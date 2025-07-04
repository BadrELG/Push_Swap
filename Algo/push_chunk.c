/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:48:52 by badr              #+#    #+#             */
/*   Updated: 2025/07/04 19:26:49 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Amène un élément à la position spécifiée au sommet de la pile
void rotate_to_top(t_stack *stack, int position)
{
    if (position <= stack->size / 2)
    {
        while (position-- > 0)
            ra(stack, 1);
    }
    else
    {
        while (position++ < stack->size)
            rra(stack, 1);
    }
}

// Optimise le placement d'un élément dans la pile B
void optimize_b_position(t_stack *stack_b, int chunk_min, int chunk_max)
{
    if (stack_b->top && stack_b->size > 1 && 
        stack_b->top->index > (chunk_min + chunk_max) / 2)
        rb(stack_b, 1);
}

// Pousse un élément de A vers B et optimise sa position
void push_and_optimize(t_stack *stack_a, t_stack *stack_b, int chunk_min, int chunk_max)
{
    pb(stack_a, stack_b);
    optimize_b_position(stack_b, chunk_min, chunk_max);
}

// Pousse tous les éléments d'un chunk de A vers B
void process_chunk(t_stack *stack_a, t_stack *stack_b, int chunk_min, int chunk_max)
{
    int position;
    
    while (1)
    {
        position = find_closest_in_chunk(stack_a, chunk_min, chunk_max);
        if (position == -1)
            break;  // Plus d'éléments dans ce chunk
        
        rotate_to_top(stack_a, position);
        push_and_optimize(stack_a, stack_b, chunk_min, chunk_max);
    }
}

// Fonction principale qui orchestre le tri par chunks
void push_chunks_to_b(t_stack *stack_a, t_stack *stack_b)
{
    int chunk_count;
    int original_size;
    int chunk_min;
    int chunk_max;
    int chunk;
    
    original_size = stack_a->size;
    chunk_count = get_chunk_count(original_size);
    chunk = 0;
    
    while (chunk < chunk_count)
    {
        chunk_min = get_chunk_min(original_size, chunk_count, chunk);
        chunk_max = get_chunk_max(original_size, chunk_count, chunk);
        
        process_chunk(stack_a, stack_b, chunk_min, chunk_max);
        chunk++;
    }
}