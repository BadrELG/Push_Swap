/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 16:49:06 by badr              #+#    #+#             */
/*   Updated: 2025/07/02 18:08:12 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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