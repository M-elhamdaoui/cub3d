/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions-1_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:17:03 by hmrabet           #+#    #+#             */
/*   Updated: 2024/11/04 19:27:49 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	handle_menu(t_cub3d *c)
{
	if (c->menu.is_resume)
	{
		c->open_menu = FALSE;
		c->freeze = 0;
	}
	else
		ft_exit(NULL, 0, c);
}

static void	key_press_fun2(mlx_key_data_t keydata, t_cub3d *c)
{
	if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_RELEASE)
	{
		if (c->open_menu)
			handle_menu(c);
		else
			1 && (c->freeze = 1, c->open_menu = TRUE, c->actions_lock = FALSE,
				c->action = NORMAL, c->menu.is_resume = TRUE);
	}
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		c->menu.is_resume = !c->menu.is_resume;
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		c->menu.is_resume = !c->menu.is_resume;
	if (keydata.key == MLX_KEY_ENTER && keydata.action == MLX_RELEASE
		&& c->open_menu)
		handle_menu(c);
}

void	key_press_fun(mlx_key_data_t keydata, void *params)
{
	t_cub3d	*c;

	c = (t_cub3d *)params;
	if (keydata.key == MLX_KEY_V && keydata.action == MLX_PRESS)
	{
		1 && (c->freeze = 1, c->wraith.wraith_frame = 0, c->p.rot_ang += M_PI);
		1 && (c->actions_lock = FALSE, c->action = NORMAL);
		(c->p.rot_ang > (2 * M_PI)) && (c->p.rot_ang -= 2 * M_PI);
	}
	if (keydata.key == MLX_KEY_V && keydata.action == MLX_RELEASE)
	{
		1 && (c->freeze = 0, c->wraith.wraith_frame = 0, c->p.rot_ang += M_PI);
		(c->p.rot_ang > (2 * M_PI)) && (c->p.rot_ang -= 2 * M_PI);
	}
	if (keydata.key == MLX_KEY_K && keydata.action == MLX_RELEASE
		&& !c->actions_lock && !c->freeze)
		1 && (c->actions_lock = TRUE, c->action = KICK);
	if (keydata.key == MLX_KEY_LEFT_CONTROL && keydata.action == MLX_RELEASE)
		1 && (c->mouse = !c->mouse, ((!c->mouse) && (c->p.td = 0)));
	if (keydata.key == MLX_KEY_LEFT_SHIFT && keydata.action == MLX_PRESS)
		c->p.ms = 5;
	if (keydata.key == MLX_KEY_LEFT_SHIFT && keydata.action == MLX_RELEASE)
		c->p.ms = 3;
	key_press_fun2(keydata, c);
}
