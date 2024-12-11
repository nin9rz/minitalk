/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenibaud <jenibaud@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:13:17 by jenibaud          #+#    #+#             */
/*   Updated: 2024/11/25 15:02:39 by jenibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write(1, str, ft_strlen(str));
	return ((int)ft_strlen(str));
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	putnbr_base(unsigned long n, char *base)
{
	char			c;
	unsigned long	len;

	len = ft_strlen(base);
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= len)
		return (putnbr_base(n / len, base) + putnbr_base(n % len, base));
	else
	{
		c = base[n];
		write(1, &c, 1);
		return (1);
	}
}

int	ft_putnbr(long long nb)
{
	int	len;

	len = (nb < 0);
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
	{
		len += ft_putnbr(nb / 10);
		len += ft_putnbr(nb % 10);
	}
	else
		len += ft_putchar(nb + '0');
	return (len);
}
