/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:12:03 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/08/05 19:05:15 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct	s_data
{
	void	*mlx_ptr; // MLX pointer
	void	*win_ptr; // MLX window pointer
	void	*textures[5]; // MLX image pointers (on the stack)
	t_map	*map; // map pointer (contains map details - preferably on the stack)
}	t_data;

typedef struct	s_map
{
	size_t	height;
	size_t	width;
	size_t	y;
	size_t	x;
	char	**arrays;
	char	*linemap;
}	t_map;

int	newstrlen(char *str, char c);
int	check_extension(char *string);
int	create_map(char **av);
int	main(int argc, char **argv);

#endif
