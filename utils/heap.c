/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houbet <houbet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:55:49 by hmrabet           #+#    #+#             */
/*   Updated: 2024/08/26 14:51:10 by houbet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	close_fds(t_cub3d *cub)
{
	int	fd;

	fd = cub->max_fd;
	while (fd >= 3)
	{
		close(fd);
		fd--;
	}
}

void	ft_exit(char *msg, int status, t_cub3d *cub)
{
	if (msg)
		ft_putstr_fd(msg, 2);
	close_fds(cub);
	ft_free(&cub->collector);
	exit(status);
}

void	*ft_malloc(t_cub3d *cub, t_block_memory **memory, size_t size)
{
	void			*res;
	t_block_memory	*new;
	t_block_memory	*tmp;

	tmp = *memory;
	res = malloc(size);
	if (!res)
		ft_exit("Allocation error!", 1, cub);
	new = (t_block_memory *)malloc(sizeof(t_block_memory));
	if (!new)
	{
		free(res);
		ft_exit("Allocation error!", 1, cub);
	}
	new->leak = res;
	new->next = NULL;
	if (!tmp)
		*memory = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (res);
}

void	ft_free(t_block_memory **memory)
{
	t_block_memory	*to_free;
	t_block_memory	*to_hold;

	to_free = *memory;
	while (to_free)
	{
		to_hold = to_free->next;
		free(to_free->leak);
		free(to_free);
		to_free = to_hold;
	}
	*memory = NULL;
}
