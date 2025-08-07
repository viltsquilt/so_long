/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:20:26 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/08/07 18:44:07 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_and_print_error(char *msg, t_map *map, int fd)
{
	ft_printf("%s", msg);
	free_map(map);
	close(fd);
	exit (1);
}

void	print_error(char *msg, t_map *map)
{
	ft_printf("%s", msg);
	free_map(map);
	exit (1);
}

static void	*clean(void *waste)
{
	if (waste)
	{
		free(waste);
		waste = NULL;
	}
	return (waste);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->mapgrid)
	{
		while (map->mapgrid[i])
		{
			map->mapgrid[i] = clean(map->mapgrid[i]);
			i++;
		}
		map->mapgrid = clean(map->mapgrid);
	}
	if (map->linemap)
		map->linemap = clean(map->linemap);
	if (map)
		map = clean(map);
}
