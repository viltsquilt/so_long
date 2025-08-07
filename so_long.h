/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:12:03 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/08/07 14:39:40 by vahdekiv         ###   ########.fr       */
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
	char	**map;
	char	*linemap;
}	t_map;

typedef struct s_game
{
	void	*mlx_ptr; // MLX pointer
	void	*win_ptr; // MLX window pointer
	void	*textures[5]; // MLX image pointers (on the stack)
	t_map	*maps; //map pointer (contains map details, preferably on the stack)
}	t_game;

size_t	newstrlen(char *str, char c);
int		check_extension(char *string);
int		get_map_size(t_map *maps, int fd);
int		check_walls(t_map *maps, int fd);
int		check_char(t_map *maps);
int		charcount(char *str, t_map *maps);
int		main(int argc, char **argv);
int		is_path_available(t_map *maps);
void	player_pos(t_map *maps);
void	create_map(char *mapfile);
void	free_map(t_map *maps);
void	close_and_print_error(char *msg, t_map *maps, int fd);
void	print_error(char *msg, t_map *maps);
void	flood_fill(t_map *mapcopy, size_t x, size_t y);
t_map	*copy_map(t_map *maps);

#endif
