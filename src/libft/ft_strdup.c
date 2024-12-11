/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenibaud <jean.nibaudeau2@outlook.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:35:54 by jenibaud          #+#    #+#             */
/*   Updated: 2024/10/18 15:09:48 by jenibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*cpy;
	char	*dest;

	i = 0;
	cpy = (char *)s;
	dest = malloc(ft_strlen(cpy) * sizeof(char) + 1);
	if (!dest)
		return (NULL);
	while (cpy[i] != '\0')
	{
		dest[i] = cpy[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
