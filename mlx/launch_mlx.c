/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:36:42 by mel-hamd          #+#    #+#             */
/*   Updated: 2024/09/07 18:24:51 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	generate_color(char c)
{
	int	color;

	color = 0;
	if (c == ' ')
		color = ft_create_color(0, 0, 0, 255);
	else if (c == '1')
		color = ft_create_color(255, 255, 255, 255);
	else
		color = ft_create_color(3, 140, 127, 255);
	return (color);
}

void	rneder_map_2d(t_cub3d *cub)
{
	char	**map;
	int		i;
	int		j;
	t_d		d;
	t_corr	c;

	1 && (i = 0, j = 0, d.h = US, d.w = US, map = cub->map.map);
	while (map && map[i])
	{
		j = 0;
		while (map[i] && map[i][j])
		{
			1 && (c.y = US * i, c.x = US * j);
			put_square(&c, &d, cub, generate_color(map[i][j]));
			j++;
		}
		i++;
	}
	print_rays(W_SIZE, cub);
	render_circle(cub->p.c.x, cub->p.c.y,  
		ft_create_color(0, 255, 0, 255), cub);
}

int	lunch_mlx(t_cub3d *cub)
{
	t_corr	c;
	t_d		d;

	c.x = 0;
	c.y = 0;
	d.h = US;
	d.w = US;
	cub->m = mlx_init(W_SIZE, H_SIZE, "CUB3D", 0);
	if (!cub->m)
		return (0);
	cub->img = create_image(W_SIZE, H_SIZE, cub);
	if (!cub->img)
		ft_exit("Fail to create image\n", 1, cub);
	mlx_image_to_window(cub->m, cub->img, 0, 0);
	print_rays(W_SIZE, cub);
	// rneder_map_2d(cub);
	mlx_loop_hook(cub->m, &key_fun, cub);
	mlx_loop(cub->m);
	return (1);
}
