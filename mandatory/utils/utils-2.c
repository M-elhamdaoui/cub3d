/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils-2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houbet <houbet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 19:59:09 by hmrabet           #+#    #+#             */
/*   Updated: 2024/08/26 14:51:10 by houbet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strjoin(char *s1, char *s2, t_cub3d *cub)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	str = (char *)ft_malloc(cub, &cub->collector,
			ft_strlen(s1) + ft_strlen(s2) + 1);
	while (*(s1 + i))
	{
		*(str + i) = *(s1 + i);
		i++;
	}
	while (*(s2 + j))
	{
		*(str + i + j) = *(s2 + j);
		j++;
	}
	*(str + i + j) = '\0';
	return (str);
}

char	*ft_strdup(char *s1, t_cub3d *cub)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)ft_malloc(cub, &cub->collector, ft_strlen(s1) + 1);
	while (*(s1 + i))
	{
		*(str + i) = *(s1 + i);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}

char	*ft_substr(t_cub3d *cub, char *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		res = (char *)ft_malloc(cub, &cub->collector, 1);
		if (!res)
			return (NULL);
		return (res[0] = '\0', res);
	}
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	res = (char *)ft_malloc(cub, &cub->collector, sizeof(char) * (len + 1));
	i = 0;
	while (i < len && *(s + start + i))
	{
		*(res + i) = *(s + start + i);
		i++;
	}
	return (*(res + i) = '\0', res);
}

char	*ft_strtrim(t_cub3d *cub, char *s1, char *set)
{
	int		start;
	int		end;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, *(s1 + start)) && start <= end)
		start++;
	if (start > end)
		return (ft_strdup(s1 + end + 1, cub));
	while (ft_strchr(set, *(s1 + end)) && end >= 0)
		end--;
	str = ft_malloc(cub, &cub->collector, end - start + 2);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + start, end - start + 2);
	return (str);
}
