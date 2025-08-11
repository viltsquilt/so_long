/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:20:26 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/08/11 20:39:22 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	close_and_free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->floor)
		mlx_delete_image(game->mlx_ptr, game->floor);
	if (game->wall)
		mlx_delete_image(game->mlx_ptr, game->wall);
	if (game->player)
		mlx_delete_image(game->mlx_ptr, game->player);
	if (game->collectable)
		mlx_delete_image(game->mlx_ptr, game->collectable);
	if (game->closed_exit)
		mlx_delete_image(game->mlx_ptr, game->closed_exit);
	if (game->exit)
		mlx_delete_image(game->mlx_ptr, game->exit);
	if (game->map)
		free_map(game->map);
	if (game->mlx_ptr)
		mlx_terminate(game->mlx_ptr);
}
