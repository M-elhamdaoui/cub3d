/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 19:52:50 by hmrabet           #+#    #+#             */
/*   Updated: 2024/10/29 15:20:22 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static size_t	count_length(int n)
{
	size_t	len;
	long	nb;

	nb = n;
	len = 0;
	if (nb < 0)
	{
		len++;
		nb = -nb;
	}
	if (nb == 0)
		len++;
	while (nb > 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

static size_t	ft_tenpow(size_t n)
{
	size_t	ten;

	ten = 1;
	if (n == 0)
		return (ten);
	while (n > 0)
	{
		ten *= 10;
		n--;
	}
	return (ten);
}

char	*ft_itoa(t_cub3d *cub, int n)
{
	size_t	len;
	size_t	i;
	long	nb;
	char	*res;

	len = count_length(n);
	res = (char *)ft_malloc(cub, &cub->collector, len + 1);
	nb = n;
	i = 0;
	if (nb < 0)
	{
		*res = '-';
		nb = -nb;
		i++;
		len--;
	}
	while (len-- > 0)
	{
		*(res + i++) = ((nb / ft_tenpow(len)) % 10) + 48;
	}
	*(res + i) = '\0';
	return (res);
}
