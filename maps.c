/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:18:19 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/08/14 14:35:36 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extension(char *string)
{
	int	i;

	i = 0;
	while (string[i])
		i++;
	i--;
	if (string[i] == 'r' && string[i - 1] == 'e'
		&& string[i - 2] == 'b' && string[i - 3] == '.')
		return (0);
	return (1);
}

t_map	*draw_map(char *file)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
	{
		ft_printf("Error\nFailed to create map\n");
		exit (1);
	}
	get_map_size(map, file);
	buildgrid(map, file);
	if (MONITOR_WIDTH < map->width * MAP_SQUARE
		|| MONITOR_HEIGHT < map->height * MAP_SQUARE)
		print_error("Error\nMap too big\n", map);
	if (check_walls(map) == 1)
		print_error("Error\nInvalid map\n", map);
	if (check_char(map) == 1)
		print_error("Error\nInvalid number of elements\n", map);
	player_pos(map);
	if (is_path_valid(map) == 1)
		print_error("Error\nNo valid path\n", map);
	return (map);
}

void	get_map_size(t_map *map, char *file)
{
	int	fd;

	map->flag = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		print_error("Error\nInvalid file\n", map);
	map->line = get_next_line(fd);
	if (!map->line)
		print_error("Error\nget_next_line failure\n", map);
	map->width = newstrlen(map->line, '\n');
	map->height = 1;
	while (1)
	{
		free(map->line);
		map->line = get_next_line(fd);
		if (map->line == NULL)
			break ;
		map->height++;
		if (newstrlen(map->line, '\n') != map->width)
			map->flag = 1;
	}
	if (map->flag == 1)
		specific_line_error("Error\nMap not rectangular\n", map, fd);
	close(fd);
}

int	check_walls(t_map *map)
{
	map->y = 0;
	while (map->y < map->height)
	{
		map->x = 0;
		while (map->x < map->width)
		{
			if ((map->y == 0 || map->y == map->height - 1)
				&& map->mapgrid[map->y][map->x] != '1')
				return (1);
			else if ((map->y != 0 || map->y != map->height - 1)
				&& (map->x == 0 || map->x == map->width - 1)
				&& (map->mapgrid[map->y][map->x] != '1'))
				return (1);
			map->x++;
		}
		map->y++;
	}
	return (0);
}

int	check_char(t_map *map)
{
	size_t	i;

	i = 0;
	map->y = 0;
	map->linemap = malloc((map->width * map->height + 1) * sizeof(char *));
	if (!map->linemap)
		return (1);
	while (map->y < map->height)
	{
		map->x = 0;
		while (map->x < map->width)
			map->linemap[i++] = map->mapgrid[map->y][map->x++];
		map->y++;
	}
	map->linemap[i] = '\0';
	if (charcount(map->linemap, map) == 1)
		return (1);
	return (0);
}
