/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 20:18:54 by mel-hamd          #+#    #+#             */
/*   Updated: 2024/09/02 10:18:20 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_line(t_corr a, t_corr b, t_cub3d *cub)
{
	int		m;
	double	dx;
	double	dy;
	int		steps;
	double	inc[2];

	dx = b.x - a.x;
	dy = b.y - a.y;
	if (fabs(dx) < fabs(dy))
		m = 10;
	else
		m = fabs(dy) / fabs(dx);
	if (m > 1)
		steps = round(fabs(dy));
	else
		steps = round(fabs(dx));
	inc[0] = dx / steps;
	inc[1] = dy / steps;
	while (steps--)
	{
		a.x += inc[0];
		a.y += inc[1];
		mlx_put_pixel(cub->img, round(a.x), round(a.y),
			ft_create_color(255, 125, 0, 255));
	}
}
