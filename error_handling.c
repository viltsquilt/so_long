/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 13:20:26 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/08/06 16:54:41 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_and_print_error(char *msg, t_map *maps, int fd)
{
	ft_printf("%s", msg);
	free_map(maps);
	close(fd);
	exit (1);
}

void	print_error(char *msg, t_map *maps)
{
	ft_printf("%s", msg);
	free_map(maps);
	exit (1);
}

void	free_map(t_map *maps)
{
	int	i;

	i = 0;
	if (maps)
	{
		free(maps[i]);
		maps[i] = NULL;
		i++;
	}
	free(maps);
	maps = NULL;
}
