/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line_v2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 10:33:13 by mel-hamd          #+#    #+#             */
/*   Updated: 2024/10/27 14:14:53 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_line_v2(t_corr c, int d, double ang, t_cub3d *cub)
{
	double	i;
	t_corr p;

	i = 0;
	while(i <= d)
	{
		p.x = c.x + i * cos(ang);
		p.y = c.y + i * sin(ang);
		if (p.x < 0 || p.y < 0)
			break ;
		if (p.x >= W_SIZE || p.y >= H_SIZE)
			break ;
		mlx_put_pixel(cub->img, p.x, p.y, c.color);
		i++;
	}
}
