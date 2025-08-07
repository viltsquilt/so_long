/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:18:33 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/08/07 18:57:28 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Error: Invalid map count\n");
		return (1);
	}
	if (check_extension(argv[1]) == 1)
	{
		ft_printf("Wrong file type\n");
		return (1);
	}
	game.map = create_map(argv[1]);
	free_map(game.map);
	ft_printf("Done");
	return (0);
}
/*
int	on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int	on_keypress(int keysym, t_data *data)
{
	(void)data;
	ft_printf("Pressed key: %d\n", keysym);
	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 400, "test");
	if (!data.win_ptr)
		return (free(data.win_ptr), 1);
	
	// Register key release hook
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);

	// Register destroy hook
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);

	// Loop over the MLX pointer
	mlx_loop(data.mlx_ptr);
	return (0);
}
*/
/*
mlx_init
Initializes the MLX library. Must be called before using any other functions

mlx_new_window
Creates a new window instance

mlx_hook
Registers events

mlx_loop
Loops over the MLX pointer, triggering each hook in order of registration

mlx_xpm_file_to_image
Converts an XPM file to an MLX iage pointer

mlx_put_image_to_window
Puts your image to the screen at the given coordinates

mlx_destroy_image
Frees the  image

mlx_destroy_window
Frees the window instance

mlx_destroy_display
Frees MLX
*/
