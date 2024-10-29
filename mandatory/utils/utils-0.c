/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils-0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmrabet <hmrabet@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 19:49:18 by hmrabet           #+#    #+#             */
/*   Updated: 2024/08/31 15:01:50 by hmrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

t_bool	ft_strchr(char *s, char c)
{
	size_t	i;

	if (!s)
		return (FALSE);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while ((*(s1 + i) || *(s2 + i)))
	{
		if (*(unsigned char *)(s1 + i) != *(unsigned char *)(s2 + i))
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
		i++;
	}
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((*(s1 + i) || *(s2 + i)) && i < n)
	{
		if (*(unsigned char *)(s1 + i) != *(unsigned char *)(s2 + i))
			return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
		i++;
	}
	return (0);
}

char	*ft_strnstr(char *haystack, char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (!*needle || (!len && !*needle))
		return ((char *)haystack);
	if (!len)
		return (NULL);
	res = (char *)haystack;
	i = 0;
	if (len > ft_strlen(haystack))
		len = ft_strlen(haystack);
	if (*needle == '\0')
		return (res);
	while (i < len)
	{
		j = 0;
		while (*(haystack + i + j) == *(needle + j) && (i + j) < len)
		{
			if (needle[++j] == '\0')
				return (res + i);
		}
		i++;
	}
	return (NULL);
}
