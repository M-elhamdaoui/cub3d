/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:44:58 by hmrabet           #+#    #+#             */
/*   Updated: 2024/11/18 19:28:39 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static t_bool	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
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

static t_bool	check_surrounding_walls(t_cub3d *cub, int i, int j, int height)
{
	return ((((i == 0 || i == (height - 1))
				&& (cub->map.map[i][j] == '0' || is_player(cub->map.map[i][j])))
				|| ((j == 0 || j == (int)ft_strlen(cub->map.map[i]) - 1)
					&& (cub->map.map[i][j] == '0'
					|| is_player(cub->map.map[i][j]))))
				|| (cub->map.map[i][j] == ' '
				&& ((cub->map.map[i][j + 1] == '0'
					|| is_player(cub->map.map[i][j + 1]))
					|| (j != 0 && (cub->map.map[i][j - 1] == '0'
						|| is_player(cub->map.map[i][j - 1])))
					|| (i != 0 && (cub->map.map[i - 1][j] == '0'
						|| is_player(cub->map.map[i - 1][j])))
					|| (i != (height - 1) && (cub->map.map[i + 1][j] == '0'
						|| is_player(cub->map.map[i + 1][j]))))));
}

void	parse_map(t_cub3d *cub)
{
	int	i;
	int	j;
	int	height;

	i = -1;
	height = get_map_height(cub->map.map, 0);
	while (cub->map.map[++i])
	{
		j = 0;
		while (cub->map.map[i][j])
		{
			if (check_surrounding_walls(cub, i, j, height))
				ft_exit("The map must be surrounded by walls!\n", 1, cub);
			j++;
		}
	}
	count_players(cub);
	empty_lines_map_check(cub);
}
