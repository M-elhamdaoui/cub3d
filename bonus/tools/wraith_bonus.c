/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wraith_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 00:28:27 by hmrabet           #+#    #+#             */
/*   Updated: 2024/11/03 19:12:41 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	stand(t_cub3d *c, unsigned int i)
{
	float	scale;
	int		scaled_x;
	int		scaled_y;

	if (c->wraith.stand_frame == 12)
		c->wraith.stand_frame = 0;
	scale = 1;
	scaled_x = (W_SIZE - (int)(c->wraith.stand[c->wraith.stand_frame]->width * scale));
	scaled_y = (H_SIZE - (int)(c->wraith.stand[c->wraith.stand_frame]->height * scale));
	ft_draw_image(c, c->wraith.stand[c->wraith.stand_frame], scaled_x, scaled_y);
	(!(i % 2)) && (c->wraith.stand_frame++);
}
