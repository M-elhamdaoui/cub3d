/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 22:00:46 by mel-hamd          #+#    #+#             */
/*   Updated: 2024/09/01 23:57:36 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_fun(void *params)
{
	t_cub3d	*c;

	c = (t_cub3d *)params;
	if (mlx_is_key_down(c->m, MLX_KEY_DOWN))
		printf("to\n");
	else if (mlx_is_key_down(c->m, MLX_KEY_UP))
		printf("to\n");
	else if (mlx_is_key_down(c->m, MLX_KEY_LEFT))
		c->p.td = -1;
	else if (mlx_is_key_down(c->m, MLX_KEY_RIGHT))
		c->p.td = 1;
	cam_move(c);
	printf("sp %f , td %d\n", c->p.rot_speed,c->p.td);
	rneder_map_2d(c);
	c->p.td = 0;
}
