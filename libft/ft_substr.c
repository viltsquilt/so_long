/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:01:36 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/07/22 13:52:28 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	length;
	char	*arr;

	if (!s)
		return (NULL);
	i = 0;
	j = start;
	length = ft_strlen(s);
	if (start > length || len == 0)
		return (ft_calloc(1, 1));
	if (len > length - start)
		len = (length - start);
	arr = malloc(len + 1);
	if (!arr)
		return (NULL);
	while (s[j] && i < len)
	{
		arr[i] = s[j];
		i++;
		j++;
	}
	arr[i] = '\0';
	return ((char *) arr);
}
