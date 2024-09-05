/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:37:27 by houbet            #+#    #+#             */
/*   Updated: 2024/09/05 20:48:15 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	fill_map(t_cub3d *cub)
{
	int	big_line;
	int	height;
	int	i;
	int	j;

	big_line = get_big_line(cub->map.pre_map, 0);
	(1) && (height = get_map_height(cub->map.pre_map, 0), i = 0);
	cub->map.height = height;
	cub->map.map = ft_malloc(cub, &cub->collector, sizeof(char *) * height + 1);
	while (i < height)
	{
		j = 0;
		cub->map.map[i] = ft_malloc(cub,
				&cub->collector, sizeof(char) * big_line + 1);
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
	cub->map.width = ft_strlen(cub->map.map[0]);
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
		ft_exit("empty map!\n", 1, cub);
	parse_identifiers(cub);
	fill_map(cub);
	parse_map(cub);
}
