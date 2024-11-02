/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wraith_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 00:28:27 by hmrabet           #+#    #+#             */
/*   Updated: 2024/11/02 00:43:26 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	wraith(t_cub3d *c)
{
	float	scale;
	int		scaled_x;
	int		scaled_y;

	if (c->wraith_stand_frame == 16)
		c->wraith_stand_frame = 0;
	scale = 1;
	scaled_x = (W_SIZE - (int)(c->wraith[c->wraith_stand_frame]->width * scale));
	scaled_y = (H_SIZE - (int)(c->wraith[c->wraith_stand_frame]->height * scale));
	ft_draw_image(c, c->wraith[c->wraith_stand_frame], scaled_x, scaled_y);
	c->wraith_stand_frame++;
}
