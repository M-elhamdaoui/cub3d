/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 08:57:39 by hmrabet           #+#    #+#             */
/*   Updated: 2024/08/31 14:33:30 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# include <fcntl.h>
# include "mlx.h"

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

typedef struct s_map
{
	char	**map;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*floor;
	char	*ceiling;
}	t_map;

typedef struct s_cub3d
{
	char				*input;
	unsigned int		max_fd;
	t_map				map;
	t_block_memory		*collector;
}	t_cub3d;

// GARBAGE COLLECTOR
void	*ft_malloc(t_cub3d *cub, t_block_memory **g, size_t s);
void	ft_free(t_block_memory **memory);
void	ft_exit(char *msg, int status, t_cub3d *cub);
void	close_fds(t_cub3d *cub);

// UTILS
size_t	ft_strlen(const char *s);
t_bool	ft_strchr(char *s, char c);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(char *haystack, char *needle, size_t len);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);
int		ft_atoi(char *str);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char *s1, char *s2, t_cub3d *cub);
char	*ft_strdup(char *s1, t_cub3d *cub);
char	*ft_substr(t_cub3d *cub, char *s, unsigned int start, size_t len);
char	*ft_strtrim(t_cub3d *cub, char *s1, char *set);
char	*ft_itoa(t_cub3d *cub, int n);
char	**ft_split(char *s, char c, t_cub3d *cub);

// INITIALIZERS
void	init_data(t_cub3d *cub, char **av);

// PARSERS
int		parse_map(char **map);

#endif
