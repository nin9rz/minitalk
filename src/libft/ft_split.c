/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenibaud <jean.nibaudeau2@outlook.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:01:21 by jenibaud          #+#    #+#             */
/*   Updated: 2024/10/23 19:12:28 by jenibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	parts_count(char *str, char sep)
{
	size_t	i;
	size_t	j;
	size_t	parts;

	i = 0;
	parts = 0;
	while (str[i] != '\0')
	{
		j = i + 1;
		if ((str[i] != sep) && (str[j] == sep))
			parts++;
		if ((str[i] != sep) && (str[j] == '\0'))
			parts++;
		i++;
	}
	return (parts);
}

static void	ft_free(char **res)
{
	size_t	i;

	i = 0;
	while (res[i] != NULL)
	{
		free(res[i]);
		i++;
	}
	free(res);
}

static int	part_len(size_t start, char *str, char sep)
{
	size_t	i;

	i = start;
	while (str[i] != sep && str[i] != '\0')
	{
		i++;
	}
	return (i - start);
}

static char	**table_fill(char **res, char *tmp, char sep)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (tmp[i] != '\0')
	{
		if (((i == 0) && (tmp[i] != sep))
			|| ((tmp[i - 1] == sep) && (tmp[i] != sep)))
		{
			res[j] = ft_substr(tmp, i, part_len(i, tmp, sep));
			if (!res[j])
			{
				return (NULL);
			}
			j++;
		}
		i++;
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	char	*tmp;

	if (!s)
		return (NULL);
	tmp = (char *)s;
	res = ft_calloc((parts_count(tmp, c) + 1), sizeof(char *));
	if (!res)
		return (0);
	res = table_fill(res, tmp, c);
	if (!res)
	{
		ft_free(res);
		return (NULL);
	}
	return (res);
}
