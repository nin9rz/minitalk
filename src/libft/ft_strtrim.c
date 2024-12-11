/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenibaud <jean.nibaudeau2@outlook.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:01:37 by jenibaud          #+#    #+#             */
/*   Updated: 2024/10/17 18:44:00 by jenibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	start(char *dest, char *set)
{
	size_t	i;

	i = 0;
	while (is_in_set(dest[i], set))
	{
		i++;
	}
	return (i);
}

static int	end(char *dest, char *set)
{
	size_t	i;

	i = ft_strlen(dest) - 1;
	while (is_in_set(dest[i], set))
	{
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*dest;
	char	*res;

	if (s1 == NULL || set == NULL)
		return (0);
	dest = (char *)s1;
	i = start(dest, (char *)set);
	j = end(dest, (char *)set);
	res = ft_substr(dest, i, (j - i) + 1);
	if (!res)
		return (NULL);
	return (res);
}
