/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:23:46 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/08/12 17:02:12 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	keypress(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
			execute_move(game, -1, 0);
		if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
			execute_move(game, 1, 0);
		if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
			execute_move(game, 0, -1);
		if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
			execute_move(game, 0, 1);
		if (keydata.key == MLX_KEY_ESCAPE)
			game_over("Game exited\n", game);
	}
}

void	execute_move(t_game *game, int y_move, int x_move)
{
	size_t	nav_y;
	size_t	nav_x;
	char	mapsquare;

	nav_y = game->map->playery + y_move;
	nav_x = game->map->playerx + x_move;
	mapsquare = game->map->mapgrid[nav_y][nav_x];
	if (mapsquare == '1')
		return ;
	game->map->playerx = nav_x;
	game->map->playery = nav_y;
	game->player->instances->x = nav_x * MAP_SQUARE;
	game->player->instances->y = nav_y * MAP_SQUARE;
	game->moves++;
	ft_printf("Moves:");
	ft_putnbr_fd(game->moves, 1);
	ft_printf("\n");
	if (mapsquare == 'C')
		collecting(game, nav_x, nav_y);
	if (mapsquare == 'E' && game->collected == game->map->ccount)
		exiting(game, nav_x, nav_y);
}

void	collecting(t_game *game, size_t x, size_t y)
{
	size_t	i;

	i = 0;
	while (i < game->map->ccount)
	{
		if (game->collectable->instances[i].x == (int32_t) x * MAP_SQUARE
			&& game->collectable->instances[i].y == (int32_t) y * MAP_SQUARE)
		{
			game->collectable->instances[i].enabled = false;
			break ;
		}
		i++;
	}
	game->map->mapgrid[y][x] = '0';
	game->collected++;
}

void	exiting(t_game *game, size_t x, size_t y)
{
	if (game->exit->instances->x == (int32_t) x * MAP_SQUARE
		&& game->exit->instances->y == (int32_t) y * MAP_SQUARE)
		game_over("You won!\n", game);
}
