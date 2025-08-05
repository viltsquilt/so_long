/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:18:19 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/08/05 19:10:00 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* flood fill

map parsing:

valid extension (.ber)
*/
int	check_extension(char *string)
{
	int	i;

	i = 0;
	while (string[i])
		i++;
	i--;
	if (string[i] == 'r' && string[i -1] == 'e'
		&& string[i -2] == 'b' && string[i - 3] == '.')
		return (0);
	return (1);
}

// get map size and check if rectangular
// check for empty lines (start reading from columns)

int	create_map(char **av)
{
	int	fd;
	t_map	*maps;

	maps->height = 0;
	maps->mapsize = ft_calloc(1, sizeof(t_map));
	if (!maps->mapsize)
		return (NULL);
	fd = open(av[1], O_RDONLY);
	if (!fd)
		return (1);
	maps->width = newstrlen(get_next_line(fd, '\n'));
	maps->height++;
	while (1)
	{
		if (newstrlen(get_next_line(fd, '\n')) != maps->width
			|| newstrlen(get_next_line(fd, '\0')) != maps->width)
			return (1);
		height++;
		if (newstrlen(get_next_line(fd, '\0')) == maps->width)
			break ;
	}
	if (maps->width <= maps->height)
		return (1);
	close(fd);
	return (0);
}

// solid walls (surrounded by 1s)

int	solid_walls(char **av)
{
	t_map	*maps;

	
}
// max 5 different characters (1, 0, P, E, C)
// valid path
// not empty map

/*
if (all_collectables_collected && exit_count == 1)
	return map_valid;
if (on_wall)
	return map_invalid;
if (on_collectable)
	collectables++;
if (on_exit)
	exit++;
replace_current_position_with_wall;
if (one_of_the_four_adjacent_directions_is_possible)
	return map_invalid;
return map_invalid;
*/
