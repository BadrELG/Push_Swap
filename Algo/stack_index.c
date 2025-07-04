/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:34:09 by badr              #+#    #+#             */
/*   Updated: 2025/07/04 19:26:51 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Attribue des indices à chaque élément (0 pour le plus petit, n-1 pour le plus grand)
void index_stack(t_stack *stack)
{
    t_node  *current;
    t_node  *tmp;
    int     min;
    int     index;
    int     size;

    size = stack->size;
    index = 0;
    while (index < size)
    {
        min = INT_MAX;
        current = stack->top;
        
        // Trouve le plus petit élément non indexé
        while (current)
        {
            if (current->value < min && current->index == -1)
                min = current->value;
            current = current->next;
        }
        
        // Attribue l'index à l'élément trouvé
        current = stack->top;
        while (current)
        {
            if (current->value == min)
                current->index = index++;
            current = current->next;
        }
    }
}

// Détermine le nombre de chunks en fonction de la taille de la pile
int get_chunk_count(int size)
{
    if (size <= 10)
        return 2;
    else if (size <= 100)
        return 4;
    else if (size <= 500)
        return 9;
    return 11;
}

// Calcule la limite minimale d'un chunk
int get_chunk_min(int size, int chunk_count, int chunk_num)
{
    int chunk_size = size / chunk_count;
    return chunk_num * chunk_size;
}

// Calcule la limite maximale d'un chunk
int get_chunk_max(int size, int chunk_count, int chunk_num)
{
    int chunk_size = size / chunk_count;
    if (chunk_num == chunk_count - 1)
        return size;  // Dernier chunk prend les éléments restants
    else
        return (chunk_num + 1) * chunk_size;
}