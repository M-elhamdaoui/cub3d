/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays_h.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:53:05 by mel-hamd          #+#    #+#             */
/*   Updated: 2024/09/06 17:16:32 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	cast_h_condition(t_corr inter, t_cub3d *c)
{
	if (inter.x >= 0
		&& (int)(inter.x / US) < c->map.width
		&& inter.y >= 0
		&& (int)(inter.y / US) < c->map.height)
		return (1);
	return (0);
}

t_ray	cast_ray_h(t_cub3d *c, double ang,int is_r_down,int is_r_left)
{
	double	step[2];
	t_ray	ray;
	t_corr	intercept;
	double	tmp;

	intercept.y = floor(c->p.c.y / US) * US;
	if (is_r_down)
		intercept.y += US;
	intercept.x = c->p.c.x + ((intercept.y - c->p.c.y) / tan(ang));
	setup_steps_h(step, is_r_down, is_r_left, ang);
	while (cast_h_condition(intercept, c))
	{
		if (is_r_down)
			tmp = intercept.y + 1;
		else
			tmp = intercept.y - 1;
		if (c->map.map[(int)(tmp / US)][(int)(intercept.x / US)] == '1')
		{
			ray.distance = calc_distance(c->p.c, intercept);
			return (ray.is_w_hited = 1, ray.hit_wall = intercept, ray);
		}
		intercept.x += step[1];
		intercept.y += step[0];
	}
	return (ray.is_w_hited = 0, ray);
}
