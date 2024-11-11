/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init-data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:33:25 by houbet            #+#    #+#             */
/*   Updated: 2024/11/09 16:52:43 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	get_colors(t_cub3d *cub)
{
	char	**rgb;

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
	1 && (cub->max_fd = 2, cub->collector = NULL);
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
