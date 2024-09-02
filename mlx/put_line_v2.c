/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line_v2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 10:33:13 by mel-hamd          #+#    #+#             */
/*   Updated: 2024/09/02 10:54:15 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_line_v2(t_corr c, int d, t_cub3d *cub)
{
	double	i;
	t_corr p;

	i = 0;
	while(i < d)
	{
		p.x = c.x + i * cos(cub->p.rot_ang);
		p.y = c.y + i * sin(cub->p.rot_ang);
		mlx_put_pixel(cub->img, p.x, p.y, ft_create_color(255, 120, 0, 255));
		i++;
	}
}
