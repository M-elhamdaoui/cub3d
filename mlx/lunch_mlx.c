/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunch_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:36:42 by mel-hamd          #+#    #+#             */
/*   Updated: 2024/08/31 22:59:06 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void rneder_map_2d(t_cub3d *cub)
{
	char	**map;
	int 	i;
	int		j;
	int		color;
	t_d		d;
	t_corr	c;

	i = 0;
	j = 0;
	d.h = 16;
	d.w = 16;
	map = cub->map.map;
	while (map && map[i])
	{
		j = 0;
		while (map[i] && map[i][j])
		{
			c.y = 16 * i;
			c.x = 16 * j;
			if (map[i][j] == ' ')
				color = ft_create_color(0, 0, 0, 255);
			else if (map[i][j] == '1')
				color = ft_create_color(255, 255, 255, 255);
			else if (map[i][j] == '0')
				color = ft_create_color(3, 140, 127, 255);
			else
				color = ft_create_color(180, 0, 120, 255);
			put_square(&c, &d, cub, color);
			j++;
		}
		i++;
	}
}


int lunch_mlx(t_cub3d *cub)
{
	t_corr	c;
	t_d		d;

	c.x = 0;
	c.y = 0;
	d.h = 16;
	d.w = 16;
	cub->m = mlx_init(900, 900, "CUB3D", 0);
	if (!cub->m)
		return (0);
	cub->img = create_image(900, 900, cub);
	if (!cub->img)
		ft_exit("Error\nFail to create image\n", 1, cub);
	mlx_image_to_window(cub->m, cub->img , 0, 0);
	rneder_map_2d(cub);
	mlx_loop(cub->m);
	return (1);
}
