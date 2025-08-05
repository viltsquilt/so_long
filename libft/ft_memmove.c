/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:42:05 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/04/23 16:26:42 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dest_array;
	char	*src_array;
	size_t	i;

	i = 0;
	dest_array = (char *) dest;
	src_array = (char *) src;
	if (!dest && !src)
		return (0);
	if (dest <= src)
	{
		while (i < n)
		{
			dest_array[i] = src_array[i];
			i++;
		}
	}
	else if (dest > src)
	{
		while (n--)
			dest_array[n] = src_array[n];
	}
	return (dest);
}
