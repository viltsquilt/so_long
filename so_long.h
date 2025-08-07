/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:12:03 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/08/07 19:35:20 by vahdekiv         ###   ########.fr       */
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
	void	*mlx_ptr; // MLX pointer
	void	*win_ptr; // MLX window pointer
	void	*textures[5]; // MLX image pointers (on the stack)
	t_map	*map; //map pointer (contains map details, preferably on the stack)
}	t_game;

size_t	newstrlen(char *str, char c);
int		check_extension(char *string);
int		check_walls(t_map *map);
int		check_char(t_map *map);
int		charcount(char *str, t_map *map);
int		main(int argc, char **argv);
int		is_path_available(t_map *map);
void	player_pos(t_map *map);
t_map	*create_map(char *file);
void	get_map_size(t_map *map, char *file);
void	free_map(t_map *map);
void	close_and_print_error(char *msg, t_map *map, int fd);
void	print_error(char *msg, t_map *map);
void	buildgrid(t_map *map, char *file);
void	flood_fill(t_map *mapcopy, size_t x, size_t y);
t_map	*copy_map(t_map *map);
t_map	*create_map(char *file);

#endif
