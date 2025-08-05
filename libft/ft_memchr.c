/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:04:38 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/05/02 15:31:15 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	unsigned char		needle;
	int					i;

	if (!s)
		return (0);
	i = 0;
	str = (unsigned char *) s;
	needle = c;
	while (n > 0)
	{
		if (*str == needle)
		{
			return ((char *) str);
		}
		str++;
		n--;
	}
	return (0);
}
