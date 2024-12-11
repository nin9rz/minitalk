/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenibaud <jean.nibaudeau2@outlook.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:18:30 by jenibaud          #+#    #+#             */
/*   Updated: 2024/10/11 14:43:48 by jenibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	dest_len = ft_strlen(dst);
	while (((dest_len + i) < size - 1) && src[i] != '\0')
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	dst[dest_len + i] = '\0';
	if (size < dest_len)
		return (size + ft_strlen(src));
	return (dest_len + ft_strlen(src));
}
