/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wraith_2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:58:22 by hmrabet           #+#    #+#             */
/*   Updated: 2024/11/06 11:06:07 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	wraith(t_cub3d *c, unsigned int i)
{
	int		scaled_x;
	int		scaled_y;

	if (c->wraith.wraith_frame == 154)
		c->wraith.wraith_frame = 0;
	scaled_x = (W_SIZE
			- (int)(c->wraith.wraith[c->wraith.wraith_frame]->width));
	scaled_y = (H_SIZE
			- (int)(c->wraith.wraith[c->wraith.wraith_frame]->height));
	ft_draw_image(c, c->wraith.wraith[c->wraith.wraith_frame],
		scaled_x, scaled_y);
	(!(i % 2)) && (c->wraith.wraith_frame++);
}
