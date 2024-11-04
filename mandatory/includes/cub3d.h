/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 08:57:39 by hmrabet           #+#    #+#             */
/*   Updated: 2024/11/04 16:42:44 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# include <fcntl.h>
# include "MLX42.h"
# include <math.h>

# define US 32
# define W_SIZE 1200
# define H_SIZE 900
# define FOV 1.0471975511965976

typedef uint32_t	t_ui;

typedef enum e_bool
{
	FALSE,
	TRUE,
}	t_bool;

typedef struct s_block_memory
{
	void					*leak;
	struct s_block_memory	*next;
}	t_block_memory;

typedef struct s_corr
{
	double	x;
	double	y;
	int		color;
}	t_corr;

typedef struct s_player
{
	t_corr	c;
	int		rad;
	int		td;
	int		wd;
	int		wd_h;
	double	rot_ang;
	double	ms;
	double	rot_speed;
}	t_player;

typedef struct s_d
{
	int	w;
	int	h;
}	t_d;

typedef struct s_map
{
	char		**map;
	char		**pre_map;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		*floor;
	char		*ceiling;
	int			f_rgb[3];
	int			c_rgb[3];
	int			height;
	int			width;
}	t_map;

typedef struct s_ray
{
	t_corr	hit_wall;
	double	ang;
	t_bool	is_w_hited;
	double	distance;
	char	type;
}	t_ray;

typedef struct s_wall
{
	double			wall_h;
	double			o_wall_h;
	double			p_wall_h;
	double			x;
	double			y;
	double			start;
	double			end;
	int				pixel_index;
	mlx_texture_t	*png;
}	t_wall;

typedef struct s_cub3d
{
	char				*input;
	unsigned int		max_fd;
	t_map				map;
	t_block_memory		*collector;
	mlx_t				*m;
	t_player			p;
	t_wall				wall;
	t_ray				ray;
	mlx_image_t			*img;
	mlx_texture_t		*wall_n;
	mlx_texture_t		*wall_s;
	mlx_texture_t		*wall_w;
	mlx_texture_t		*wall_e;
}	t_cub3d;

// GARBAGE COLLECTOR
void		*ft_malloc(t_cub3d *cub, t_block_memory **g, size_t s);
void		ft_free(t_block_memory **memory);
void		ft_exit(char *msg, int status, t_cub3d *cub);
void		close_fds(t_cub3d *cub);

// UTILS
size_t		ft_strlen(const char *s);
t_bool		ft_strchr(char *s, char c);
int			ft_strcmp(char *s1, char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(char *haystack, char *needle, size_t len);
size_t		ft_strlcpy(char *dst, char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, char *src, size_t dstsize);
int			ft_atoi(char *str);
void		ft_putstr_fd(char *s, int fd);
char		*ft_strjoin(char *s1, char *s2, t_cub3d *cub);
char		*ft_strdup(char *s1, t_cub3d *cub);
char		*ft_substr(t_cub3d *cub, char *s, unsigned int start, size_t len);
char		*ft_strtrim(t_cub3d *cub, char *s1, char *set);
char		*ft_itoa(t_cub3d *cub, int n);
char		**ft_split(char *s, char c, t_cub3d *cub);
t_bool		ft_isal(char c);
t_bool		ft_isnum(char c);
t_bool		ft_isalnum(char c);

// INITIALIZERS
void		init_data(t_cub3d *cub, char **av);

// PARSERS
int			get_map_height(char **splitted, int i);
int			get_big_line(char **splitted, int i);
void		check_map_row(t_cub3d *cub, char *row);
void		check_chars(t_cub3d *cub);
void		check_colors(t_cub3d *cub);
void		parse_map(t_cub3d *cub);
void		parse_identifiers(t_cub3d *cub);
void		init_map(t_cub3d *cub, char **av);

// run mlx
int			lunch_mlx(t_cub3d *cub);
int			put_square(t_corr *corr, t_d *d, t_cub3d *cub, int color);
int			ft_create_color(int r, int g, int b, int a);
void		rneder_map_2d(t_cub3d *cub);
mlx_image_t	*create_image(int w, int h, t_cub3d *cub);
void		render_circle(int x, int y, int color, t_cub3d *cub);
void		put_line(t_corr a, t_corr b, t_cub3d *cub);
void		key_fun(void *params);
void		cam_move(t_cub3d *cub);
void		put_line_v2(t_corr c, int d, double ang, t_cub3d *cub);
void		draw_textures(t_cub3d *cub, double x, t_bool reverse);
void		print_rays(t_cub3d *cub);
void		move_f_b(t_cub3d *c);
void		move_l_r(t_cub3d *c);
void		move(t_cub3d *c);
t_ray		cast_ray_h(t_cub3d *c, double ang, int is_r_down, int is_r_left);
double		get_angle(double ang);
void		get_angl_direction(int *is_r_down, int *is_r_left, double ang);
void		setup_steps_h(double step[2], int down, int left, double ang);
double		calc_distance(t_corr a, t_corr b);
void		setup_steps_v(double step[2], int down, int left, double ang);
int			cast_condition(t_corr inter, t_cub3d *c);
t_ray		cast_ray_v(double ang, int is_down, int is_left, t_cub3d *c);
t_ray		which_ray(double ang, t_cub3d *c);

#endif
