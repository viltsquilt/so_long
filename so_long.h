/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:12:03 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/08/11 20:17:00 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

# define MAP_SQUARE 64

typedef struct s_map
{
	size_t	height;
	size_t	width;
	size_t	y;
	size_t	x;
	size_t	playery;
	size_t	playerx;
	size_t	ecount;
	size_t	pcount;
	size_t	ccount;
	char	*line;
	char	**mapgrid;
	char	*linemap;
}	t_map;

typedef struct s_game
{
	mlx_t		*mlx_ptr;
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*player;
	mlx_image_t	*collectable;
	mlx_image_t	*exit;
	mlx_image_t	*closed_exit;
	size_t		moves;
	size_t		collected;
	t_map		*map;
}	t_game;

size_t	newstrlen(char *str, char c);
int		check_extension(char *string);
int		check_walls(t_map *map);
int		check_char(t_map *map);
int		charcount(char *str, t_map *map);
int		main(int argc, char **argv);
int		is_path_valid(t_map *map);
void	player_pos(t_map *map);
void	get_map_size(t_map *map, char *file);
void	free_map(t_map *map);
void	close_and_free_game(t_game *game);
void	close_and_print_error(char *msg, t_map *map, int fd);
void	print_error(char *msg, t_map *map);
void	error_exit(char *msg);
void	game_over(char *msg, t_game *game);
void	buildgrid(t_map *map, char *file);
void	flood_fill(t_map *mapcopy, size_t x, size_t y);
void	launch(t_game *game);
void	load_images(t_game *game);
void	make_floor(t_game *game);
void	spread_game_elements(t_game *game);
void	keypress(mlx_key_data_t keydata, void *param);
void	execute_move(t_game *game, int y_move, int x_move);
void	collecting(t_game *game, size_t x, size_t y);
void	exiting(t_game *game, size_t x, size_t y);
t_map	*copy_map(t_map *map);
t_map	*create_map(char *file);

#endif
