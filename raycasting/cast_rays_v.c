/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays_v.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:41:49 by mel-hamd          #+#    #+#             */
/*   Updated: 2024/09/06 18:50:03 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_ray	cast_rays_v(double ang, int is_down, int is_left, t_cub3d *c)
{
	double	step[2];
	t_ray	ray;
	t_corr	intercept;
	double	tmp;

	intercept.x = floor(c->p.c.x / US) * US;
	if (!is_left)
		intercept.x += US;
	intercept.y = c->p.c.y + ((intercept.x - c->p.c.x) * tan(ang));
	setup_steps_v(step, is_down, is_left, ang);
	while (cast_condition(intercept, c))
	{
		if (is_left)
			tmp = intercept.x - 1;
		else
			tmp = intercept.x + 1;
		if (c->map.map[(int)(intercept.y / US)][(int)(tmp / US)] == '1')
		{
			ray.distance = calc_distance(intercept, c->p.c);
			return (ray.is_w_hited = 1, ray.hit_wall = intercept, ray);
		}
		intercept.x += step[0];
		intercept.y += step[1];
	}
	return (ray.is_w_hited = 0, ray);
}
