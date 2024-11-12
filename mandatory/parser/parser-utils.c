/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser-utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:46:36 by hmrabet           #+#    #+#             */
/*   Updated: 2024/11/12 18:36:17 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_map_height(char **splitted, int i)
{
	int	height;

	height = 0;
	while (splitted[i])
	{
		height++;
		i++;
	}
	return (height);
}

int	get_big_line(char **splitted, int i)
{
	int	big_line;

	big_line = 0;
	while (splitted[i])
	{
		if (ft_strlen(splitted[i]) > (size_t)big_line)
			big_line = ft_strlen(splitted[i]);
		i++;
	}
	return (big_line);
}

void	check_map_row(t_cub3d *cub, char *row)
{
	int	i;

	i = 0;
	while (row[i])
	{
		if (row[i] != '0' && row[i] != '1' && row[i] != ' ' && row[i] != 'N'
			&& row[i] != 'S' && row[i] != 'E' && row[i] != 'W')
			ft_exit("Invalid map character!\n", 1, cub);
		i++;
	}
}

void	check_colors(t_cub3d *cub)
{
	char	**rgb;
	int		i;

	check_chars(cub);
	1 && (i = -1, rgb = ft_split(cub->map.floor, ',', cub));
	while (rgb[++i])
	{
		rgb[i] = ft_strtrim(cub, rgb[i], " ");
		if (ft_strchr(rgb[i], ' ') || ft_atoi(rgb[i]) > 255
			|| ft_atoi(rgb[i]) < 0 || i > 2)
			ft_exit("Invalid Floor color!\n", 1, cub);
	}
	if (i < 3)
		ft_exit("Invalid Floor color!\n", 1, cub);
	1 && (rgb = ft_split(cub->map.ceiling, ',', cub), i = -1);
	while (rgb[++i])
	{
		rgb[i] = ft_strtrim(cub, rgb[i], " ");
		if (ft_strchr(rgb[i], ' ') || ft_atoi(rgb[i]) > 255
			|| ft_atoi(rgb[i]) < 0 || i > 2)
			ft_exit("Invalid Ceiling color!\n", 1, cub);
	}
	if (i < 3)
		ft_exit("Invalid ceiling color!\n", 1, cub);
}

void	check_chars(t_cub3d *cub)
{
	char	*rgb_f;
	char	*rgb_c;
	int		i;

	i = 0;
	rgb_c = ft_strtrim(cub, cub->map.ceiling, " ");
	if (!ft_isnum(rgb_c[0]) || !ft_isnum(rgb_c[ft_strlen(rgb_c) - 1]))
		ft_exit("Invalid Ceiling color!\n", 1, cub);
	rgb_f = ft_strtrim(cub, cub->map.floor, " ");
	if (!ft_isnum(rgb_f[0]) || !ft_isnum(rgb_f[ft_strlen(rgb_f) - 1]))
		ft_exit("Invalid Floor color!\n", 1, cub);
	while (rgb_c[i])
	{
		if (!ft_isnum(rgb_c[i]) && rgb_c[i] != ',' && rgb_c[i] != ' ')
			ft_exit("Invalid Ceiling color!\n", 1, cub);
		i++;
	}
	i = 0;
	while (rgb_f[i])
	{
		if (!ft_isnum(rgb_f[i]) && rgb_f[i] != ',' && rgb_f[i] != ' ')
			ft_exit("Invalid Floor color!\n", 1, cub);
		i++;
	}
}
