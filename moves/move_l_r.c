/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_l_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:51:22 by mel-hamd          #+#    #+#             */
/*   Updated: 2024/09/02 19:06:05 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_l_r(t_cub3d *c)
{
	double	ang;
	double	tmp;
	double	tmp2;
	double	r;

	r = c->p.rad / 2;
	if (c->p.wd_h == 0)
		return ;
	ang = c->p.rot_ang + (M_PI / 2) * c->p.wd_h;
	tmp = c->p.c.x + c->p.ms * cos(ang);
	tmp2 =c->p.c.y + c->p.ms * sin(ang);
	if (c->map.map[(int)((tmp2) / US)][(int)((tmp + r) / US)] == '1')
		return ;
	else if (c->map.map[(int)((tmp2) / US)][(int)((tmp - r) / US)] == '1')
		return ;
	else if (c->map.map[(int)((tmp2 + r) / US)][(int)((tmp) / US)] == '1')
		return ;
	else if (c->map.map[(int)((tmp2 - r) / US)][(int)((tmp) / US)] == '1')
		return ;
	c->p.c.y = tmp2;
	c->p.c.x = tmp;
}
