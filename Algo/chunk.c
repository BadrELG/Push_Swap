/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:44:23 by badr              #+#    #+#             */
/*   Updated: 2025/07/04 19:28:30 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Vérifie si un index est dans le chunk spécifié
int is_in_chunk(int index, int chunk_min, int chunk_max)
{
    return (index >= chunk_min && index < chunk_max);
}

// Calcule le coût pour amener un élément au sommet de la pile
// en fonction de sa position
int calculate_rotation_cost(int position, int stack_size)
{
    if (position <= stack_size / 2)
        return position;
    else
        return stack_size - position;
}

// Obtient l'index du nœud dans la pile
int get_node_index(t_node *node)
{
    return node->index;
}

// Trouve la position du premier élément dans le chunk
// Retourne -1 si aucun élément trouvé
int find_first_in_chunk(t_stack *stack, int chunk_min, int chunk_max)
{
    t_node *current = stack->top;
    int pos = 0;
    
    while (current)
    {
        if (is_in_chunk(get_node_index(current), chunk_min, chunk_max))
            return pos;
        current = current->next;
        pos++;
    }
    return -1;
}

// Fonction principale qui trouve l'élément le plus proche du chunk actuel
int find_closest_chunk_element(t_stack *stack_a, int chunk_min, int chunk_max, int *position)
{
    t_node *current = stack_a->top;
    int min_cost = INT_MAX;
    int min_cost_position = -1;
    int size = stack_a->size;
    int pos = 0;
    
    while (current)
    {
        int index = get_node_index(current);
        if (is_in_chunk(index, chunk_min, chunk_max))
        {
            int cost = calculate_rotation_cost(pos, size);
            if (cost < min_cost)
            {
                min_cost = cost;
                min_cost_position = pos;
            }
        }
        current = current->next;
        pos++;
    }
    
    *position = min_cost_position;
    return min_cost_position != -1;
}