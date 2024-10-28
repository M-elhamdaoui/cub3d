/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line_v2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 10:33:13 by mel-hamd          #+#    #+#             */
/*   Updated: 2024/10/28 18:17:05 by hmrabet          ###   ########.fr       */
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

uint32_t	get_texture_pixel(mlx_texture_t *texture, int x, int y)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;
	int		index;

	if (x >= 0 && (uint32_t)x < texture->width
		&& y >= 0 && (uint32_t)y < texture->height)
	{
		index = (y * texture->width + x) * texture->bytes_per_pixel;
		r = texture->pixels[index];
		g = texture->pixels[index + 1];
		b = texture->pixels[index + 2];
		a = texture->pixels[index + 3];
		return (r << 24 | g << 16 | b << 8 | a);
	}
	return (0x000000FF);
}

extern double rachid;

void	draw_textures(t_cub3d *cub, double start, double end, double x, t_ray r, double line_h)
{
	double 		offset_x;
	double 		offset_y;
	int			index;
	uint32_t	color;
	int			begin;
	(void)line_h;

	begin = 0;
	offset_x = (uint32_t)(r.hit_wall.x * cub->texture->width / US) % cub->texture->width;
	if (r.type == 'v')
		offset_x = (uint32_t)(r.hit_wall.y * cub->texture->width / US) % cub->texture->width;
	while(start <= end)
	{
		double hossam = 0;
		if (rachid>= H_SIZE)
			hossam = rachid - H_SIZE;
		
		offset_y = (begin + hossam / 2) * cub->texture->height / rachid;
		
		index = cub->texture->width * offset_y + offset_x;
		index *= cub->texture->bytes_per_pixel;
		// if (x >= 0 && (uint32_t)x < texture->width
		// 	&& y >= 0 && (uint32_t)y < texture->height)
		// color = ft_create_color(cub->texture->pixels[index], cub->texture->pixels[index + 1], cub->texture->pixels[index + 2], cub->texture->pixels[index + 3]);
		color = get_texture_pixel(cub->texture, offset_x, offset_y);
		mlx_put_pixel(cub->img, x, start, color);
		start++;
		begin++;
	}
}
