/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line_v2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 10:33:13 by mel-hamd          #+#    #+#             */
/*   Updated: 2024/10/29 14:33:57 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_line_v2(t_corr c, int d, double ang, t_cub3d *cub)
{
	double	i;
	t_corr	p;

	i = 0;
	while (i <= d)
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

t_ui	get_texture_pixel(t_cub3d *c)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;

	c->wall.shade = 0.5 - (c->ray.distance / 1000);
	(c->wall.shade > 1) && (c->wall.shade = 1);
	(c->wall.shade < 0.2) && (c->wall.shade = 0.2);
	if ((int)c->wall.x >= 0
		&& (t_ui)c->wall.x < c->wall.png->width
		&& (int)c->wall.y >= 0
		&& (t_ui)c->wall.y < c->wall.png->height)
	{
		c->wall.pixel_index = ((int)c->wall.y * c->wall.png->width
				+ (int)c->wall.x) * c->wall.png->bytes_per_pixel;
		r = c->wall.png->pixels[c->wall.pixel_index] * c->wall.shade;
		g = c->wall.png->pixels[c->wall.pixel_index + 1] * c->wall.shade;
		b = c->wall.png->pixels[c->wall.pixel_index + 2] * c->wall.shade;
		a = c->wall.png->pixels[c->wall.pixel_index + 3];
		return (r << 24 | g << 16 | b << 8 | a);
	}
	return (0x000000FF);
}

void	draw_textures(t_cub3d *cub, double x)
{
	t_ui	color;
	int		begin;

	cub->wall.p_wall_h = 0;
	begin = 0;
	cub->wall.x = cub->ray.hit_wall.x * cub->wall.png->width / US;
	if (cub->ray.type == 'v')
		cub->wall.x = cub->ray.hit_wall.y * cub->wall.png->width / US;
	cub->wall.x = (t_ui)cub->wall.x % cub->wall.png->width;
	while (cub->wall.start < cub->wall.end)
	{
		if (cub->wall.o_wall_h >= H_SIZE)
			cub->wall.p_wall_h = cub->wall.o_wall_h - H_SIZE;
		cub->wall.y = (begin + cub->wall.p_wall_h / 2);
		cub->wall.y *= cub->wall.png->height / cub->wall.o_wall_h;
		color = get_texture_pixel(cub);
		mlx_put_pixel(cub->img, x, cub->wall.start, color);
		cub->wall.start++;
		begin++;
	}
}
