/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line_v2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 10:33:13 by mel-hamd          #+#    #+#             */
/*   Updated: 2024/10/29 11:29:22 by hmrabet          ###   ########.fr       */
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

uint32_t	get_texture_pixel(mlx_texture_t *texture, int x, int y, t_ray ray)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;
	int		index;
	double	intensity;

	intensity = 0.5 - (ray.distance / 1000);
	(intensity > 1) && (intensity = 1);
	(intensity < 0.05) && (intensity = 0.05);
	if (x >= 0 && (uint32_t)x < texture->width
		&& y >= 0 && (uint32_t)y < texture->height)
	{
		index = (y * texture->width + x) * texture->bytes_per_pixel;
		r = texture->pixels[index] * intensity;
		g = texture->pixels[index + 1] * intensity;
		b = texture->pixels[index + 2] * intensity;
		a = texture->pixels[index + 3];
		return (r << 24 | g << 16 | b << 8 | a);
	}
	return (0x000000FF);
}

void	draw_textures(t_cub3d *cub, double x, t_ray r)
{
	int			index;
	uint32_t	color;
	int			begin;

	cub->wall.p_wall_h = 0;
	begin = 0;
	cub->wall.offset_x = (uint32_t)(r.hit_wall.x * cub->wall.texture->width / US) % cub->wall.texture->width;
	if (r.type == 'v')
		cub->wall.offset_x = (uint32_t)(r.hit_wall.y * cub->wall.texture->width / US) % cub->wall.texture->width;
	while(cub->wall.start < cub->wall.end)
	{
		if (cub->wall.o_wall_h >= H_SIZE)
			cub->wall.p_wall_h = cub->wall.o_wall_h - H_SIZE;
		cub->wall.offset_y = (begin + cub->wall.p_wall_h / 2) * cub->wall.texture->height / cub->wall.o_wall_h;
		index = cub->wall.texture->width * cub->wall.offset_y + cub->wall.offset_x;
		index *= cub->wall.texture->bytes_per_pixel;
		color = get_texture_pixel(cub->wall.texture, cub->wall.offset_x, cub->wall.offset_y, r);
		mlx_put_pixel(cub->img, x, cub->wall.start, color);
		cub->wall.start++;
		begin++;
	}
}
