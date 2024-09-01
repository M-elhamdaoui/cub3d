/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser-0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:37:27 by houbet            #+#    #+#             */
/*   Updated: 2024/09/01 18:09:57 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// check empty line inside map

void	count_players(t_cub3d *cub)
{
	int	player;
	int	i;
	int	j;

	i = 0;
	player = 0;
	while (cub->map.map[i])
	{
		j = 0;
		while (cub->map.map[i][j])
		{
			if (cub->map.map[i][j] == 'N' || cub->map.map[i][j] == 'S' || cub->map.map[i][j] == 'E' || cub->map.map[i][j] == 'W')
			{
				cub->map.corr.x = j;
				cub->map.corr.y = i;
				if (player == 1)
					ft_exit("Error\nThe map must have only one player!\n", 1, cub);
				player++;
			}
			j++;
		}
		i++;
	}
	if (!player)
		ft_exit("Error\nThe map must have one player!\n", 1, cub);
}

void	parse_map(t_cub3d *cub)
{
	int	i;
	int	j;
	int	height;

	i = 0;
	height = get_map_height(cub->map.map, 0);
	while (cub->map.map[i])
	{
		j = 0;
		while (cub->map.map[i][j])
		{
			if (((i == 0 || i == (height - 1)) && cub->map.map[i][j] == '0') || ((j == 0 || j == (int)ft_strlen(cub->map.map[i]) - 1) && cub->map.map[i][j] == '0'))
				ft_exit("Error\nThe map must be surrounded by walls!\n", 1, cub);
			if (cub->map.map[i][j] == ' ')
			{
				if (cub->map.map[i][j + 1] == '0' || (j != 0 && cub->map.map[i][j - 1] == '0') || (i != 0 && cub->map.map[i - 1][j] == '0') || (i != (height - 1) && cub->map.map[i + 1][j] == '0'))
					ft_exit("Error\nThe map must be surrounded by walls!\n", 1, cub);
			}
			j++;
		}
		i++;
	}
	count_players(cub);
}

void	fill_map(t_cub3d *cub)
{
	int	big_line;
	int	height;
	int	i;
	int	j;

	big_line = get_big_line(cub->map.pre_map, 0);
	height = get_map_height(cub->map.pre_map, 0);
	cub->map.map = ft_malloc(cub, &cub->collector, sizeof(char *) * height + 1);
	i = 0;
	while (i < height)
	{
		j = 0;
		cub->map.map[i] = ft_malloc(cub, &cub->collector, sizeof(char) * big_line + 1);
		while (cub->map.pre_map[i][j])
		{
			cub->map.map[i][j] = cub->map.pre_map[i][j];
			j++;
		}
		while (j < big_line)
		{
			cub->map.map[i][j] = ' ';
			j++;
		}
		i++;
	}
}

void	init_map(t_cub3d *cub, char **av)
{
	char	*buffer;
	int		len;
	int		fd;

	len = 1;
	fd = open(ft_strtrim(cub, av[1], " "), O_RDONLY, 0777);
	cub->max_fd = fd;
	buffer = ft_malloc(cub, &cub->collector, 42);
	while (len > 0)
	{
		len = read(fd, buffer, 41);
		buffer[len] = '\0';
		cub->input = ft_strjoin(cub->input, buffer, cub);
	}
	if (!ft_strtrim(cub, cub->input, " ")
		|| !ft_strtrim(cub, cub->input, " ")[0])
		ft_exit("Error\nempty map!\n", 1, cub);
	parse_identifiers(cub);
	fill_map(cub);
	parse_map(cub);
}
