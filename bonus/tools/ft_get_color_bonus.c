/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:59:39 by mel-hamd          #+#    #+#             */
/*   Updated: 2024/10/30 11:02:08 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_create_color(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
