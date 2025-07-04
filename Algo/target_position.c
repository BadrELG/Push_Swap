/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:51:36 by badr              #+#    #+#             */
/*   Updated: 2025/07/04 19:26:53 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Trouve la position de l'élément le plus petit dans la pile
int get_min_position(t_stack *stack)
{
    t_node *current;
    int min_value;
    int min_pos;
    int pos;

    if (!stack->top)
        return (-1);
    
    min_value = stack->top->value;
    min_pos = 0;
    pos = 0;
    current = stack->top;
    
    while (current)
    {
        if (current->value < min_value)
        {
            min_value = current->value;
            min_pos = pos;
        }
        pos++;
        current = current->next;
    }
    
    return (min_pos);
}

// Trouve le prochain élément plus grand dans la pile A
int find_target_position(t_stack *stack_a, int b_index)
{
    t_node *current;
    int target_index;
    int target_pos;
    int i;
    
    target_index = INT_MAX;
    target_pos = 0;
    
    // Chercher l'élément juste supérieur à b_index dans A
    i = 0;
    current = stack_a->top;
    while (current)
    {
        if (current->index > b_index && current->index < target_index)
        {
            target_index = current->index;
            target_pos = i;
        }
        i++;
        current = current->next;
    }
    
    // Si aucun élément plus grand n'est trouvé, cibler le plus petit
    if (target_index == INT_MAX)
        return (get_min_position(stack_a));
    
    return (target_pos);
}

// Calcule la position cible pour chaque élément de B
void get_target_positions(t_stack *stack_a, t_stack *stack_b)
{
    t_node *current;
    int i;
    
    i = 0;
    current = stack_b->top;
    while (current)
    {
        current->target_pos = find_target_position(stack_a, current->index);
        i++;
        current = current->next;
    }
}