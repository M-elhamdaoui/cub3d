/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_circle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:28:04 by mel-hamd          #+#    #+#             */
/*   Updated: 2024/10/30 11:02:37 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_circle(int x, int y, int color, t_cub3d *cub)
{
	int	i;
	int	j;
	int	r;

	r = cub->p.rad;
	i = r * (-1);
	while (i < r)
	{
		j = r * (-1);
		while (j < r)
		{
			if (x + j < 0 || y + i < 0)
				break ;
			if (x + j >= W_SIZE || y + i >= H_SIZE)
				break ;
			if ((j * j) + (i * i) <= r * r)
				mlx_put_pixel(cub->img, x + j, y + i, color);
			j++;
		}
		i++;
	}
}
