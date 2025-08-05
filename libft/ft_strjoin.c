/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 09:37:40 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/04/23 17:00:18 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*newstr;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		newstr = malloc(len1 + len2 + 1);
		if (!newstr)
			return (NULL);
		ft_memcpy(newstr, s1, len1);
		ft_memcpy(newstr + len1, s2, len2);
		newstr[len1 + len2] = '\0';
		return ((char *) newstr);
	}
	return (NULL);
}
