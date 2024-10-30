/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   omen_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:58:22 by hmrabet           #+#    #+#             */
/*   Updated: 2024/10/30 19:01:03 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void    omen(t_cub3d *c)
{
    if (c->omenFrame == 30)
        c->omenFrame = 0;
    float scale = 0.5;
    int scaled_x = ((int)(c->omen[c->omenFrame]->width * scale) - W_SIZE) / 4;
    int scaled_y = (H_SIZE - (int)(c->omen[c->omenFrame]->height * scale)) / 2;
    ft_draw_image(c, c->omen[c->omenFrame], scaled_x, scaled_y);
    c->omenFrame++;	
}