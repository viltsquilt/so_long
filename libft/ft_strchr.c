/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 10:51:59 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/05/02 13:28:31 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char		needle;

	needle = (unsigned char) c;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == needle)
		{
			return ((char *) s);
		}
		s++;
	}
	if (needle == '\0')
		return ((char *) s);
	return (0);
}
