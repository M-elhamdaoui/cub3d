/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wraith_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 00:28:27 by hmrabet           #+#    #+#             */
/*   Updated: 2024/11/04 20:19:04 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	stand(t_cub3d *c, unsigned int i)
{
	float	scale;
	int		scaled_x;
	int		scaled_y;

	c->wraith.walk_frame = 0;
	c->wraith.pre_walk_frame = 0;
	if (c->wraith.stand_frame == 12)
		c->wraith.stand_frame = 0;
	scale = 1;
	scaled_x = (W_SIZE
			- (int)(c->wraith.stand[c->wraith.stand_frame]->width * scale));
	scaled_y = (H_SIZE
			- (int)(c->wraith.stand[c->wraith.stand_frame]->height * scale));
	ft_draw_image(c, c->wraith.stand[c->wraith.stand_frame],
		scaled_x, scaled_y);
	(!(i % 2)) && (c->wraith.stand_frame++);
}

void	hit(t_cub3d *c, unsigned int i)
{
	float	scale;
	int		scaled_x;
	int		scaled_y;

	scale = 1;
	scaled_x = (W_SIZE
			- (int)(c->wraith.hit[c->wraith.hit_frame]->width * scale));
	scaled_y = (H_SIZE
			- (int)(c->wraith.hit[c->wraith.hit_frame]->height * scale));
	ft_draw_image(c, c->wraith.hit[c->wraith.hit_frame], scaled_x, scaled_y);
	(!(i % 3)) && (c->wraith.hit_frame++);
	if (c->wraith.hit_frame == 8)
		1 && (c->wraith.hit_frame = 0,
			c->actions_lock = FALSE, c->action = NORMAL);
}

void	knife(t_cub3d *c, unsigned int i)
{
	float	scale;
	int		scaled_x;
	int		scaled_y;

	scale = 1;
	scaled_x = (W_SIZE
			- (int)(c->wraith.knife[c->wraith.knife_frame]->width * scale));
	scaled_y = (H_SIZE
			- (int)(c->wraith.knife[c->wraith.knife_frame]->height * scale));
	ft_draw_image(c, c->wraith.knife[c->wraith.knife_frame],
		scaled_x, scaled_y);
	(!(i % 2)) && (c->wraith.knife_frame++);
	if (c->wraith.knife_frame == 48)
		1 && (c->wraith.knife_frame = 0, c->actions_lock = FALSE,
			c->action = NORMAL);
}

void	flex(t_cub3d *c, unsigned int i)
{
	float	scale;
	int		scaled_x;
	int		scaled_y;

	scale = 1;
	scaled_x = (W_SIZE
			- (int)(c->wraith.flex[c->wraith.flex_frame]->width * scale));
	scaled_y = (H_SIZE
			- (int)(c->wraith.flex[c->wraith.flex_frame]->height * scale));
	ft_draw_image(c, c->wraith.flex[c->wraith.flex_frame], scaled_x, scaled_y);
	(!(i % 2)) && (c->wraith.flex_frame++);
	if (c->wraith.flex_frame == 25)
		1 && (c->wraith.flex_frame = 0, c->actions_lock = FALSE,
			c->action = NORMAL);
}

void	kick(t_cub3d *c, unsigned int i)
{
	float	scale;
	int		scaled_x;
	int		scaled_y;

	scale = 1;
	scaled_x = (W_SIZE
			- (int)(c->wraith.kick[c->wraith.kick_frame]->width * scale));
	scaled_y = (H_SIZE
			- (int)(c->wraith.kick[c->wraith.kick_frame]->height * scale));
	ft_draw_image(c, c->wraith.kick[c->wraith.kick_frame], scaled_x, scaled_y);
	(!(i % 2)) && (c->wraith.kick_frame++);
	if (c->wraith.kick_frame == 22)
		1 && (c->wraith.kick_frame = 0, c->actions_lock = FALSE,
			c->action = NORMAL);
}
