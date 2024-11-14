/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init-data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:33:25 by hmrabet           #+#    #+#             */
/*   Updated: 2024/11/14 17:09:12 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	get_colors(t_cub3d *cub)
{
	char	**rgb;
	int		it[3];

	1 && (it[2] = -1, it[0] = 0, it[1] = 0);
	while (cub->map.floor[++it[2]])
	{
		if (cub->map.floor[i] == ',')
			it[0]++;
	}
	it[2] = -1;
	while (cub->map.ceiling[++it[2]])
	{
		if (cub->map.ceiling[i] == ',')
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
	int	fd[12];
	int	i;

	i = -1;
	fd[0] = open(cub->map.east, O_RDONLY);
	fd[1] = open(cub->map.north, O_RDONLY);
	fd[2] = open(cub->map.south, O_RDONLY);
	fd[3] = open(cub->map.west, O_RDONLY);
	fd[4] = open("bonus/textures/menu/resume_e.png", O_RDONLY);
	fd[5] = open("bonus/textures/menu/resume_d.png", O_RDONLY);
	fd[6] = open("bonus/textures/menu/quit_e.png", O_RDONLY);
	fd[7] = open("bonus/textures/menu/quit_d.png", O_RDONLY);
	fd[8] = open("bonus/textures/menu/e.png", O_RDONLY);
	fd[9] = open("bonus/textures/menu/d.png", O_RDONLY);
	fd[10] = open("bonus/textures/door.png", O_RDONLY);
	fd[11] = open("bonus/textures/sky.png", O_RDONLY);
	while (++i < 12)
	{
		if (fd[i] == -1)
			ft_exit("Invalid textures!\n", 1, cub);
	}
	i = -1;
	while (++i < 12)
		close(fd[i]);
}

static void	init_player(t_cub3d *cub)
{
	init_wraith(cub);
	init_stand(cub);
	init_walk(cub);
	init_flex_hit(cub);
	init_knife_kick(cub);
}

static void	init_textures(t_cub3d *cub)
{
	cub->wall_e = mlx_load_png(cub->map.east);
	cub->wall_w = mlx_load_png(cub->map.west);
	cub->wall_n = mlx_load_png(cub->map.north);
	cub->wall_s = mlx_load_png(cub->map.south);
	cub->menu.resume_e = mlx_load_png("bonus/textures/menu/resume_e.png");
	cub->menu.resume_d = mlx_load_png("bonus/textures/menu/resume_d.png");
	cub->menu.quit_e = mlx_load_png("bonus/textures/menu/quit_e.png");
	cub->menu.quit_d = mlx_load_png("bonus/textures/menu/quit_d.png");
	cub->menu.e = mlx_load_png("bonus/textures/menu/e.png");
	cub->menu.d = mlx_load_png("bonus/textures/menu/d.png");
	cub->door = mlx_load_png("bonus/textures/door.png");
	cub->sky.sky = mlx_load_png("bonus/textures/sky.png");
	if (!cub->wall_e || !cub->wall_s || !cub->wall_n || !cub->wall_w
		|| !cub->menu.resume_e || !cub->menu.resume_d || !cub->menu.quit_e
		|| !cub->menu.quit_d || !cub->menu.e || !cub->menu.d || !cub->door
		|| !cub->sky.sky)
		ft_exit("Failed to load images\n", 1, cub);
}

void	init_data(t_cub3d *cub, char **av)
{
	1 && (cub->m = NULL, cub->img = NULL);
	cub->collector = NULL;
	cub->input = ft_strdup("", cub);
	1 && (cub->map.map = NULL, cub->map.north = NULL);
	1 && (cub->map.east = NULL, cub->map.west = NULL);
	1 && (cub->map.south = NULL, cub->map.floor = NULL);
	1 && (cub->map.ceiling = NULL, cub->freeze = 0);
	1 && (cub->p.rot_ang = 0, cub->mouse = 1);
	1 && (cub->p.rad = 4, cub->p.td = 0);
	1 && (cub->p.wd_h = 0, cub->p.wd = 0, cub->p.ms = 3);
	cub->p.rot_speed = 3 * (M_PI / 180);
	1 && (cub->open_menu = FALSE, cub->menu.option = RESUME_D);
	1 && (cub->sky.enabled = FALSE, cub->i = 0);
	init_map(cub, av);
	get_colors(cub);
	check_files_access(cub);
	init_textures(cub);
	init_player(cub);
}
