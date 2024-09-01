/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser-1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 18:02:10 by hmrabet           #+#    #+#             */
/*   Updated: 2024/09/01 16:03:29 by hmrabet          ###   ########.fr       */
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

char	*get_identifier(t_cub3d *cub, char *identifier, int size)
{
	while (identifier[size] == ' ')
		size++;
	return (ft_substr(cub, identifier, size, ft_strlen(identifier)));
}

void	check_chars(t_cub3d *cub)
{
	char	*trimed_rgb_f;
	char	*trimed_rgb_c;
	int		i;

	i = 0;
	trimed_rgb_c = ft_strtrim(cub, cub->map.ceiling, " ");
	if (!ft_isnum(trimed_rgb_c[0]) || !ft_isnum(trimed_rgb_c[ft_strlen(trimed_rgb_c) - 1]))
		ft_exit("Error\nInvalid Ceiling color!\n", 1, cub);
	trimed_rgb_f = ft_strtrim(cub, cub->map.floor, " ");
	if (!ft_isnum(trimed_rgb_f[0]) || !ft_isnum(trimed_rgb_f[ft_strlen(trimed_rgb_f) - 1]))
		ft_exit("Error\nInvalid Floor color!\n", 1, cub);
	while (trimed_rgb_c[i])
	{
		if (!ft_isnum(trimed_rgb_c[i]) && trimed_rgb_c[i] != ',')
			ft_exit("Error\nInvalid Ceiling color!\n", 1, cub);
		i++;
	}
	i = 0;
	while (trimed_rgb_f[i])
	{
		if (!ft_isnum(trimed_rgb_f[i]) && trimed_rgb_f[i] != ',')
			ft_exit("Error\nInvalid Floor color!\n", 1, cub);
		i++;
	}
}

void	check_map_row(t_cub3d *cub, char *row)
{
	int	i;

	i = 0;
	while (row[i])
	{
		if (row[i] != '0' && row[i] != '1' && row[i] != ' ' && row[i] != 'N' && row[i] != 'S' && row[i] != 'E' && row[i] != 'W')
			ft_exit("Error\nInvalid map character!\n", 1, cub);
		i++;
	}
}

void	check_colors(t_cub3d *cub)
{
	char	**rgb;
	int		i;
	
	i = 0;
	check_chars(cub);
	rgb = ft_split(cub->map.floor, ',', cub);
	while (rgb[i])
	{
		if (ft_atoi(rgb[i]) > 255 || ft_atoi(rgb[i]) < 0 || i > 2)
			ft_exit("Error\nInvalid Floor color!\n", 1, cub);
		i++;
	}
	if (i < 3)
		ft_exit("Error\nInvalid Floor color!\n", 1, cub);
	rgb = ft_split(cub->map.ceiling, ',', cub);
	i = 0;
	while (rgb[i])
	{
		if (ft_atoi(rgb[i]) > 255 || ft_atoi(rgb[i]) < 0 || i > 2)
			ft_exit("Error\nInvalid Ceiling color!\n", 1, cub);
		i++;
	}
	if (i < 3)
		ft_exit("Error\nInvalid ceiling color!\n", 1, cub);
}

void	parse_identifiers(t_cub3d *cub)
{
	char	**splitted;
	int		i;
	int		big_line;
	int		height;
	int		j;

	i = 0;
	splitted = ft_split(cub->input, '\n', cub);
	while (splitted[i] && (!cub->map.ceiling || !cub->map.floor || !cub->map.east || !cub->map.north || !cub->map.west || !cub->map.south))
	{
		if (!ft_strncmp(ft_strtrim(cub, splitted[i], " "), "NO ", 3))
		{
			if (cub->map.north)
				ft_exit("Error\nNorth texture duplicated\n", 1, cub);
			cub->map.north = get_identifier(cub, ft_strtrim(cub, splitted[i], " "), 2);
		}
		else if (!ft_strncmp(ft_strtrim(cub, splitted[i], " "), "SO ", 3))
		{
			if (cub->map.south)
				ft_exit("Error\nSouth texture duplicated\n", 1, cub);
			cub->map.south = get_identifier(cub, ft_strtrim(cub, splitted[i], " "), 2);
		}
		else if (!ft_strncmp(ft_strtrim(cub, splitted[i], " "), "EA ", 3))
		{
			if (cub->map.east)
				ft_exit("Error\nEast texture duplicated\n", 1, cub);
			cub->map.east = get_identifier(cub, ft_strtrim(cub, splitted[i], " "), 2);
		}
		else if (!ft_strncmp(ft_strtrim(cub, splitted[i], " "), "WE ", 3))
		{
			if (cub->map.west)
				ft_exit("Error\nWest texture duplicated\n", 1, cub);
			cub->map.west = get_identifier(cub, ft_strtrim(cub, splitted[i], " "), 2);
		}
		else if (!ft_strncmp(ft_strtrim(cub, splitted[i], " "), "F ", 2))
		{
			if (cub->map.floor)
				ft_exit("Error\nFloor color duplicated\n", 1, cub);
			cub->map.floor = get_identifier(cub, ft_strtrim(cub, splitted[i], " "), 1);
		}
		else if (!ft_strncmp(ft_strtrim(cub, splitted[i], " "), "C ", 2))
		{
			if (cub->map.ceiling)
				ft_exit("Error\nCeiling color duplicated\n", 1, cub);
			cub->map.ceiling = get_identifier(cub, ft_strtrim(cub, splitted[i], " "), 1);
		}
		else if (!ft_strtrim(cub, splitted[i], " ")[0])
		{
			i++;
			continue ;
		}
		else
		{
			if (!cub->map.north || !cub->map.south || !cub->map.east || !cub->map.west || !cub->map.ceiling || !cub->map.floor)
				ft_exit("Error\nMap should be last!\n", 1, cub);
			else
				break ;
		}
		i++;
	}
	check_colors(cub);
	big_line = get_big_line(splitted, i);
	height = get_map_height(splitted, i);
	if (cub->input[ft_strlen(cub->input) - 1] == '\n')
		ft_exit("Error\nMap shouldn't have empty lines!\n", 1, cub);
	cub->map.pre_map = ft_malloc(cub, &cub->collector, sizeof(char *) * height + 1);
	j = 0;
	while (splitted[i])
	{
		if (!ft_strtrim(cub, splitted[i], " ")[0])
			ft_exit("Error\nMap shouldn't have empty lines!\n", 1, cub);
		check_map_row(cub, splitted[i]);
		cub->map.pre_map[j++] = ft_strdup(splitted[i], cub);
		i++;
	}
	cub->map.pre_map[j] = NULL;
}
