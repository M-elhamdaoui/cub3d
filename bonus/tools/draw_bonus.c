/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:01:08 by hmrabet           #+#    #+#             */
/*   Updated: 2024/10/30 19:12:10 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	ft_color(int r, int g, int b, int a)
{
	return ((((r * 256 + g) * 256) + b) * 256 + a);
}

static int	ft_texture_colors(unsigned int c)
{
	int	r;
	int	g;
	int	b;
	int	a;

	a = c % 256;
	c /= 256;
	b = c % 256;
	c /= 256;
	g = c % 256;
	c /= 256;
	r = c;
	return (ft_color(a, b, g, r));
}

void	ft_draw_image(t_cub3d *data, mlx_texture_t *texture, int x, int y)
{
	int	i ;
	int	j;
	int	color;
	t_ui *colors;

	i = 0;
	j = 0;
	colors = (uint32_t *)texture->pixels;
	while (i < (int)texture->height)
	{
		j = 0;
		while (j < (int)texture->width)
		{
			color = ft_texture_colors(colors[i * texture->width + j]);
			if (color && (j + x >= 0 && j + x < W_SIZE && i + y >= 0 && i + y < H_SIZE))
			    mlx_put_pixel(data->img, j + x, i + y, \
			ft_texture_colors(colors[i * texture->width + j]));
			j++;
		}
		i++;
	}
}
