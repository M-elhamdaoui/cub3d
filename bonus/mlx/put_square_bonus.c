/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_square_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:06:04 by mel-hamd          #+#    #+#             */
/*   Updated: 2024/11/13 14:49:16 by mel-hamd         ###   ########.fr       */
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
			mlx_put_pixel(cub->img, corr->x + i, corr->y + j, color);
			j++;
		}
		i++;
	}
	return (0);
}
