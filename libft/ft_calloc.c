/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:56:05 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/04/28 10:46:19 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*space;
	char			*error;
	size_t			total;

	total = nmemb * size;
	if (nmemb == 0 || size == 0)
	{
		error = malloc(1);
		error[0] = '\0';
		return (error);
	}
	else if (total / nmemb != size)
		return (NULL);
	space = malloc (total);
	if (!space)
		return (NULL);
	ft_bzero(space, total);
	return (space);
}
