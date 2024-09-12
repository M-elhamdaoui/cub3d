/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:13:37 by mel-hamd          #+#    #+#             */
/*   Updated: 2024/09/12 13:31:24 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	render_y_of_image(t_corr c, int d, double ang, t_cub3d *cub)
{
	double	i;
	t_corr	p;
	int	 	color;
	t_corr	tmp;

	i = 0;
	while(i <= d && cub)
	{
		p.x = c.x + i * cos(ang);
		p.y = c.y + i * sin(ang);
		tmp = p;
		tmp.y = i ;
		if (p.x < 0 || p.y < 0)
			break ;
		if (p.x >= W_SIZE || p.y >= H_SIZE)
			break ;
		color = return_pixel(tmp, cub->wall_1);
		mlx_put_pixel(cub->img, p.x, p.y, color);
		i++;
	}
}

int	return_pixel(t_corr point, mlx_texture_t* t)
{
		t_corr	tmp;
		int		from;
		int		color;

		tmp.x = fmod(point.x, US) * t->width / US;
		tmp.y = point.y * t->height / US;;
		from = (tmp.x + tmp.y*t->width) * t->bytes_per_pixel;
		printf("%d\n", from);
		color = 0;
		// color = ft_create_color(t->pixels[from],t->pixels[from + 1],t->pixels[from + 2],t->pixels[from + 3]);
		return (color);
}
