/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils-1_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 19:58:06 by hmrabet           #+#    #+#             */
/*   Updated: 2024/10/29 15:20:27 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;

	srclen = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (srclen);
	while (*(src + i) && i < dstsize - 1)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = '\0';
	return (srclen);
}

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	srclen = ft_strlen(src);
	if (!dstsize)
		return (srclen);
	i = 0;
	dstlen = 0;
	while (*(dst + dstlen) && dstlen < dstsize)
	{
		dstlen++;
	}
	while (*(src + i) && dstlen + i + 1 < dstsize)
	{
		*(dst + i + dstlen) = *(src + i);
		i++;
	}
	if (dstlen + i < dstsize)
	{
		*(dst + i + dstlen) = '\0';
	}
	return (dstlen + srclen);
}

int	ft_atoi(char *str)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while (*(str + i) && (*(str + i) == ' '
			|| (*(str + i) >= 9 && *(str + i) <= 13)))
		i++;
	if (*(str + i) == '+' || *(str + i) == '-')
	{
		if (*(str + i) == '-')
			sign = -sign;
		i++;
	}
	while (*(str + i) >= '0' && *(str + i) <= '9')
	{
		res = res * 10 + *(str + i) - 48;
		i++;
	}
	return (sign * (int)res);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (s && fd)
	{
		while (*(s + i))
		{
			ft_putchar_fd(*(s + i), fd);
			i++;
		}
	}
}
