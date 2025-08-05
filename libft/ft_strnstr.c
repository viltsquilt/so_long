/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:06:32 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/05/02 11:32:58 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*needle;
	const char	*haystack;
	size_t		i;

	if (!*little)
		return ((char *)big);
	i = 0;
	while (*big && len > 0)
	{
		haystack = big;
		needle = little;
		while (i < len && (*haystack == *needle))
		{
			needle++;
			haystack++;
			i++;
		}
		if (!*needle)
			return ((char *)big);
		i = 0;
		big++;
		len--;
	}
	return (0);
}
