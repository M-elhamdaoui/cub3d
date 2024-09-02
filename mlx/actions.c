/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 22:00:46 by mel-hamd          #+#    #+#             */
/*   Updated: 2024/09/02 18:09:32 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_fun(void *params)
{
	t_cub3d	*c;

	c = (t_cub3d *)params;
	if (mlx_is_key_down(c->m, MLX_KEY_S))
		c->p.wd = -1;
	else if (mlx_is_key_down(c->m, MLX_KEY_W))
		c->p.wd = 1;
	else if (mlx_is_key_down(c->m, MLX_KEY_D))
		c->p.wd_h = 1;
	else if (mlx_is_key_down(c->m, MLX_KEY_A))
		c->p.wd_h = -1;
	else if (mlx_is_key_down(c->m, MLX_KEY_LEFT))
		c->p.td = -1;
	else if (mlx_is_key_down(c->m, MLX_KEY_RIGHT))
		c->p.td = 1;
	move(c);
	printf("sp %f , td %d\n", c->p.rot_speed,c->p.td);
	rneder_map_2d(c);
}
