/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:49:06 by badr              #+#    #+#             */
/*   Updated: 2025/07/02 19:01:17 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Vérifie si doublons parmis les arguments
int	ft_check_doubles(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (tab[i] == tab[j] && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

// Vérifie qu'il n'y a qu'un signe et la validité du int
int valid_nbr(char *str)
{
    int i;

    i = 0;
    if (!str)
        return (0);
    if (str[0] == '-' || str[0] == '+')
    {
        if (!(str[1] >= '0' && str[1] <= '9'))
            return (0);
    }
    while (str[i])
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (0);
    }
    return (1);
}

// Atoi qui évite les overflow d'int
int	ft_ultimate_atoi(char *str, int *error_flag)
{
	int			i;
	int			sign;
	long int	result;

	i = 0;
	sign = 1;
	result = 0;
	*error_flag = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && result > (long)INT_MAX + 1))
			return (*error_flag = 1, 0);
		i++;
	}
	return (sign * result);
}