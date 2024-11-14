/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init-data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:33:25 by hmrabet           #+#    #+#             */
/*   Updated: 2024/11/14 17:12:01 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_colors(t_cub3d *cub)
{
	char	**rgb;
	int		it[3];

	1 && (it[2] = -1, it[0] = 0, it[1] = 0);
	while (cub->map.floor[++it[2]])
	{
		if (cub->map.floor[it[2]] == ',')
			it[0]++;
	}
	it[2] = -1;
	while (cub->map.ceiling[++it[2]])
	{
		if (cub->map.ceiling[it[2]] == ',')
			it[1]++;
	}
	if (it[0] != 2 || it[1] != 2)
		ft_exit("Invalid RGB value\n", 1, cub);
	rgb = ft_split(cub->map.floor, ',', cub);
	cub->map.f_rgb[0] = ft_atoi(rgb[0]);
	cub->map.f_rgb[1] = ft_atoi(rgb[1]);
	cub->map.f_rgb[2] = ft_atoi(rgb[2]);
	rgb = ft_split(cub->map.ceiling, ',', cub);
	cub->map.c_rgb[0] = ft_atoi(rgb[0]);
	cub->map.c_rgb[1] = ft_atoi(rgb[1]);
	cub->map.c_rgb[2] = ft_atoi(rgb[2]);
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
	1 && (cub->p.rad = 4, cub->p.td = 0);
	cub->p.wd_h = 0;
	cub->p.wd = 0;
	cub->p.ms = 3;
	cub->p.rot_speed = 3 * (M_PI / 180);
	init_map(cub, av);
	get_colors(cub);
	check_files_access(cub);
	cub->wall_e = mlx_load_png(cub->map.east);
	cub->wall_w = mlx_load_png(cub->map.west);
	cub->wall_n = mlx_load_png(cub->map.north);
	cub->wall_s = mlx_load_png(cub->map.south);
	if (!cub->wall_e || !cub->wall_s || !cub->wall_n || !cub->wall_w)
		ft_exit("Failed to load images\n", 1, cub);
}
