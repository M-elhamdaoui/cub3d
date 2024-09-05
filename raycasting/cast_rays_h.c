/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays_h.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:53:05 by mel-hamd          #+#    #+#             */
/*   Updated: 2024/09/05 18:50:58 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


double	get_angle(double ang)
{
	ang = fmod(ang, 2 * M_PI);
	if (ang < 0)
		ang = ang + (2 * M_PI);
	return (ang);
}

void	cast_ray(t_cub3d *c, double ang)
{
	double	stepx;
	double	stepy;
	int		distance;
	t_corr	intercept;
	int		is_r_down;
	int		is_r_left;
	// t_corr	next;	

	intercept.y = floor(c->p.c.y / US) * US;
	intercept.x = c->p.c.x + (intercept.y - c->p.c.y) / tan(ang);
	if (ang >= 0 && ang < M_PI)
		is_r_down = 1;
	else
		is_r_down = 0;
	if (ang >= M_PI / 2 && ang <= 3 * M_PI / 2)
		is_r_left = 1;
	else
		is_r_left = 0;
	if (is_r_down)
		intercept.y += US;
	stepy = US;
	if (!is_r_down)
		stepy *= -1;
	stepx = stepy / tan(ang);
	if ((!is_r_left && stepx < 0) || (is_r_left && stepx > 0))
		stepx *= -1;
	if (!is_r_down)
		intercept.y--;
	while (intercept.x >= 0 && intercept.x < W_SIZE && intercept.y >= 0 && intercept.y < H_SIZE)
	{
		if (c->map.map[(int)floor(intercept.y / US)][(int)floor(intercept.x / US)] == '1')
			break;
		intercept.x += stepx;
		intercept.y += stepy;
	}
	printf("is down : %d || is left : %d\n", is_r_down, is_r_left);
	distance = sqrt((intercept.x - c->p.c.x) * (intercept.x - c->p.c.x) + (intercept.y - c->p.c.y) * (intercept.y - c->p.c.y));
	printf("%d sksk\n", distance);
	put_line_v2(c->p.c, distance, ang, c);
}
