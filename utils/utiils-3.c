/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiils-3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 17:45:23 by hmrabet           #+#    #+#             */
/*   Updated: 2024/08/31 17:46:15 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
