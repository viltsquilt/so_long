/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 11:40:09 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/04/28 11:08:12 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_isset(char c, const char *setstring)
{
	int	i;

	i = 0;
	while (setstring[i])
	{
		if (setstring[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*newstr;
	int		len1;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (NULL);
	len1 = ft_strlen(s1);
	while (ft_isset(s1[i], set) == 1)
		i++;
	while (ft_isset(s1[len1 - 1], set) == 1)
		len1--;
	if (i > len1)
		len1 = i - len1;
	newstr = malloc((len1 - i) + 1);
	if (!newstr)
		return (NULL);
	while (i < len1)
		newstr[j++] = s1[i++];
	newstr[j] = '\0';
	return (newstr);
}
