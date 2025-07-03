/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:02:56 by badr              #+#    #+#             */
/*   Updated: 2025/07/03 15:10:57 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// free l'integralite de mes valeurs dans mes tableaux
void	free_all(char **str_values, int *int_values)
{
	ft_free(str_values);
	free(int_values);
}

// Vérifie et convertie les valeurs pour le tableau
int	ft_verif_and_convert(char **str_values, int *int_values)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (str_values[i])
	{
		if (!(ft_is_number(str_values[i])))
			return (0);
		int_values[i] = ft_ultimate_atoi(str_values[i], &error);
		if (error)
			return (0);
		i++;
	}
	if (error == 1)
		return (free(int_values), 0);
	i++;
	return (1);
}

// controle final des arguments
int	*parse_args(int ac, char **av)
{
	char	**str_values;
	int		*int_values;

	if (ac > 1)
	{
		int_values = ft_calloc(sizeof(int), (count_total_args(ac, av)));
		str_values = split_args(ac, av);
		if (!(ft_verif_and_convert(str_values, int_values))
			|| ft_check_doubles(int_values, count_args(ac, av)))
		{
			ft_putstr_fd("Error\n", 2);
			free_all(str_values, int_values);
			return (NULL);
		}
	}
	else
		return (ft_putstr_fd("Error\n", 2), NULL);
	ft_free(str_values);
	return (int_values);
}