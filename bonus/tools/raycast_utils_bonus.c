/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:25:51 by mel-hamd          #+#    #+#             */
/*   Updated: 2024/10/29 15:20:16 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

double	get_angle(double ang)
{
	ang = fmod(ang, 2 * M_PI);
	if (ang < 0)
		ang = ang + (2 * M_PI);
	return (ang);
}

void	get_angl_direction(int *is_r_down, int *is_r_left, double ang)
{
	if (ang >= 0 && ang <= M_PI)
		*is_r_down = 1;
	else
		*is_r_down = 0;
	if (ang < (M_PI / 2) || ang > (3 * M_PI / 2))
		*is_r_left = 0;
	else
		*is_r_left = 1;
}

void	setup_steps_h(double step[2], int is_r_down, int is_r_left, double ang)
{
	step[0] = US;
	if (!is_r_down)
		step[0] *= -1;
	step[1] = step[0] / tan(ang);
	if ((!is_r_left && step[1] < 0) || (is_r_left && step[1] > 0))
		step[1] *= -1;
}

double	calc_distance(t_corr a, t_corr b)
{
	double	distance;

	distance = sqrt((a.x - b.x) * (a.x - b.x)
			+ (a.y - b.y) * (a.y - b.y));
	return (distance);
}

void	setup_steps_v(double step[2], int is_r_down, int is_r_left, double ang)
{
	step[0] = US;
	if (is_r_left)
		step[0] *= -1;
	step[1] = step[0] * tan(ang);
	if ((is_r_down && step[1] < 0) || (!is_r_down && step[1] > 0))
		step[1] *= -1;
}
