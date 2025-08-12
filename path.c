/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:49:12 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/08/12 18:39:22 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_pos(t_map *map)
{
	map->y = 0;
	map->playerx = 0;
	map->playery = 0;
	while (map->y < map->height)
	{
		map->x = 0;
		while (map->x < map->width)
		{
			if (map->mapgrid[map->y][map->x] == 'P')
			{
				map->playerx = map->x;
				map->playery = map->y;
			}
			map->x++;
		}
		map->y++;
	}
}

int	is_path_valid(t_map *map)
{
	t_map	*mapcopy;

	mapcopy = copy_map(map);
	if (mapcopy->mapgrid == NULL)
		print_error("Map allocation failed\n", map);
	flood_fill(mapcopy, map->playerx, map->playery);
	mapcopy->y = 0;
	while (mapcopy->y < map->height)
	{
		mapcopy->x = 0;
		while (mapcopy->x < map->width)
		{
			if (mapcopy->mapgrid[mapcopy->y][mapcopy->x] == 'E'
				|| mapcopy->mapgrid[mapcopy->y][mapcopy->x] == 'C')
			{
				free_map(mapcopy);
				return (1);
			}
			mapcopy->x++;
		}
		mapcopy->y++;
	}
	free_map(mapcopy);
	return (0);
}

t_map	*copy_map(t_map *map)
{
	t_map	*mapcopy;
	size_t	i;

	i = 0;
	mapcopy = ft_calloc(1, sizeof(t_map));
	if (!mapcopy)
		print_error("Mapcopy allocation failed\n", map);
	mapcopy->mapgrid = ft_calloc(map->height + 1, sizeof(char *));
	if (!mapcopy->mapgrid)
	{
		free(mapcopy);
		print_error("Mapcopy allocation failed\n", map);
	}
	while (i < map->height)
	{
		mapcopy->mapgrid[i] = ft_strdup(map->mapgrid[i]);
		if (!mapcopy->mapgrid[i])
		{
			free_map(mapcopy);
			print_error("Map copying failed\n", map);
		}
		i++;
	}
	mapcopy->mapgrid[i] = NULL;
	return (mapcopy);
}

void	flood_fill(t_map *mapcopy, size_t x, size_t y)
{
	if (mapcopy->mapgrid[y][x] == '1' || mapcopy->mapgrid[y][x] == 'F')
		return ;
	mapcopy->mapgrid[y][x] = 'F';
	flood_fill(mapcopy, x + 1, y);
	flood_fill(mapcopy, x - 1, y);
	flood_fill(mapcopy, x, y + 1);
	flood_fill(mapcopy, x, y - 1);
}
