/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 22:00:46 by mel-hamd          #+#    #+#             */
/*   Updated: 2024/11/04 17:44:16 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
	if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_RELEASE)
		1 && (c->freeze = 1, c->open_menu = TRUE, c->actions_lock = FALSE, c->action = NORMAL, c->menu.is_resume = TRUE);
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		c->menu.is_resume = !c->menu.is_resume;
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		c->menu.is_resume = !c->menu.is_resume;
	if (keydata.key == MLX_KEY_ENTER && keydata.action == MLX_RELEASE && c->open_menu)
	{
		if (c->menu.is_resume)
		{
			c->open_menu = FALSE;
			c->freeze = 0;
		}
		else
			ft_exit(NULL, 0, c);
	}
}

static void	key_func(t_cub3d *c)
{
	if (mlx_is_key_down(c->m, MLX_KEY_ESCAPE))
		ft_exit(NULL, 0, c);
	if (!c->freeze)
	{
		if (mlx_is_key_down(c->m, MLX_KEY_S) && (c->action != KICK))
			c->p.wd += -1;
		if (mlx_is_key_down(c->m, MLX_KEY_W) && (c->action != KICK))
			c->p.wd += 1;
		if (mlx_is_key_down(c->m, MLX_KEY_D) && (c->action != KICK))
			c->p.wd_h += 1;
		if (mlx_is_key_down(c->m, MLX_KEY_A) && (c->action != KICK))
			c->p.wd_h += -1;
		if (mlx_is_key_down(c->m, MLX_KEY_LEFT))
			c->p.td += -3;
		if (mlx_is_key_down(c->m, MLX_KEY_RIGHT))
			c->p.td += 3;
		if (mlx_is_key_down(c->m, MLX_KEY_UP) && c->open_menu)
			c->menu.is_resume = !c->menu.is_resume;
		if (mlx_is_key_down(c->m, MLX_KEY_DOWN) && c->open_menu)
			c->menu.is_resume = !c->menu.is_resume;
		move(c);
	}
}

static void	walk(t_cub3d *c, unsigned int i)
{
	int	scaled_x;
	int	scaled_y;

	if (c->wraith.pre_walk_frame == 9)
	{
		(c->wraith.walk_frame == 14) && (c->wraith.walk_frame = 0);
		scaled_x = (W_SIZE
				- (int)(c->wraith.walk[c->wraith.walk_frame]->width));
		scaled_y = (H_SIZE
				- (int)(c->wraith.walk[c->wraith.walk_frame]->height));
		ft_draw_image(c, c->wraith.walk[c->wraith.walk_frame],
			scaled_x, scaled_y);
		(!(i % 2)) && (c->wraith.walk_frame++);
	}
	else
	{
		scaled_x = (W_SIZE
				- (int)(c->wraith.pre_walk[c->wraith.pre_walk_frame]->width));
		scaled_y = (H_SIZE
				- (int)(c->wraith.pre_walk[c->wraith.pre_walk_frame]->height));
		ft_draw_image(c, c->wraith.pre_walk[c->wraith.pre_walk_frame],
			scaled_x, scaled_y);
		c->wraith.pre_walk_frame++;
	}
}

static void	moves(t_cub3d *c, unsigned int i)
{
	if (mlx_is_key_down(c->m, MLX_KEY_S) || mlx_is_key_down(c->m, MLX_KEY_W)
		|| mlx_is_key_down(c->m, MLX_KEY_D) || mlx_is_key_down(c->m, MLX_KEY_A))
		walk(c, i);
	else
		stand(c, i);
}

void	menu(t_cub3d *c)
{
	mlx_texture_t *texture;

	texture = c->menu.quit;
	if (c->menu.is_resume)
		texture = c->menu.resume;
	ft_draw_image(c, texture, 0, 0);
}

void	rendrer(void *params)
{
	static unsigned int	i;
	t_cub3d				*c;

	c = (t_cub3d *)params;
	key_func(c);
	print_rays(c);
	if (c->open_menu)
		menu(c);
	else
	{
		if (c->freeze)
			wraith(c, i);
		else if (c->actions_lock)
		{
			if (c->action == HIT)
				hit(c, i);
			else if (c->action == FLEX)
				flex(c, i);
			else if (c->action == KNIFE)
				knife(c, i);
			else if (c->action == KICK)
				kick(c, i);
		}
		else if (!c->actions_lock)
			moves(c, i);		
	}
	i++;
}
