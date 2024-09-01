/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_circle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:28:04 by mel-hamd          #+#    #+#             */
/*   Updated: 2024/09/01 18:12:02 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_circle(int x, int y, int color, t_cub3d *cub)
{
	int	i;
	int	j;
	int	r;

	r = US / 2;
	i = r * (-1);
	while (i < r)
	{
		j = r * (-1);
		while (j < r)
		{
			if ((j * j) + (i * i) <= r * r)
				mlx_put_pixel(cub->img, x * US + j + r, y * US + i + r, color);
			j++;
		}
		i++;
	}
}
