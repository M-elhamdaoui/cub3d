/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rays.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:44:11 by mel-hamd          #+#    #+#             */
/*   Updated: 2024/09/07 11:48:29 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

t_ray which_ray(double ang, t_cub3d *c)
{
	int		ang_dir[2];
	t_ray	r1;
	t_ray	r2;

	get_angl_direction(&ang_dir[0],&ang_dir[1], get_angle(ang));
	r1 = cast_ray_h(c, get_angle(ang), ang_dir[0], ang_dir[1]);
	r2 = cast_ray_v(get_angle(ang), ang_dir[0], ang_dir[1], c);
	r1.ang = get_angle(ang);
	r2.ang = get_angle(ang);
	if (r1.is_w_hited && r2.is_w_hited)
	{
		if (r1.distance < r2.distance)
			return (r1);
		return (r2);
	}
	if (r1.is_w_hited)
		return (r1);
	return (r2);
}

void	print_rays(int n, t_cub3d *cub)
{
	double	stp_ray;
	double	str_ang;
	t_ray	r;

	stp_ray = FOV / n;
	str_ang = cub->p.rot_ang - (FOV / 2);
	while (str_ang <=  cub->p.rot_ang + (FOV / 2))
	{
		
		
		r = which_ray(str_ang, cub);
		if (r.is_w_hited)
			put_line_v2(cub->p.c, r.distance, r.ang, cub);
		str_ang += stp_ray;
	}
}
