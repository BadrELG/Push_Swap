/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bael-gho <bael-gho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:22:40 by bael-gho          #+#    #+#             */
/*   Updated: 2025/05/07 03:18:36 by bael-gho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static char	*ft_allocate_word(char const *s, char c)
{
	int		i;
	int		j;
	char	*word;

	i = 0;
	j = 0;
	while (s[i] != c && s[i])
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	while (j < i)
	{
		word[j] = s[j];
		j++;
	}
	word[j] = '\0';
	return (word);
}

static void	ft_free_array(char **array, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static char	**process_array(char const *s, char c, char **out)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			out[j] = ft_allocate_word(&s[i], c);
			if (!out[j])
			{
				ft_free_array(out, j);
				return (NULL);
			}
			j++;
		}
		while (s[i] != c && s[i])
			i++;
	}
	return (out);
}

char	**ft_split(char const *s, char c)
{
	int		word_count;
	char	**out;

	if (!s)
		return (NULL);
	word_count = ft_count_words(s, c);
	out = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!out)
		return (NULL);
	out = process_array(s, c, out);
	if (!out)
		return (NULL);
	out[word_count] = NULL;
	return (out);
}
