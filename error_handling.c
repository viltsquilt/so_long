/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 13:00:13 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/08/11 20:39:44 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_and_print_error(char *msg, t_map *map, int fd)
{
	ft_printf("%s", msg);
	free_map(map);
	close(fd);
	exit (1);
}

void	print_error(char *msg, t_map *map)
{
	ft_printf("%s", msg);
	free_map(map);
	exit (1);
}

void	game_over(char *msg, t_game *game)
{
	ft_printf("%s", msg);
	close_and_free_game(game);
}

void	error_exit(char *msg)
{
	ft_printf("%s", msg);
	exit (1);
}
