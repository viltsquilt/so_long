/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:52:24 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/05/02 15:32:04 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_array;
	const unsigned char	*src_array;
	size_t				i;

	i = 0;
	dest_array = (unsigned char *) dest;
	src_array = (unsigned char *) src;
	while (i < n)
	{
		dest_array[i] = src_array[i];
		i++;
	}
	return (dest_array);
}
