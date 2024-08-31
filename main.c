/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 08:59:06 by hmrabet           #+#    #+#             */
/*   Updated: 2024/08/31 15:21:55 by hmrabet          ###   ########.fr       */
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

void	get_identifiers(t_cub3d *cub)
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
			cub->map.north = ft_strdup(ft_strtrim(cub, splitted[i], " "), cub);
		}
		else if (!ft_strncmp(ft_strtrim(cub, splitted[i], " "), "SO ", 3))
		{
			if (cub->map.south)
				ft_exit("Error\nSouth texture duplicated\n", 1, cub);
			cub->map.south = ft_strdup(ft_strtrim(cub, splitted[i], " "), cub);
		}
		else if (!ft_strncmp(ft_strtrim(cub, splitted[i], " "), "EA ", 3))
		{
			if (cub->map.east)
				ft_exit("Error\nEast texture duplicated\n", 1, cub);
			cub->map.east = ft_strdup(ft_strtrim(cub, splitted[i], " "), cub);
		}
		else if (!ft_strncmp(ft_strtrim(cub, splitted[i], " "), "WE ", 3))
		{
			if (cub->map.west)
				ft_exit("Error\nWest texture duplicated\n", 1, cub);
			cub->map.west = ft_strdup(ft_strtrim(cub, splitted[i], " "), cub);
		}
		else if (!ft_strncmp(ft_strtrim(cub, splitted[i], " "), "F ", 2))
		{
			if (cub->map.floor)
				ft_exit("Error\nFloor color duplicated\n", 1, cub);
			cub->map.floor = ft_strdup(ft_strtrim(cub, splitted[i], " "), cub);
		}
		else if (!ft_strncmp(ft_strtrim(cub, splitted[i], " "), "C ", 2))
		{
			if (cub->map.ceiling)
				ft_exit("Error\nCeiling color duplicated\n", 1, cub);
			cub->map.ceiling = ft_strdup(ft_strtrim(cub, splitted[i], " "), cub);
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
	big_line = get_big_line(splitted, i);
	height = get_map_height(splitted, i);
	cub->map.map = ft_malloc(cub, &cub->collector, height + 1);
	j = 0;
	while (splitted[i])
	{
		cub->map.map[j++] = ft_strdup(splitted[i], cub);
		i++;
	}
	cub->map.map[j] = NULL;
}

void	init_map(t_cub3d *cub, char **av)
{
	char	*buffer;
	int		len;
	int		fd;
	int		i;

	i = 0;
	len = 1;
	fd = open(ft_strtrim(cub, av[1], " "), O_RDONLY, 0777);
	cub->max_fd = fd;
	buffer = ft_malloc(cub, &cub->collector, 42);
	while (len > 0)
	{
		len = read(fd, buffer, 41);
		buffer[41] = '\0';
		cub->input = ft_strjoin(cub->input, buffer, cub);
	}
	if (!ft_strtrim(cub, cub->input, " ")
		|| !ft_strtrim(cub, cub->input, " ")[0])
		ft_exit("Error\nempty map!\n", 1, cub);
	get_identifiers(cub);
}

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
	init_map(cub, av);
}

int	main(int ac, char **av)
{
	t_cub3d	cub;

	if (ac == 2 && ft_strnstr(av[1], ".cub", ft_strlen(av[1]))
		&& !ft_strncmp(av[1] + (ft_strlen(av[1]) - 4), ".cub", 5))
	{
		init_data(&cub, av);
		int	i;
		i = 0;
		printf("%s\n", cub.map.north);
		printf("%s\n", cub.map.south);
		printf("%s\n", cub.map.east);
		printf("%s\n", cub.map.west);
		printf("%s\n", cub.map.ceiling);
		printf("%s\n\n", cub.map.floor);
		while (cub.map.map[i])
		{
			printf("%s\n", cub.map.map[i]);
			i++;
		}
	}
	else
		return (ft_putstr_fd("Error\ninvalid arguments!\n", 2), 1);
}
