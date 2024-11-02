/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 22:00:46 by mel-hamd          #+#    #+#             */
/*   Updated: 2024/11/02 07:30:04 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_mouse_move(double xpos, double ypos, void *d)
{
	t_cub3d	*cub;
	int		x;
	int		y;

	cub = d;
	(void)xpos;
	(void)ypos;
	if (cub->mouse)
	{
		mlx_get_mouse_pos(cub->m, &x, &y);
		cub->p.td = MOUSE_SPEED * (double)(x - (W_SIZE / 2));
		mlx_set_mouse_pos(cub->m, (W_SIZE / 2), (H_SIZE / 2));
	}
}

void	key_press_fun(mlx_key_data_t keydata, void *params)
{
	t_cub3d	*c;

	c = (t_cub3d *)params;
	if (keydata.key == MLX_KEY_V && keydata.action == MLX_PRESS)
	{
		c->freeze = 1;
		c->omen_frame = 0;
		play_sound_effect("afplay bonus/textures/omen/omen.mp3");
		c->p.rot_ang += M_PI;
		(c->p.rot_ang > (2 * M_PI)) && (c->p.rot_ang -= 2 * M_PI);
	}
	if (keydata.key == MLX_KEY_V && keydata.action == MLX_RELEASE)
	{
		c->freeze = 0;
		c->omen_frame = 0;
		kill_sound_effect();
		c->p.rot_ang += M_PI;
		if (c->p.rot_ang > (2 * M_PI))
			c->p.rot_ang -= 2 * M_PI;
	}
	if (keydata.key == MLX_KEY_LEFT_CONTROL && keydata.action == MLX_RELEASE)
	{
		c->mouse = !c->mouse;
		(!c->mouse) && (c->p.td = 0);
	}
	if (keydata.key == MLX_KEY_LEFT_SHIFT && keydata.action == MLX_PRESS)
	{
		c->p.ms = 5;
	}
	if (keydata.key == MLX_KEY_LEFT_SHIFT && keydata.action == MLX_RELEASE)
	{
		c->p.ms = 3;
	}
}

void	key_fun(void *params)
{
	t_cub3d	*c;

	c = (t_cub3d *)params;
	if (mlx_is_key_down(c->m, MLX_KEY_ESCAPE))
		ft_exit(NULL, 0, c);
	if (!c->freeze)
	{
		if (mlx_is_key_down(c->m, MLX_KEY_S))
			c->p.wd += -1;
		if (mlx_is_key_down(c->m, MLX_KEY_W))
			c->p.wd += 1;
		if (mlx_is_key_down(c->m, MLX_KEY_D))
			c->p.wd_h += 1;
		if (mlx_is_key_down(c->m, MLX_KEY_A))
			c->p.wd_h += -1;
		if (mlx_is_key_down(c->m, MLX_KEY_LEFT))
			c->p.td += -3;
		if (mlx_is_key_down(c->m, MLX_KEY_RIGHT))
			c->p.td += 3;
		move(c);
	}
	print_rays(c);
	if (c->freeze)
		omen(c);
	else
	{
		if (mlx_is_key_down(c->m, MLX_KEY_S) || mlx_is_key_down(c->m, MLX_KEY_W)
			|| mlx_is_key_down(c->m, MLX_KEY_D) || mlx_is_key_down(c->m, MLX_KEY_A))
		{
			int scaled_x;
			int scaled_y;
			if (c->pre_walk_frame == 9)
			{
				if (c->walk_frame == 14)
					c->walk_frame = 0;
				scaled_x = (W_SIZE - (int)(c->walk[c->walk_frame]->width));
				scaled_y = (H_SIZE - (int)(c->walk[c->walk_frame]->height ));
				ft_draw_image(c, c->walk[c->walk_frame], scaled_x, scaled_y);
				c->walk_frame++;
			}
			else
			{
				scaled_x = (W_SIZE - (int)(c->pre_walk[c->pre_walk_frame]->width));
				scaled_y = (H_SIZE - (int)(c->pre_walk[c->pre_walk_frame]->height ));
				ft_draw_image(c, c->pre_walk[c->pre_walk_frame], scaled_x, scaled_y);
				c->pre_walk_frame++;
			}
		}
		else
		{
			c->walk_frame = 0;
			c->pre_walk_frame = 0;
			wraith(c);
		}
	}
}
