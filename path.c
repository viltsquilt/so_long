/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:49:12 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/08/07 14:55:39 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_pos(t_map *maps)
{
	maps->y = 0;
	maps->playerx = 0;
	maps->playery = 0;
	while (maps->y)
	{
		maps->x = 0;
		while (maps->x <= maps->width)
		{
			if (maps->map[maps->y][maps->x] == 'P')
			{
				maps->playerx = maps->x;
				maps->playery = maps->y;
			}
			maps->x++;
		}
		maps->y++;
	}
}

int	is_path_available(t_map *maps)
{
	t_map	*mapcopy;

	mapcopy = copy_map(maps);
	if (mapcopy->map == NULL)
		print_error("Map allocation failed\n", maps);
	flood_fill(mapcopy, maps->playerx, maps->playery);
	mapcopy->y = 0;
	while (mapcopy->y <= maps->height)
	{
		mapcopy->x = 0;
		while (mapcopy->x <= maps->width)
		{
			if (mapcopy->map[mapcopy->y][mapcopy->x] != 'F'
				|| mapcopy->map[mapcopy->y][mapcopy->x] != '1')
			{
				free_map(mapcopy);
				free_map(maps);
				return (1);
			}
			mapcopy->x++;
		}
		mapcopy->y++;
	}
	free_map(mapcopy);
	return (0);
}

t_map	*copy_map(t_map *maps)
{
	t_map	*mapcopy;
	size_t	i;

	i = 0;
	mapcopy = ft_calloc(1, sizeof(t_map));
	if (!mapcopy)
		return (NULL);
	mapcopy->map = ft_calloc(maps->height + 1, sizeof(char *));
	if (!mapcopy->map)
	{
		free_map(maps);
		return (NULL);
	}
	while (i <= maps->height)
	{
		mapcopy->map[i] = ft_strdup(maps->map[i]);
		if (!mapcopy->map[i])
		{
			free_map(mapcopy);
			return (NULL);
		}
		i++;
	}
	mapcopy->map[i] = NULL;
	return (mapcopy);
}

void	flood_fill(t_map *mapcopy, size_t x, size_t y)
{
	if (mapcopy->map[x][y] == '1' || mapcopy->map[x][y] == 'F')
		return ;
	mapcopy->map[y][x] = 'F';
	flood_fill(mapcopy, x + 1, y);
	flood_fill(mapcopy, x - 1, y);
	flood_fill(mapcopy, x, y + 1);
	flood_fill(mapcopy, x, y - 1);
}
