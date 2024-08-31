/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houbet <houbet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:37:27 by houbet            #+#    #+#             */
/*   Updated: 2024/08/26 14:51:10 by houbet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_map(char **map)
{
	if (!map || !*map)
		return (ft_putstr_fd("Error\nempty map!\n", 2), 1);
	return (ft_putstr_fd("Error\ninvalid map!\n", 2), 1);
}
