/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays_h_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:53:05 by mel-hamd          #+#    #+#             */
/*   Updated: 2024/11/12 17:41:44 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static inline t_bool	condition(t_cub3d *c, t_corr i, double tmp)
{
	return (floor(tmp / US) < c->map.height
		&& (int)floor(i.x / US) < c->map.width
		&& floor(tmp / US) >= 0 && (int)floor(i.x / US) >= 0
		&& ((c->map.map[(int)floor(tmp / US)][(int)floor(i.x / US)] == '1')
		|| ((c->map.map[(int)floor(tmp / US)][(int)floor(i.x / US)] == 'D'
			&& (int)floor(fmod(i.x, US)) >= ft_get_door(c, (int)floor(i.x / US),
				(int)floor(tmp / US))->progress))));
}

int	cast_condition(t_corr inter, t_cub3d *c)
{
	if (inter.x >= 0
		&& floor(inter.x / US) < c->map.width
		&& inter.y >= 0
		&& floor(inter.y / US) < c->map.height)
		return (1);
	return (0);
}

t_ray	cast_ray_h(t_cub3d *c, double ang, int is_r_down, int is_r_left)
{
	double	step[2];
	t_ray	ray;
	t_corr	intercept;
	double	tmp;

	intercept.y = floor(c->p.c.y / US) * US;
	(is_r_down) && (intercept.y += US);
	intercept.x = c->p.c.x + ((intercept.y - c->p.c.y) / tan(ang));
	setup_steps_h(step, is_r_down, is_r_left, ang);
	while (cast_condition(intercept, c))
	{
		(is_r_down) && (tmp = intercept.y + 1);
		(!is_r_down) && (tmp = intercept.y - 1);
		if (condition(c, intercept, tmp))
		{
			ray.distance = calc_distance(c->p.c, intercept);
			ray.is_door = c->map.map[(int)floor(tmp / US)]
			[(int)floor(intercept.x / US)] == 'D';
			intercept.y = tmp;
			return (ray.is_w_hited = 1, ray.hit_wall = intercept, ray);
		}
		1 && (intercept.y += step[0], intercept.x += step[1]);
	}
	return (ray.is_w_hited = 0, ray);
}
