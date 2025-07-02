/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:54:51 by badr              #+#    #+#             */
/*   Updated: 2025/07/02 18:56:00 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	if (!parse_args(ac, av))
	{
		printf("Parsing invalide\n");
		return (0);
	}
	printf("Parsing valide\n");
	return (1);
}