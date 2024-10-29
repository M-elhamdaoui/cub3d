/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils-3_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:45:23 by hmrabet           #+#    #+#             */
/*   Updated: 2024/10/29 15:20:31 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_bool	ft_isal(char c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

t_bool	ft_isnum(char c)
{
	return ((c >= '0' && c <= '9'));
}

t_bool	ft_isalnum(char c)
{
	return (ft_isnum(c) || ft_isal(c));
}
