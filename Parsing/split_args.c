/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: badr <badr@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 19:02:29 by badr              #+#    #+#             */
/*   Updated: 2025/07/02 19:08:43 by badr             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// Compte le nombre d'arguments
int	count_args(int ac, char **av)
{
	int	i;
	int	total;

	i = 1;
	total = 0;
	while (i < ac)
	{
		total += ft_count_word(av[i], ' ');
		i++;
	}
	return (total);
}

// Copie les strings de tmp dans tab
static int	clean_tab(char **tab, char **tmp, int k)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		tab[k] = ft_strdup(tmp[i]);
		if (!tab[k])
			return (-1);
		free(tmp[i]);
		i++;
		k++;
	}
	free(tmp);
	return (k);
}

// Sépare les arguments si elles sont dans une seule string
char	**split_args(int ac, char **av)
{
	char	**tab;
	int		i;
	int		k;
	char	**tmp;
	int		total;

	i = 1;
	k = 0;
	total = count_total_args(ac, av);
	tab = malloc(sizeof(char *) * (total + 1));
	while (av[i])
	{
		tmp = ft_split(av[i], ' ');
		if (!tmp)
		{
			free(tmp);
			return (NULL);
		}
		k = clean_tab(tab, tmp, k);
		if (k == -1)
			return (NULL);
		i++;
	}
	tab[k] = NULL;
	return (tab);
}