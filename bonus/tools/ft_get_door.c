/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_door.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:45:29 by mel-hamd          #+#    #+#             */
/*   Updated: 2024/11/12 16:50:40 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_doors	*ft_get_door(t_cub3d *c, int x, int y)
{
	int	i;

	i = 0;
	if (!c->doors)
		return (NULL);
	while (c->doors[i])
	{
		if (c->doors[i]->x == x && c->doors[i]->y == y)
			return (c->doors[i]);
		i++;
	}
	return (NULL);
}
