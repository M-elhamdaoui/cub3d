/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rays.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:44:11 by mel-hamd          #+#    #+#             */
/*   Updated: 2024/10/29 11:11:51 by hmrabet          ###   ########.fr       */
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
	r1.ang = get_angle(ang);
	r1.distance *= cos(get_angle(c->p.rot_ang) - ang);
	r2 = cast_ray_v(get_angle(ang), ang_dir[0], ang_dir[1], c);
	r2.type = 'v';
	r2.ang = get_angle(ang);
	r2.distance *= cos(get_angle(c->p.rot_ang) - ang);
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

int	ft_texture_color(unsigned int c)
{
	int	r;
	int	g;
	int	b;
	int	a;

	a = c % 256;
	c /= 256;
	b = c % 256;
	c /= 256;
	g = c % 256;
	c /= 256;
	r = c;
	return (ft_create_color(a, b, g, r));
}

void	draw_wall(t_cub3d *cub, t_ray r, t_corr *c)
{
	int		r_down;
	int		r_left;

	cub->wall.start = (H_SIZE / 2 - cub->wall.o_wall_h / 2);
	if (cub->wall.start < 0)
		cub->wall.start = 0;
	cub->wall.end = (H_SIZE / 2 + cub->wall.o_wall_h / 2);
	if (cub->wall.end >= H_SIZE)
		cub->wall.end = H_SIZE;
	get_angl_direction(&r_down, &r_left, r.ang);
	if (r_left && r.type == 'v')
		cub->wall.texture = cub->wall_E;
	else if (!r_left && r.type == 'v')
		cub->wall.texture = cub->wall_W;
	else if (r_down && r.type == 'h')
		cub->wall.texture = cub->wall_N;
	else if (!r_down && r.type == 'h')
		cub->wall.texture = cub->wall_S;
	draw_textures(cub, c->x, r);
}


void	print_rays(t_cub3d *cub)
{
	double	stp_ray;
	double	str_ang;
	double	line_h;
	t_corr	c;
	t_ray	r;

	stp_ray = FOV / W_SIZE;
	str_ang = cub->p.rot_ang - (FOV / 2);
	1 && (c.y = 0, c.x = 0);
	int i = -1;
	while (++i < W_SIZE)
	{
		r = which_ray(str_ang, cub);
		(1) && (cub->wall.wall_h = (US * H_SIZE) / r.distance);
		cub->wall.o_wall_h = cub->wall.wall_h;
		(!r.distance || cub->wall.wall_h > H_SIZE) && (cub->wall.wall_h = H_SIZE);
		c.y = 0;
		c.color = ft_create_color(cub->map.ceiling_rgb[0], cub->map.ceiling_rgb[1], cub->map.ceiling_rgb[2], 200);
		put_line_v2(c, floor(H_SIZE / 2 - cub->wall.wall_h / 2), M_PI / 2, cub );
		c.y = floor(H_SIZE / 2 + cub->wall.wall_h / 2);
		c.color = ft_create_color(cub->map.floor_rgb[0], cub->map.floor_rgb[1], cub->map.floor_rgb[2], 160);
		if (H_SIZE / 2 + cub->wall.wall_h / 2  < H_SIZE)
			put_line_v2(c,floor(H_SIZE / 2 + cub->wall.wall_h / 2), M_PI / 2, cub);
		draw_wall(cub, r, &c);
		1 && (c.x++, str_ang += stp_ray);
	}
}
