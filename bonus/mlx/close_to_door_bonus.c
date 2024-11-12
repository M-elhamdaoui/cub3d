/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_to_door_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:49:16 by hmrabet           #+#    #+#             */
/*   Updated: 2024/11/12 17:56:39 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static t_bool	door_con(t_cub3d *c, int i)
{
	return ((floor(c->p.c.x / US) + 1 == c->doors[i]->x
			|| floor(c->p.c.x / US) - 1 == c->doors[i]->x
			|| floor(c->p.c.x / US) == c->doors[i]->x)
		&& (floor(c->p.c.y / US) + 1 == c->doors[i]->y
			|| floor(c->p.c.y / US) - 1 == c->doors[i]->y
			|| floor(c->p.c.y / US) == c->doors[i]->y));
}

int	close_to_door(t_cub3d *c)
{
	int	i;

	i = -1;
	while (c->doors[++i])
	{
		if (door_con(c, i))
		{
			if (c->doors[i]->progress < US)
			{
				1 && (c->doors[i]->progress++, c->doors[i]->is_opening = 1);
				c->doors[i]->is_closing = 0;
			}
			else
				c->doors[i]->is_closed = 0;
			continue ;
		}
		if (c->doors[i]->progress > 0)
		{
			1 && (c->doors[i]->progress--, c->doors[i]->is_opening = 0);
			c->doors[i]->is_closing = 1;
		}
		else
			c->doors[i]->is_closed = 1;
	}
	return (0);
}
