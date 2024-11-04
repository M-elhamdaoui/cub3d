/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init-player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:06:14 by hmrabet           #+#    #+#             */
/*   Updated: 2024/11/04 16:26:48 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_wraith(t_cub3d *cub)
{
	char	*file_name;
	int		i;

	i = 0;
	cub->wraith.wraith_frame = 0;
	while (i < 154)
	{
		file_name = ft_strdup("bonus/textures/wraith/", cub);
		file_name = ft_strjoin(file_name, ft_itoa(cub, i + 1), cub);
		file_name = ft_strjoin(file_name, ".png", cub);
		cub->wraith.wraith[i] = mlx_load_png(file_name);
		if (!cub->wraith.wraith[i])
			ft_exit("Failed to load images\n", 1, cub);
		i++;
	}
}

void	init_stand(t_cub3d *cub)
{
	char	*file_name;
	int		i;

	i = 0;
	cub->wraith.stand_frame = 0;
	while (i < 12)
	{
		file_name = ft_strdup("bonus/textures/stand/", cub);
		file_name = ft_strjoin(file_name, ft_itoa(cub, i + 1), cub);
		file_name = ft_strjoin(file_name, ".png", cub);
		cub->wraith.stand[i] = mlx_load_png(file_name);
		if (!cub->wraith.stand[i])
			ft_exit("Failed to load images\n", 1, cub);
		i++;
	}
}

void	init_walk(t_cub3d *cub)
{
	char	*file_name;
	int		i;

	1 && (i = 0, cub->wraith.pre_walk_frame = 0);
	while (i < 9)
	{
		file_name = ft_strdup("bonus/textures/walking/pre/", cub);
		file_name = ft_strjoin(file_name, ft_itoa(cub, i + 1), cub);
		file_name = ft_strjoin(file_name, ".png", cub);
		cub->wraith.pre_walk[i] = mlx_load_png(file_name);
		if (!cub->wraith.pre_walk[i])
			ft_exit("Failed to load images\n", 1, cub);
		i++;
	}
	1 && (i = 0, cub->wraith.walk_frame = 0);
	while (i < 14)
	{
		file_name = ft_strdup("bonus/textures/walking/", cub);
		file_name = ft_strjoin(file_name, ft_itoa(cub, i + 1), cub);
		file_name = ft_strjoin(file_name, ".png", cub);
		cub->wraith.walk[i] = mlx_load_png(file_name);
		if (!cub->wraith.walk[i])
			ft_exit("Failed to load images\n", 1, cub);
		i++;
	}
}

void	init_flex_hit(t_cub3d *cub)
{
	char	*file_name;
	int		i;

	1 && (i = 0, cub->wraith.flex_frame = 0);
	while (i < 26)
	{
		file_name = ft_strdup("bonus/textures/flex/", cub);
		file_name = ft_strjoin(file_name, ft_itoa(cub, i + 1), cub);
		file_name = ft_strjoin(file_name, ".png", cub);
		cub->wraith.flex[i] = mlx_load_png(file_name);
		if (!cub->wraith.flex[i])
			ft_exit("Failed to load images\n", 1, cub);
		i++;
	}
	1 && (i = 0, cub->wraith.hit_frame = 0);
	while (i < 9)
	{
		file_name = ft_strdup("bonus/textures/hit/", cub);
		file_name = ft_strjoin(file_name, ft_itoa(cub, i + 1), cub);
		file_name = ft_strjoin(file_name, ".png", cub);
		cub->wraith.hit[i] = mlx_load_png(file_name);
		if (!cub->wraith.hit[i])
			ft_exit("Failed to load images\n", 1, cub);
		i++;
	}
}

void	init_knife_kick(t_cub3d *cub)
{
	char	*file_name;
	int		i;

	1 && (i = 0, cub->wraith.kick_frame = 0);
	while (i < 23)
	{
		file_name = ft_strdup("bonus/textures/kick/", cub);
		file_name = ft_strjoin(file_name, ft_itoa(cub, i + 1), cub);
		file_name = ft_strjoin(file_name, ".png", cub);
		cub->wraith.kick[i] = mlx_load_png(file_name);
		if (!cub->wraith.kick[i])
			ft_exit("Failed to load images\n", 1, cub);
		i++;
	}
	1 && (i = 0, cub->wraith.knife_frame = 0);
	while (i < 49)
	{
		file_name = ft_strdup("bonus/textures/knife/", cub);
		file_name = ft_strjoin(file_name, ft_itoa(cub, i + 1), cub);
		file_name = ft_strjoin(file_name, ".png", cub);
		cub->wraith.knife[i] = mlx_load_png(file_name);
		if (!cub->wraith.knife[i])
			ft_exit("Failed to load images\n", 1, cub);
		i++;
	}
}
