/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init-data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:33:25 by houbet            #+#    #+#             */
/*   Updated: 2024/10/21 05:44:49 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_colors(t_cub3d *cub)
{
	char	**rgb;

	rgb = ft_split(cub->map.floor, ',', cub);
	cub->map.floor_rgb[0] = ft_atoi(rgb[0]);
	cub->map.floor_rgb[1] = ft_atoi(rgb[1]);
	cub->map.floor_rgb[2] = ft_atoi(rgb[2]);
	rgb = ft_split(cub->map.ceiling, ',', cub);
	cub->map.ceiling_rgb[0] = ft_atoi(rgb[0]);
	cub->map.ceiling_rgb[1] = ft_atoi(rgb[1]);
	cub->map.ceiling_rgb[2] = ft_atoi(rgb[2]);
}

void	check_files_access(t_cub3d *cub)
{
	int	fd1;
	int	fd2;
	int	fd3;
	int	fd4;

	fd1 = open(cub->map.east, O_RDONLY);
	fd2 = open(cub->map.north, O_RDONLY);
	fd3 = open(cub->map.south, O_RDONLY);
	fd4 = open(cub->map.west, O_RDONLY);
	if (fd1 == -1 || fd2 == -1 || fd3 == -1 || fd4 == -1)
		ft_exit("Invalid textures!\n", 1, cub);
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
}

void	init_data(t_cub3d *cub, char **av)
{
	1 && (cub->m = NULL, cub->img = NULL);
	1 && (cub->max_fd = 2, cub->collector = NULL);
	cub->input = ft_strdup("", cub);
	cub->map.map = NULL;
	cub->map.north = NULL;
	cub->map.east = NULL;
	cub->map.west = NULL;
	cub->map.south = NULL;
	cub->map.floor = NULL;
	cub->map.ceiling = NULL;
	cub->p.rot_ang = 0;
	1 && (cub->p.rad = 4, cub->p.td = 0);
	cub->p.wd_h = 0;
	cub->p.wd = 0;
	cub->p.ms = 2;
	cub->p.rot_speed = 3 * (M_PI / 180);
	init_map(cub, av);
	get_colors(cub);
	check_files_access(cub);
	cub->wall_E = mlx_load_png(cub->map.east);
	cub->wall_W = mlx_load_png(cub->map.west);
	cub->wall_N = mlx_load_png(cub->map.north);
	cub->wall_S = mlx_load_png(cub->map.south);
	if (!cub->wall_E || !cub->wall_S || !cub->wall_N || !cub->wall_W)
		ft_exit("Failed to load images\n", 1, cub);
}
