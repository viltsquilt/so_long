/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:05:17 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/04/28 10:56:24 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_countwords(char const *str, char c)
{
	int	i;
	int	trigger;
	int	count;

	i = 0;
	trigger = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c && trigger == 0)
		{
			count++;
			trigger = 1;
		}
		else if (str[i] == c)
		{
			trigger = 0;
		}
		i++;
	}
	return (count);
}

static char	**ft_free(char **arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(arr[i++]);
	}
	free(arr);
	return (0);
}

static char	**ft_array(char **array, char const *s, int start, char c)
{
	size_t	j;
	size_t	i;
	size_t	len;

	j = 0;
	i = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c && start != -1)
			|| (i == len && start >= 0))
		{
			array[j] = ft_substr(s, start, i - start);
			if (!array[j])
				return (ft_free(array, j));
			j++;
			start = -1;
		}
		i++;
	}
	array[j] = 0;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	int		start;
	char	**array;

	if (!s)
		return (NULL);
	start = -1;
	array = malloc((ft_countwords(s, c) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	array = ft_array(array, s, start, c);
	return (array);
}
