/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:20:26 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/08/12 17:21:37 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->mapgrid)
	{
		while (map->mapgrid[i])
		{
			free(map->mapgrid[i]);
			i++;
		}
		free(map->mapgrid);
	}
	if (map->linemap)
		free(map->linemap);
	if (map)
		free(map);
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
	if (game->exit)
		mlx_delete_image(game->mlx_ptr, game->exit);
	if (game->map)
		free_map(game->map);
	if (game->mlx_ptr)
		mlx_terminate(game->mlx_ptr);
	exit (0);
}
