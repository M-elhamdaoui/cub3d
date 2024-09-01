/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 20:18:54 by mel-hamd          #+#    #+#             */
/*   Updated: 2024/09/01 21:01:11 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_line(t_corr a, t_corr b, t_cub3d *cub)
{
	int		m;
	double	dx;
	double	dy;
	double	steps;
	double	inc[2];

	dx = b.x - a.x;
	dy = b.y - a.y;
	if (dx > dy)
		steps = dx;
	else
		steps = dy;
	if (dx < dy)
		m = 10;
	else
		m = dy / dx;
	incx[0] = dx / steps;
	incy[1] = dy / steps;
	while (--steps)
	{
		a.x += incx[0];
		a.y += incy[1];
		mlx_put_pixel(cub->img, round(a.x), round(a.y),
			ft_create_color(255, 125, 0, 255));
	}
}
