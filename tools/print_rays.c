/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rays.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:44:11 by mel-hamd          #+#    #+#             */
/*   Updated: 2024/09/06 18:53:25 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

void	print_rays(int n, t_cub3d *cub)
{
	double	stp_ray;
	double	str_ang;
	int		ang_dir[2];
	t_ray	r;

	stp_ray = FOV / n;
	str_ang = cub->p.rot_ang - (FOV / 2);
	while (str_ang <=  cub->p.rot_ang + (FOV / 2))
	{
		get_angl_direction(&ang_dir[0],&ang_dir[1], get_angle(str_ang));
		r = cast_rays_v(get_angle(str_ang), ang_dir[0], ang_dir[1], cub);
		r.ang = str_ang;
		if (r.is_w_hited)
			put_line_v2(cub->p.c, r.distance, r.ang, cub);
		str_ang += stp_ray;
	}
}
