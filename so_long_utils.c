/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 18:43:10 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/08/12 18:40:21 by vahdekiv         ###   ########.fr       */
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

void	buildgrid(t_map *map, char *file)
{
	int	fd;

	map->y = 0;
	map->x = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		print_error("Failed to open map file\n", map);
	map->mapgrid = ft_calloc(map->height + 1, sizeof(char *));
	if (!map->mapgrid)
		print_error("Memory allocation failed\n", map);
	while (map->y < map->height)
	{
		map->line = get_next_line(fd);
		if (!map->line)
			print_error("Memory allocation failed\n", map);
		map->line[newstrlen(map->line, '\n')] = '\0';
		map->mapgrid[map->y] = ft_strdup(map->line);
		free(map->line);
		if (!map->mapgrid[map->y])
			close_and_print_error("Memory allocation failed\n", map, fd);
		map->y++;
	}
	map->mapgrid[map->y] = NULL;
	close(fd);
}

int	oversize(t_map *map)
{
	int32_t	monitor_height;
	int32_t	monitor_width;
	mlx_t	*test;

	test = mlx_init(1, 1, "test", false);
	mlx_get_monitor_size(0, &monitor_width, &monitor_height);
	mlx_terminate(test);
	if (monitor_width < (int32_t)map->width * MAP_SQUARE
		|| monitor_height < (int32_t)map->height * MAP_SQUARE)
		return (1);
	return (0);
}
