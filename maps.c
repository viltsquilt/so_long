/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:18:19 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/08/06 17:20:45 by vahdekiv         ###   ########.fr       */
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

void	create_map(char	*mapfile)
{
	t_map	*maps;
	t_map	*mapcopy;

	mapcopy = NULL;
	maps = NULL;
	if (get_map_size(mapfile, maps) == 1)
		print_error("Invalid map\n", maps);
	maps->linemap = malloc((maps->width * maps->height + 1) * sizeof(char *));
	if (!maps->linemap)
	{
		free_map(maps);
		exit (1);
	}
	if (check_char(maps) == 1)
		print_error("Invalid number of elements\n", maps);
	player_pos(maps);
	if (is_path_available(maps) == 1)
		print_error("No valid path\n", maps);
	free_map(mapcopy);
	free(maps->linemap);
}

int	get_map_size(char *mapfile, t_map *maps)
{
	int		fd;
	char	*line;

	maps->height = 0;
	maps = ft_calloc(1, sizeof(t_map));
	if (!maps)
		return (1);
	fd = open(mapfile, O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	maps->width = newstrlen(line, '\n');
	maps->height = 1;
	while (1)
	{
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		maps->height++;
		if (newstrlen(line, '\n') != maps->width)
		{
			free(line);
			close_and_print_error("Map creation failed\n", maps, fd);
		}
	}
	if (maps->width <= maps->height || check_walls(maps, fd) == 1)
		return (1);
	close(fd);
	return (0);
}

int	check_walls(t_map *maps, int fd)
{
	maps->x = 0;
	maps->y = 0;
	maps->map = NULL;
	while (maps->y <= maps->height)
		maps->map[maps->y++] = get_next_line(fd);
	if (maps->map == NULL)
		return (1);
	while (maps->map[maps->y])
	{
		while (maps->x <= maps->width)
		{
			if ((maps->y == 0 || maps->y == maps->height)
				&& maps->map[maps->y][maps->x] != '1')
				return (1);
			else if ((maps->y != 0 || maps->y != maps->height)
				&& (maps->x == 0 || maps->x == maps->width)
				&& (maps->map[maps->y][maps->x] != '1'))
				return (1);
			maps->x++;
		}
		maps->y++;
	}
	return (0);
}

int	check_char(t_map *maps)
{
	size_t	i;

	i = 0;
	maps->y = 0;
	while (maps->map[maps->y])
	{
		maps->x = 0;
		while (maps->x <= maps->width)
			maps->linemap[i++] = maps->map[maps->y][maps->x++];
		maps->y++;
	}
	maps->linemap[i] = '\0';
	if (charcount(maps->linemap) == 1)
		return (1);
	return (0);
}
