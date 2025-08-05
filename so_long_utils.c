/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 18:43:10 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/08/05 18:44:37 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int newstrlen(char *str, char c)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] == c)
			break ;
		i++;
	}
	i--;
	return (i);
}
