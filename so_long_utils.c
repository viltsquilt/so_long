/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 18:43:10 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/08/07 14:09:19 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	newstrlen(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			break ;
		i++;
	}
	i--;
	return (i);
}

int	charcount(char *str, t_map *maps)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 'P' || str[i] != '0' || str[i] != 'E' || str[i] != '1'
			|| str[i] != 'C')
			return (1);
		if (str[i] == 'P')
			maps->pcount++;
		if (str[i] == 'E')
			maps->ecount++;
		if (str[i] == 'C')
			maps->ccount++;
		i++;
	}
	if (maps->pcount != 1 || maps->ecount != 1 || maps->ccount > 1)
		return (1);
	return (0);
}
