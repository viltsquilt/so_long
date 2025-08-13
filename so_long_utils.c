/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 18:43:10 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/08/13 11:52:57 by vahdekiv         ###   ########.fr       */
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
	return (i);
}

int	charcount(char *str, t_map *map)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] == 'P' || str[i] == '0' || str[i] == 'E' || str[i] == '1'
				|| str[i] == 'C'))
			return (1);
		if (str[i] == 'P')
			map->pcount++;
		if (str[i] == 'E')
			map->ecount++;
		if (str[i] == 'C')
			map->ccount++;
		i++;
	}
	if (map->pcount != 1 || map->ecount != 1 || map->ccount < 1)
		return (1);
	return (0);
}

static char	*linefiller(t_map *map, int fd)
{
	map->mapgrid[map->y] = get_next_line(fd);
	if (!map->mapgrid[map->y])
		print_error("Error\nMemory allocation failed\n", map);
	map->mapgrid[map->y][newstrlen(map->mapgrid[map->y], '\n')] = '\0';
	return (map->mapgrid[map->y]);
}

void	buildgrid(t_map *map, char *file)
{
	int	fd;

	map->y = 0;
	map->x = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		print_error("Error\nFailed to open map file\n", map);
	map->mapgrid = ft_calloc(map->height + 1, sizeof(char *));
	if (!map->mapgrid)
		print_error("Error\nMemory allocation failed\n", map);
	while (map->y < map->height)
	{
		map->mapgrid[map->y] = linefiller(map, fd);
		if (!map->mapgrid[map->y])
			close_and_print_error("Error\nMemory allocation failed\n", map, fd);
		map->y++;
	}
	map->mapgrid[map->y] = NULL;
	close(fd);
}
