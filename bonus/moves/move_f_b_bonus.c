/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_f_b_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:41:12 by mel-hamd          #+#    #+#             */
/*   Updated: 2024/11/11 17:21:05 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	check_is_door(t_cub3d *c, double x, double y)
{
	t_doors *door;

	door = ft_get_door(c, floor(x / US), floor(y / US));
	if (!door)
		return (1);
	if ((door->is_closed && !door->is_opening) || door->is_closing)
		return (0);
	if (door->is_opening)
	{
		
	
		if ((int)floor(fmod(y , US)) >= door->progress
			&& c->map.map[(int)floor(y / US) + 1][(int)floor(x /  US)] == '1' 
			&& c->map.map[(int)floor(y / US) - 1][(int)floor(x / US)] == '1')
			return (0);
		if ((int)floor(fmod(x , US)) >= door->progress 
			&& c->map.map[(int)floor(y / US)][(int)floor(x /  US) + 1] == '1' 
			&& c->map.map[(int)floor(y / US)][(int)floor(x / US) - 1] == '1')
			return (0);
		return (1);
	}
	if (!door->is_closed && !door->is_closing)
		return (1);
	return (0);
}

void	move_f_b(t_cub3d *c)
{
	double	ang;
	double	tmp;
	double	tmp2;
	double	r;

	r = c->p.rad / 2;
	ang = c->p.rot_ang;
	tmp = c->p.c.x + c->p.ms * cos(ang) * c->p.wd;
	tmp2 = c->p.c.y + c->p.ms * sin(ang) * c->p.wd;
	if (c->map.map[(int)(c->p.c.y / US)][(int)((tmp + r) / US)] == '1'
		|| c->map.map[(int)(c->p.c.y / US)][(int)((tmp - r) / US)] == '1')
		tmp = c->p.c.x;
	if (c->map.map[(int)((tmp2 + r) / US)][(int)((c->p.c.x) / US)] == '1'
		|| c->map.map[(int)((tmp2 - r) / US)][(int)((c->p.c.x) / US)] == '1')
		tmp2 = c->p.c.y;
	if (c->map.map[(int)(tmp2 / US)][(int)(tmp / US)] == '1')
		return ;
	if (check_is_door(c, tmp, tmp2) == 0)
		return ;
	c->p.c.y = tmp2;
	c->p.c.x = tmp;
}
