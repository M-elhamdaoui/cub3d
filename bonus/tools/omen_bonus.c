/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   omen_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:58:22 by hmrabet           #+#    #+#             */
/*   Updated: 2024/10/31 08:21:04 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	omen(t_cub3d *c)
{
	float	scale;
	int		scaled_x;
	int		scaled_y;

	if (c->omen_frame == 30)
		c->omen_frame = 0;
	scale = 0.5;
	scaled_x = ((int)(c->omen[c->omen_frame]->width * scale) - W_SIZE) / 4;
	scaled_y = (H_SIZE - (int)(c->omen[c->omen_frame]->height * scale)) / 2;
	ft_draw_image(c, c->omen[c->omen_frame], scaled_x, scaled_y);
	c->omen_frame++;
}
