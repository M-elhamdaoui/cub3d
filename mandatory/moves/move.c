/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:57:44 by mel-hamd          #+#    #+#             */
/*   Updated: 2024/10/30 11:02:50 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move(t_cub3d *c)
{
	cam_move(c);
	move_f_b(c);
	move_l_r(c);
	c->p.wd = 0;
	c->p.wd_h = 0;
	c->p.td = 0;
}
