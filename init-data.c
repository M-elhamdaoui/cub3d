/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init-data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houbet <houbet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:33:25 by houbet            #+#    #+#             */
/*   Updated: 2024/08/26 14:57:21 by houbet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_map(t_cub3d *cub, char **av)
{
	char	*buffer;
	int		len;
	int		fd;

	len = 1;
	fd = open(ft_strtrim(cub, av[1], " "), O_RDONLY, 0777);
	if (fd == -1)
		ft_exit("Error\nOpen failed!", 1, cub);
	cub->max_fd = fd;
	buffer = ft_malloc(cub, &cub->collector, 42);
	while (len > 0)
	{
		len = read(fd, buffer, 41);
		buffer[41] = '\0';
		cub->input = ft_strjoin(cub->input, buffer, cub);
	}
	cub->map = ft_split(cub->input, '\n', cub);
}

void	init_data(t_cub3d *cub, char **av)
{
	cub->max_fd = 2;
	cub->collector = NULL;
	cub->input = ft_strdup("", cub);
	cub->map = NULL;
	init_map(cub, av);
}
