/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-identifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 18:02:10 by hmrabet           #+#    #+#             */
/*   Updated: 2024/09/01 20:11:20 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*get_identifier(t_cub3d *cub, char *identifier, int size)
{
	while (identifier[size] == ' ')
		size++;
	return (ft_substr(cub, identifier, size, ft_strlen(identifier)));
}

static int	fill_identifiers2(t_cub3d *cub, char **splitted, int i)
{
	if (!ft_strncmp(ft_strtrim(cub, splitted[i], " "), "WE ", 3))
	{
		if (cub->map.west)
			ft_exit("West texture duplicated\n", 1, cub);
		return (cub->map.west = get_identifier(cub,
				ft_strtrim(cub, splitted[i], " "), 2), 1);
	}
	else if (!ft_strncmp(ft_strtrim(cub, splitted[i], " "), "F ", 2))
	{
		if (cub->map.floor)
			ft_exit("Floor color duplicated\n", 1, cub);
		return (cub->map.floor = get_identifier(cub,
				ft_strtrim(cub, splitted[i], " "), 1), 1);
	}
	else if (!ft_strncmp(ft_strtrim(cub, splitted[i], " "), "C ", 2))
	{
		if (cub->map.ceiling)
			ft_exit("Ceiling color duplicated\n", 1, cub);
		return (cub->map.ceiling = get_identifier(cub,
				ft_strtrim(cub, splitted[i], " "), 1), 1);
	}
	return (0);
}

static int	fill_identifiers(t_cub3d *cub, char **splitted, int i)
{
	if (!ft_strncmp(ft_strtrim(cub, splitted[i], " "), "NO ", 3))
	{
		if (cub->map.north)
			ft_exit("North texture duplicated\n", 1, cub);
		return (cub->map.north = get_identifier(cub,
				ft_strtrim(cub, splitted[i], " "), 2), 1);
	}
	else if (!ft_strncmp(ft_strtrim(cub, splitted[i], " "), "SO ", 3))
	{
		if (cub->map.south)
			ft_exit("South texture duplicated\n", 1, cub);
		return (cub->map.south = get_identifier(cub,
				ft_strtrim(cub, splitted[i], " "), 2), 1);
	}
	else if (!ft_strncmp(ft_strtrim(cub, splitted[i], " "), "EA ", 3))
	{
		if (cub->map.east)
			ft_exit("East texture duplicated\n", 1, cub);
		return (cub->map.east = get_identifier(cub,
				ft_strtrim(cub, splitted[i], " "), 2), 1);
	}
	else if (fill_identifiers2(cub, splitted, i))
		return (1);
	return (0);
}

static void	parse_identifiers2(t_cub3d *cub, char **splitted, int i)
{
	int	height;
	int	j;

	check_colors(cub);
	height = get_map_height(splitted, i);
	if (cub->input[ft_strlen(cub->input) - 1] == '\n')
		ft_exit("Map shouldn't have empty lines!\n", 1, cub);
	cub->map.pre_map = ft_malloc(cub, &cub->collector,
			sizeof(char *) * height + 1);
	j = 0;
	while (splitted[i])
	{
		if (!ft_strtrim(cub, splitted[i], " ")[0])
			ft_exit("Map shouldn't have empty lines!\n", 1, cub);
		check_map_row(cub, splitted[i]);
		cub->map.pre_map[j++] = ft_strdup(splitted[i], cub);
		i++;
	}
	cub->map.pre_map[j] = NULL;
}

void	parse_identifiers(t_cub3d *cub)
{
	char	**splitted;
	int		i;

	1 && (i = 0, splitted = ft_split(cub->input, '\n', cub));
	while (splitted[i] && (!cub->map.ceiling || !cub->map.floor
			|| !cub->map.east || !cub->map.north
			|| !cub->map.west || !cub->map.south))
	{
		if (fill_identifiers(cub, splitted, i))
			;
		else if (!ft_strtrim(cub, splitted[i], " ")[0])
			;
		else
		{
			if (!cub->map.north || !cub->map.south || !cub->map.east
				|| !cub->map.west || !cub->map.ceiling || !cub->map.floor)
				ft_exit("Map should be last!\n", 1, cub);
			else
				break ;
		}
		i++;
	}
	parse_identifiers2(cub, splitted, i);
}
