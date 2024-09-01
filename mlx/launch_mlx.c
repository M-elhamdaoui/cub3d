/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:36:42 by mel-hamd          #+#    #+#             */
/*   Updated: 2024/09/01 20:16:31 by hmrabet          ###   ########.fr       */
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
	d.h = US;
	d.w = US;
	map = cub->map.map;
	while (map && map[i])
	{
		j = 0;
		while (map[i] && map[i][j])
		{
			c.y = US * i;
			c.x = US * j;
			if (map[i][j] == ' ')
				color = ft_create_color(0, 0, 0, 255);
			else if (map[i][j] == '1')
				color = ft_create_color(255, 255, 255, 255);
			else if (map[i][j] == '0')
				color = ft_create_color(3, 140, 127, 255);
			put_square(&c, &d, cub, color);
			j++;
		}
		i++;
	}
	render_circle(cub->p.c.x,cub->p.c.y, ft_create_color(255, 126, 0, 255), cub);
}


int lunch_mlx(t_cub3d *cub)
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
	mlx_image_to_window(cub->m, cub->img , 0, 0);
	rneder_map_2d(cub);
	mlx_loop(cub->m);
	return (1);
}
