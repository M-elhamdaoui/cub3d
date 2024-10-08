/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init-data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:33:25 by houbet            #+#    #+#             */
/*   Updated: 2024/10/08 22:27:03 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_colors(t_cub3d *cub)
{
	char **rgb;

	rgb = ft_split(cub->map.floor, ',', cub);
	cub->map.floor_rgb[0] = ft_atoi(rgb[0]);
	cub->map.floor_rgb[1] = ft_atoi(rgb[1]);
	cub->map.floor_rgb[2] = ft_atoi(rgb[2]);
	rgb = ft_split(cub->map.ceiling, ',', cub);
	cub->map.ceiling_rgb[0] = ft_atoi(rgb[0]);
	cub->map.ceiling_rgb[1] = ft_atoi(rgb[1]);
	cub->map.ceiling_rgb[2] = ft_atoi(rgb[2]);
}

void	init_data(t_cub3d *cub, char **av)
{
	cub->max_fd = 2;
	cub->collector = NULL;
	cub->input = ft_strdup("", cub);
	cub->map.map = NULL;
	cub->map.north = NULL;
	cub->map.east = NULL;
	cub->map.west = NULL;
	cub->map.south = NULL;
	cub->map.floor = NULL;
	cub->map.ceiling = NULL;
	cub->p.rot_ang = 0;
	cub->p.rad = 4;
	cub->p.td = 0;
	cub->p.wd_h = 0;
	cub->p.wd = 0;
	cub->p.ms = 2;
	cub->p.rot_speed = 3 * (M_PI / 180);
	cub->wall_1 =  mlx_load_png("textures/texture1.png");
	init_map(cub, av);
	get_colors(cub);
}
