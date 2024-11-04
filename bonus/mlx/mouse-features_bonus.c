/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse-features_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:38:18 by hmrabet           #+#    #+#             */
/*   Updated: 2024/11/04 16:38:28 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	mouse_click_handler(mouse_key_t button, action_t action,
		modifier_key_t mods, void *param)
{
	t_cub3d	*cub;

	(void)mods;
	cub = param;
	if (button == MLX_MOUSE_BUTTON_LEFT
		&& action == MLX_RELEASE && !cub->actions_lock && !cub->freeze)
		1 && (cub->actions_lock = TRUE, cub->action = HIT);
	if (button == MLX_MOUSE_BUTTON_RIGHT
		&& action == MLX_RELEASE && !cub->actions_lock && !cub->freeze)
		1 && (cub->actions_lock = TRUE, cub->action = FLEX);
	if (button == MLX_MOUSE_BUTTON_MIDDLE
		&& action == MLX_RELEASE && !cub->actions_lock && !cub->freeze)
		1 && (cub->actions_lock = TRUE, cub->action = KNIFE);
}

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
