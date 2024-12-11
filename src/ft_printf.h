/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenibaud <jenibaud@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:05:35 by jenibaud          #+#    #+#             */
/*   Updated: 2024/11/25 15:02:20 by jenibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);

/* Utils */

int		ft_putchar(char c);
int		ft_putstr(char *str);
size_t	ft_strlen(const char *s);
int		ft_putnbr(long long n);
int		putnbr_base(unsigned long n, char *base);

#endif
