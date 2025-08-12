/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:18:33 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/08/12 20:12:57 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_exit("Error\nInvalid map count\n");
	if (check_extension(argv[1]) == 1)
		error_exit("Error\nWrong file type\n");
	game.map = draw_map(argv[1]);
	launch(&game);
	mlx_key_hook(game.mlx_ptr, keypress, &game);
	mlx_loop(game.mlx_ptr);
	game_over("Game exited\n", &game);
	return (0);
}
