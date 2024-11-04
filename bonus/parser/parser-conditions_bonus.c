/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser-conditions_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:56:51 by hmrabet           #+#    #+#             */
/*   Updated: 2024/11/04 16:05:19 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_bool	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

t_bool	not_walls_surround(t_cub3d *cub, int i, int j)
{
	int	height;

	height = get_map_height(cub->map.map, 0);
	return ((((i == 0 || i == (height - 1))
				&& (cub->map.map[i][j] == '0'
				|| cub->map.map[i][j] == 'D'))
				|| ((j == 0 || j == (int)ft_strlen(cub->map.map[i]) - 1)
					&& (cub->map.map[i][j] == '0'
						|| cub->map.map[i][j] == 'D')))
					|| (cub->map.map[i][j] == ' '
				&& ((cub->map.map[i][j + 1] == '0'
				|| cub->map.map[i][j + 1] == 'D')
					|| (j != 0 && (cub->map.map[i][j - 1] == '0'
					|| cub->map.map[i][j - 1] == 'D'))
					|| (i != 0 && (cub->map.map[i - 1][j] == '0'
					|| cub->map.map[i - 1][j] == 'D'))
					|| (i != (height - 1) && (cub->map.map[i + 1][j] == '0'
					|| cub->map.map[i + 1][j] == 'D')))));
}
