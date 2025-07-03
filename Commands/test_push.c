/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:32:49 by badr              #+#    #+#             */
/*   Updated: 2025/07/03 15:32:52 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stack(t_list *stack, char *name)
{
	printf("Stack %s: ", name);
	while (stack)
	{
		printf("%d", *(int *)stack->content);
		stack = stack->next;
	}
	printf("\n");
}

int	main(void)
{
	t_list	*a = NULL;
	t_list	*b = NULL;
	int		*n1 = malloc(sizeof(int));
	int		*n2 = malloc(sizeof(int));
	int		*n3 = malloc(sizeof(int));

	*n1 = 4;
	*n2 = 3;
	*n3 = 2;

	ft_lstadd_front(&a, ft_lstnew(n1));
	ft_lstadd_front(&a, ft_lstnew(n2));
	ft_lstadd_front(&a, ft_lstnew(n3));


	print_stack(a, "A");
	print_stack(b, "B");

	printf("Activation de pb\n");
	pb(&a, &b);

	print_stack(a, "A");
	print_stack(b, "B");

	printf("Activation de pa\n");
	pa(&a, &b);

	print_stack(a, "A");
	print_stack(b, "B");

	return (0);
}