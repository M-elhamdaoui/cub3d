/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rays.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:44:11 by mel-hamd          #+#    #+#             */
/*   Updated: 2024/09/02 14:16:54 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	print_rays(int n, t_cub3d *cub)
{
	double	stp_ray;
	double	str_ang;
	t_corr	c;

	stp_ray = FOV / n;
	str_ang = cub->p.rot_ang - (FOV / 2);
	1 && (c.x = cub->p.c.x, c.y = cub->p.c.y );
	while (str_ang <=  cub->p.rot_ang + (FOV / 2))
	{
		put_line_v2(cub->p.c, 90, str_ang, cub);
		str_ang += stp_ray;
	}
}
