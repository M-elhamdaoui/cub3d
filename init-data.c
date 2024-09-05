/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init-data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:33:25 by houbet            #+#    #+#             */
/*   Updated: 2024/09/05 20:32:07 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	cub->p.rot_ang = 3 * M_PI / 2;
	cub->p.rad = 1;
	cub->p.td = 0;
	cub->p.wd_h = 0;
	cub->p.wd = 0;
	cub->p.ms = 2;
	cub->p.rot_speed = 3 * (M_PI / 180);
	init_map(cub, av);
}
