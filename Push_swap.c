/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 19:38:55 by badr              #+#    #+#             */
/*   Updated: 2025/07/04 18:56:54 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Vérifie si un argument est un nombre valide
int is_valid_number(char *str)
{
    int i;
    
    i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    if (!str[i])
        return (0);
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

// Vérifie si un nombre est déjà présent dans la pile
int is_duplicate(t_stack *stack, int num)
{
    t_node *current;
    
    current = stack->top;
    while (current)
    {
        if (current->value == num)
            return (1);
        current = current->next;
    }
    return (0);
}

// Analyse les arguments et remplit la pile
int parse_args(int argc, char **argv, t_stack *stack)
{
    int i;
    long num;
    
    i = argc - 1;
    while (i > 0)
    {
        if (!is_valid_number(argv[i]))
            return (0);
        
        num = ft_atoi(argv[i]);
        if (num > INT_MAX || num < INT_MIN)
            return (0);
            
        if (is_duplicate(stack, (int)num))
            return (0);
            
        add_top(stack, (int)num);
        i--;
    }
    return (1);
}

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    
    if (argc < 2)
        return (0);
    
    stack_a = init_stack();
    stack_b = init_stack();
    if (!stack_a || !stack_b)
    {
        write(2, "Error\n", 6);
        return (1);
    }
    
    if (!parse_args(argc, argv, stack_a))
    {
        write(2, "Error\n", 6);
        free_stack(stack_a);
        free_stack(stack_b);
        return (1);
    }
    
    if (!is_sorted(stack_a))
        sort_turk(stack_a, stack_b);
    
    free_stack(stack_a);
    free_stack(stack_b);
    return (0);
}