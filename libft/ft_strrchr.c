/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:07:26 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/04/25 12:37:15 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	if (!s)
		return (0);
	str = (char *) s;
	while (str[i])
		i++;
	if (c == '\0')
		return (&str[i]);
	i--;
	while (i >= 0)
	{
		if (str[i] == (char) c)
		{
			return (&str[i]);
		}
		i--;
	}
	return (0);
}
