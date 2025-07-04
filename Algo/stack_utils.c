/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 17:51:23 by badr              #+#    #+#             */
/*   Updated: 2025/07/04 19:26:52 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Initialise une pile vide
t_stack  *init_stack(void)
{
    t_stack *stack;

    stack = malloc(sizeof(t_stack));
    if (!stack)
        return (NULL);
    stack->top = NULL;
    stack->size = 0;
    return (stack);
}

// Ajoute un élément au sommet de la pile
void add_top(t_stack *stack, int value)
{
    t_node *new_node;

    new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node)
        return;
    new_node->value = value;
    new_node->index = -1;  // Sera défini plus tard
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
    
    // Mettre à jour les positions
    update_positions(stack);
}

// Mettra à jour la position de chaque valeur de la pile
void    update_positions(t_stack *stack)
{
    t_node *current;
    int position;

    position = 0;
    current = stack->top;
    while (current)
    {
        current->position = position;
        current = current->next;
        position++;
    }
}

// Liberer la mémoire alloué a une pile 
void    free_stack(t_stack *stack)
{
    t_node *current;
    t_node *next;
    
    current = stack->top;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    free(stack);
}

// Vérifie si la pile est triée
int is_sorted(t_stack *stack)
{
    t_node *current;

    current = stack->top;
    while (current && current->next)
    {
        if (current->value > current->next->value)
            return (0);
        current = current->next;
    }
    return (1);
}