/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_square_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:06:04 by mel-hamd          #+#    #+#             */
/*   Updated: 2024/10/30 11:01:36 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

mlx_image_t	*create_image(int w, int h, t_cub3d *cub)
{
	mlx_image_t	*img;

	img = mlx_new_image(cub->m, w, h);
	return (img);
}

int	put_square(t_corr *corr, t_d *d, t_cub3d *cub, int color)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < d->w)
	{
		j = 0;
		while (j < d->h)
		{
			if (corr->x + i == corr->x || corr->x + i == corr->x + d->w - 1)
				mlx_put_pixel(cub->img, corr->x + i, corr->y + j,
					ft_create_color(0, 0, 0, 255));
			else if (corr->y + j == corr->y
				|| corr->y + j == corr->y + d->h - 1)
				mlx_put_pixel(cub->img, corr->x + i, corr->y + j,
					ft_create_color(0, 0, 0, 255));
			else
				mlx_put_pixel(cub->img, corr->x + i, corr->y + j, color);
			j++;
		}
		i++;
	}
	return (0);
}
