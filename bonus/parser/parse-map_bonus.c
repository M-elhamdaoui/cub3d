/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:44:58 by hmrabet           #+#    #+#             */
/*   Updated: 2024/11/04 15:57:22 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	empty_lines_map_check(t_cub3d *cub)
{
	char	*map;
	int		i;

	i = 0;
	map = ft_strdup("", cub);
	while (cub->map.pre_map[i])
	{
		if (i != 0)
			map = ft_strjoin(map, "\n", cub);
		map = ft_strjoin(map, cub->map.pre_map[i], cub);
		i++;
	}
	if (!ft_strnstr(cub->input, map, ft_strlen(cub->input) + 100))
		ft_exit("Map shouldn't have empty lines!\n", 1, cub);
}

void	count_players(t_cub3d *cub)
{
	int	player;
	int	i;
	int	j;

	(1) && (i = -1, player = 0);
	while (cub->map.map[++i])
	{
		j = 0;
		while (cub->map.map[i][j])
		{
			if (is_player(cub->map.map[i][j]))
			{
				cub->p.c.x = j * US + US / 2;
				cub->p.c.y = i * US + US / 2;
				(cub->map.map[i][j] == 'N')
					&& (cub->p.rot_ang = (3 * M_PI) / 2);
				(cub->map.map[i][j] == 'S') && (cub->p.rot_ang = (M_PI) / 2);
				(cub->map.map[i][j] == 'W') && (cub->p.rot_ang = M_PI);
				player++;
			}
			j++;
		}
	}
	if (player != 1)
		ft_exit("The map must have one player!\n", 1, cub);
}

static void	parse_doors(t_cub3d *cub)
{
	int	i;
	int	j;

	i = -1;
	while (cub->map.map[++i])
	{
		j = 0;
		while (cub->map.map[i][j])
		{
			if (cub->map.map[i][j] == 'D'
				&& !((cub->map.map[i][j - 1] == '1'
				&& cub->map.map[i][j + 1] == '1')
				|| (cub->map.map[i - 1][j] == '1'
				&& cub->map.map[i + 1][j] == '1')))
				ft_exit("The Doors must be between two walls!\n", 1, cub);
			j++;
		}
	}
}

void	parse_map(t_cub3d *cub)
{
	int	i;
	int	j;

	i = -1;
	while (cub->map.map[++i])
	{
		j = 0;
		while (cub->map.map[i][j])
		{
			if (not_walls_surround(cub, i, j))
				ft_exit("The map must be surrounded by walls!\n", 1, cub);
			j++;
		}
	}
	parse_doors(cub);
	count_players(cub);
	empty_lines_map_check(cub);
}
