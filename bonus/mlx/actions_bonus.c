/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 22:00:46 by mel-hamd          #+#    #+#             */
/*   Updated: 2024/11/13 23:54:33 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
	mlx_texture_t	*texture;

	texture = c->menu.resume_d;
	if (c->open_menu)
	{
		if (c->menu.option == RESUME_E)
			texture = c->menu.resume_e;
		else if (c->menu.option == D)
			texture = c->menu.d;
		else if (c->menu.option == QUIT_E)
			texture = c->menu.quit_e;
		else if (c->menu.option == QUIT_D)
			texture = c->menu.quit_d;
		else if (c->menu.option == E)
			texture = c->menu.e;
		else
			texture = c->menu.resume_d;
		ft_draw_image(c, texture, 0, 0);
	}
}

void	rendrer(void *c)
{
	key_func((t_cub3d *)c);
	print_rays((t_cub3d *)c);
	if (!((t_cub3d *)c)->open_menu)
	{
		if (((t_cub3d *)c)->freeze)
			wraith((t_cub3d *)c, ((t_cub3d *)c)->i);
		else if (((t_cub3d *)c)->actions_lock)
		{
			if (((t_cub3d *)c)->action == HIT)
				hit((t_cub3d *)c, ((t_cub3d *)c)->i);
			else if (((t_cub3d *)c)->action == FLEX)
				flex((t_cub3d *)c, ((t_cub3d *)c)->i);
			else if (((t_cub3d *)c)->action == KNIFE)
				knife((t_cub3d *)c, ((t_cub3d *)c)->i);
			else if (((t_cub3d *)c)->action == KICK)
				kick((t_cub3d *)c, ((t_cub3d *)c)->i);
		}
		else if (!((t_cub3d *)c)->actions_lock)
			moves((t_cub3d *)c, ((t_cub3d *)c)->i);
	}
	close_to_door(c);
	draw_minimap(c);
	menu((t_cub3d *)c);
	((t_cub3d *)c)->i++;
}
