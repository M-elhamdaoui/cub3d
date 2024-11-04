/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:37:27 by houbet            #+#    #+#             */
/*   Updated: 2024/11/04 15:50:27 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	fill_map(t_cub3d *cub)
{
	int	big_line;
	int	h;
	int	i;
	int	j;

	big_line = get_big_line(cub->map.pre_map, 0);
	(1) && (h = get_map_height(cub->map.pre_map, 0), i = -1);
	cub->map.height = h;
	cub->map.map = ft_malloc(cub, &cub->collector, sizeof(char *) * (h + 1));
	while (++i < h)
	{
		j = -1;
		cub->map.map[i] = ft_malloc(cub,
				&cub->collector, sizeof(char) * (big_line + 1));
		while (cub->map.pre_map[i][++j])
			cub->map.map[i][j] = cub->map.pre_map[i][j];
		while (j < big_line)
		{
			cub->map.map[i][j] = ' ';
			j++;
		}
		cub->map.map[i][j] = '\0';
	}
	cub->map.map[i] = NULL;
	cub->map.width = ft_strlen(cub->map.map[0]);
}

static int	count_doors(t_cub3d *cub)
{
	int	i;
	int	j;
	int	counter;

	i = -1;
	counter = 0;
	while (cub->map.map[++i])
	{
		j = 0;
		while (cub->map.map[i][j])
		{
			if (cub->map.map[i][j] == 'D')
				counter++;
			j++;
		}
	}
	return (counter);
}

static void	get_doors(t_cub3d *cub)
{
	int	i;
	int	j;
	int	count;

	1 && (i = -1, count = 0);
	cub->doors = ft_malloc(cub, &cub->collector, sizeof(t_doors)
			* (count_doors(cub) + 1));
	while (cub->map.map[++i])
	{
		j = 0;
		while (cub->map.map[i][j])
		{
			if (cub->map.map[i][j] == 'D')
			{
				cub->doors[count].is_closed = TRUE;
				cub->doors[count].is_closing = FALSE;
				cub->doors[count].is_opening = FALSE;
				cub->doors[count].progress = 0;
				cub->doors[count].x = i;
				cub->doors[count].y = j;
				count++;
			}
			j++;
		}
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
		ft_exit("empty map!\n", 1, cub);
	parse_identifiers(cub);
	fill_map(cub);
	parse_map(cub);
	get_doors(cub);
}
