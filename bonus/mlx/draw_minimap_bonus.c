/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 23:38:08 by mel-hamd          #+#    #+#             */
/*   Updated: 2024/11/14 01:43:55 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	generate_color(char c)
{
	int	color;

	color = 0;
	if (c == ' ')
		color = ft_create_color(60, 60, 60, 100);
	else if (c == '1')
		color = ft_create_color(255, 255, 255, 180);
	else
		color = ft_create_color(3, 140, 127, 255);
	return (color);
}

static void	print_door(t_cub3d *cub, t_d d, t_corr c, int iter[2])
{
	t_d		d1;
	t_corr	c1;
	char	**map;

	d1 = d;
	c1 = c;
	map = cub->map.map;
	if (map[iter[0] - 1][iter[1]] == '1' && map[iter[0] + 1][iter[1]] == '1')
	{
		d1.h = US - ft_get_door(cub, iter[1], iter[0])->progress;
		c1.y += US - d1.h;
	}
	else
	{
		d1.w = US - ft_get_door(cub, iter[1], iter[0])->progress;
		c1.x += US - d1.w;
	}
	put_square(&c1, &d1, cub, ft_create_color(0, 0, 0, 125));
}

static void	draw_blank(t_cub3d *cub, t_d d, int i, int j)
{
	t_corr	c;

	c.y = US * i;
	c.x = US * j;
	put_square(&c, &d, cub, ft_create_color(60, 60, 60, 100));
}

static void	draw_squares(t_cub3d *cub, int i, int j, double iter[])
{
	double	map_c[2];
	int		it[2];
	char	**map;
	t_corr	c;
	t_d		d;

	1 && (d.h = US, d.w = US, map = cub->map.map);
	map_c[0] = (iter[1] / US) + j;
	map_c[1] = (iter[0] / US) + i;
	if (map_c[0] >= 0 && map_c[0] < cub->map.width
		&& map_c[1] >= 0 && map_c[1] < cub->map.height)
	{
		1 && (c.y = US * i, c.x = US * j);
		put_square(&c, &d, cub,
			generate_color(map[(int)floor(map_c[1])]
			[(int)floor(map_c[0])]));
		if (map[(int)floor(map_c[1])][(int)floor(map_c[0])] == 'D'
			&& ft_get_door(cub, map_c[0], map_c[1]))
		{
			1 && (it[0] = map_c[1], it[1] = map_c[0]);
			print_door(cub, d, c, it);
		}
	}
	else
		draw_blank(cub, d, i, j);
}

void	draw_minimap(t_cub3d *cub)
{
	double	iter[2];
	t_corr	a;
	int		j;
	int		i;

	iter[0] = (cub->p.c.y) - ((RNG / 2) * US);
	iter[1] = (cub->p.c.x) - ((RNG / 2) * US);
	i = 0;
	while (++i < RNG + 1)
	{
		j = 0;
		while (++j < RNG + 1)
			draw_squares(cub, i, j, iter);
	}
	render_circle(128 + US / 2, 128 + US / 2,
		ft_create_color(0, 255, 0, 255), cub);
	a.x = 128 + US / 2;
	a.y = 128 + US / 2;
	a.color = ft_create_color(0, 255, 0, 255);
	put_line_v2(a, 10, cub->p.rot_ang, cub);
}
