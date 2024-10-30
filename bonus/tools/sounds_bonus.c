/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sounds_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:05:27 by hmrabet           #+#    #+#             */
/*   Updated: 2024/10/30 19:06:12 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	*run_sound(char *text)
{
	system(text);
	return (NULL);
}

void	play_sound_effect(char *text)
{
	pthread_t	thread;

	pthread_create(&thread, NULL, (void *)run_sound, (text));
	pthread_detach(thread);
}

void	kill_sound_effect(void)
{
	int	i;
 
	i = fork();
	if (!i)
		execve("/usr/bin/killall", (char *[]){"killall", "afplay", NULL}, NULL);
}