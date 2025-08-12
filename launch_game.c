/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 13:09:32 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/08/12 17:00:09 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	launch(t_game *game)
{
	if (!game || !game->map)
		game_over("Failed to launch game\n", game);
	game->mlx_ptr = mlx_init(game->map->width * MAP_SQUARE,
			game->map->height * MAP_SQUARE, "gamename", true);
	if (!game->mlx_ptr)
		game_over("Failed to launch game\n", game);
	game->collected = 0;
	game->moves = 0;
	load_images(game);
}

static mlx_image_t	*load_textures(t_game *game, char *path)
{
	mlx_texture_t	*texture_ptr;
	mlx_image_t		*image_ptr;

	texture_ptr = mlx_load_png(path);
	if (!texture_ptr)
		return (NULL);
	image_ptr = mlx_texture_to_image(game->mlx_ptr, texture_ptr);
	if (!image_ptr)
	{
		mlx_delete_texture(texture_ptr);
		return (NULL);
	}
	mlx_delete_texture(texture_ptr);
	return (image_ptr);
}

void	load_images(t_game *game)
{
	game->floor = load_textures(game, "./textures/floor.png");
	game->wall = load_textures(game, "./textures/wall.png");
	game->collectable = load_textures(game, "./textures/crystal.png");
	game->exit = load_textures(game, "./textures/opendoor.png");
	game->player = load_textures(game, "./textures/penguin.png");
	if (!(game->floor || game->wall || game->collectable || game->exit
			|| game->player))
		game_over("Failed to load textures\n", game);
	make_floor(game);
}

void	make_floor(t_game *game)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			mlx_image_to_window(game->mlx_ptr, game->floor, x * MAP_SQUARE,
				y * MAP_SQUARE);
			x++;
		}
		y++;
	}
	spread_game_elements(game);
}

void	spread_game_elements(t_game *game)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->mapgrid[y][x] == '1')
				mlx_image_to_window(game->mlx_ptr, game->wall, x * MAP_SQUARE,
					y * MAP_SQUARE);
			if (game->map->mapgrid[y][x] == 'C')
				mlx_image_to_window(game->mlx_ptr, game->collectable,
					x * MAP_SQUARE, y * MAP_SQUARE);
			if (game->map->mapgrid[y][x] == 'E')
				mlx_image_to_window(game->mlx_ptr, game->exit,
					x * MAP_SQUARE, y * MAP_SQUARE);
			x++;
		}
		y++;
	}
	mlx_image_to_window(game->mlx_ptr, game->player,
		game->map->playerx * MAP_SQUARE, game->map->playery * MAP_SQUARE);
}
