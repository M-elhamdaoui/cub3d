/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wraith_2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:58:22 by hmrabet           #+#    #+#             */
/*   Updated: 2024/11/04 15:33:15 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	wraith(t_cub3d *c, unsigned int i)
{
	float	scale;
	int		scaled_x;
	int		scaled_y;

	if (c->wraith.wraith_frame == 154)
		c->wraith.wraith_frame = 0;
	scale = 0.001;
	scaled_x = ((int)(c->wraith.wraith[c->wraith.wraith_frame]->width * scale)
			- W_SIZE) / 8;
	scaled_y = (H_SIZE - (int)(c->wraith.wraith[c->wraith.wraith_frame]->height
				* scale)) / 8;
	ft_draw_image(c, c->wraith.wraith[c->wraith.wraith_frame],
		scaled_x, scaled_y);
	(!(i % 2)) && (c->wraith.wraith_frame++);
}
