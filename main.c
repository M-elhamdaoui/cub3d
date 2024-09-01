/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 08:59:06 by hmrabet           #+#    #+#             */
/*   Updated: 2024/09/01 19:13:51 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		lunch_mlx(&cub);
	}
	else
		return (ft_putstr_fd("Error\ninvalid arguments!\n", 2), 1);
}
