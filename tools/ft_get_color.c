/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hamd <mel-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:59:39 by mel-hamd          #+#    #+#             */
/*   Updated: 2024/08/31 21:01:59 by mel-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_create_color(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}