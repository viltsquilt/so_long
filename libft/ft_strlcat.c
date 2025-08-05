/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:55:04 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/04/25 12:57:22 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;
	size_t	total;

	if (!src || !dst)
		return (0);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	total = src_len + dst_len;
	if (size < dst_len)
		return (src_len + size);
	if (size > 0 && size > dst_len + 1)
	{
		while (src[i] && dst_len <= size - 2)
		{
			dst[dst_len] = src[i];
			dst_len++;
			i++;
		}
	}
	dst[dst_len] = '\0';
	return (total);
}
