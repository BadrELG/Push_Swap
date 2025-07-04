/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_and_execute.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:53:06 by badr              #+#    #+#             */
/*   Updated: 2025/07/04 19:26:48 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int ft_abs(int n)
{
    return (n < 0) ? -n : n;
}

// Calcule le coût pour déplacer chaque élément à sa position cible
void calculate_costs(t_stack *stack_a, t_stack *stack_b)
{
    t_node *current;
    int i;
    
    i = 0;
    current = stack_b->top;
    while (current)
    {
        // Coût pour positionner dans B (amener au sommet)
        if (i <= stack_b->size / 2)
            current->cost_b = i;
        else
            current->cost_b = -(stack_b->size - i);
        
        // Coût pour positionner dans A (amener la position cible au sommet)
        if (current->target_pos <= stack_a->size / 2)
            current->cost_a = current->target_pos;
        else
            current->cost_a = -(stack_a->size - current->target_pos);
        
        i++;
        current = current->next;
    }
}

// Trouve l'élément avec le coût total minimal
t_node *find_cheapest(t_stack *stack_b)
{
    t_node *current;
    t_node *cheapest;
    int min_cost;
    
    if (!stack_b->top)
        return (NULL);
    
    min_cost = INT_MAX;
    cheapest = NULL;
    current = stack_b->top;
    
    while (current)
    {
        int total_cost = ft_abs(current->cost_a) + ft_abs(current->cost_b);
        if (total_cost < min_cost)
        {
            min_cost = total_cost;
            cheapest = current;
        }
        current = current->next;
    }
    
    return (cheapest);
}

// Exécute les rotations simultanées (optimise rr et rrr)
void execute_rotations(t_stack *stack_a, t_stack *stack_b, int cost_a, int cost_b)
{
    // Rotations simultanées dans la même direction (rr)
    while (cost_a > 0 && cost_b > 0)
    {
        rr(stack_a, stack_b);
        cost_a--;
        cost_b--;
    }
    
    // Rotations inverses simultanées (rrr)
    while (cost_a < 0 && cost_b < 0)
    {
        rrr(stack_a, stack_b);
        cost_a++;
        cost_b++;
    }
    
    // Rotations restantes individuelles pour A
    while (cost_a > 0)
    {
        ra(stack_a, 1);
        cost_a--;
    }
    while (cost_a < 0)
    {
        rra(stack_a, 1);
        cost_a++;
    }
    
    // Rotations restantes individuelles pour B
    while (cost_b > 0)
    {
        rb(stack_b, 1);
        cost_b--;
    }
    while (cost_b < 0)
    {
        rrb(stack_b, 1);
        cost_b++;
    }
}

// Exécute le mouvement le moins coûteux
void execute_cheapest_move(t_stack *stack_a, t_stack *stack_b)
{
    t_node *cheapest;
    
    cheapest = find_cheapest(stack_b);
    if (!cheapest)
        return;
    
    // Exécuter les rotations nécessaires
    execute_rotations(stack_a, stack_b, cheapest->cost_a, cheapest->cost_b);
    
    // Pousser l'élément de B vers A
    pa(stack_a, stack_b);
}