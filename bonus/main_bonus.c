/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 08:59:06 by hmrabet           #+#    #+#             */
/*   Updated: 2024/10/30 11:02:18 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
