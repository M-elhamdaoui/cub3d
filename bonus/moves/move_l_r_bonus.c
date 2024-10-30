/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_l_r_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:51:22 by mel-hamd          #+#    #+#             */
/*   Updated: 2024/10/30 11:01:42 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
	tmp2 = c->p.c.y + c->p.ms * sin(ang);
	if (c->map.map[(int)(c->p.c.y / US)][(int)((tmp + r) / US)] == '1'
		|| c->map.map[(int)(c->p.c.y / US)][(int)((tmp - r) / US)] == '1')
		tmp = c->p.c.x;
	if (c->map.map[(int)((tmp2 + r) / US)][(int)((c->p.c.x) / US)] == '1'
		|| c->map.map[(int)((tmp2 - r) / US)][(int)((c->p.c.x) / US)] == '1')
		tmp2 = c->p.c.y;
	if (c->map.map[(int)(tmp2 / US)][(int)(tmp / US)] == '1')
		return ;
	c->p.c.y = tmp2;
	c->p.c.x = tmp;
}
