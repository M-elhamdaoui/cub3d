/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_mlx_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:36:42 by mel-hamd          #+#    #+#             */
/*   Updated: 2024/11/14 00:26:42 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	close_window(void *params)
{
	t_cub3d	*c;

	c = (t_cub3d *) params;
	ft_exit(NULL, 0, c);
}

void	lunch_mlx(t_cub3d *cub)
{
	cub->m = mlx_init(W_SIZE, H_SIZE, "CUB3D_Bonus", 0);
	if (!cub->m)
		ft_exit("mlx_init failed\n", 1, cub);
	cub->img = create_image(W_SIZE, H_SIZE, cub);
	if (!cub->img)
		ft_exit("Failed to create image\n", 1, cub);
	if (mlx_image_to_window(cub->m, cub->img, 0, 0) == -1)
		ft_exit("mlx_image_to_window failed\n", 1, cub);
	print_rays(cub);
	mlx_close_hook(cub->m, close_window, cub);
	mlx_loop_hook(cub->m, &rendrer, cub);
	mlx_key_hook(cub->m, &key_press_fun, cub);
	mlx_mouse_hook(cub->m, &mouse_click_handler, cub);
	mlx_set_cursor_mode(cub->m, MLX_MOUSE_HIDDEN);
	mlx_cursor_hook(cub->m, &ft_mouse_move, cub);
	mlx_loop(cub->m);
}
