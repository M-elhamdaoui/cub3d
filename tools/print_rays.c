/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rays.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:44:11 by mel-hamd          #+#    #+#             */
/*   Updated: 2024/09/12 13:35:32 by mel-hamd         ###   ########.fr       */
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
	r1.type = 'h';
	r2.ang = get_angle(ang);
	r1.distance *= cos(get_angle(c->p.rot_ang) - ang);
	r2 = cast_ray_v(get_angle(ang), ang_dir[0], ang_dir[1], c);
	r2.type = 'v';
	r1.ang = get_angle(ang);
	r2.distance *= cos(get_angle(c->p.rot_ang) - ang);
	if (r1.is_w_hited && r2.is_w_hited)
	{
		if (r1.distance < r2.distance)
			return (r1);
		if (r1.distance == r2.distance)
			printf("r1 %f r2 %f\n", r1.distance, r2.distance);
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
	double		line_h;
	t_corr	c;
	t_ray	r;

	stp_ray = FOV / n;
	str_ang = cub->p.rot_ang - (FOV / 2);
	c.y = 0;
	c.x = 0;
	while (str_ang <=  cub->p.rot_ang + (FOV / 2))
	{
		
		r = which_ray(str_ang, cub);
		if (r.distance != 0)
			line_h = (US * H_SIZE) / r.distance;
		else
			line_h = H_SIZE;
		if (line_h > H_SIZE)
			line_h = H_SIZE;
		c.y = 0;
		c.color = ft_create_color(255, 0, 0, 255);
		put_line_v2(c, floor(H_SIZE / 2 - line_h / 2), M_PI / 2, cub );	
		c.y = floor(H_SIZE / 2 + line_h / 2);
		c.color = ft_create_color(0, 0, 255, 255);
		if (H_SIZE / 2 + line_h / 2  < H_SIZE)
			put_line_v2(c,floor(H_SIZE / 2 + line_h / 2), M_PI / 2, cub);
		if (r.type == 'v')
			c.color = ft_create_color(0, 255, 0, 155);
		else
			c.color = ft_create_color(0, 255, 0, 255);
		c.y = floor((H_SIZE / 2) - (line_h / 2));
		if ((H_SIZE / 2) - (line_h / 2) >= 0 ) 
			put_line_v2(c, floor(line_h), M_PI / 2, cub);
		c.x++;
		str_ang += stp_ray;
	}
}
