/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 22:00:46 by mel-hamd          #+#    #+#             */
/*   Updated: 2024/10/30 18:44:08 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_mouse_move(double xpos, double ypos, void *d)
{
	t_cub3d	*cub;
	int		x;
	int		y;

	cub = d;
	(void)xpos;
	(void)ypos;
	if (cub->mouse)
	{
		mlx_get_mouse_pos(cub->m, &x, &y);
		cub->p.td = MOUSE_SPEED * (double)(x - \
												(W_SIZE / 2));
		mlx_set_mouse_pos(cub->m, (W_SIZE / 2), \
												(H_SIZE / 2));
	}
}

void	*thread_function_handler(char *text)
{
	system(text);
	return (NULL);
}

void	play_omen_sound(char *text)
{
	pthread_t	thread;

	pthread_create(&thread, NULL, (void *)thread_function_handler, (text));
	pthread_detach(thread);
}

void	kill_omen_sound(void)
{
	int	i;
 
	i = fork();
	if (!i)
		execve("/usr/bin/killall", (char *[]){"killall", "afplay", NULL}, NULL);
}

void	key_press_fun(mlx_key_data_t keydata, void *params)
{
	t_cub3d	*c;

	c = (t_cub3d *)params;
	if (keydata.key == MLX_KEY_V && keydata.action == MLX_PRESS)
	{
		c->freeze = 1;
		c->omenFrame = 0;
		play_omen_sound("afplay bonus/textures/omen/omen.mp3");
		c->p.rot_ang += M_PI;
		if (c->p.rot_ang > (2 * M_PI))
			c->p.rot_ang -= 2 * M_PI;
	}
	if (keydata.key == MLX_KEY_V && keydata.action == MLX_RELEASE)
	{
		c->freeze = 0;
		c->omenFrame = 0;
		kill_omen_sound();
		c->p.rot_ang += M_PI;
		if (c->p.rot_ang > (2 * M_PI))
			c->p.rot_ang -= 2 * M_PI;
	}
	if (keydata.key == MLX_KEY_LEFT_CONTROL && keydata.action == MLX_RELEASE)
	{
		c->mouse = !c->mouse;
		(!c->mouse) && (c->p.td = 0);
	}
}

void	ft_mlx_put_pixel(t_cub3d *data, int x, int y, int color)
{
	if (x >= 0 && x < W_SIZE && y >= 0 && y < H_SIZE && color != 435292927)
		mlx_put_pixel(data->img, x, y, color);
}

int	ft_color(int r, int g, int b, int a)
{
	return ((((r * 256 + g) * 256) + b) * 256 + a);
}

int	ft_texture_colors(unsigned int c)
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
	return (ft_color(a, b, g, r));
}

void	ft_draw_image(t_cub3d *data, mlx_texture_t *texture, int x, int y)
{
	int	i ;
	int	j;
	int	color;
	t_ui *colors;

	i = 0;
	j = 0;
	colors = (uint32_t *)texture->pixels;
	while (i < (int)texture->height)
	{
		j = 0;
		while (j < (int)texture->width)
		{
			color = ft_texture_colors(colors[i * texture->width + j]);
			if (color)
				ft_mlx_put_pixel(data, j + x, i + y, \
			ft_texture_colors(colors[i * texture->width + j]));
			j++;
		}
		i++;
	}
}

void	key_fun(void *params)
{
	t_cub3d	*c;

	c = (t_cub3d *)params;
	if (mlx_is_key_down(c->m, MLX_KEY_ESCAPE))
		ft_exit(NULL, 0, c);
	if (!c->freeze)
	{
		if (mlx_is_key_down(c->m, MLX_KEY_S))
			c->p.wd += -1;
		if (mlx_is_key_down(c->m, MLX_KEY_W))
			c->p.wd += 1;
		if (mlx_is_key_down(c->m, MLX_KEY_D))
			c->p.wd_h += 1;
		if (mlx_is_key_down(c->m, MLX_KEY_A))
			c->p.wd_h += -1;
		if (mlx_is_key_down(c->m, MLX_KEY_LEFT))
			c->p.td += -1;
		if (mlx_is_key_down(c->m, MLX_KEY_RIGHT))
			c->p.td += 1;
		move(c);
	}
	print_rays(c);
	if (c->freeze)
	{
		if (c->omenFrame == 30)
			c->omenFrame = 0;
		float scale = 0.5;
		int scaled_x = ((int)(c->omen[c->omenFrame]->width * scale) - W_SIZE) / 4;
		int scaled_y = (H_SIZE - (int)(c->omen[c->omenFrame]->height * scale)) / 2;
		ft_draw_image(c, c->omen[c->omenFrame], scaled_x, scaled_y);
		c->omenFrame++;	
	}
}
